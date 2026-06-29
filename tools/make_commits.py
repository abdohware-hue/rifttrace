#!/usr/bin/env python3
"""Create natural commit history for rifttrace."""
import subprocess
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]

COMMITS = [
    (
        [
            "LICENSE",
            "AUTHORS",
            "README.md",
            ".gitignore",
            "include/rifttrace/errors.hpp",
            "include/rifttrace/format.hpp",
            "include/rifttrace/byte_reader.hpp",
            "include/rifttrace/container.hpp",
            "include/rifttrace/section_table.hpp",
            "include/rifttrace/block_decoder.hpp",
            "src/format.cpp",
            "src/byte_reader.cpp",
            "src/container.cpp",
            "src/section_table.cpp",
            "src/block_decoder.cpp",
        ],
        "Add project scaffold and RIFT archive parser foundation.\n\n"
        "Introduce MIT-licensed rifttrace with format constants, bounded byte reader,\n"
        "container header parsing, section table validation, and block decoding entry points.",
    ),
    (
        [
            "include/rifttrace/record.hpp",
            "include/rifttrace/record_decoder.hpp",
            "include/rifttrace/string_table.hpp",
            "include/rifttrace/symbol_table.hpp",
            "src/record.cpp",
            "src/record_decoder.cpp",
            "src/string_table.cpp",
            "src/symbol_table.cpp",
        ],
        "Implement typed records and string/symbol table materialization.\n\n"
        "Add object/frame/event/alias record encoding, batch decoding, and interned\n"
        "string tables with symbol rebuild hooks for downstream resolution.",
    ),
    (
        [
            "include/rifttrace/frame_index.hpp",
            "include/rifttrace/object_pool.hpp",
            "include/rifttrace/block_cache.hpp",
            "include/rifttrace/model.hpp",
            "include/rifttrace/resolver.hpp",
            "include/rifttrace/checksum.hpp",
            "include/rifttrace/diagnostics.hpp",
            "src/frame_index.cpp",
            "src/object_pool.cpp",
            "src/block_cache.cpp",
            "src/model.cpp",
            "src/resolver.cpp",
            "src/checksum.cpp",
            "src/diagnostics.cpp",
        ],
        "Add telemetry model, caches, and cross-reference resolution.\n\n"
        "Build frame index, object pool compaction, LRU block cache, resolver graph,\n"
        "and checksum/diagnostic helpers over parsed archive state.",
    ),
    (
        None,
        "Expand stream replay, export pipelines, and analysis subsystems.\n\n"
        "Add incremental stream commands, timeline/search/export paths, checkpoint replay,\n"
        "codec registry, metadata parsing, JSON reporting, and CLI tooling for archive inspection.",
    ),
    (
        [
            "tests/",
            "tools/make_sample.cpp",
            "tools/dump_archive.cpp",
            "tools/mutate_sample.cpp",
            "tools/gen_corpus.py",
            "CMakeLists.txt",
        ],
        "Add unit tests, sample generators, and CMake build graph.\n\n"
        "Cover reader/container/export/block/string/index/resolver/stream behavior with\n"
        "assert-based tests plus make-sample, dump, mutate, and corpus generation utilities.",
    ),
    (
        ["fuzz/", ".clusterfuzzlite/"],
        "Integrate ClusterFuzzLite harnesses and structured seed corpus.\n\n"
        "Wire five deep libFuzzer entry points, dictionary tokens, 60 near-valid seeds,\n"
        "and sanitizer-friendly build scripts for platform fuzzing workflows.",
    ),
]


def run(cmd):
    print("+", " ".join(cmd))
    subprocess.check_call(cmd, cwd=ROOT)


def main():
    run(["git", "config", "user.name", "abdohware"])
    run(["git", "config", "user.email", "abdohware9@gmail.com"])

    committed = set()
    for paths, message in COMMITS:
        if paths is None:
            remaining = []
            for p in ROOT.rglob("*"):
                if p.is_dir() or ".git" in p.parts:
                    continue
                rel = p.relative_to(ROOT).as_posix()
                if rel in committed:
                    continue
                remaining.append(rel)
            paths = remaining
        for rel in paths:
            p = ROOT / rel
            if p.is_dir():
                run(["git", "add", rel])
            elif p.exists():
                run(["git", "add", rel])
                committed.add(rel)
            else:
                print("skip missing", rel)
        run(["git", "commit", "-m", message])

    run(["git", "log", "--oneline"])


if __name__ == "__main__":
    main()
