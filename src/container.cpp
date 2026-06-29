// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT

#include "rifttrace/container.hpp"

#include <cstring>
#include <fstream>

#include "rifttrace/byte_reader.hpp"
#include "rifttrace/checksum.hpp"

namespace rifttrace {

bool validate_header(const std::uint8_t* data, std::size_t size) {
  if (size < 12) {
    return false;
  }
  return std::memcmp(data, kMagic, 4) == 0;
}

Archive parse_archive(const std::uint8_t* data, std::size_t size) {
  if (size < 12) {
    throw ParseError(ErrorCode::kTruncated, "archive too small for header");
  }
  if (std::memcmp(data, kMagic, 4) != 0) {
    throw ParseError(ErrorCode::kBadMagic, "invalid RIFT magic");
  }

  ByteReader reader(data, size);
  reader.skip(4);

  Archive archive;
  archive.header.version = reader.read_u16_le();
  archive.header.flags = reader.read_u16_le();
  archive.header.section_count = reader.read_u32_le();

  if (archive.header.version != kFormatVersion) {
    throw ParseError(ErrorCode::kUnsupportedVersion, "unsupported archive version");
  }

  const std::size_t table_bytes =
      static_cast<std::size_t>(archive.header.section_count) * 16u;
  if (reader.remaining() < table_bytes) {
    throw ParseError(ErrorCode::kTruncated, "section table truncated");
  }

  archive.sections.reserve(archive.header.section_count);
  for (std::uint32_t i = 0; i < archive.header.section_count; ++i) {
    SectionEntry entry;
    entry.type = reader.read_u32_le();
    entry.offset = reader.read_u32_le();
    entry.size = reader.read_u32_le();
    entry.flags = reader.read_u32_le();
    if (entry.offset + entry.size > size) {
      throw ParseError(ErrorCode::kInvalidSection, "section out of bounds");
    }
    archive.sections.push_back(entry);
  }

  archive.bytes.assign(data, data + size);
  return archive;
}

Archive parse_archive_file(const char* path) {
  std::ifstream input(path, std::ios::binary);
  if (!input) {
    throw ParseError(ErrorCode::kTruncated, "failed to open archive file");
  }
  std::vector<std::uint8_t> bytes((std::istreambuf_iterator<char>(input)),
                                  std::istreambuf_iterator<char>());
  return parse_archive(bytes.data(), bytes.size());
}

std::uint32_t archive_checksum(const Archive& archive) {
  const auto hash = fnv1a64(archive.bytes.data(), archive.bytes.size());
  return static_cast<std::uint32_t>(hash ^ (hash >> 32));
}

}  // namespace rifttrace
