# rifttrace

**rifttrace** is a C++17 library and command-line toolchain for working with **RIFT** (`.rft`) binary telemetry archives. It parses sectioned capture files, builds an in-memory telemetry model, resolves symbols and aliases, supports incremental stream commands, and exports searchable timeline summaries.

**Author:** abdohware ([abdohware9@gmail.com](mailto:abdohware9@gmail.com))  
**Copyright:** 2026 abdohware  
**GitHub:** [abdohware-hue](https://github.com/abdohware-hue)

## Features

- **Archive parsing** — RIFT v1 header, section table, and typed section bodies (`STRS`, `DATA`, `IDX0`, `META`, `CMP0`)
- **Record model** — object, frame, event, and alias records with encode/decode helpers
- **State** — string/symbol tables, frame index, object pool, LRU block cache
- **Resolution** — cross-reference resolver over parsed records and string names
- **Stream processing** — append, rebuild strings, evict block, compact pool, finalize
- **Export** — timeline construction, substring search, FNV-1a summary hashes
- **CLI** — `rifttrace-dump` prints archive statistics and diagnostics

## RIFT archive format

All integers are little-endian. See `include/rifttrace/format.hpp` for section layouts and fourCC constants.

## Build

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build
ctest --test-dir build
```

| Target | Description |
|--------|-------------|
| `rifttrace` | Core library |
| `rifttrace-dump` | CLI archive summary |
| `rifttrace-make-sample` | Write a valid sample `.rft` |
| `rifttrace-mutate-sample` | Perturb a sample into near-valid inputs |
| `rifttrace-tests` | Unit tests |

## Usage

```bash
./build/rifttrace-make-sample sample.rft
./build/rifttrace-dump sample.rft
./build/rifttrace-mutate-sample sample.rft mutated.rft 1234
python tools/gen_corpus.py
```

## Architecture

```
parse_archive → build_model → Resolver + Timeline + SearchIndex → export_summary
                     ↓
              StreamProcessor (append / rebuild / evict / compact / finalize)
```

Core modules: `byte_reader`, `container`, `section_table`, `block_decoder`, `record_decoder`, `string_table`, `symbol_table`, `frame_index`, `object_pool`, `block_cache`, `resolver`, `stream`, `timeline`, `search`, `export_summary`.

## Fuzzing (`fuzz/`)

ClusterFuzzLite configuration lives in `.clusterfuzzlite/`. Harnesses call the same library APIs as the CLI and reach parse → model → resolve → export paths. Seeds are generated with `tools/gen_corpus.py` (no build required).

## License

MIT — see [LICENSE](LICENSE).
