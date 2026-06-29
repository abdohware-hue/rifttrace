// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT

#pragma once

#include <cstdint>
#include <vector>

#include "rifttrace/model.hpp"

namespace rifttrace {

struct TimelineEntry {
  std::uint32_t frame_id = 0;
  std::uint64_t timestamp_ns = 0;
  std::uint32_t event_count = 0;
};

class Timeline {
 public:
  explicit Timeline(const TelemetryModel& model);

  const std::vector<TimelineEntry>& entries() const noexcept { return entries_; }
  std::uint64_t duration_ns() const noexcept { return duration_ns_; }

 private:
  std::vector<TimelineEntry> entries_;
  std::uint64_t duration_ns_ = 0;
};

}  // namespace rifttrace
