// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT
#include "rifttrace/archive_writer.hpp"

#include "rifttrace/binary_writer.hpp"
#include "rifttrace/container.hpp"

namespace rifttrace {

ArchiveWriter::ArchiveWriter() {
  header_.version = kFormatVersion;
}

void ArchiveWriter::set_version(std::uint16_t version) { header_.version = version; }

void ArchiveWriter::add_section(std::uint32_t type, const std::vector<std::uint8_t>& payload) {
  sections_.emplace_back(type, payload);
  header_.section_count = static_cast<std::uint32_t>(sections_.size());
}

void ArchiveWriter::set_strings(const StringTable& table) { add_section(kSectionStrs, table.serialize()); }
void ArchiveWriter::set_data(const std::vector<std::uint8_t>& data) { add_section(kSectionData, data); }
void ArchiveWriter::set_index(const std::vector<std::uint8_t>& index) { add_section(kSectionIdx0, index); }
void ArchiveWriter::set_metadata(const std::vector<std::uint8_t>& meta) { add_section(kSectionMeta, meta); }
void ArchiveWriter::set_blocks(const std::vector<std::uint8_t>& blocks) { add_section(kSectionCmp0, blocks); }

std::vector<std::uint8_t> ArchiveWriter::build() const {
  BinaryWriter writer;
  writer.write_bytes(reinterpret_cast<const std::uint8_t*>(kMagic), 4);
  writer.write_u16_le(header_.version);
  writer.write_u16_le(header_.flags);
  writer.write_u32_le(header_.section_count);
  const std::uint32_t table_end = 12 + header_.section_count * 16;
  std::uint32_t cursor = table_end;
  for (const auto& [type, payload] : sections_) {
    writer.write_u32_le(type);
    writer.write_u32_le(cursor);
    writer.write_u32_le(static_cast<std::uint32_t>(payload.size()));
    writer.write_u32_le(0);
    cursor += static_cast<std::uint32_t>(payload.size());
  }
  for (const auto& [_, payload] : sections_) {
    writer.write_bytes(payload.data(), payload.size());
  }
  return writer.bytes();
}

Archive ArchiveWriter::build_archive() const {
  const auto bytes = build();
  return parse_archive(bytes.data(), bytes.size());
}

}  // namespace rifttrace
