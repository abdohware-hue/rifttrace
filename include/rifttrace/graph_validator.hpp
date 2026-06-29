// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT
#pragma once

#include <cstdint>
#include <string>
#include <vector>

#include "rifttrace/model.hpp"
#include "rifttrace/resolver.hpp"

namespace rifttrace {

struct GraphIssue {
  std::uint32_t rule = 0;
  std::string severity;
  std::string message;
};

struct GraphReport {
  std::vector<GraphIssue> issues;
  bool valid = true;
};

class GraphValidator {
 public:
  static GraphIssue check_rule_1(const TelemetryModel& model, const Resolver& resolver);
  static GraphIssue check_rule_2(const TelemetryModel& model, const Resolver& resolver);
  static GraphIssue check_rule_3(const TelemetryModel& model, const Resolver& resolver);
  static GraphIssue check_rule_4(const TelemetryModel& model, const Resolver& resolver);
  static GraphIssue check_rule_5(const TelemetryModel& model, const Resolver& resolver);
  static GraphIssue check_rule_6(const TelemetryModel& model, const Resolver& resolver);
  static GraphIssue check_rule_7(const TelemetryModel& model, const Resolver& resolver);
  static GraphIssue check_rule_8(const TelemetryModel& model, const Resolver& resolver);
  static GraphIssue check_rule_9(const TelemetryModel& model, const Resolver& resolver);
  static GraphIssue check_rule_10(const TelemetryModel& model, const Resolver& resolver);
  static GraphIssue check_rule_11(const TelemetryModel& model, const Resolver& resolver);
  static GraphIssue check_rule_12(const TelemetryModel& model, const Resolver& resolver);
  static GraphIssue check_rule_13(const TelemetryModel& model, const Resolver& resolver);
  static GraphIssue check_rule_14(const TelemetryModel& model, const Resolver& resolver);
  static GraphIssue check_rule_15(const TelemetryModel& model, const Resolver& resolver);
  static GraphIssue check_rule_16(const TelemetryModel& model, const Resolver& resolver);
  static GraphIssue check_rule_17(const TelemetryModel& model, const Resolver& resolver);
  static GraphIssue check_rule_18(const TelemetryModel& model, const Resolver& resolver);
  static GraphIssue check_rule_19(const TelemetryModel& model, const Resolver& resolver);
  static GraphIssue check_rule_20(const TelemetryModel& model, const Resolver& resolver);
  static GraphIssue check_rule_21(const TelemetryModel& model, const Resolver& resolver);
  static GraphIssue check_rule_22(const TelemetryModel& model, const Resolver& resolver);
  static GraphIssue check_rule_23(const TelemetryModel& model, const Resolver& resolver);
  static GraphIssue check_rule_24(const TelemetryModel& model, const Resolver& resolver);
  static GraphIssue check_rule_25(const TelemetryModel& model, const Resolver& resolver);
  static GraphReport validate(const TelemetryModel& model, const Resolver& resolver);
  static bool has_cycles(const Resolver& resolver);
};

}  // namespace rifttrace
