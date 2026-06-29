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

struct CorrelationResult {
  std::uint32_t rule = 0;
  std::uint32_t score = 0;
  bool passed = false;
};

class CorrelationEngine {
 public:
  static CorrelationResult eval_1(const TelemetryModel& model, const Resolver& resolver);
  static CorrelationResult eval_2(const TelemetryModel& model, const Resolver& resolver);
  static CorrelationResult eval_3(const TelemetryModel& model, const Resolver& resolver);
  static CorrelationResult eval_4(const TelemetryModel& model, const Resolver& resolver);
  static CorrelationResult eval_5(const TelemetryModel& model, const Resolver& resolver);
  static CorrelationResult eval_6(const TelemetryModel& model, const Resolver& resolver);
  static CorrelationResult eval_7(const TelemetryModel& model, const Resolver& resolver);
  static CorrelationResult eval_8(const TelemetryModel& model, const Resolver& resolver);
  static CorrelationResult eval_9(const TelemetryModel& model, const Resolver& resolver);
  static CorrelationResult eval_10(const TelemetryModel& model, const Resolver& resolver);
  static CorrelationResult eval_11(const TelemetryModel& model, const Resolver& resolver);
  static CorrelationResult eval_12(const TelemetryModel& model, const Resolver& resolver);
  static CorrelationResult eval_13(const TelemetryModel& model, const Resolver& resolver);
  static CorrelationResult eval_14(const TelemetryModel& model, const Resolver& resolver);
  static CorrelationResult eval_15(const TelemetryModel& model, const Resolver& resolver);
  static CorrelationResult eval_16(const TelemetryModel& model, const Resolver& resolver);
  static CorrelationResult eval_17(const TelemetryModel& model, const Resolver& resolver);
  static CorrelationResult eval_18(const TelemetryModel& model, const Resolver& resolver);
  static CorrelationResult eval_19(const TelemetryModel& model, const Resolver& resolver);
  static CorrelationResult eval_20(const TelemetryModel& model, const Resolver& resolver);
  static CorrelationResult eval_21(const TelemetryModel& model, const Resolver& resolver);
  static CorrelationResult eval_22(const TelemetryModel& model, const Resolver& resolver);
  static CorrelationResult eval_23(const TelemetryModel& model, const Resolver& resolver);
  static CorrelationResult eval_24(const TelemetryModel& model, const Resolver& resolver);
  static CorrelationResult eval_25(const TelemetryModel& model, const Resolver& resolver);
  static CorrelationResult eval_26(const TelemetryModel& model, const Resolver& resolver);
  static CorrelationResult eval_27(const TelemetryModel& model, const Resolver& resolver);
  static CorrelationResult eval_28(const TelemetryModel& model, const Resolver& resolver);
  static CorrelationResult eval_29(const TelemetryModel& model, const Resolver& resolver);
  static CorrelationResult eval_30(const TelemetryModel& model, const Resolver& resolver);
  static CorrelationResult eval_31(const TelemetryModel& model, const Resolver& resolver);
  static CorrelationResult eval_32(const TelemetryModel& model, const Resolver& resolver);
  static CorrelationResult eval_33(const TelemetryModel& model, const Resolver& resolver);
  static CorrelationResult eval_34(const TelemetryModel& model, const Resolver& resolver);
  static CorrelationResult eval_35(const TelemetryModel& model, const Resolver& resolver);
  static std::vector<CorrelationResult> run_all(const TelemetryModel& model, const Resolver& resolver);
};

}  // namespace rifttrace
