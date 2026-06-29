// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT

#pragma once

#include <cstddef>
#include <cstdint>
#include <string>
#include <vector>

#include "rifttrace/model.hpp"
#include "rifttrace/resolver.hpp"

namespace rifttrace {

struct StreamCommandEntry {
  StreamCommand command = StreamCommand::kAppendRecord;
  std::vector<std::uint8_t> payload;
};

class StreamProcessor {
 public:
  explicit StreamProcessor(TelemetryModel* model);

  void apply(const StreamCommandEntry& entry);
  void apply_batch(const std::vector<StreamCommandEntry>& commands);
  void finalize();

  bool is_finalized() const noexcept { return finalized_; }

 private:
  void append_record(const std::uint8_t* data, std::size_t size);
  void rebuild_strings();
  void evict_block(const std::uint8_t* data, std::size_t size);
  void compact_pool();

  TelemetryModel* model_;
  Resolver resolver_;
  bool finalized_ = false;
};

std::vector<StreamCommandEntry> parse_stream_commands(const std::uint8_t* data,
                                                      std::size_t size);

}  // namespace rifttrace
