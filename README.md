# rifttrace

**rifttrace** is a C++17 library and command-line toolchain for working with **RIFT** (`.rft`) binary telemetry archives. It parses sectioned archives, materializes a typed telemetry model, resolves symbols and aliases, supports incremental stream replay, and produces structured summaries and JSON reports for downstream analysis.

**Author:** abdohware ([abdohware9@gmail.com](mailto:abdohware9@gmail.com))  
**Copyright:** 2026 abdohware  
**GitHub:** [abdohware-hue](https://github.com/abdohware-hue)

## Features

- **Archive I/O** — parse and build RIFT v1 archives with `STRS`, `DATA`, `IDX0`, `META`, and `CMP0` sections
- **Record model** — objects, frames, events, and alias records with typed encode/decode
- **Resolution** — string/symbol tables, alias graph traversal, inverted search index
- **Stream processing** — append/evict/compact/finalize command log with query engine
- **Validation** — format version rules, section validation, graph consistency checks
- **Codecs** — raw, simple RLE, delta, and dictionary block codecs with transcode registry
- **Checkpoint replay** — capture and replay model checkpoints during stream processing
- **Export** — timeline analytics, event aggregation, frame deltas, JSON report rendering

## RIFT archive format

All integers are little-endian.

### Header (12 bytes)

| Field | Type | Description |
|-------|------|-------------|
| magic | char[4] | `"RIFT"` |
| version | u16 | currently `1` |
| flags | u16 | reserved |
| section_count | u32 | number of section table entries |

### Section table (16 bytes × section_count)

| Field | Type | Description |
|-------|------|-------------|
| type | u32 | fourCC: `STRS`, `DATA`, `IDX0`, `META`, `CMP0` |
| offset | u32 | byte offset from file start |
| size | u32 | section payload size |
| flags | u32 | reserved |

See inline documentation in `include/rifttrace/format.hpp` for section payload layouts.

## Build

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build
ctest --test-dir build
```

### Targets

| Target | Description |
|--------|-------------|
| `rifttrace` | Core static library |
| `rifttrace-dump` | CLI archive summary |
| `rifttrace-make-sample` | Write a valid sample `.rft` |
| `rifttrace-mutate-sample` | Perturb a valid sample into near-valid fuzz seeds |
| `rifttrace-tests` | Unit test aggregate |

## Usage

```bash
./build/rifttrace-make-sample sample.rft
./build/rifttrace-dump sample.rft
./build/rifttrace-mutate-sample sample.rft mutated.rft 1234
```

## Architecture

```
parse_archive → build_model → Resolver / Timeline / SearchIndex
                     ↓
              StreamProcessor → CheckpointReplay → ExportPipeline → JsonReportRenderer
```

Key modules live under `include/rifttrace/` and `src/`: archive builder/writer, metadata parser, delta/dictionary codecs, graph validator, frame deltas, event aggregation, alias graph, format rules, stream query engine, and telemetry pipeline orchestration.

## Quality tooling (`fuzz/`)

Continuous fuzzing is configured for ClusterFuzzLite (`.clusterfuzzlite/`). The `fuzz/` directory holds harnesses and seed corpora — it supports quality assurance but is not the primary product surface.

```bash
python tools/gen_corpus.py          # regenerate 30+ Python-built seeds (no binary required)
./build/rifttrace-mutate-sample sample.rft fuzz/corpus/container_fuzzer/near_valid.rft
```

Harnesses exercise full parse → model → resolve → export paths:

- `container_fuzzer` — archive parse, validation, export pipeline
- `stream_fuzzer` — stream commands, checkpoint capture, JSON export
- `metadata_fuzzer` — metadata parsing and section validation
- `resolver_fuzzer` — alias graph, inverted index, correlation
- `export_fuzzer` — summaries, frame deltas, event aggregation, JSON reports

## License

MIT — see [LICENSE](LICENSE).
