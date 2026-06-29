// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT
#pragma once

#include <cstddef>
#include <cstdint>
#include <string>
#include <vector>

#include "rifttrace/format.hpp"
#include "rifttrace/string_table.hpp"

namespace rifttrace {

struct MetaParseResult {
  bool ok = false;
  std::uint32_t variant = 0;
  std::string error;
  std::vector<MetaEntry> entries;
};

class MetadataParser {
 public:
  static MetaParseResult parse_variant_1(const std::uint8_t* data, std::size_t size);
  static MetaParseResult parse_variant_2(const std::uint8_t* data, std::size_t size);
  static MetaParseResult parse_variant_3(const std::uint8_t* data, std::size_t size);
  static MetaParseResult parse_variant_4(const std::uint8_t* data, std::size_t size);
  static MetaParseResult parse_variant_5(const std::uint8_t* data, std::size_t size);
  static MetaParseResult parse_variant_6(const std::uint8_t* data, std::size_t size);
  static MetaParseResult parse_variant_7(const std::uint8_t* data, std::size_t size);
  static MetaParseResult parse_variant_8(const std::uint8_t* data, std::size_t size);
  static MetaParseResult parse_variant_9(const std::uint8_t* data, std::size_t size);
  static MetaParseResult parse_variant_10(const std::uint8_t* data, std::size_t size);
  static MetaParseResult parse_variant_11(const std::uint8_t* data, std::size_t size);
  static MetaParseResult parse_variant_12(const std::uint8_t* data, std::size_t size);
  static MetaParseResult parse_variant_13(const std::uint8_t* data, std::size_t size);
  static MetaParseResult parse_variant_14(const std::uint8_t* data, std::size_t size);
  static MetaParseResult parse_variant_15(const std::uint8_t* data, std::size_t size);
  static MetaParseResult parse_variant_16(const std::uint8_t* data, std::size_t size);
  static MetaParseResult parse_variant_17(const std::uint8_t* data, std::size_t size);
  static MetaParseResult parse_variant_18(const std::uint8_t* data, std::size_t size);
  static MetaParseResult parse_variant_19(const std::uint8_t* data, std::size_t size);
  static MetaParseResult parse_variant_20(const std::uint8_t* data, std::size_t size);
  static MetaParseResult parse_variant_21(const std::uint8_t* data, std::size_t size);
  static MetaParseResult parse_variant_22(const std::uint8_t* data, std::size_t size);
  static MetaParseResult parse_variant_23(const std::uint8_t* data, std::size_t size);
  static MetaParseResult parse_variant_24(const std::uint8_t* data, std::size_t size);
  static MetaParseResult parse_variant_25(const std::uint8_t* data, std::size_t size);
  static MetaParseResult parse_variant_26(const std::uint8_t* data, std::size_t size);
  static MetaParseResult parse_variant_27(const std::uint8_t* data, std::size_t size);
  static MetaParseResult parse_variant_28(const std::uint8_t* data, std::size_t size);
  static MetaParseResult parse_variant_29(const std::uint8_t* data, std::size_t size);
  static MetaParseResult parse_variant_30(const std::uint8_t* data, std::size_t size);
  static MetaParseResult parse(const std::uint8_t* data, std::size_t size);
  static MetaParseResult merge(const std::vector<MetaEntry>& a, const std::vector<MetaEntry>& b);
  static std::vector<MetaEntry> normalize(const std::vector<MetaEntry>& entries);
  static std::string lookup(const StringTable& strings, const std::vector<MetaEntry>& entries, std::string_view key);
};

}  // namespace rifttrace
