// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT
#pragma once

#include <cstdint>
#include <vector>

#include "rifttrace/export_summary.hpp"
#include "rifttrace/model.hpp"

namespace rifttrace {

struct Checkpoint {
  std::uint32_t id = 0;
  std::uint32_t record_count = 0;
  std::uint32_t string_count = 0;
  std::uint32_t block_count = 0;
  bool finalized = false;
  std::uint64_t content_hash = 0;
  std::vector<std::uint32_t> snapshot;
  std::vector<std::uint32_t> metadata_keys;
};

class CheckpointReplay {
 public:
  static Checkpoint capture_state_1(const TelemetryModel& model);
  static bool restore_state_1(TelemetryModel* model, const Checkpoint& cp);
  static Checkpoint capture_state_2(const TelemetryModel& model);
  static bool restore_state_2(TelemetryModel* model, const Checkpoint& cp);
  static Checkpoint capture_state_3(const TelemetryModel& model);
  static bool restore_state_3(TelemetryModel* model, const Checkpoint& cp);
  static Checkpoint capture_state_4(const TelemetryModel& model);
  static bool restore_state_4(TelemetryModel* model, const Checkpoint& cp);
  static Checkpoint capture_state_5(const TelemetryModel& model);
  static bool restore_state_5(TelemetryModel* model, const Checkpoint& cp);
  static Checkpoint capture_state_6(const TelemetryModel& model);
  static bool restore_state_6(TelemetryModel* model, const Checkpoint& cp);
  static Checkpoint capture_state_7(const TelemetryModel& model);
  static bool restore_state_7(TelemetryModel* model, const Checkpoint& cp);
  static Checkpoint capture_state_8(const TelemetryModel& model);
  static bool restore_state_8(TelemetryModel* model, const Checkpoint& cp);
  static Checkpoint capture_state_9(const TelemetryModel& model);
  static bool restore_state_9(TelemetryModel* model, const Checkpoint& cp);
  static Checkpoint capture_state_10(const TelemetryModel& model);
  static bool restore_state_10(TelemetryModel* model, const Checkpoint& cp);
  static Checkpoint capture_state_11(const TelemetryModel& model);
  static bool restore_state_11(TelemetryModel* model, const Checkpoint& cp);
  static Checkpoint capture_state_12(const TelemetryModel& model);
  static bool restore_state_12(TelemetryModel* model, const Checkpoint& cp);
  static Checkpoint capture_state_13(const TelemetryModel& model);
  static bool restore_state_13(TelemetryModel* model, const Checkpoint& cp);
  static Checkpoint capture_state_14(const TelemetryModel& model);
  static bool restore_state_14(TelemetryModel* model, const Checkpoint& cp);
  static Checkpoint capture_state_15(const TelemetryModel& model);
  static bool restore_state_15(TelemetryModel* model, const Checkpoint& cp);
  static Checkpoint capture_state_16(const TelemetryModel& model);
  static bool restore_state_16(TelemetryModel* model, const Checkpoint& cp);
  static Checkpoint capture_state_17(const TelemetryModel& model);
  static bool restore_state_17(TelemetryModel* model, const Checkpoint& cp);
  static Checkpoint capture_state_18(const TelemetryModel& model);
  static bool restore_state_18(TelemetryModel* model, const Checkpoint& cp);
  static Checkpoint capture_state_19(const TelemetryModel& model);
  static bool restore_state_19(TelemetryModel* model, const Checkpoint& cp);
  static Checkpoint capture_state_20(const TelemetryModel& model);
  static bool restore_state_20(TelemetryModel* model, const Checkpoint& cp);
  static Checkpoint capture_state_21(const TelemetryModel& model);
  static bool restore_state_21(TelemetryModel* model, const Checkpoint& cp);
  static Checkpoint capture_state_22(const TelemetryModel& model);
  static bool restore_state_22(TelemetryModel* model, const Checkpoint& cp);
  static Checkpoint capture_state_23(const TelemetryModel& model);
  static bool restore_state_23(TelemetryModel* model, const Checkpoint& cp);
  static Checkpoint capture_state_24(const TelemetryModel& model);
  static bool restore_state_24(TelemetryModel* model, const Checkpoint& cp);
  static Checkpoint capture_state_25(const TelemetryModel& model);
  static bool restore_state_25(TelemetryModel* model, const Checkpoint& cp);
  static Checkpoint capture(const TelemetryModel& model);
  static bool restore(TelemetryModel* model, const Checkpoint& cp);
  static std::vector<Checkpoint> replay_log(const TelemetryModel& model, std::size_t steps);
};

}  // namespace rifttrace
