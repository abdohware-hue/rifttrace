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

struct QueryAstResult {
  std::uint32_t rule = 0;
  std::uint32_t score = 0;
  bool passed = false;
};

class QueryAstEngine {
 public:
  static QueryAstResult eval_1(const TelemetryModel& model, const Resolver& resolver);
  static QueryAstResult eval_2(const TelemetryModel& model, const Resolver& resolver);
  static QueryAstResult eval_3(const TelemetryModel& model, const Resolver& resolver);
  static QueryAstResult eval_4(const TelemetryModel& model, const Resolver& resolver);
  static QueryAstResult eval_5(const TelemetryModel& model, const Resolver& resolver);
  static QueryAstResult eval_6(const TelemetryModel& model, const Resolver& resolver);
  static QueryAstResult eval_7(const TelemetryModel& model, const Resolver& resolver);
  static QueryAstResult eval_8(const TelemetryModel& model, const Resolver& resolver);
  static QueryAstResult eval_9(const TelemetryModel& model, const Resolver& resolver);
  static QueryAstResult eval_10(const TelemetryModel& model, const Resolver& resolver);
  static QueryAstResult eval_11(const TelemetryModel& model, const Resolver& resolver);
  static QueryAstResult eval_12(const TelemetryModel& model, const Resolver& resolver);
  static QueryAstResult eval_13(const TelemetryModel& model, const Resolver& resolver);
  static QueryAstResult eval_14(const TelemetryModel& model, const Resolver& resolver);
  static QueryAstResult eval_15(const TelemetryModel& model, const Resolver& resolver);
  static QueryAstResult eval_16(const TelemetryModel& model, const Resolver& resolver);
  static QueryAstResult eval_17(const TelemetryModel& model, const Resolver& resolver);
  static QueryAstResult eval_18(const TelemetryModel& model, const Resolver& resolver);
  static QueryAstResult eval_19(const TelemetryModel& model, const Resolver& resolver);
  static QueryAstResult eval_20(const TelemetryModel& model, const Resolver& resolver);
  static QueryAstResult eval_21(const TelemetryModel& model, const Resolver& resolver);
  static QueryAstResult eval_22(const TelemetryModel& model, const Resolver& resolver);
  static QueryAstResult eval_23(const TelemetryModel& model, const Resolver& resolver);
  static QueryAstResult eval_24(const TelemetryModel& model, const Resolver& resolver);
  static QueryAstResult eval_25(const TelemetryModel& model, const Resolver& resolver);
  static QueryAstResult eval_26(const TelemetryModel& model, const Resolver& resolver);
  static QueryAstResult eval_27(const TelemetryModel& model, const Resolver& resolver);
  static QueryAstResult eval_28(const TelemetryModel& model, const Resolver& resolver);
  static QueryAstResult eval_29(const TelemetryModel& model, const Resolver& resolver);
  static QueryAstResult eval_30(const TelemetryModel& model, const Resolver& resolver);
  static std::vector<QueryAstResult> run_all(const TelemetryModel& model, const Resolver& resolver);
};

}  // namespace rifttrace
