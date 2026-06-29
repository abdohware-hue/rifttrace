#!/bin/bash -eu

PROJECT="$SRC"
BUILD="$WORK/build"
mkdir -p "$BUILD"

COMMON_SRC=(
  "$PROJECT/src/alias_graph.cpp"
  "$PROJECT/src/archive_builder.cpp"
  "$PROJECT/src/archive_writer.cpp"
  "$PROJECT/src/binary_writer.cpp"
  "$PROJECT/src/block_cache.cpp"
  "$PROJECT/src/block_decoder.cpp"
  "$PROJECT/src/block_encoder.cpp"
  "$PROJECT/src/byte_reader.cpp"
  "$PROJECT/src/checkpoint_replay.cpp"
  "$PROJECT/src/checkpoint_store.cpp"
  "$PROJECT/src/codec_registry.cpp"
  "$PROJECT/src/container.cpp"
  "$PROJECT/src/correlation_engine.cpp"
  "$PROJECT/src/delta_codec.cpp"
  "$PROJECT/src/diagnostics.cpp"
  "$PROJECT/src/dictionary_codec.cpp"
  "$PROJECT/src/event_aggregator.cpp"
  "$PROJECT/src/export_pipeline.cpp"
  "$PROJECT/src/export_summary.cpp"
  "$PROJECT/src/filter_engine.cpp"
  "$PROJECT/src/format.cpp"
  "$PROJECT/src/format_rules.cpp"
  "$PROJECT/src/frame_delta.cpp"
  "$PROJECT/src/frame_index.cpp"
  "$PROJECT/src/graph_validator.cpp"
  "$PROJECT/src/index_builder.cpp"
  "$PROJECT/src/inverted_index.cpp"
  "$PROJECT/src/json_report.cpp"
  "$PROJECT/src/metadata_parser.cpp"
  "$PROJECT/src/model.cpp"
  "$PROJECT/src/object_pool.cpp"
  "$PROJECT/src/pool_analyzer.cpp"
  "$PROJECT/src/query_ast.cpp"
  "$PROJECT/src/record.cpp"
  "$PROJECT/src/record_builder.cpp"
  "$PROJECT/src/record_decoder.cpp"
  "$PROJECT/src/replay_session.cpp"
  "$PROJECT/src/resolver.cpp"
  "$PROJECT/src/search.cpp"
  "$PROJECT/src/section_table.cpp"
  "$PROJECT/src/section_validator.cpp"
  "$PROJECT/src/stream.cpp"
  "$PROJECT/src/stream_query.cpp"
  "$PROJECT/src/string_table.cpp"
  "$PROJECT/src/summary_builder.cpp"
  "$PROJECT/src/symbol_table.cpp"
  "$PROJECT/src/telemetry_pipeline.cpp"
  "$PROJECT/src/timeline.cpp"
  "$PROJECT/src/timeline_analytics.cpp"
  "$PROJECT/src/checksum.cpp"
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
