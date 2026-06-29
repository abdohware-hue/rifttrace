// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT

#include "rifttrace/frame_index.hpp"

#include "rifttrace/byte_reader.hpp"

namespace rifttrace {

FrameIndex FrameIndex::parse(const std::uint8_t* data, std::size_t size) {
  FrameIndex index;
  if (size == 0) {
    return index;
  }
  ByteReader reader(data, size);
  const auto count = reader.read_u32_le();
  for (std::uint32_t i = 0; i < count; ++i) {
    IndexEntry entry;
    entry.record_id = reader.read_u32_le();
    entry.data_offset = reader.read_u32_le();
    entry.alias_id = reader.read_u32_le();
    index.insert(entry);
  }
  return index;
}

void FrameIndex::insert(IndexEntry entry) {
  const auto slot = entries_.size();
  by_record_[entry.record_id] = slot;
  if (entry.alias_id != 0) {
    by_alias_[entry.alias_id] = slot;
  }
  entries_.push_back(entry);
}

std::optional<IndexEntry> FrameIndex::find_by_record(std::uint32_t record_id) const {
  const auto it = by_record_.find(record_id);
  if (it == by_record_.end()) {
    return std::nullopt;
  }
  return entries_[it->second];
}

std::optional<IndexEntry> FrameIndex::find_by_alias(std::uint32_t alias_id) const {
  const auto it = by_alias_.find(alias_id);
  if (it == by_alias_.end()) {
    return std::nullopt;
  }
  return entries_[it->second];
}

}  // namespace rifttrace
