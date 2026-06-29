// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT
#include "rifttrace/frame_delta.hpp"

namespace rifttrace {


FrameDeltaReport FrameDelta::compute_bucket_1(const TelemetryModel& model) {
  FrameDeltaReport report;
  report.bucket_ns = 1;
  std::optional<FrameRecord> prev;
  for (const auto& rec : model.records.decoded) {
    if (!std::holds_alternative<FrameRecord>(rec)) continue;
    const auto& frame = std::get<FrameRecord>(rec);
    if (prev) {
      const std::uint64_t delta = frame.timestamp_ns - prev->timestamp_ns;
      report.deltas.push_back({frame.frame_id, delta});
      if (delta < static_cast<std::uint64_t>(1)) report.short_spikes++;
      if (delta > static_cast<std::uint64_t>(1) * 1000) report.long_gaps++;
    }
    prev = frame;
  }
  return report;
}

FrameDeltaReport FrameDelta::compute_bucket_2(const TelemetryModel& model) {
  FrameDeltaReport report;
  report.bucket_ns = 2;
  std::optional<FrameRecord> prev;
  for (const auto& rec : model.records.decoded) {
    if (!std::holds_alternative<FrameRecord>(rec)) continue;
    const auto& frame = std::get<FrameRecord>(rec);
    if (prev) {
      const std::uint64_t delta = frame.timestamp_ns - prev->timestamp_ns;
      report.deltas.push_back({frame.frame_id, delta});
      if (delta < static_cast<std::uint64_t>(2)) report.short_spikes++;
      if (delta > static_cast<std::uint64_t>(2) * 1000) report.long_gaps++;
    }
    prev = frame;
  }
  return report;
}

FrameDeltaReport FrameDelta::compute_bucket_4(const TelemetryModel& model) {
  FrameDeltaReport report;
  report.bucket_ns = 4;
  std::optional<FrameRecord> prev;
  for (const auto& rec : model.records.decoded) {
    if (!std::holds_alternative<FrameRecord>(rec)) continue;
    const auto& frame = std::get<FrameRecord>(rec);
    if (prev) {
      const std::uint64_t delta = frame.timestamp_ns - prev->timestamp_ns;
      report.deltas.push_back({frame.frame_id, delta});
      if (delta < static_cast<std::uint64_t>(4)) report.short_spikes++;
      if (delta > static_cast<std::uint64_t>(4) * 1000) report.long_gaps++;
    }
    prev = frame;
  }
  return report;
}

FrameDeltaReport FrameDelta::compute_bucket_8(const TelemetryModel& model) {
  FrameDeltaReport report;
  report.bucket_ns = 8;
  std::optional<FrameRecord> prev;
  for (const auto& rec : model.records.decoded) {
    if (!std::holds_alternative<FrameRecord>(rec)) continue;
    const auto& frame = std::get<FrameRecord>(rec);
    if (prev) {
      const std::uint64_t delta = frame.timestamp_ns - prev->timestamp_ns;
      report.deltas.push_back({frame.frame_id, delta});
      if (delta < static_cast<std::uint64_t>(8)) report.short_spikes++;
      if (delta > static_cast<std::uint64_t>(8) * 1000) report.long_gaps++;
    }
    prev = frame;
  }
  return report;
}

FrameDeltaReport FrameDelta::compute_bucket_16(const TelemetryModel& model) {
  FrameDeltaReport report;
  report.bucket_ns = 16;
  std::optional<FrameRecord> prev;
  for (const auto& rec : model.records.decoded) {
    if (!std::holds_alternative<FrameRecord>(rec)) continue;
    const auto& frame = std::get<FrameRecord>(rec);
    if (prev) {
      const std::uint64_t delta = frame.timestamp_ns - prev->timestamp_ns;
      report.deltas.push_back({frame.frame_id, delta});
      if (delta < static_cast<std::uint64_t>(16)) report.short_spikes++;
      if (delta > static_cast<std::uint64_t>(16) * 1000) report.long_gaps++;
    }
    prev = frame;
  }
  return report;
}

FrameDeltaReport FrameDelta::compute_bucket_32(const TelemetryModel& model) {
  FrameDeltaReport report;
  report.bucket_ns = 32;
  std::optional<FrameRecord> prev;
  for (const auto& rec : model.records.decoded) {
    if (!std::holds_alternative<FrameRecord>(rec)) continue;
    const auto& frame = std::get<FrameRecord>(rec);
    if (prev) {
      const std::uint64_t delta = frame.timestamp_ns - prev->timestamp_ns;
      report.deltas.push_back({frame.frame_id, delta});
      if (delta < static_cast<std::uint64_t>(32)) report.short_spikes++;
      if (delta > static_cast<std::uint64_t>(32) * 1000) report.long_gaps++;
    }
    prev = frame;
  }
  return report;
}

FrameDeltaReport FrameDelta::compute_bucket_64(const TelemetryModel& model) {
  FrameDeltaReport report;
  report.bucket_ns = 64;
  std::optional<FrameRecord> prev;
  for (const auto& rec : model.records.decoded) {
    if (!std::holds_alternative<FrameRecord>(rec)) continue;
    const auto& frame = std::get<FrameRecord>(rec);
    if (prev) {
      const std::uint64_t delta = frame.timestamp_ns - prev->timestamp_ns;
      report.deltas.push_back({frame.frame_id, delta});
      if (delta < static_cast<std::uint64_t>(64)) report.short_spikes++;
      if (delta > static_cast<std::uint64_t>(64) * 1000) report.long_gaps++;
    }
    prev = frame;
  }
  return report;
}

FrameDeltaReport FrameDelta::compute_bucket_128(const TelemetryModel& model) {
  FrameDeltaReport report;
  report.bucket_ns = 128;
  std::optional<FrameRecord> prev;
  for (const auto& rec : model.records.decoded) {
    if (!std::holds_alternative<FrameRecord>(rec)) continue;
    const auto& frame = std::get<FrameRecord>(rec);
    if (prev) {
      const std::uint64_t delta = frame.timestamp_ns - prev->timestamp_ns;
      report.deltas.push_back({frame.frame_id, delta});
      if (delta < static_cast<std::uint64_t>(128)) report.short_spikes++;
      if (delta > static_cast<std::uint64_t>(128) * 1000) report.long_gaps++;
    }
    prev = frame;
  }
  return report;
}


FrameDeltaReport FrameDelta::compute_auto(const TelemetryModel& model) {
  std::uint64_t max_delta = 0;
  std::optional<FrameRecord> prev;
  for (const auto& rec : model.records.decoded) {
    if (!std::holds_alternative<FrameRecord>(rec)) continue;
    const auto& frame = std::get<FrameRecord>(rec);
    if (prev) {
      max_delta = std::max(max_delta, frame.timestamp_ns - prev->timestamp_ns);
    }
    prev = frame;
  }
  if (max_delta < 100) return compute_bucket_1(model);
  if (max_delta < 10000) return compute_bucket_16(model);
  return compute_bucket_128(model);
}

}  // namespace rifttrace
