// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT
#pragma once

#include <cstdint>
#include <vector>

#include "rifttrace/format.hpp"
#include "rifttrace/string_table.hpp"

namespace rifttrace {

class ArchiveWriter {
 public:
  ArchiveWriter();
  void set_version(std::uint16_t version);
  void add_section(std::uint32_t type, const std::vector<std::uint8_t>& payload);
  void set_strings(const StringTable& table);
  void set_data(const std::vector<std::uint8_t>& data);
  void set_index(const std::vector<std::uint8_t>& index);
  void set_metadata(const std::vector<std::uint8_t>& meta);
  void set_blocks(const std::vector<std::uint8_t>& blocks);
  std::vector<std::uint8_t> build() const;
  Archive build_archive() const;
 private:
  ArchiveHeader header_;
  std::vector<std::pair<std::uint32_t, std::vector<std::uint8_t>>> sections_;
};

}  // namespace rifttrace
