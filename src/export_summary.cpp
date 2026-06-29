// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT

#include "rifttrace/export_summary.hpp"

#include <sstream>

#include "rifttrace/checksum.hpp"
#include "rifttrace/record.hpp"

namespace rifttrace {

std::uint64_t hash_names(const Resolver& resolver) {
  std::uint64_t hash = kFnvOffsetBasis;
  for (const auto& object : resolver.objects()) {
    hash = fnv1a64_str(object.name, hash);
    hash = fnv1a64_str(object.symbol, hash);
  }
  for (const auto& alias : resolver.aliases()) {
    hash = fnv1a64_str(alias.name, hash);
  }
  return hash;
}

std::uint64_t hash_content(const TelemetryModel& model) {
  std::uint64_t hash = kFnvOffsetBasis;
  for (const auto& record : model.records.decoded) {
    const auto id = record_id(record);
    hash = fnv1a64(reinterpret_cast<const std::uint8_t*>(&id), sizeof(id), hash);
  }
  hash = fnv1a64(model.archive.bytes.data(), model.archive.bytes.size(), hash);
  return hash;
}

ExportSummary export_summary(const TelemetryModel& model, const Resolver& resolver,
                             const Timeline& timeline) {
  ExportSummary summary;
  for (const auto& record : model.records.decoded) {
    if (std::holds_alternative<ObjectRecord>(record)) {
      ++summary.object_count;
    } else if (std::holds_alternative<FrameRecord>(record)) {
      ++summary.frame_count;
    } else if (std::holds_alternative<EventRecord>(record)) {
      ++summary.event_count;
    } else if (std::holds_alternative<AliasRecord>(record)) {
      ++summary.alias_count;
    }
  }
  summary.duration_ns = timeline.duration_ns();
  summary.name_hash = hash_names(resolver);
  summary.content_hash = hash_content(model);

  std::ostringstream digest;
  digest << std::hex << summary.name_hash << ":" << summary.content_hash;
  summary.digest = digest.str();
  return summary;
}

}  // namespace rifttrace
