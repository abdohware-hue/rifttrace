cmake_minimum_required(VERSION 3.16)
project(rifttrace VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(RIFTTRACE_SOURCES
  src/byte_reader.cpp
  src/format.cpp
  src/container.cpp
  src/section_table.cpp
  src/block_decoder.cpp
  src/record.cpp
  src/record_decoder.cpp
  src/string_table.cpp
  src/symbol_table.cpp
  src/frame_index.cpp
  src/object_pool.cpp
  src/block_cache.cpp
  src/model.cpp
  src/resolver.cpp
  src/stream.cpp
  src/timeline.cpp
  src/search.cpp
  src/export_summary.cpp
  src/checksum.cpp
  src/diagnostics.cpp
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

foreach(
  test_name
  IN ITEMS
    reader
    container
    export
    blocks
    records
    strings
    index
    resolver
    stream
)
  add_executable(test_${test_name} tests/test_${test_name}.cpp)
  target_link_libraries(test_${test_name} PRIVATE rifttrace)
  add_test(NAME test_${test_name} COMMAND test_${test_name})
endforeach()

add_custom_target(
  rifttrace-tests
  DEPENDS
    test_reader test_container test_export test_blocks test_records
    test_strings test_index test_resolver test_stream
)

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
