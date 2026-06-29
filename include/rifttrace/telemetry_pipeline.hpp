// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT
#pragma once

#include <cstddef>
#include <cstdint>
#include <string>
#include <vector>

namespace rifttrace {

struct PipelineStepResult {
  std::uint32_t step = 0;
  bool ok = false;
  std::string error;
  std::uint32_t records = 0;
  std::uint32_t rule_failures = 0;
  bool graph_valid = false;
  std::uint32_t index_tokens = 0;
  std::string digest;
};

class TelemetryPipeline {
 public:
  static PipelineStepResult step_1(const std::uint8_t* data, std::size_t size);
  static PipelineStepResult step_2(const std::uint8_t* data, std::size_t size);
  static PipelineStepResult step_3(const std::uint8_t* data, std::size_t size);
  static PipelineStepResult step_4(const std::uint8_t* data, std::size_t size);
  static PipelineStepResult step_5(const std::uint8_t* data, std::size_t size);
  static PipelineStepResult step_6(const std::uint8_t* data, std::size_t size);
  static PipelineStepResult step_7(const std::uint8_t* data, std::size_t size);
  static PipelineStepResult step_8(const std::uint8_t* data, std::size_t size);
  static PipelineStepResult step_9(const std::uint8_t* data, std::size_t size);
  static PipelineStepResult step_10(const std::uint8_t* data, std::size_t size);
  static PipelineStepResult step_11(const std::uint8_t* data, std::size_t size);
  static PipelineStepResult step_12(const std::uint8_t* data, std::size_t size);
  static PipelineStepResult step_13(const std::uint8_t* data, std::size_t size);
  static PipelineStepResult step_14(const std::uint8_t* data, std::size_t size);
  static PipelineStepResult step_15(const std::uint8_t* data, std::size_t size);
  static std::vector<PipelineStepResult> run(const std::uint8_t* data, std::size_t size);
};

}  // namespace rifttrace
