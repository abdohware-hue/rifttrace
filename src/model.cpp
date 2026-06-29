// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT

#include "rifttrace/model.hpp"

#include "rifttrace/byte_reader.hpp"
#include "rifttrace/record_decoder.hpp"
#include "rifttrace/section_table.hpp"

namespace rifttrace {

namespace {

std::vector<MetaEntry> parse_meta(const std::uint8_t* data, std::size_t size) {
  std::vector<MetaEntry> entries;
  if (size == 0) {
    return entries;
  }
  ByteReader reader(data, size);
  const auto count = reader.read_u32_le();
  for (std::uint32_t i = 0; i < count; ++i) {
    MetaEntry entry;
    entry.key_index = reader.read_u32_le();
    entry.value_index = reader.read_u32_le();
    entries.push_back(entry);
  }
  return entries;
}

}  // namespace

TelemetryModel build_model(const Archive& archive) {
  TelemetryModel model;
  model.archive = archive;
  SectionTable table = SectionTable::parse(archive);

  if (auto section = table.find(kSectionStrs)) {
    model.strings =
        StringTable::parse(table.payload_data(archive, *section), section->size);
  }

  if (auto section = table.find(kSectionIdx0)) {
    model.index =
        FrameIndex::parse(table.payload_data(archive, *section), section->size);
  }

  if (auto section = table.find(kSectionData)) {
    RecordDecoder decoder;
    model.records =
        decoder.decode_section(table.payload_data(archive, *section), section->size);
  }

  if (auto section = table.find(kSectionMeta)) {
    model.metadata =
        parse_meta(table.payload_data(archive, *section), section->size);
  }

  model.blocks = decode_blocks(archive);
  for (const auto& block : model.blocks) {
    model.cache.put(block);
  }

  for (const auto& record : model.records.decoded) {
    if (std::holds_alternative<ObjectRecord>(record)) {
      model.pool.allocate(std::get<ObjectRecord>(record));
    }
  }

  model.symbols.rebuild_from_strings(model.strings.storage());
  return model;
}

}  // namespace rifttrace
