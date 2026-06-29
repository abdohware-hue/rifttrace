// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT

#include "rifttrace/timeline.hpp"

#include <algorithm>

namespace rifttrace {

Timeline::Timeline(const TelemetryModel& model) {
  for (const auto& record : model.records.decoded) {
    if (std::holds_alternative<FrameRecord>(record)) {
      const auto& frame = std::get<FrameRecord>(record);
      TimelineEntry entry;
      entry.frame_id = frame.frame_id;
      entry.timestamp_ns = frame.timestamp_ns;
      entries_.push_back(entry);
    }
  }
  std::sort(entries_.begin(), entries_.end(),
            [](const TimelineEntry& a, const TimelineEntry& b) {
              return a.timestamp_ns < b.timestamp_ns;
            });

  for (const auto& record : model.records.decoded) {
    if (std::holds_alternative<EventRecord>(record)) {
      const auto& event = std::get<EventRecord>(record);
      for (auto& entry : entries_) {
        if (entry.frame_id == event.frame_id) {
          ++entry.event_count;
        }
      }
    }
  }

  if (!entries_.empty()) {
    duration_ns_ = entries_.back().timestamp_ns - entries_.front().timestamp_ns;
  }
}

}  // namespace rifttrace
