cmake_minimum_required(VERSION 3.16)
project(rifttrace VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(RIFTTRACE_SOURCES
  src/alias_graph.cpp
  src/archive_builder.cpp
  src/archive_writer.cpp
  src/binary_writer.cpp
  src/block_cache.cpp
  src/block_decoder.cpp
  src/block_encoder.cpp
  src/byte_reader.cpp
  src/checkpoint_replay.cpp
  src/checkpoint_store.cpp
  src/codec_registry.cpp
  src/container.cpp
  src/correlation_engine.cpp
  src/delta_codec.cpp
  src/diagnostics.cpp
  src/dictionary_codec.cpp
  src/event_aggregator.cpp
  src/export_pipeline.cpp
  src/export_summary.cpp
  src/filter_engine.cpp
  src/format.cpp
  src/format_rules.cpp
  src/frame_delta.cpp
  src/frame_index.cpp
  src/graph_validator.cpp
  src/index_builder.cpp
  src/inverted_index.cpp
  src/json_report.cpp
  src/metadata_parser.cpp
  src/model.cpp
  src/object_pool.cpp
  src/pool_analyzer.cpp
  src/query_ast.cpp
  src/record.cpp
  src/record_builder.cpp
  src/record_decoder.cpp
  src/replay_session.cpp
  src/resolver.cpp
  src/search.cpp
  src/section_table.cpp
  src/section_validator.cpp
  src/stream.cpp
  src/stream_query.cpp
  src/string_table.cpp
  src/summary_builder.cpp
  src/symbol_table.cpp
  src/telemetry_pipeline.cpp
  src/timeline.cpp
  src/timeline_analytics.cpp
  src/checksum.cpp
)

add_library(rifttrace ${RIFTTRACE_SOURCES})
target_include_directories(rifttrace PUBLIC include)

add_executable(rifttrace-dump src/cli.cpp)
target_link_libraries(rifttrace-dump PRIVATE rifttrace)

add_executable(rifttrace-make-sample tools/make_sample.cpp)
target_link_libraries(rifttrace-make-sample PRIVATE rifttrace)

add_executable(rifttrace-dump-tool tools/dump_archive.cpp)
target_link_libraries(rifttrace-dump-tool PRIVATE rifttrace)

add_executable(rifttrace-mutate-sample tools/mutate_sample.cpp)
target_link_libraries(rifttrace-mutate-sample PRIVATE rifttrace)

enable_testing()

add_executable(test_reader tests/test_reader.cpp)
target_link_libraries(test_reader PRIVATE rifttrace)
add_test(NAME test_reader COMMAND test_reader)

add_executable(test_container tests/test_container.cpp)
target_link_libraries(test_container PRIVATE rifttrace)
add_test(NAME test_container COMMAND test_container)

add_executable(test_export tests/test_export.cpp)
target_link_libraries(test_export PRIVATE rifttrace)
add_test(NAME test_export COMMAND test_export)

add_executable(test_blocks tests/test_blocks.cpp)
target_link_libraries(test_blocks PRIVATE rifttrace)
add_test(NAME test_blocks COMMAND test_blocks)

add_executable(test_records tests/test_records.cpp)
target_link_libraries(test_records PRIVATE rifttrace)
add_test(NAME test_records COMMAND test_records)

add_executable(test_strings tests/test_strings.cpp)
target_link_libraries(test_strings PRIVATE rifttrace)
add_test(NAME test_strings COMMAND test_strings)

add_executable(test_index tests/test_index.cpp)
target_link_libraries(test_index PRIVATE rifttrace)
add_test(NAME test_index COMMAND test_index)

add_executable(test_resolver tests/test_resolver.cpp)
target_link_libraries(test_resolver PRIVATE rifttrace)
add_test(NAME test_resolver COMMAND test_resolver)

add_executable(test_stream tests/test_stream.cpp)
target_link_libraries(test_stream PRIVATE rifttrace)
add_test(NAME test_stream COMMAND test_stream)

add_custom_target(rifttrace-tests DEPENDS
  test_reader test_container test_export test_blocks test_records
  test_strings test_index test_resolver test_stream)

if(DEFINED ENV{LIB_FUZZING_ENGINE} OR DEFINED LIB_FUZZING_ENGINE)
  set(FUZZ_ENGINE $ENV{LIB_FUZZING_ENGINE})
  if(NOT FUZZ_ENGINE)
    set(FUZZ_ENGINE ${LIB_FUZZING_ENGINE})
  endif()
  foreach(target container stream metadata resolver export)
    add_executable(${target}_fuzzer fuzz/${target}_fuzzer.cc)
    target_link_libraries(${target}_fuzzer PRIVATE rifttrace ${FUZZ_ENGINE})
  endforeach()
endif()
