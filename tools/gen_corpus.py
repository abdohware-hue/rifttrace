#!/usr/bin/env python3
# Copyright (c) 2026 abdohware
"""Generate varied fuzz seed corpora for rifttrace without requiring a built binary."""

import struct
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
CORPUS = ROOT / "fuzz" / "corpus"

HARNESSes = (
    "container_fuzzer",
    "stream_fuzzer",
    "metadata_fuzzer",
    "resolver_fuzzer",
    "export_fuzzer",
)


def u16(v):
    return struct.pack("<H", v)


def u32(v):
    return struct.pack("<I", v)


def u64(v):
    return struct.pack("<Q", v)


def cstring(s: str) -> bytes:
    return s.encode("utf-8") + b"\x00"


def build_strings(names):
    blob = b"".join(cstring(n) for n in names)
    offsets = []
    cursor = 0
    for name in names:
        offsets.append(cursor)
        cursor += len(name) + 1
    out = bytearray()
    out += u32(len(names))
    out += u32(4 + 4 * len(names))
    for off in offsets:
        out += u32(off)
    out += blob
    return bytes(out)


def build_record(record_type, payload):
    out = bytearray()
    out.append(record_type)
    out += u32(len(payload))
    out += payload
    return bytes(out)


def object_payload(obj_id, name_index, symbol_index, pool_slot):
    return u32(obj_id) + u32(name_index) + u32(symbol_index) + u32(pool_slot)


def frame_payload(frame_id, ts, parent, obj_count):
    return u32(frame_id) + u64(ts) + u32(parent) + u32(obj_count)


def event_payload(event_id, frame_id, name_index, severity):
    return u32(event_id) + u32(frame_id) + u32(name_index) + bytes([severity])


def alias_payload(alias_id, target_id, name_index):
    return u32(alias_id) + u32(target_id) + u32(name_index)


def build_data(records):
    out = bytearray(u32(len(records)))
    for rec in records:
        out += rec
    return bytes(out)


def build_index(entries):
    out = bytearray(u32(len(entries)))
    for record_id, data_offset, alias_id in entries:
        out += u32(record_id)
        out += u32(data_offset)
        out += u32(alias_id)
    return bytes(out)


def build_meta(pairs):
    out = bytearray(u32(len(pairs)))
    for key_index, value_index in pairs:
        out += u32(key_index)
        out += u32(value_index)
    return bytes(out)


def build_cmp0(blocks):
    out = bytearray(u32(len(blocks)))
    for block_id, codec, compressed, uncompressed in blocks:
        out += u32(block_id)
        out += bytes([codec])
        out += u32(len(compressed))
        out += u32(uncompressed)
        out += compressed
    return bytes(out)


def build_archive(sections):
    header_size = 12
    table_size = len(sections) * 16
    cursor = header_size + table_size
    out = bytearray(b"RIFT")
    out += u16(1)
    out += u16(0)
    out += u32(len(sections))
    payloads = []
    for sec_type, payload in sections:
        out += u32(sec_type)
        out += u32(cursor)
        out += u32(len(payload))
        out += u32(0)
        cursor += len(payload)
        payloads.append(payload)
    for payload in payloads:
        out += payload
    return bytes(out)


def build_stream(commands):
    out = bytearray(u32(len(commands)))
    for cmd, payload in commands:
        out.append(cmd)
        out += u32(len(payload))
        out += payload
    return bytes(out)


STRS = 0x53545253
DATA = 0x41544144
IDX0 = 0x30584449
META = 0x4154454D
CMP0 = 0x30504D43


