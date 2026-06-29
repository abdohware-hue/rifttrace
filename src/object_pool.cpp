// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT

#include "rifttrace/object_pool.hpp"

#include <algorithm>

namespace rifttrace {

std::uint32_t ObjectPool::allocate(const ObjectRecord& object) {
  const auto it = id_to_slot_.find(object.object_id);
  if (it != id_to_slot_.end()) {
    objects_[it->second] = object;
    return static_cast<std::uint32_t>(it->second);
  }
  const auto slot = objects_.size();
  id_to_slot_[object.object_id] = slot;
  objects_.push_back(object);
  objects_.back().pool_slot = static_cast<std::uint32_t>(slot);
  return static_cast<std::uint32_t>(slot);
}

std::optional<ObjectRecord> ObjectPool::get(std::uint32_t slot) const {
  if (slot >= objects_.size()) {
    return std::nullopt;
  }
  return objects_[slot];
}

void ObjectPool::compact() {
  std::vector<ObjectRecord> compacted;
  compacted.reserve(objects_.size());
  id_to_slot_.clear();
  for (auto object : objects_) {
    if (object.object_id == 0) {
      continue;
    }
    const auto slot = compacted.size();
    object.pool_slot = static_cast<std::uint32_t>(slot);
    id_to_slot_[object.object_id] = slot;
    compacted.push_back(object);
  }
  objects_.swap(compacted);
}

}  // namespace rifttrace
