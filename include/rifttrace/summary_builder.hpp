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

struct SummaryBuildResult {
  std::uint32_t rule = 0;
  std::uint32_t score = 0;
  bool passed = false;
};

class SummaryBuildEngine {
 public:
  static SummaryBuildResult eval_1(const TelemetryModel& model, const Resolver& resolver);
  static SummaryBuildResult eval_2(const TelemetryModel& model, const Resolver& resolver);
  static SummaryBuildResult eval_3(const TelemetryModel& model, const Resolver& resolver);
  static SummaryBuildResult eval_4(const TelemetryModel& model, const Resolver& resolver);
  static SummaryBuildResult eval_5(const TelemetryModel& model, const Resolver& resolver);
  static SummaryBuildResult eval_6(const TelemetryModel& model, const Resolver& resolver);
  static SummaryBuildResult eval_7(const TelemetryModel& model, const Resolver& resolver);
  static SummaryBuildResult eval_8(const TelemetryModel& model, const Resolver& resolver);
  static SummaryBuildResult eval_9(const TelemetryModel& model, const Resolver& resolver);
  static SummaryBuildResult eval_10(const TelemetryModel& model, const Resolver& resolver);
  static SummaryBuildResult eval_11(const TelemetryModel& model, const Resolver& resolver);
  static SummaryBuildResult eval_12(const TelemetryModel& model, const Resolver& resolver);
  static SummaryBuildResult eval_13(const TelemetryModel& model, const Resolver& resolver);
  static SummaryBuildResult eval_14(const TelemetryModel& model, const Resolver& resolver);
  static SummaryBuildResult eval_15(const TelemetryModel& model, const Resolver& resolver);
  static SummaryBuildResult eval_16(const TelemetryModel& model, const Resolver& resolver);
  static SummaryBuildResult eval_17(const TelemetryModel& model, const Resolver& resolver);
  static SummaryBuildResult eval_18(const TelemetryModel& model, const Resolver& resolver);
  static SummaryBuildResult eval_19(const TelemetryModel& model, const Resolver& resolver);
  static SummaryBuildResult eval_20(const TelemetryModel& model, const Resolver& resolver);
  static SummaryBuildResult eval_21(const TelemetryModel& model, const Resolver& resolver);
  static SummaryBuildResult eval_22(const TelemetryModel& model, const Resolver& resolver);
  static SummaryBuildResult eval_23(const TelemetryModel& model, const Resolver& resolver);
  static SummaryBuildResult eval_24(const TelemetryModel& model, const Resolver& resolver);
  static SummaryBuildResult eval_25(const TelemetryModel& model, const Resolver& resolver);
  static SummaryBuildResult eval_26(const TelemetryModel& model, const Resolver& resolver);
  static SummaryBuildResult eval_27(const TelemetryModel& model, const Resolver& resolver);
  static SummaryBuildResult eval_28(const TelemetryModel& model, const Resolver& resolver);
  static SummaryBuildResult eval_29(const TelemetryModel& model, const Resolver& resolver);
  static SummaryBuildResult eval_30(const TelemetryModel& model, const Resolver& resolver);
  static std::vector<SummaryBuildResult> run_all(const TelemetryModel& model, const Resolver& resolver);
};

}  // namespace rifttrace
