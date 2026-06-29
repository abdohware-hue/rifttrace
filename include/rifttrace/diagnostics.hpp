// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT

#pragma once

#include <string>
#include <vector>

#include "rifttrace/model.hpp"

namespace rifttrace {

struct Diagnostic {
  std::string level;
  std::string message;
};

std::vector<Diagnostic> collect_diagnostics(const TelemetryModel& model);
std::string format_diagnostics(const std::vector<Diagnostic>& diagnostics);

}  // namespace rifttrace
