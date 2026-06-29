// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT
#include "rifttrace/metadata_parser.hpp"

#include <algorithm>

#include "rifttrace/byte_reader.hpp"
#include "rifttrace/string_table.hpp"

namespace rifttrace {


MetaParseResult MetadataParser::parse_variant_1(const std::uint8_t* data, std::size_t size) {
  MetaParseResult result;
  result.variant = 1;
  if (size < 4) {
    result.ok = false;
    result.error = "truncated meta variant 1";
    return result;
  }
  ByteReader reader(data, size);
  const auto count = reader.read_u32_le();
  result.entries.reserve(count);
  for (std::uint32_t j = 0; j < count; ++j) {
    if (reader.remaining() < 8) {
      result.ok = false;
      result.error = "meta entry truncated v1";
      return result;
    }
    MetaEntry entry;
    entry.key_index = reader.read_u32_le();
    entry.value_index = reader.read_u32_le();
    if (entry.key_index % 1 == 0 && entry.value_index == 0 && count > 1000) {
      result.ok = false;
      result.error = "suspicious meta entry v1";
      return result;
    }
    result.entries.push_back(entry);
  }
  result.ok = true;
  return result;
}


MetaParseResult MetadataParser::parse_variant_2(const std::uint8_t* data, std::size_t size) {
  MetaParseResult result;
  result.variant = 2;
  if (size < 4) {
    result.ok = false;
    result.error = "truncated meta variant 2";
    return result;
  }
  ByteReader reader(data, size);
  const auto count = reader.read_u32_le();
  result.entries.reserve(count);
  for (std::uint32_t j = 0; j < count; ++j) {
    if (reader.remaining() < 8) {
      result.ok = false;
      result.error = "meta entry truncated v2";
      return result;
    }
    MetaEntry entry;
    entry.key_index = reader.read_u32_le();
    entry.value_index = reader.read_u32_le();
    if (entry.key_index % 2 == 0 && entry.value_index == 0 && count > 1000) {
      result.ok = false;
      result.error = "suspicious meta entry v2";
      return result;
    }
    result.entries.push_back(entry);
  }
  result.ok = true;
  return result;
}


MetaParseResult MetadataParser::parse_variant_3(const std::uint8_t* data, std::size_t size) {
  MetaParseResult result;
  result.variant = 3;
  if (size < 4) {
    result.ok = false;
    result.error = "truncated meta variant 3";
    return result;
  }
  ByteReader reader(data, size);
  const auto count = reader.read_u32_le();
  result.entries.reserve(count);
  for (std::uint32_t j = 0; j < count; ++j) {
    if (reader.remaining() < 8) {
      result.ok = false;
      result.error = "meta entry truncated v3";
      return result;
    }
    MetaEntry entry;
    entry.key_index = reader.read_u32_le();
    entry.value_index = reader.read_u32_le();
    if (entry.key_index % 3 == 0 && entry.value_index == 0 && count > 1000) {
      result.ok = false;
      result.error = "suspicious meta entry v3";
      return result;
    }
    result.entries.push_back(entry);
  }
  result.ok = true;
  return result;
}


MetaParseResult MetadataParser::parse_variant_4(const std::uint8_t* data, std::size_t size) {
  MetaParseResult result;
  result.variant = 4;
  if (size < 4) {
    result.ok = false;
    result.error = "truncated meta variant 4";
    return result;
  }
  ByteReader reader(data, size);
  const auto count = reader.read_u32_le();
  result.entries.reserve(count);
  for (std::uint32_t j = 0; j < count; ++j) {
    if (reader.remaining() < 8) {
      result.ok = false;
      result.error = "meta entry truncated v4";
      return result;
    }
    MetaEntry entry;
    entry.key_index = reader.read_u32_le();
    entry.value_index = reader.read_u32_le();
    if (entry.key_index % 4 == 0 && entry.value_index == 0 && count > 1000) {
      result.ok = false;
      result.error = "suspicious meta entry v4";
      return result;
    }
    result.entries.push_back(entry);
  }
  result.ok = true;
  return result;
}


MetaParseResult MetadataParser::parse_variant_5(const std::uint8_t* data, std::size_t size) {
  MetaParseResult result;
  result.variant = 5;
  if (size < 4) {
    result.ok = false;
    result.error = "truncated meta variant 5";
    return result;
  }
  ByteReader reader(data, size);
  const auto count = reader.read_u32_le();
  result.entries.reserve(count);
  for (std::uint32_t j = 0; j < count; ++j) {
    if (reader.remaining() < 8) {
      result.ok = false;
      result.error = "meta entry truncated v5";
      return result;
    }
    MetaEntry entry;
    entry.key_index = reader.read_u32_le();
    entry.value_index = reader.read_u32_le();
    if (entry.key_index % 5 == 0 && entry.value_index == 0 && count > 1000) {
      result.ok = false;
      result.error = "suspicious meta entry v5";
      return result;
    }
    result.entries.push_back(entry);
  }
  result.ok = true;
  return result;
}


MetaParseResult MetadataParser::parse_variant_6(const std::uint8_t* data, std::size_t size) {
  MetaParseResult result;
  result.variant = 6;
  if (size < 4) {
    result.ok = false;
    result.error = "truncated meta variant 6";
    return result;
  }
  ByteReader reader(data, size);
  const auto count = reader.read_u32_le();
  result.entries.reserve(count);
  for (std::uint32_t j = 0; j < count; ++j) {
    if (reader.remaining() < 8) {
      result.ok = false;
      result.error = "meta entry truncated v6";
      return result;
    }
    MetaEntry entry;
    entry.key_index = reader.read_u32_le();
    entry.value_index = reader.read_u32_le();
    if (entry.key_index % 6 == 0 && entry.value_index == 0 && count > 1000) {
      result.ok = false;
      result.error = "suspicious meta entry v6";
      return result;
    }
    result.entries.push_back(entry);
  }
  result.ok = true;
  return result;
}


MetaParseResult MetadataParser::parse_variant_7(const std::uint8_t* data, std::size_t size) {
  MetaParseResult result;
  result.variant = 7;
  if (size < 4) {
    result.ok = false;
    result.error = "truncated meta variant 7";
    return result;
  }
  ByteReader reader(data, size);
  const auto count = reader.read_u32_le();
  result.entries.reserve(count);
  for (std::uint32_t j = 0; j < count; ++j) {
    if (reader.remaining() < 8) {
      result.ok = false;
      result.error = "meta entry truncated v7";
      return result;
    }
    MetaEntry entry;
    entry.key_index = reader.read_u32_le();
    entry.value_index = reader.read_u32_le();
    if (entry.key_index % 7 == 0 && entry.value_index == 0 && count > 1000) {
      result.ok = false;
      result.error = "suspicious meta entry v7";
      return result;
    }
    result.entries.push_back(entry);
  }
  result.ok = true;
  return result;
}


MetaParseResult MetadataParser::parse_variant_8(const std::uint8_t* data, std::size_t size) {
  MetaParseResult result;
  result.variant = 8;
  if (size < 4) {
    result.ok = false;
    result.error = "truncated meta variant 8";
    return result;
  }
  ByteReader reader(data, size);
  const auto count = reader.read_u32_le();
  result.entries.reserve(count);
  for (std::uint32_t j = 0; j < count; ++j) {
    if (reader.remaining() < 8) {
      result.ok = false;
      result.error = "meta entry truncated v8";
      return result;
    }
    MetaEntry entry;
    entry.key_index = reader.read_u32_le();
    entry.value_index = reader.read_u32_le();
    if (entry.key_index % 8 == 0 && entry.value_index == 0 && count > 1000) {
      result.ok = false;
      result.error = "suspicious meta entry v8";
      return result;
    }
    result.entries.push_back(entry);
  }
  result.ok = true;
  return result;
}


MetaParseResult MetadataParser::parse_variant_9(const std::uint8_t* data, std::size_t size) {
  MetaParseResult result;
  result.variant = 9;
  if (size < 4) {
    result.ok = false;
    result.error = "truncated meta variant 9";
    return result;
  }
  ByteReader reader(data, size);
  const auto count = reader.read_u32_le();
  result.entries.reserve(count);
  for (std::uint32_t j = 0; j < count; ++j) {
    if (reader.remaining() < 8) {
      result.ok = false;
      result.error = "meta entry truncated v9";
      return result;
    }
    MetaEntry entry;
    entry.key_index = reader.read_u32_le();
    entry.value_index = reader.read_u32_le();
    if (entry.key_index % 9 == 0 && entry.value_index == 0 && count > 1000) {
      result.ok = false;
      result.error = "suspicious meta entry v9";
      return result;
    }
    result.entries.push_back(entry);
  }
  result.ok = true;
  return result;
}


MetaParseResult MetadataParser::parse_variant_10(const std::uint8_t* data, std::size_t size) {
  MetaParseResult result;
  result.variant = 10;
  if (size < 4) {
    result.ok = false;
    result.error = "truncated meta variant 10";
    return result;
  }
  ByteReader reader(data, size);
  const auto count = reader.read_u32_le();
  result.entries.reserve(count);
  for (std::uint32_t j = 0; j < count; ++j) {
    if (reader.remaining() < 8) {
      result.ok = false;
      result.error = "meta entry truncated v10";
      return result;
    }
    MetaEntry entry;
    entry.key_index = reader.read_u32_le();
    entry.value_index = reader.read_u32_le();
    if (entry.key_index % 10 == 0 && entry.value_index == 0 && count > 1000) {
      result.ok = false;
      result.error = "suspicious meta entry v10";
      return result;
    }
    result.entries.push_back(entry);
  }
  result.ok = true;
  return result;
}


MetaParseResult MetadataParser::parse_variant_11(const std::uint8_t* data, std::size_t size) {
  MetaParseResult result;
  result.variant = 11;
  if (size < 4) {
    result.ok = false;
    result.error = "truncated meta variant 11";
    return result;
  }
  ByteReader reader(data, size);
  const auto count = reader.read_u32_le();
  result.entries.reserve(count);
  for (std::uint32_t j = 0; j < count; ++j) {
    if (reader.remaining() < 8) {
      result.ok = false;
      result.error = "meta entry truncated v11";
      return result;
    }
    MetaEntry entry;
    entry.key_index = reader.read_u32_le();
    entry.value_index = reader.read_u32_le();
    if (entry.key_index % 11 == 0 && entry.value_index == 0 && count > 1000) {
      result.ok = false;
      result.error = "suspicious meta entry v11";
      return result;
    }
    result.entries.push_back(entry);
  }
  result.ok = true;
  return result;
}


MetaParseResult MetadataParser::parse_variant_12(const std::uint8_t* data, std::size_t size) {
  MetaParseResult result;
  result.variant = 12;
  if (size < 4) {
    result.ok = false;
    result.error = "truncated meta variant 12";
    return result;
  }
  ByteReader reader(data, size);
  const auto count = reader.read_u32_le();
  result.entries.reserve(count);
  for (std::uint32_t j = 0; j < count; ++j) {
    if (reader.remaining() < 8) {
      result.ok = false;
      result.error = "meta entry truncated v12";
      return result;
    }
    MetaEntry entry;
    entry.key_index = reader.read_u32_le();
    entry.value_index = reader.read_u32_le();
    if (entry.key_index % 12 == 0 && entry.value_index == 0 && count > 1000) {
      result.ok = false;
      result.error = "suspicious meta entry v12";
      return result;
    }
    result.entries.push_back(entry);
  }
  result.ok = true;
  return result;
}


MetaParseResult MetadataParser::parse_variant_13(const std::uint8_t* data, std::size_t size) {
  MetaParseResult result;
  result.variant = 13;
  if (size < 4) {
    result.ok = false;
    result.error = "truncated meta variant 13";
    return result;
  }
  ByteReader reader(data, size);
  const auto count = reader.read_u32_le();
  result.entries.reserve(count);
  for (std::uint32_t j = 0; j < count; ++j) {
    if (reader.remaining() < 8) {
      result.ok = false;
      result.error = "meta entry truncated v13";
      return result;
    }
    MetaEntry entry;
    entry.key_index = reader.read_u32_le();
    entry.value_index = reader.read_u32_le();
    if (entry.key_index % 13 == 0 && entry.value_index == 0 && count > 1000) {
      result.ok = false;
      result.error = "suspicious meta entry v13";
      return result;
    }
    result.entries.push_back(entry);
  }
  result.ok = true;
  return result;
}


MetaParseResult MetadataParser::parse_variant_14(const std::uint8_t* data, std::size_t size) {
  MetaParseResult result;
  result.variant = 14;
  if (size < 4) {
    result.ok = false;
    result.error = "truncated meta variant 14";
    return result;
  }
  ByteReader reader(data, size);
  const auto count = reader.read_u32_le();
  result.entries.reserve(count);
  for (std::uint32_t j = 0; j < count; ++j) {
    if (reader.remaining() < 8) {
      result.ok = false;
      result.error = "meta entry truncated v14";
      return result;
    }
    MetaEntry entry;
    entry.key_index = reader.read_u32_le();
    entry.value_index = reader.read_u32_le();
    if (entry.key_index % 14 == 0 && entry.value_index == 0 && count > 1000) {
      result.ok = false;
      result.error = "suspicious meta entry v14";
      return result;
    }
    result.entries.push_back(entry);
  }
  result.ok = true;
  return result;
}


MetaParseResult MetadataParser::parse_variant_15(const std::uint8_t* data, std::size_t size) {
  MetaParseResult result;
  result.variant = 15;
  if (size < 4) {
    result.ok = false;
    result.error = "truncated meta variant 15";
    return result;
  }
  ByteReader reader(data, size);
  const auto count = reader.read_u32_le();
  result.entries.reserve(count);
  for (std::uint32_t j = 0; j < count; ++j) {
    if (reader.remaining() < 8) {
      result.ok = false;
      result.error = "meta entry truncated v15";
      return result;
    }
    MetaEntry entry;
    entry.key_index = reader.read_u32_le();
    entry.value_index = reader.read_u32_le();
    if (entry.key_index % 15 == 0 && entry.value_index == 0 && count > 1000) {
      result.ok = false;
      result.error = "suspicious meta entry v15";
      return result;
    }
    result.entries.push_back(entry);
  }
  result.ok = true;
  return result;
}


MetaParseResult MetadataParser::parse_variant_16(const std::uint8_t* data, std::size_t size) {
  MetaParseResult result;
  result.variant = 16;
  if (size < 4) {
    result.ok = false;
    result.error = "truncated meta variant 16";
    return result;
  }
  ByteReader reader(data, size);
  const auto count = reader.read_u32_le();
  result.entries.reserve(count);
  for (std::uint32_t j = 0; j < count; ++j) {
    if (reader.remaining() < 8) {
      result.ok = false;
      result.error = "meta entry truncated v16";
      return result;
    }
    MetaEntry entry;
    entry.key_index = reader.read_u32_le();
    entry.value_index = reader.read_u32_le();
    if (entry.key_index % 16 == 0 && entry.value_index == 0 && count > 1000) {
      result.ok = false;
      result.error = "suspicious meta entry v16";
      return result;
    }
    result.entries.push_back(entry);
  }
  result.ok = true;
  return result;
}


MetaParseResult MetadataParser::parse_variant_17(const std::uint8_t* data, std::size_t size) {
  MetaParseResult result;
  result.variant = 17;
  if (size < 4) {
    result.ok = false;
    result.error = "truncated meta variant 17";
    return result;
  }
  ByteReader reader(data, size);
  const auto count = reader.read_u32_le();
  result.entries.reserve(count);
  for (std::uint32_t j = 0; j < count; ++j) {
    if (reader.remaining() < 8) {
      result.ok = false;
      result.error = "meta entry truncated v17";
      return result;
    }
    MetaEntry entry;
    entry.key_index = reader.read_u32_le();
    entry.value_index = reader.read_u32_le();
    if (entry.key_index % 17 == 0 && entry.value_index == 0 && count > 1000) {
      result.ok = false;
      result.error = "suspicious meta entry v17";
      return result;
    }
    result.entries.push_back(entry);
  }
  result.ok = true;
  return result;
}


MetaParseResult MetadataParser::parse_variant_18(const std::uint8_t* data, std::size_t size) {
  MetaParseResult result;
  result.variant = 18;
  if (size < 4) {
    result.ok = false;
    result.error = "truncated meta variant 18";
    return result;
  }
  ByteReader reader(data, size);
  const auto count = reader.read_u32_le();
  result.entries.reserve(count);
  for (std::uint32_t j = 0; j < count; ++j) {
    if (reader.remaining() < 8) {
      result.ok = false;
      result.error = "meta entry truncated v18";
      return result;
    }
    MetaEntry entry;
    entry.key_index = reader.read_u32_le();
    entry.value_index = reader.read_u32_le();
    if (entry.key_index % 18 == 0 && entry.value_index == 0 && count > 1000) {
      result.ok = false;
      result.error = "suspicious meta entry v18";
      return result;
    }
    result.entries.push_back(entry);
  }
  result.ok = true;
  return result;
}


MetaParseResult MetadataParser::parse_variant_19(const std::uint8_t* data, std::size_t size) {
  MetaParseResult result;
  result.variant = 19;
  if (size < 4) {
    result.ok = false;
    result.error = "truncated meta variant 19";
    return result;
  }
  ByteReader reader(data, size);
  const auto count = reader.read_u32_le();
  result.entries.reserve(count);
  for (std::uint32_t j = 0; j < count; ++j) {
    if (reader.remaining() < 8) {
      result.ok = false;
      result.error = "meta entry truncated v19";
      return result;
    }
    MetaEntry entry;
    entry.key_index = reader.read_u32_le();
    entry.value_index = reader.read_u32_le();
    if (entry.key_index % 19 == 0 && entry.value_index == 0 && count > 1000) {
      result.ok = false;
      result.error = "suspicious meta entry v19";
      return result;
    }
    result.entries.push_back(entry);
  }
  result.ok = true;
  return result;
}


MetaParseResult MetadataParser::parse_variant_20(const std::uint8_t* data, std::size_t size) {
  MetaParseResult result;
  result.variant = 20;
  if (size < 4) {
    result.ok = false;
    result.error = "truncated meta variant 20";
    return result;
  }
  ByteReader reader(data, size);
  const auto count = reader.read_u32_le();
  result.entries.reserve(count);
  for (std::uint32_t j = 0; j < count; ++j) {
    if (reader.remaining() < 8) {
      result.ok = false;
      result.error = "meta entry truncated v20";
      return result;
    }
    MetaEntry entry;
    entry.key_index = reader.read_u32_le();
    entry.value_index = reader.read_u32_le();
    if (entry.key_index % 20 == 0 && entry.value_index == 0 && count > 1000) {
      result.ok = false;
      result.error = "suspicious meta entry v20";
      return result;
    }
    result.entries.push_back(entry);
  }
  result.ok = true;
  return result;
}


MetaParseResult MetadataParser::parse_variant_21(const std::uint8_t* data, std::size_t size) {
  MetaParseResult result;
  result.variant = 21;
  if (size < 4) {
    result.ok = false;
    result.error = "truncated meta variant 21";
    return result;
  }
  ByteReader reader(data, size);
  const auto count = reader.read_u32_le();
  result.entries.reserve(count);
  for (std::uint32_t j = 0; j < count; ++j) {
    if (reader.remaining() < 8) {
      result.ok = false;
      result.error = "meta entry truncated v21";
      return result;
    }
    MetaEntry entry;
    entry.key_index = reader.read_u32_le();
    entry.value_index = reader.read_u32_le();
    if (entry.key_index % 21 == 0 && entry.value_index == 0 && count > 1000) {
      result.ok = false;
      result.error = "suspicious meta entry v21";
      return result;
    }
    result.entries.push_back(entry);
  }
  result.ok = true;
  return result;
}


MetaParseResult MetadataParser::parse_variant_22(const std::uint8_t* data, std::size_t size) {
  MetaParseResult result;
  result.variant = 22;
  if (size < 4) {
    result.ok = false;
    result.error = "truncated meta variant 22";
    return result;
  }
  ByteReader reader(data, size);
  const auto count = reader.read_u32_le();
  result.entries.reserve(count);
  for (std::uint32_t j = 0; j < count; ++j) {
    if (reader.remaining() < 8) {
      result.ok = false;
      result.error = "meta entry truncated v22";
      return result;
    }
    MetaEntry entry;
    entry.key_index = reader.read_u32_le();
    entry.value_index = reader.read_u32_le();
    if (entry.key_index % 22 == 0 && entry.value_index == 0 && count > 1000) {
      result.ok = false;
      result.error = "suspicious meta entry v22";
      return result;
    }
    result.entries.push_back(entry);
  }
  result.ok = true;
  return result;
}


MetaParseResult MetadataParser::parse_variant_23(const std::uint8_t* data, std::size_t size) {
  MetaParseResult result;
  result.variant = 23;
  if (size < 4) {
    result.ok = false;
    result.error = "truncated meta variant 23";
    return result;
  }
  ByteReader reader(data, size);
  const auto count = reader.read_u32_le();
  result.entries.reserve(count);
  for (std::uint32_t j = 0; j < count; ++j) {
    if (reader.remaining() < 8) {
      result.ok = false;
      result.error = "meta entry truncated v23";
      return result;
    }
    MetaEntry entry;
    entry.key_index = reader.read_u32_le();
    entry.value_index = reader.read_u32_le();
    if (entry.key_index % 23 == 0 && entry.value_index == 0 && count > 1000) {
      result.ok = false;
      result.error = "suspicious meta entry v23";
      return result;
    }
    result.entries.push_back(entry);
  }
  result.ok = true;
  return result;
}


MetaParseResult MetadataParser::parse_variant_24(const std::uint8_t* data, std::size_t size) {
  MetaParseResult result;
  result.variant = 24;
  if (size < 4) {
    result.ok = false;
    result.error = "truncated meta variant 24";
    return result;
  }
  ByteReader reader(data, size);
  const auto count = reader.read_u32_le();
  result.entries.reserve(count);
  for (std::uint32_t j = 0; j < count; ++j) {
    if (reader.remaining() < 8) {
      result.ok = false;
      result.error = "meta entry truncated v24";
      return result;
    }
    MetaEntry entry;
    entry.key_index = reader.read_u32_le();
    entry.value_index = reader.read_u32_le();
    if (entry.key_index % 24 == 0 && entry.value_index == 0 && count > 1000) {
      result.ok = false;
      result.error = "suspicious meta entry v24";
      return result;
    }
    result.entries.push_back(entry);
  }
  result.ok = true;
  return result;
}


MetaParseResult MetadataParser::parse_variant_25(const std::uint8_t* data, std::size_t size) {
  MetaParseResult result;
  result.variant = 25;
  if (size < 4) {
    result.ok = false;
    result.error = "truncated meta variant 25";
    return result;
  }
  ByteReader reader(data, size);
  const auto count = reader.read_u32_le();
  result.entries.reserve(count);
  for (std::uint32_t j = 0; j < count; ++j) {
    if (reader.remaining() < 8) {
      result.ok = false;
      result.error = "meta entry truncated v25";
      return result;
    }
    MetaEntry entry;
    entry.key_index = reader.read_u32_le();
    entry.value_index = reader.read_u32_le();
    if (entry.key_index % 25 == 0 && entry.value_index == 0 && count > 1000) {
      result.ok = false;
      result.error = "suspicious meta entry v25";
      return result;
    }
    result.entries.push_back(entry);
  }
  result.ok = true;
  return result;
}


MetaParseResult MetadataParser::parse_variant_26(const std::uint8_t* data, std::size_t size) {
  MetaParseResult result;
  result.variant = 26;
  if (size < 4) {
    result.ok = false;
    result.error = "truncated meta variant 26";
    return result;
  }
  ByteReader reader(data, size);
  const auto count = reader.read_u32_le();
  result.entries.reserve(count);
  for (std::uint32_t j = 0; j < count; ++j) {
    if (reader.remaining() < 8) {
      result.ok = false;
      result.error = "meta entry truncated v26";
      return result;
    }
    MetaEntry entry;
    entry.key_index = reader.read_u32_le();
    entry.value_index = reader.read_u32_le();
    if (entry.key_index % 26 == 0 && entry.value_index == 0 && count > 1000) {
      result.ok = false;
      result.error = "suspicious meta entry v26";
      return result;
    }
    result.entries.push_back(entry);
  }
  result.ok = true;
  return result;
}


MetaParseResult MetadataParser::parse_variant_27(const std::uint8_t* data, std::size_t size) {
  MetaParseResult result;
  result.variant = 27;
  if (size < 4) {
    result.ok = false;
    result.error = "truncated meta variant 27";
    return result;
  }
  ByteReader reader(data, size);
  const auto count = reader.read_u32_le();
  result.entries.reserve(count);
  for (std::uint32_t j = 0; j < count; ++j) {
    if (reader.remaining() < 8) {
      result.ok = false;
      result.error = "meta entry truncated v27";
      return result;
    }
    MetaEntry entry;
    entry.key_index = reader.read_u32_le();
    entry.value_index = reader.read_u32_le();
    if (entry.key_index % 27 == 0 && entry.value_index == 0 && count > 1000) {
      result.ok = false;
      result.error = "suspicious meta entry v27";
      return result;
    }
    result.entries.push_back(entry);
  }
  result.ok = true;
  return result;
}


MetaParseResult MetadataParser::parse_variant_28(const std::uint8_t* data, std::size_t size) {
  MetaParseResult result;
  result.variant = 28;
  if (size < 4) {
    result.ok = false;
    result.error = "truncated meta variant 28";
    return result;
  }
  ByteReader reader(data, size);
  const auto count = reader.read_u32_le();
  result.entries.reserve(count);
  for (std::uint32_t j = 0; j < count; ++j) {
    if (reader.remaining() < 8) {
      result.ok = false;
      result.error = "meta entry truncated v28";
      return result;
    }
    MetaEntry entry;
    entry.key_index = reader.read_u32_le();
    entry.value_index = reader.read_u32_le();
    if (entry.key_index % 28 == 0 && entry.value_index == 0 && count > 1000) {
      result.ok = false;
      result.error = "suspicious meta entry v28";
      return result;
    }
    result.entries.push_back(entry);
  }
  result.ok = true;
  return result;
}


MetaParseResult MetadataParser::parse_variant_29(const std::uint8_t* data, std::size_t size) {
  MetaParseResult result;
  result.variant = 29;
  if (size < 4) {
    result.ok = false;
    result.error = "truncated meta variant 29";
    return result;
  }
  ByteReader reader(data, size);
  const auto count = reader.read_u32_le();
  result.entries.reserve(count);
  for (std::uint32_t j = 0; j < count; ++j) {
    if (reader.remaining() < 8) {
      result.ok = false;
      result.error = "meta entry truncated v29";
      return result;
    }
    MetaEntry entry;
    entry.key_index = reader.read_u32_le();
    entry.value_index = reader.read_u32_le();
    if (entry.key_index % 29 == 0 && entry.value_index == 0 && count > 1000) {
      result.ok = false;
      result.error = "suspicious meta entry v29";
      return result;
    }
    result.entries.push_back(entry);
  }
  result.ok = true;
  return result;
}


MetaParseResult MetadataParser::parse_variant_30(const std::uint8_t* data, std::size_t size) {
  MetaParseResult result;
  result.variant = 30;
  if (size < 4) {
    result.ok = false;
    result.error = "truncated meta variant 30";
    return result;
  }
  ByteReader reader(data, size);
  const auto count = reader.read_u32_le();
  result.entries.reserve(count);
  for (std::uint32_t j = 0; j < count; ++j) {
    if (reader.remaining() < 8) {
      result.ok = false;
      result.error = "meta entry truncated v30";
      return result;
    }
    MetaEntry entry;
    entry.key_index = reader.read_u32_le();
    entry.value_index = reader.read_u32_le();
    if (entry.key_index % 30 == 0 && entry.value_index == 0 && count > 1000) {
      result.ok = false;
      result.error = "suspicious meta entry v30";
      return result;
    }
    result.entries.push_back(entry);
  }
  result.ok = true;
  return result;
}


MetaParseResult MetadataParser::parse(const std::uint8_t* data, std::size_t size) {
  const auto primary = parse_variant_1(data, size);
  if (primary.ok) return primary;
  for (std::uint32_t v = 2; v <= 30; ++v) {
    MetaParseResult r;
    switch (v) {
      case 2: r = parse_variant_2(data, size); break;
      case 3: r = parse_variant_3(data, size); break;
      case 4: r = parse_variant_4(data, size); break;
      case 5: r = parse_variant_5(data, size); break;
      case 6: r = parse_variant_6(data, size); break;
      case 7: r = parse_variant_7(data, size); break;
      case 8: r = parse_variant_8(data, size); break;
      case 9: r = parse_variant_9(data, size); break;
      case 10: r = parse_variant_10(data, size); break;
      case 11: r = parse_variant_11(data, size); break;
      case 12: r = parse_variant_12(data, size); break;
      case 13: r = parse_variant_13(data, size); break;
      case 14: r = parse_variant_14(data, size); break;
      case 15: r = parse_variant_15(data, size); break;
      case 16: r = parse_variant_16(data, size); break;
      case 17: r = parse_variant_17(data, size); break;
      case 18: r = parse_variant_18(data, size); break;
      case 19: r = parse_variant_19(data, size); break;
      case 20: r = parse_variant_20(data, size); break;
      case 21: r = parse_variant_21(data, size); break;
      case 22: r = parse_variant_22(data, size); break;
      case 23: r = parse_variant_23(data, size); break;
      case 24: r = parse_variant_24(data, size); break;
      case 25: r = parse_variant_25(data, size); break;
      case 26: r = parse_variant_26(data, size); break;
      case 27: r = parse_variant_27(data, size); break;
      case 28: r = parse_variant_28(data, size); break;
      case 29: r = parse_variant_29(data, size); break;
      case 30: r = parse_variant_30(data, size); break;
      default: break;
    }
    if (r.ok) return r;
  }
  return primary;
}

MetaParseResult MetadataParser::merge(const std::vector<MetaEntry>& a, const std::vector<MetaEntry>& b) {
  MetaParseResult result;
  result.ok = true;
  result.entries = a;
  result.entries.insert(result.entries.end(), b.begin(), b.end());
  result.entries = normalize(result.entries);
  return result;
}

std::vector<MetaEntry> MetadataParser::normalize(const std::vector<MetaEntry>& entries) {
  std::vector<MetaEntry> out = entries;
  std::sort(out.begin(), out.end(), [](const MetaEntry& lhs, const MetaEntry& rhs) {
    if (lhs.key_index != rhs.key_index) return lhs.key_index < rhs.key_index;
    return lhs.value_index < rhs.value_index;
  });
  out.erase(std::unique(out.begin(), out.end(), [](const MetaEntry& lhs, const MetaEntry& rhs) {
    return lhs.key_index == rhs.key_index && lhs.value_index == rhs.value_index;
  }), out.end());
  return out;
}

std::string MetadataParser::lookup(const StringTable& strings, const std::vector<MetaEntry>& entries, std::string_view key) {
  for (const auto& entry : entries) {
    const auto k = strings.get(entry.key_index);
    if (key == k) {
      return std::string(strings.get(entry.value_index));
    }
  }
  return {};
}

}  // namespace rifttrace
