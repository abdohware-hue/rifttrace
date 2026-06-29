// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT

#pragma once

#include <cstddef>
#include <cstdint>
#include <optional>
#include <unordered_map>
#include <vector>

#include "rifttrace/format.hpp"

namespace rifttrace {

class FrameIndex {
 public:
  static FrameIndex parse(const std::uint8_t* data, std::size_t size);

  void insert(IndexEntry entry);
  std::optional<IndexEntry> find_by_record(std::uint32_t record_id) const;
  std::optional<IndexEntry> find_by_alias(std::uint32_t alias_id) const;

  const std::vector<IndexEntry>& entries() const noexcept { return entries_; }

 private:
  std::vector<IndexEntry> entries_;
  std::unordered_map<std::uint32_t, std::size_t> by_record_;
  std::unordered_map<std::uint32_t, std::size_t> by_alias_;
};

}  // namespace rifttrace
