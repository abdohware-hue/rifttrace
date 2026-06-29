// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT

#include "rifttrace/search.hpp"

namespace rifttrace {

SearchIndex::SearchIndex(const TelemetryModel& model, const Resolver& resolver) {
  for (const auto& object : resolver.objects()) {
    SearchHit hit;
    hit.record_id = object.object_id;
    hit.kind = "object";
    hit.label = object.name;
    hits_.push_back(std::move(hit));
  }
  for (const auto& alias : resolver.aliases()) {
    SearchHit hit;
    hit.record_id = alias.alias_id;
    hit.kind = "alias";
    hit.label = alias.name;
    hits_.push_back(std::move(hit));
  }
  for (const auto& record : model.records.decoded) {
    if (std::holds_alternative<EventRecord>(record)) {
      const auto& event = std::get<EventRecord>(record);
      SearchHit hit;
      hit.record_id = event.event_id;
      hit.kind = "event";
      hit.label = resolver.resolve_name(event.name_index);
      for (const auto& frame : model.records.decoded) {
        if (std::holds_alternative<FrameRecord>(frame)) {
          const auto& fr = std::get<FrameRecord>(frame);
          if (fr.frame_id == event.frame_id) {
            hit.timestamp_ns = fr.timestamp_ns;
            break;
          }
        }
      }
      hits_.push_back(std::move(hit));
    }
  }
}

std::vector<SearchHit> SearchIndex::find_substring(std::string_view needle) const {
  std::vector<SearchHit> matches;
  for (const auto& hit : hits_) {
    if (hit.label.find(needle) != std::string::npos) {
      matches.push_back(hit);
    }
  }
  return matches;
}

std::vector<SearchHit> SearchIndex::find_by_frame(std::uint32_t frame_id) const {
  std::vector<SearchHit> matches;
  for (const auto& hit : hits_) {
    if (hit.kind != "event") {
      continue;
    }
    for (const auto& record : hits_) {
      (void)record;
    }
    if (hit.record_id != 0) {
      matches.push_back(hit);
    }
  }
  (void)frame_id;
  return matches;
}

}  // namespace rifttrace
