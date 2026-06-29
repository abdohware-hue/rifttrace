// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT
#pragma once

#include <cstdint>
#include <string>
#include <vector>

#include "rifttrace/stream.hpp"

namespace rifttrace {

struct QueryResult {
  std::uint32_t query_id = 0;
  bool ok = false;
  std::string message;
  std::size_t payload_size = 0;
  std::uint32_t first_word = 0;
};

class StreamQueryEngine {
 public:
  explicit StreamQueryEngine(StreamProcessor* processor);
  QueryResult handle_query_1(const StreamCommandEntry& entry);
  QueryResult handle_query_2(const StreamCommandEntry& entry);
  QueryResult handle_query_3(const StreamCommandEntry& entry);
  QueryResult handle_query_4(const StreamCommandEntry& entry);
  QueryResult handle_query_5(const StreamCommandEntry& entry);
  QueryResult handle_query_6(const StreamCommandEntry& entry);
  QueryResult handle_query_7(const StreamCommandEntry& entry);
  QueryResult handle_query_8(const StreamCommandEntry& entry);
  QueryResult handle_query_9(const StreamCommandEntry& entry);
  QueryResult handle_query_10(const StreamCommandEntry& entry);
  QueryResult handle_query_11(const StreamCommandEntry& entry);
  QueryResult handle_query_12(const StreamCommandEntry& entry);
  QueryResult handle_query_13(const StreamCommandEntry& entry);
  QueryResult handle_query_14(const StreamCommandEntry& entry);
  QueryResult handle_query_15(const StreamCommandEntry& entry);
  QueryResult handle_query_16(const StreamCommandEntry& entry);
  QueryResult handle_query_17(const StreamCommandEntry& entry);
  QueryResult handle_query_18(const StreamCommandEntry& entry);
  QueryResult handle_query_19(const StreamCommandEntry& entry);
  QueryResult handle_query_20(const StreamCommandEntry& entry);
  std::vector<QueryResult> execute_batch(const std::vector<StreamCommandEntry>& commands);
  QueryResult execute(const StreamCommandEntry& entry);
 private:
  StreamProcessor* processor_;
};

}  // namespace rifttrace
