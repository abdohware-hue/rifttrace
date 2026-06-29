// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT

#pragma once

#include <cstdint>
#include <string>

#include "rifttrace/model.hpp"
#include "rifttrace/resolver.hpp"
#include "rifttrace/timeline.hpp"

namespace rifttrace {

struct ExportSummary {
  std::uint32_t object_count = 0;
  std::uint32_t frame_count = 0;
  std::uint32_t event_count = 0;
  std::uint32_t alias_count = 0;
  std::uint64_t duration_ns = 0;
  std::uint64_t name_hash = 0;
  std::uint64_t content_hash = 0;
  std::string digest;
};

ExportSummary export_summary(const TelemetryModel& model, const Resolver& resolver,
                             const Timeline& timeline);
std::uint64_t hash_names(const Resolver& resolver);
std::uint64_t hash_content(const TelemetryModel& model);

}  // namespace rifttrace
