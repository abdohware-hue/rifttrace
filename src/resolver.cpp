// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT

#include "rifttrace/resolver.hpp"

namespace rifttrace {

Resolver::Resolver(TelemetryModel* model) : model_(model) { rebuild(); }

void Resolver::rebuild() {
  aliases_.clear();
  objects_.clear();
  object_map_.clear();
  alias_map_.clear();

  for (const auto& record : model_->records.decoded) {
    if (std::holds_alternative<ObjectRecord>(record)) {
      const auto& object = std::get<ObjectRecord>(record);
      ResolvedObject resolved;
      resolved.object_id = object.object_id;
      resolved.name = std::string(model_->strings.get(object.name_index));
      resolved.symbol = std::string(model_->symbols.resolve(object.symbol_index));
      resolved.pool_slot = object.pool_slot;
      object_map_[object.object_id] = objects_.size();
      objects_.push_back(std::move(resolved));
    } else if (std::holds_alternative<AliasRecord>(record)) {
      const auto& alias = std::get<AliasRecord>(record);
      ResolvedAlias resolved;
      resolved.alias_id = alias.alias_id;
      resolved.target_id = alias.target_id;
      resolved.name = std::string(model_->strings.get(alias.name_index));
      alias_map_[alias.alias_id] = aliases_.size();
      aliases_.push_back(std::move(resolved));
    }
  }
}

std::string Resolver::resolve_name(std::uint32_t string_index) const {
  return std::string(model_->strings.get(string_index));
}

std::optional<ResolvedObject> Resolver::resolve_object(std::uint32_t object_id) const {
  const auto it = object_map_.find(object_id);
  if (it == object_map_.end()) {
    return std::nullopt;
  }
  return objects_[it->second];
}

std::optional<ResolvedAlias> Resolver::resolve_alias(std::uint32_t alias_id) const {
  const auto it = alias_map_.find(alias_id);
  if (it == alias_map_.end()) {
    return std::nullopt;
  }
  return aliases_[it->second];
}

std::optional<ResolvedFrame> Resolver::resolve_frame(std::uint32_t frame_id) const {
  for (const auto& record : model_->records.decoded) {
    if (std::holds_alternative<FrameRecord>(record)) {
      const auto& frame = std::get<FrameRecord>(record);
      if (frame.frame_id == frame_id) {
        ResolvedFrame resolved;
        resolved.frame_id = frame.frame_id;
        resolved.timestamp_ns = frame.timestamp_ns;
        resolved.parent_frame = frame.parent_frame;
        return resolved;
      }
    }
  }
  return std::nullopt;
}

}  // namespace rifttrace
