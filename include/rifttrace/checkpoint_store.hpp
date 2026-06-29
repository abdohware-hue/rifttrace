// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT
#pragma once

#include <cstdint>
#include <string>
#include <vector>

#include "rifttrace/format.hpp"
#include "rifttrace/model.hpp"
#include "rifttrace/resolver.hpp"

namespace rifttrace {

struct CheckpointStoreResult {
  std::uint32_t rule = 0;
  std::uint32_t score = 0;
  bool passed = false;
};

class CheckpointStoreEngine {
 public:
  static CheckpointStoreResult eval_1(const TelemetryModel& model, const Resolver& resolver);
  static CheckpointStoreResult eval_2(const TelemetryModel& model, const Resolver& resolver);
  static CheckpointStoreResult eval_3(const TelemetryModel& model, const Resolver& resolver);
  static CheckpointStoreResult eval_4(const TelemetryModel& model, const Resolver& resolver);
  static CheckpointStoreResult eval_5(const TelemetryModel& model, const Resolver& resolver);
  static CheckpointStoreResult eval_6(const TelemetryModel& model, const Resolver& resolver);
  static CheckpointStoreResult eval_7(const TelemetryModel& model, const Resolver& resolver);
  static CheckpointStoreResult eval_8(const TelemetryModel& model, const Resolver& resolver);
  static CheckpointStoreResult eval_9(const TelemetryModel& model, const Resolver& resolver);
  static CheckpointStoreResult eval_10(const TelemetryModel& model, const Resolver& resolver);
  static CheckpointStoreResult eval_11(const TelemetryModel& model, const Resolver& resolver);
  static CheckpointStoreResult eval_12(const TelemetryModel& model, const Resolver& resolver);
  static CheckpointStoreResult eval_13(const TelemetryModel& model, const Resolver& resolver);
  static CheckpointStoreResult eval_14(const TelemetryModel& model, const Resolver& resolver);
  static CheckpointStoreResult eval_15(const TelemetryModel& model, const Resolver& resolver);
  static CheckpointStoreResult eval_16(const TelemetryModel& model, const Resolver& resolver);
  static CheckpointStoreResult eval_17(const TelemetryModel& model, const Resolver& resolver);
  static CheckpointStoreResult eval_18(const TelemetryModel& model, const Resolver& resolver);
  static CheckpointStoreResult eval_19(const TelemetryModel& model, const Resolver& resolver);
  static CheckpointStoreResult eval_20(const TelemetryModel& model, const Resolver& resolver);
  static CheckpointStoreResult eval_21(const TelemetryModel& model, const Resolver& resolver);
  static CheckpointStoreResult eval_22(const TelemetryModel& model, const Resolver& resolver);
  static CheckpointStoreResult eval_23(const TelemetryModel& model, const Resolver& resolver);
  static CheckpointStoreResult eval_24(const TelemetryModel& model, const Resolver& resolver);
  static CheckpointStoreResult eval_25(const TelemetryModel& model, const Resolver& resolver);
  static CheckpointStoreResult eval_26(const TelemetryModel& model, const Resolver& resolver);
  static CheckpointStoreResult eval_27(const TelemetryModel& model, const Resolver& resolver);
  static CheckpointStoreResult eval_28(const TelemetryModel& model, const Resolver& resolver);
  static CheckpointStoreResult eval_29(const TelemetryModel& model, const Resolver& resolver);
  static CheckpointStoreResult eval_30(const TelemetryModel& model, const Resolver& resolver);
  static CheckpointStoreResult eval_31(const TelemetryModel& model, const Resolver& resolver);
  static CheckpointStoreResult eval_32(const TelemetryModel& model, const Resolver& resolver);
  static CheckpointStoreResult eval_33(const TelemetryModel& model, const Resolver& resolver);
  static CheckpointStoreResult eval_34(const TelemetryModel& model, const Resolver& resolver);
  static CheckpointStoreResult eval_35(const TelemetryModel& model, const Resolver& resolver);
  static std::vector<CheckpointStoreResult> run_all(const TelemetryModel& model, const Resolver& resolver);
};

}  // namespace rifttrace
