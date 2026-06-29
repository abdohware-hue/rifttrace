// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT
#pragma once

#include <string>

#include "rifttrace/export_summary.hpp"
#include "rifttrace/model.hpp"
#include "rifttrace/resolver.hpp"

namespace rifttrace {

class JsonReportRenderer {
 public:
  static std::string section_1(const TelemetryModel& model, const Resolver& resolver, const ExportSummary& summary);
  static std::string section_2(const TelemetryModel& model, const Resolver& resolver, const ExportSummary& summary);
  static std::string section_3(const TelemetryModel& model, const Resolver& resolver, const ExportSummary& summary);
  static std::string section_4(const TelemetryModel& model, const Resolver& resolver, const ExportSummary& summary);
  static std::string section_5(const TelemetryModel& model, const Resolver& resolver, const ExportSummary& summary);
  static std::string section_6(const TelemetryModel& model, const Resolver& resolver, const ExportSummary& summary);
  static std::string section_7(const TelemetryModel& model, const Resolver& resolver, const ExportSummary& summary);
  static std::string section_8(const TelemetryModel& model, const Resolver& resolver, const ExportSummary& summary);
  static std::string section_9(const TelemetryModel& model, const Resolver& resolver, const ExportSummary& summary);
  static std::string section_10(const TelemetryModel& model, const Resolver& resolver, const ExportSummary& summary);
  static std::string section_11(const TelemetryModel& model, const Resolver& resolver, const ExportSummary& summary);
  static std::string section_12(const TelemetryModel& model, const Resolver& resolver, const ExportSummary& summary);
  static std::string section_13(const TelemetryModel& model, const Resolver& resolver, const ExportSummary& summary);
  static std::string section_14(const TelemetryModel& model, const Resolver& resolver, const ExportSummary& summary);
  static std::string section_15(const TelemetryModel& model, const Resolver& resolver, const ExportSummary& summary);
  static std::string section_16(const TelemetryModel& model, const Resolver& resolver, const ExportSummary& summary);
  static std::string section_17(const TelemetryModel& model, const Resolver& resolver, const ExportSummary& summary);
  static std::string section_18(const TelemetryModel& model, const Resolver& resolver, const ExportSummary& summary);
  static std::string section_19(const TelemetryModel& model, const Resolver& resolver, const ExportSummary& summary);
  static std::string section_20(const TelemetryModel& model, const Resolver& resolver, const ExportSummary& summary);
  static std::string section_21(const TelemetryModel& model, const Resolver& resolver, const ExportSummary& summary);
  static std::string section_22(const TelemetryModel& model, const Resolver& resolver, const ExportSummary& summary);
  static std::string section_23(const TelemetryModel& model, const Resolver& resolver, const ExportSummary& summary);
  static std::string section_24(const TelemetryModel& model, const Resolver& resolver, const ExportSummary& summary);
  static std::string section_25(const TelemetryModel& model, const Resolver& resolver, const ExportSummary& summary);
  static std::string section_26(const TelemetryModel& model, const Resolver& resolver, const ExportSummary& summary);
  static std::string section_27(const TelemetryModel& model, const Resolver& resolver, const ExportSummary& summary);
  static std::string section_28(const TelemetryModel& model, const Resolver& resolver, const ExportSummary& summary);
  static std::string section_29(const TelemetryModel& model, const Resolver& resolver, const ExportSummary& summary);
  static std::string section_30(const TelemetryModel& model, const Resolver& resolver, const ExportSummary& summary);
  static std::string render(const TelemetryModel& model, const Resolver& resolver, const ExportSummary& summary);
  static std::string render_compact(const ExportSummary& summary);
};

}  // namespace rifttrace
