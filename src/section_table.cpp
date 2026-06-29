// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT

#include "rifttrace/section_table.hpp"

#include "rifttrace/byte_reader.hpp"

namespace rifttrace {

SectionTable SectionTable::parse(const Archive& archive) {
  SectionTable table;
  table.entries_ = archive.sections;
  return table;
}

std::optional<SectionEntry> SectionTable::find(std::uint32_t type) const {
  for (const auto& entry : entries_) {
    if (entry.type == type) {
      return entry;
    }
  }
  return std::nullopt;
}

std::vector<SectionEntry> SectionTable::find_all(std::uint32_t type) const {
  std::vector<SectionEntry> matches;
  for (const auto& entry : entries_) {
    if (entry.type == type) {
      matches.push_back(entry);
    }
  }
  return matches;
}

std::string_view SectionTable::payload(const Archive& archive,
                                       const SectionEntry& entry) const {
  return std::string_view(reinterpret_cast<const char*>(payload_data(archive, entry)),
                          payload_size(entry));
}

const std::uint8_t* SectionTable::payload_data(const Archive& archive,
                                               const SectionEntry& entry) const {
  return archive.bytes.data() + entry.offset;
}

std::size_t SectionTable::payload_size(const SectionEntry& entry) const noexcept {
  return entry.size;
}

}  // namespace rifttrace
