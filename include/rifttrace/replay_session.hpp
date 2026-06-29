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

struct ReplaySessionResult {
  std::uint32_t rule = 0;
  std::uint32_t score = 0;
  bool passed = false;
};

class ReplaySessionEngine {
 public:
  static ReplaySessionResult eval_1(const TelemetryModel& model, const Resolver& resolver);
  static ReplaySessionResult eval_2(const TelemetryModel& model, const Resolver& resolver);
  static ReplaySessionResult eval_3(const TelemetryModel& model, const Resolver& resolver);
  static ReplaySessionResult eval_4(const TelemetryModel& model, const Resolver& resolver);
  static ReplaySessionResult eval_5(const TelemetryModel& model, const Resolver& resolver);
  static ReplaySessionResult eval_6(const TelemetryModel& model, const Resolver& resolver);
  static ReplaySessionResult eval_7(const TelemetryModel& model, const Resolver& resolver);
  static ReplaySessionResult eval_8(const TelemetryModel& model, const Resolver& resolver);
  static ReplaySessionResult eval_9(const TelemetryModel& model, const Resolver& resolver);
  static ReplaySessionResult eval_10(const TelemetryModel& model, const Resolver& resolver);
  static ReplaySessionResult eval_11(const TelemetryModel& model, const Resolver& resolver);
  static ReplaySessionResult eval_12(const TelemetryModel& model, const Resolver& resolver);
  static ReplaySessionResult eval_13(const TelemetryModel& model, const Resolver& resolver);
  static ReplaySessionResult eval_14(const TelemetryModel& model, const Resolver& resolver);
  static ReplaySessionResult eval_15(const TelemetryModel& model, const Resolver& resolver);
  static ReplaySessionResult eval_16(const TelemetryModel& model, const Resolver& resolver);
  static ReplaySessionResult eval_17(const TelemetryModel& model, const Resolver& resolver);
  static ReplaySessionResult eval_18(const TelemetryModel& model, const Resolver& resolver);
  static ReplaySessionResult eval_19(const TelemetryModel& model, const Resolver& resolver);
  static ReplaySessionResult eval_20(const TelemetryModel& model, const Resolver& resolver);
  static ReplaySessionResult eval_21(const TelemetryModel& model, const Resolver& resolver);
  static ReplaySessionResult eval_22(const TelemetryModel& model, const Resolver& resolver);
  static ReplaySessionResult eval_23(const TelemetryModel& model, const Resolver& resolver);
  static ReplaySessionResult eval_24(const TelemetryModel& model, const Resolver& resolver);
  static ReplaySessionResult eval_25(const TelemetryModel& model, const Resolver& resolver);
  static ReplaySessionResult eval_26(const TelemetryModel& model, const Resolver& resolver);
  static ReplaySessionResult eval_27(const TelemetryModel& model, const Resolver& resolver);
  static ReplaySessionResult eval_28(const TelemetryModel& model, const Resolver& resolver);
  static ReplaySessionResult eval_29(const TelemetryModel& model, const Resolver& resolver);
  static ReplaySessionResult eval_30(const TelemetryModel& model, const Resolver& resolver);
  static ReplaySessionResult eval_31(const TelemetryModel& model, const Resolver& resolver);
  static ReplaySessionResult eval_32(const TelemetryModel& model, const Resolver& resolver);
  static ReplaySessionResult eval_33(const TelemetryModel& model, const Resolver& resolver);
  static ReplaySessionResult eval_34(const TelemetryModel& model, const Resolver& resolver);
  static ReplaySessionResult eval_35(const TelemetryModel& model, const Resolver& resolver);
  static std::vector<ReplaySessionResult> run_all(const TelemetryModel& model, const Resolver& resolver);
};

}  // namespace rifttrace
