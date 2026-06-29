// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT

#include "rifttrace/string_table.hpp"

#include <algorithm>
#include <unordered_map>

#include "rifttrace/byte_reader.hpp"

namespace rifttrace {

StringTable StringTable::parse(const std::uint8_t* data, std::size_t size) {
  StringTable table;
  if (size == 0) {
    return table;
  }
  ByteReader reader(data, size);
  const auto count = reader.read_u32_le();
  const auto data_offset = reader.read_u32_le();
  std::vector<std::uint32_t> offsets;
  offsets.reserve(count);
  for (std::uint32_t i = 0; i < count; ++i) {
    offsets.push_back(reader.read_u32_le());
  }
  table.strings_.reserve(count);
  for (std::uint32_t i = 0; i < count; ++i) {
    const auto absolute = data_offset + offsets[i];
    if (absolute >= size) {
      throw ParseError(ErrorCode::kInvalidReference, "string offset out of bounds");
    }
    ByteReader str_reader(data, size);
    str_reader.seek(absolute);
    table.strings_.push_back(str_reader.read_cstring());
  }
  return table;
}

std::string_view StringTable::get(std::uint32_t index) const {
  if (index >= strings_.size()) {
    throw ParseError(ErrorCode::kInvalidReference, "string index out of range");
  }
  return strings_[index];
}

std::uint32_t StringTable::intern(std::string_view value) {
  for (std::size_t i = 0; i < strings_.size(); ++i) {
    if (strings_[i] == value) {
      return static_cast<std::uint32_t>(i);
    }
  }
  strings_.emplace_back(value);
  return static_cast<std::uint32_t>(strings_.size() - 1);
}

void StringTable::compact() {
  if (strings_.empty()) {
    return;
  }
  std::vector<std::string> unique;
  unique.reserve(strings_.size());
  remap_.assign(strings_.size(), 0);
  std::unordered_map<std::string, std::uint32_t> lookup;
  for (std::size_t i = 0; i < strings_.size(); ++i) {
    const auto it = lookup.find(strings_[i]);
    if (it == lookup.end()) {
      const auto next = static_cast<std::uint32_t>(unique.size());
      lookup[strings_[i]] = next;
      remap_[i] = next;
      unique.push_back(strings_[i]);
    } else {
      remap_[i] = it->second;
    }
  }
  strings_.swap(unique);
}

std::vector<std::uint8_t> StringTable::serialize() const {
  std::vector<std::uint8_t> blob;
  for (const auto& str : strings_) {
    blob.insert(blob.end(), str.begin(), str.end());
    blob.push_back(0);
  }
  std::vector<std::uint8_t> out;
  auto count = write_u32_le(static_cast<std::uint32_t>(strings_.size()));
  const auto data_offset = 8u + static_cast<std::uint32_t>(strings_.size()) * 4u;
  auto off = write_u32_le(data_offset);
  out.insert(out.end(), count.begin(), count.end());
  out.insert(out.end(), off.begin(), off.end());
  std::uint32_t cursor = 0;
  for (const auto& str : strings_) {
    auto rel = write_u32_le(cursor);
    out.insert(out.end(), rel.begin(), rel.end());
    cursor += static_cast<std::uint32_t>(str.size() + 1);
  }
  out.insert(out.end(), blob.begin(), blob.end());
  return out;
}

}  // namespace rifttrace
