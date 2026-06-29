// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT
#pragma once

#include <cstdint>
#include <optional>
#include <vector>

#include "rifttrace/format.hpp"
#include "rifttrace/model.hpp"

namespace rifttrace {

struct FrameDeltaEntry {
  std::uint32_t frame_id = 0;
  std::uint64_t delta_ns = 0;
};

struct FrameDeltaReport {
  std::uint64_t bucket_ns = 0;
  std::vector<FrameDeltaEntry> deltas;
  std::uint32_t short_spikes = 0;
  std::uint32_t long_gaps = 0;
};

class FrameDelta {
 public:
  static FrameDeltaReport compute_bucket_1(const TelemetryModel& model);
  static FrameDeltaReport compute_bucket_2(const TelemetryModel& model);
  static FrameDeltaReport compute_bucket_4(const TelemetryModel& model);
  static FrameDeltaReport compute_bucket_8(const TelemetryModel& model);
  static FrameDeltaReport compute_bucket_16(const TelemetryModel& model);
  static FrameDeltaReport compute_bucket_32(const TelemetryModel& model);
  static FrameDeltaReport compute_bucket_64(const TelemetryModel& model);
  static FrameDeltaReport compute_bucket_128(const TelemetryModel& model);
  static FrameDeltaReport compute_auto(const TelemetryModel& model);
};

}  // namespace rifttrace
