// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT

#pragma once

#include <cstdint>
#include <optional>
#include <unordered_map>
#include <vector>

#include "rifttrace/format.hpp"

namespace rifttrace {

class ObjectPool {
 public:
  std::uint32_t allocate(const ObjectRecord& object);
  std::optional<ObjectRecord> get(std::uint32_t slot) const;
  void compact();

  std::size_t size() const noexcept { return objects_.size(); }
  const std::vector<ObjectRecord>& objects() const noexcept { return objects_; }

 private:
  std::vector<ObjectRecord> objects_;
  std::unordered_map<std::uint32_t, std::size_t> id_to_slot_;
};

}  // namespace rifttrace
