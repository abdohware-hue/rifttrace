#!/bin/bash -eu

PROJECT="$SRC"

COMMON_SRC=(
  "$PROJECT/src/byte_reader.cpp"
  "$PROJECT/src/format.cpp"
  "$PROJECT/src/container.cpp"
  "$PROJECT/src/section_table.cpp"
  "$PROJECT/src/block_decoder.cpp"
  "$PROJECT/src/record.cpp"
  "$PROJECT/src/record_decoder.cpp"
  "$PROJECT/src/string_table.cpp"
  "$PROJECT/src/symbol_table.cpp"
  "$PROJECT/src/frame_index.cpp"
  "$PROJECT/src/object_pool.cpp"
  "$PROJECT/src/block_cache.cpp"
  "$PROJECT/src/model.cpp"
  "$PROJECT/src/resolver.cpp"
  "$PROJECT/src/stream.cpp"
  "$PROJECT/src/timeline.cpp"
  "$PROJECT/src/search.cpp"
  "$PROJECT/src/export_summary.cpp"
  "$PROJECT/src/checksum.cpp"
  "$PROJECT/src/diagnostics.cpp"
)

COMMON_FLAGS=(
  -std=c++17
  -I"$PROJECT/include"
)

for target in container stream metadata resolver export; do
  $CXX $CXXFLAGS "${COMMON_FLAGS[@]}" \
    "$PROJECT/fuzz/${target}_fuzzer.cc" \
    "${COMMON_SRC[@]}" \
    $LIB_FUZZING_ENGINE \
    -o "$OUT/${target}_fuzzer"
done

if [ -f "$PROJECT/fuzz/dictionary.txt" ]; then
  cp "$PROJECT/fuzz/dictionary.txt" "$OUT/dictionary.txt"
fi
