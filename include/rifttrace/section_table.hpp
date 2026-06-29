// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT

#pragma once

#include <cstddef>
#include <cstdint>
#include <optional>
#include <vector>

#include "rifttrace/format.hpp"

namespace rifttrace {

class SectionTable {
 public:
  static SectionTable parse(const Archive& archive);

  const std::vector<SectionEntry>& entries() const noexcept { return entries_; }

  std::optional<SectionEntry> find(std::uint32_t type) const;
  std::vector<SectionEntry> find_all(std::uint32_t type) const;

  std::string_view payload(const Archive& archive, const SectionEntry& entry) const;
  const std::uint8_t* payload_data(const Archive& archive,
                                   const SectionEntry& entry) const;
  std::size_t payload_size(const SectionEntry& entry) const noexcept;

 private:
  std::vector<SectionEntry> entries_;
};

}  // namespace rifttrace
