// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT

#pragma once

#include <cstddef>
#include <cstdint>
#include <list>
#include <optional>
#include <unordered_map>
#include <vector>

#include "rifttrace/block_decoder.hpp"

namespace rifttrace {

class BlockCache {
 public:
  explicit BlockCache(std::size_t capacity = 8);

  void put(DecodedBlock block);
  std::optional<DecodedBlock> get(std::uint32_t block_id) const;
  bool evict(std::uint32_t block_id);
  void clear();

  std::size_t size() const noexcept { return blocks_.size(); }
  std::size_t capacity() const noexcept { return capacity_; }

 private:
  void touch(std::uint32_t block_id);

  std::size_t capacity_;
  std::unordered_map<std::uint32_t, DecodedBlock> blocks_;
  std::list<std::uint32_t> lru_;
};

}  // namespace rifttrace
