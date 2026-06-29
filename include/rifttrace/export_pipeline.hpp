// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT
#pragma once

#include <cstdint>
#include <string>
#include <vector>

#include "rifttrace/model.hpp"

namespace rifttrace {

struct ExportStageResult {
  std::uint32_t stage = 0;
  std::uint32_t object_count = 0;
  std::uint32_t frame_count = 0;
  std::uint32_t event_count = 0;
  bool valid = false;
  std::string digest;
  std::string json;
};

class ExportPipeline {
 public:
  ExportStageResult stage_1(TelemetryModel& model);
  ExportStageResult stage_2(TelemetryModel& model);
  ExportStageResult stage_3(TelemetryModel& model);
  ExportStageResult stage_4(TelemetryModel& model);
  ExportStageResult stage_5(TelemetryModel& model);
  ExportStageResult stage_6(TelemetryModel& model);
  ExportStageResult stage_7(TelemetryModel& model);
  ExportStageResult stage_8(TelemetryModel& model);
  ExportStageResult stage_9(TelemetryModel& model);
  ExportStageResult stage_10(TelemetryModel& model);
  ExportStageResult stage_11(TelemetryModel& model);
  ExportStageResult stage_12(TelemetryModel& model);
  ExportStageResult stage_13(TelemetryModel& model);
  ExportStageResult stage_14(TelemetryModel& model);
  ExportStageResult stage_15(TelemetryModel& model);
  ExportStageResult stage_16(TelemetryModel& model);
  ExportStageResult stage_17(TelemetryModel& model);
  ExportStageResult stage_18(TelemetryModel& model);
  ExportStageResult stage_19(TelemetryModel& model);
  ExportStageResult stage_20(TelemetryModel& model);
  static std::vector<ExportStageResult> run_all(TelemetryModel& model);
};

}  // namespace rifttrace
