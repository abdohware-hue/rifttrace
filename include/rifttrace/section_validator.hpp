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

struct SectionValidateResult {
  std::uint32_t rule = 0;
  std::uint32_t score = 0;
  bool passed = false;
};

class SectionValidateEngine {
 public:
  static SectionValidateResult eval_1(const TelemetryModel& model, const Resolver& resolver);
  static SectionValidateResult eval_2(const TelemetryModel& model, const Resolver& resolver);
  static SectionValidateResult eval_3(const TelemetryModel& model, const Resolver& resolver);
  static SectionValidateResult eval_4(const TelemetryModel& model, const Resolver& resolver);
  static SectionValidateResult eval_5(const TelemetryModel& model, const Resolver& resolver);
  static SectionValidateResult eval_6(const TelemetryModel& model, const Resolver& resolver);
  static SectionValidateResult eval_7(const TelemetryModel& model, const Resolver& resolver);
  static SectionValidateResult eval_8(const TelemetryModel& model, const Resolver& resolver);
  static SectionValidateResult eval_9(const TelemetryModel& model, const Resolver& resolver);
  static SectionValidateResult eval_10(const TelemetryModel& model, const Resolver& resolver);
  static SectionValidateResult eval_11(const TelemetryModel& model, const Resolver& resolver);
  static SectionValidateResult eval_12(const TelemetryModel& model, const Resolver& resolver);
  static SectionValidateResult eval_13(const TelemetryModel& model, const Resolver& resolver);
  static SectionValidateResult eval_14(const TelemetryModel& model, const Resolver& resolver);
  static SectionValidateResult eval_15(const TelemetryModel& model, const Resolver& resolver);
  static SectionValidateResult eval_16(const TelemetryModel& model, const Resolver& resolver);
  static SectionValidateResult eval_17(const TelemetryModel& model, const Resolver& resolver);
  static SectionValidateResult eval_18(const TelemetryModel& model, const Resolver& resolver);
  static SectionValidateResult eval_19(const TelemetryModel& model, const Resolver& resolver);
  static SectionValidateResult eval_20(const TelemetryModel& model, const Resolver& resolver);
  static SectionValidateResult eval_21(const TelemetryModel& model, const Resolver& resolver);
  static SectionValidateResult eval_22(const TelemetryModel& model, const Resolver& resolver);
  static SectionValidateResult eval_23(const TelemetryModel& model, const Resolver& resolver);
  static SectionValidateResult eval_24(const TelemetryModel& model, const Resolver& resolver);
  static SectionValidateResult eval_25(const TelemetryModel& model, const Resolver& resolver);
  static SectionValidateResult eval_26(const TelemetryModel& model, const Resolver& resolver);
  static SectionValidateResult eval_27(const TelemetryModel& model, const Resolver& resolver);
  static SectionValidateResult eval_28(const TelemetryModel& model, const Resolver& resolver);
  static SectionValidateResult eval_29(const TelemetryModel& model, const Resolver& resolver);
  static SectionValidateResult eval_30(const TelemetryModel& model, const Resolver& resolver);
  static std::vector<SectionValidateResult> run_all(const TelemetryModel& model, const Resolver& resolver);
};

}  // namespace rifttrace
