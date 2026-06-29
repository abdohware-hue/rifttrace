// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT

#include "rifttrace/diagnostics.hpp"

#include <sstream>

#include "rifttrace/section_table.hpp"

namespace rifttrace {

std::vector<Diagnostic> collect_diagnostics(const TelemetryModel& model) {
  std::vector<Diagnostic> diagnostics;
  SectionTable table = SectionTable::parse(model.archive);

  if (model.strings.empty()) {
    diagnostics.push_back({"warn", "string table is empty"});
  }
  if (model.records.decoded.empty()) {
    diagnostics.push_back({"warn", "no decoded records"});
  }
  if (!table.find(kSectionIdx0)) {
    diagnostics.push_back({"info", "missing IDX0 section"});
  }
  if (model.blocks.empty()) {
    diagnostics.push_back({"info", "no compressed blocks"});
  }
  if (!model.finalized) {
    diagnostics.push_back({"info", "model not finalized"});
  }
  return diagnostics;
}

std::string format_diagnostics(const std::vector<Diagnostic>& diagnostics) {
  std::ostringstream out;
  for (const auto& item : diagnostics) {
    out << item.level << ": " << item.message << '\n';
  }
  return out.str();
}

}  // namespace rifttrace
