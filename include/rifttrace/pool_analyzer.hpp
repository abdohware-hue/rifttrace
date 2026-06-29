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

struct PoolAnalyzeResult {
  std::uint32_t rule = 0;
  std::uint32_t score = 0;
  bool passed = false;
};

class PoolAnalyzeEngine {
 public:
  static PoolAnalyzeResult eval_1(const TelemetryModel& model, const Resolver& resolver);
  static PoolAnalyzeResult eval_2(const TelemetryModel& model, const Resolver& resolver);
  static PoolAnalyzeResult eval_3(const TelemetryModel& model, const Resolver& resolver);
  static PoolAnalyzeResult eval_4(const TelemetryModel& model, const Resolver& resolver);
  static PoolAnalyzeResult eval_5(const TelemetryModel& model, const Resolver& resolver);
  static PoolAnalyzeResult eval_6(const TelemetryModel& model, const Resolver& resolver);
  static PoolAnalyzeResult eval_7(const TelemetryModel& model, const Resolver& resolver);
  static PoolAnalyzeResult eval_8(const TelemetryModel& model, const Resolver& resolver);
  static PoolAnalyzeResult eval_9(const TelemetryModel& model, const Resolver& resolver);
  static PoolAnalyzeResult eval_10(const TelemetryModel& model, const Resolver& resolver);
  static PoolAnalyzeResult eval_11(const TelemetryModel& model, const Resolver& resolver);
  static PoolAnalyzeResult eval_12(const TelemetryModel& model, const Resolver& resolver);
  static PoolAnalyzeResult eval_13(const TelemetryModel& model, const Resolver& resolver);
  static PoolAnalyzeResult eval_14(const TelemetryModel& model, const Resolver& resolver);
  static PoolAnalyzeResult eval_15(const TelemetryModel& model, const Resolver& resolver);
  static PoolAnalyzeResult eval_16(const TelemetryModel& model, const Resolver& resolver);
  static PoolAnalyzeResult eval_17(const TelemetryModel& model, const Resolver& resolver);
  static PoolAnalyzeResult eval_18(const TelemetryModel& model, const Resolver& resolver);
  static PoolAnalyzeResult eval_19(const TelemetryModel& model, const Resolver& resolver);
  static PoolAnalyzeResult eval_20(const TelemetryModel& model, const Resolver& resolver);
  static PoolAnalyzeResult eval_21(const TelemetryModel& model, const Resolver& resolver);
  static PoolAnalyzeResult eval_22(const TelemetryModel& model, const Resolver& resolver);
  static PoolAnalyzeResult eval_23(const TelemetryModel& model, const Resolver& resolver);
  static PoolAnalyzeResult eval_24(const TelemetryModel& model, const Resolver& resolver);
  static PoolAnalyzeResult eval_25(const TelemetryModel& model, const Resolver& resolver);
  static PoolAnalyzeResult eval_26(const TelemetryModel& model, const Resolver& resolver);
  static PoolAnalyzeResult eval_27(const TelemetryModel& model, const Resolver& resolver);
  static PoolAnalyzeResult eval_28(const TelemetryModel& model, const Resolver& resolver);
  static PoolAnalyzeResult eval_29(const TelemetryModel& model, const Resolver& resolver);
  static PoolAnalyzeResult eval_30(const TelemetryModel& model, const Resolver& resolver);
  static std::vector<PoolAnalyzeResult> run_all(const TelemetryModel& model, const Resolver& resolver);
};

}  // namespace rifttrace
