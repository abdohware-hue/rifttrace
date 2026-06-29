// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT

#include "rifttrace/block_cache.hpp"

namespace rifttrace {

BlockCache::BlockCache(std::size_t capacity) : capacity_(capacity == 0 ? 1 : capacity) {}

void BlockCache::put(DecodedBlock block) {
  const auto id = block.block_id;
  if (blocks_.find(id) != blocks_.end()) {
    blocks_[id] = std::move(block);
    touch(id);
    return;
  }
  while (blocks_.size() >= capacity_ && !lru_.empty()) {
    const auto evict_id = lru_.back();
    lru_.pop_back();
    blocks_.erase(evict_id);
  }
  blocks_.emplace(id, std::move(block));
  lru_.push_front(id);
}

std::optional<DecodedBlock> BlockCache::get(std::uint32_t block_id) const {
  const auto it = blocks_.find(block_id);
  if (it == blocks_.end()) {
    return std::nullopt;
  }
  return it->second;
}

bool BlockCache::evict(std::uint32_t block_id) {
  const auto it = blocks_.find(block_id);
  if (it == blocks_.end()) {
    return false;
  }
  blocks_.erase(it);
  lru_.remove(block_id);
  return true;
}

void BlockCache::clear() {
  blocks_.clear();
  lru_.clear();
}

void BlockCache::touch(std::uint32_t block_id) {
  lru_.remove(block_id);
  lru_.push_front(block_id);
}

}  // namespace rifttrace