def seed_variants():
    names_sets = [
        ["sensor.alpha", "sensor.beta", "frame.root", "event.tick", "SymA"],
        ["io.read", "io.write", "net.rx", "net.tx", "SymIO", "alias.primary"],
        ["cpu.core0", "cpu.core1", "mem.heap", "mem.stack", "SymCPU", "trace.start"],
        ["gpu.frame", "gpu.shader", "audio.mix", "SymGPU", "meta.build", "meta.version"],
        ["app.init", "app.loop", "app.shutdown", "SymApp", "checkpoint.a", "checkpoint.b"],
        ["db.query", "db.commit", "cache.hit", "cache.miss", "SymDB"],
        ["render.pass", "render.present", "input.key", "SymRender"],
    ]

    variants = []

    for i, names in enumerate(names_sets):
        strs = build_strings(names)
        obj = build_record(1, object_payload(1 + i, 0, len(names) - 1, i % 8))
        frame = build_record(2, frame_payload(10 + i, 1000 * (i + 1), 0, 1))
        event = build_record(3, event_payload(20 + i, 10 + i, min(3, len(names) - 1), i % 5))
        alias = build_record(4, alias_payload(30 + i, 1 + i, min(4, len(names) - 1)))
        data = build_data([obj, frame, event, alias])
        idx = build_index([(1 + i, 0, 0), (10 + i, 32, 0), (30 + i, 64, 30 + i)])
        meta = build_meta([(min(2, len(names) - 1), 0), (min(5, len(names) - 1), 1)])
        payload = bytes([0xFF, 0xFF, 0x05, 0x00, 0x61, 0x62, 0x63])
        cmp0 = build_cmp0([(7 + i, 1, payload, 5)])
        archive = build_archive([(STRS, strs), (DATA, data), (IDX0, idx), (META, meta), (CMP0, cmp0)])
        variants.append((f"full_{i:02d}.rft", archive))

    for i in range(8):
        strs = build_strings([f"obj.{i}", f"sym.{i}"])
        records = [build_record(1, object_payload(i + 1, 0, 1, i))]
        if i % 2 == 0:
            records.append(build_record(2, frame_payload(100 + i, i * 500, 0, 1)))
        data = build_data(records)
        archive = build_archive([(STRS, strs), (DATA, data)])
        variants.append((f"minimal_data_{i:02d}.rft", archive))

    for i in range(6):
        meta = build_meta([(0, 1), (1, 0), (i, i + 1)])
        strs = build_strings(["key.a", "key.b", "val.x", "val.y"])
        archive = build_archive([(STRS, strs), (META, meta)])
        variants.append((f"meta_focus_{i:02d}.rft", archive))

    for i in range(6):
        stream = build_stream([
            (1, bytes([1]) + u32(16) + object_payload(50 + i, 0, 0, 0)),
            (5, b""),
        ])
        base = build_archive([])
        variants.append((f"stream_{i:02d}.rft", base + stream))

    for i in range(4):
        cmp_payload = bytes([0x61] * (8 + i))
        cmp0 = build_cmp0([(100 + i, 0, cmp_payload, len(cmp_payload))])
        archive = build_archive([(CMP0, cmp0)])
        variants.append((f"cmp_only_{i:02d}.rft", archive))

    for i in range(4):
        strs = build_strings([f"idx.{i}", f"sym.{i}"])
        idx = build_index([(i + 1, i * 4, i + 10), (i + 2, i * 8, 0)])
        archive = build_archive([(STRS, strs), (IDX0, idx)])
        variants.append((f"index_focus_{i:02d}.rft", archive))

    return variants


def write_corpus(harness, name, payload):
    target = CORPUS / harness / name
    target.parent.mkdir(parents=True, exist_ok=True)
    target.write_bytes(payload)
    return target


def extra_variants():
    """Additional near-valid archives to reach 60-80 corpus files per playbook."""
    extras = []
    for i in range(10):
        names = [f"probe.{i}.{j}" for j in range(4)]
        strs = build_strings(names)
        records = []
        for j in range(3):
            records.append(build_record(1, object_payload(1000 + i * 10 + j, j, j, (i + j) % 16)))
            records.append(build_record(2, frame_payload(2000 + i * 10 + j, (i + 1) * 1000 + j, j, 2)))
            records.append(build_record(4, alias_payload(3000 + i * 10 + j, 1000 + i * 10 + j, j)))
        data = build_data(records)
        idx = build_index([(1000 + i * 10 + j, j * 12, 3000 + i * 10 + j) for j in range(3)])
        meta = build_meta([(0, 1), (2, 3), (i % 4, (i + 1) % 4)])
        cmp0 = build_cmp0([(500 + i, 0, bytes([0x10 + i] * (6 + i)), 6 + i)])
        archive = build_archive([(STRS, strs), (DATA, data), (IDX0, idx), (META, meta), (CMP0, cmp0)])
        extras.append((f"probe_{i:02d}.rft", archive))

    for i in range(8):
        stream = build_stream([
            (1, bytes([1]) + u32(16) + object_payload(400 + i, 0, 1, i)),
            (2, b""),
            (3, u32(500 + i)),
            (4, b""),
            (5, b""),
        ])
        strs = build_strings([f"stream.{i}", f"final.{i}"])
        archive = build_archive([(STRS, strs)]) + stream
        extras.append((f"stream_deep_{i:02d}.rft", archive))

    for i in range(6):
        names = [f"resolver.{i}.a", f"resolver.{i}.b", f"alias.{i}"]
        strs = build_strings(names)
        alias = build_record(4, alias_payload(9000 + i, 9100 + i, 2))
        obj_a = build_record(1, object_payload(9100 + i, 0, 1, i))
        obj_b = build_record(1, object_payload(9101 + i, 1, 1, i + 1))
        data = build_data([obj_a, obj_b, alias])
        idx = build_index([(9100 + i, 0, 9000 + i), (9101 + i, 32, 0)])
        archive = build_archive([(STRS, strs), (DATA, data), (IDX0, idx)])
        extras.append((f"alias_graph_{i:02d}.rft", archive))

    return extras


def main():
    variants = seed_variants() + extra_variants()
    assert len(variants) >= 30, len(variants)

    # 12 seeds per harness (minimal + 11 variants) => 60 total; playbook target 30-80.
    per_harness = 11

    for harness in HARNESSes:
        write_corpus(harness, "minimal.rft", build_archive([]))
        for idx, (name, payload) in enumerate(variants):
            write_corpus(harness, name, payload)
            if idx >= per_harness - 1:
                break

    total = sum(1 for _ in CORPUS.rglob("*.rft"))
    print(f"generated {total} seed files under fuzz/corpus/")


if __name__ == "__main__":
    main()
