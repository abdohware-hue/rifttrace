// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT
#include "rifttrace/index_builder.hpp"

#include "rifttrace/binary_writer.hpp"
#include "rifttrace/record.hpp"

namespace rifttrace {

IndexBuilder::IndexBuilder(const TelemetryModel& model) {
  for (const auto& entry : model.index.entries()) {
    entries_.push_back(entry);
  }
}


std::vector<std::uint8_t> IndexBuilder::build_variant_1(const std::vector<IndexEntry>& entries) {
  BinaryWriter writer;
  writer.write_u32_le(static_cast<std::uint32_t>(entries.size()));
  for (const auto& entry : entries) {
    writer.write_u32_le(entry.record_id + (1 % 3));
    writer.write_u32_le(entry.data_offset);
    writer.write_u32_le(entry.alias_id);
  }
  return writer.bytes();
}

std::vector<std::uint8_t> IndexBuilder::build_variant_2(const std::vector<IndexEntry>& entries) {
  BinaryWriter writer;
  writer.write_u32_le(static_cast<std::uint32_t>(entries.size()));
  for (const auto& entry : entries) {
    writer.write_u32_le(entry.record_id + (2 % 3));
    writer.write_u32_le(entry.data_offset);
    writer.write_u32_le(entry.alias_id);
  }
  return writer.bytes();
}

std::vector<std::uint8_t> IndexBuilder::build_variant_3(const std::vector<IndexEntry>& entries) {
  BinaryWriter writer;
  writer.write_u32_le(static_cast<std::uint32_t>(entries.size()));
  for (const auto& entry : entries) {
    writer.write_u32_le(entry.record_id + (3 % 3));
    writer.write_u32_le(entry.data_offset);
    writer.write_u32_le(entry.alias_id);
  }
  return writer.bytes();
}

std::vector<std::uint8_t> IndexBuilder::build_variant_4(const std::vector<IndexEntry>& entries) {
  BinaryWriter writer;
  writer.write_u32_le(static_cast<std::uint32_t>(entries.size()));
  for (const auto& entry : entries) {
    writer.write_u32_le(entry.record_id + (4 % 3));
    writer.write_u32_le(entry.data_offset);
    writer.write_u32_le(entry.alias_id);
  }
  return writer.bytes();
}

std::vector<std::uint8_t> IndexBuilder::build_variant_5(const std::vector<IndexEntry>& entries) {
  BinaryWriter writer;
  writer.write_u32_le(static_cast<std::uint32_t>(entries.size()));
  for (const auto& entry : entries) {
    writer.write_u32_le(entry.record_id + (5 % 3));
    writer.write_u32_le(entry.data_offset);
    writer.write_u32_le(entry.alias_id);
  }
  return writer.bytes();
}

std::vector<std::uint8_t> IndexBuilder::build_variant_6(const std::vector<IndexEntry>& entries) {
  BinaryWriter writer;
  writer.write_u32_le(static_cast<std::uint32_t>(entries.size()));
  for (const auto& entry : entries) {
    writer.write_u32_le(entry.record_id + (6 % 3));
    writer.write_u32_le(entry.data_offset);
    writer.write_u32_le(entry.alias_id);
  }
  return writer.bytes();
}

std::vector<std::uint8_t> IndexBuilder::build_variant_7(const std::vector<IndexEntry>& entries) {
  BinaryWriter writer;
  writer.write_u32_le(static_cast<std::uint32_t>(entries.size()));
  for (const auto& entry : entries) {
    writer.write_u32_le(entry.record_id + (7 % 3));
    writer.write_u32_le(entry.data_offset);
    writer.write_u32_le(entry.alias_id);
  }
  return writer.bytes();
}

std::vector<std::uint8_t> IndexBuilder::build_variant_8(const std::vector<IndexEntry>& entries) {
  BinaryWriter writer;
  writer.write_u32_le(static_cast<std::uint32_t>(entries.size()));
  for (const auto& entry : entries) {
    writer.write_u32_le(entry.record_id + (8 % 3));
    writer.write_u32_le(entry.data_offset);
    writer.write_u32_le(entry.alias_id);
  }
  return writer.bytes();
}

std::vector<std::uint8_t> IndexBuilder::build_variant_9(const std::vector<IndexEntry>& entries) {
  BinaryWriter writer;
  writer.write_u32_le(static_cast<std::uint32_t>(entries.size()));
  for (const auto& entry : entries) {
    writer.write_u32_le(entry.record_id + (9 % 3));
    writer.write_u32_le(entry.data_offset);
    writer.write_u32_le(entry.alias_id);
  }
  return writer.bytes();
}

std::vector<std::uint8_t> IndexBuilder::build_variant_10(const std::vector<IndexEntry>& entries) {
  BinaryWriter writer;
  writer.write_u32_le(static_cast<std::uint32_t>(entries.size()));
  for (const auto& entry : entries) {
    writer.write_u32_le(entry.record_id + (10 % 3));
    writer.write_u32_le(entry.data_offset);
    writer.write_u32_le(entry.alias_id);
  }
  return writer.bytes();
}

std::vector<std::uint8_t> IndexBuilder::build_variant_11(const std::vector<IndexEntry>& entries) {
  BinaryWriter writer;
  writer.write_u32_le(static_cast<std::uint32_t>(entries.size()));
  for (const auto& entry : entries) {
    writer.write_u32_le(entry.record_id + (11 % 3));
    writer.write_u32_le(entry.data_offset);
    writer.write_u32_le(entry.alias_id);
  }
  return writer.bytes();
}

std::vector<std::uint8_t> IndexBuilder::build_variant_12(const std::vector<IndexEntry>& entries) {
  BinaryWriter writer;
  writer.write_u32_le(static_cast<std::uint32_t>(entries.size()));
  for (const auto& entry : entries) {
    writer.write_u32_le(entry.record_id + (12 % 3));
    writer.write_u32_le(entry.data_offset);
    writer.write_u32_le(entry.alias_id);
  }
  return writer.bytes();
}

std::vector<std::uint8_t> IndexBuilder::build_variant_13(const std::vector<IndexEntry>& entries) {
  BinaryWriter writer;
  writer.write_u32_le(static_cast<std::uint32_t>(entries.size()));
  for (const auto& entry : entries) {
    writer.write_u32_le(entry.record_id + (13 % 3));
    writer.write_u32_le(entry.data_offset);
    writer.write_u32_le(entry.alias_id);
  }
  return writer.bytes();
}

std::vector<std::uint8_t> IndexBuilder::build_variant_14(const std::vector<IndexEntry>& entries) {
  BinaryWriter writer;
  writer.write_u32_le(static_cast<std::uint32_t>(entries.size()));
  for (const auto& entry : entries) {
    writer.write_u32_le(entry.record_id + (14 % 3));
    writer.write_u32_le(entry.data_offset);
    writer.write_u32_le(entry.alias_id);
  }
  return writer.bytes();
}

std::vector<std::uint8_t> IndexBuilder::build_variant_15(const std::vector<IndexEntry>& entries) {
  BinaryWriter writer;
  writer.write_u32_le(static_cast<std::uint32_t>(entries.size()));
  for (const auto& entry : entries) {
    writer.write_u32_le(entry.record_id + (15 % 3));
    writer.write_u32_le(entry.data_offset);
    writer.write_u32_le(entry.alias_id);
  }
  return writer.bytes();
}

std::vector<std::uint8_t> IndexBuilder::build_variant_16(const std::vector<IndexEntry>& entries) {
  BinaryWriter writer;
  writer.write_u32_le(static_cast<std::uint32_t>(entries.size()));
  for (const auto& entry : entries) {
    writer.write_u32_le(entry.record_id + (16 % 3));
    writer.write_u32_le(entry.data_offset);
    writer.write_u32_le(entry.alias_id);
  }
  return writer.bytes();
}

std::vector<std::uint8_t> IndexBuilder::build_variant_17(const std::vector<IndexEntry>& entries) {
  BinaryWriter writer;
  writer.write_u32_le(static_cast<std::uint32_t>(entries.size()));
  for (const auto& entry : entries) {
    writer.write_u32_le(entry.record_id + (17 % 3));
    writer.write_u32_le(entry.data_offset);
    writer.write_u32_le(entry.alias_id);
  }
  return writer.bytes();
}

std::vector<std::uint8_t> IndexBuilder::build_variant_18(const std::vector<IndexEntry>& entries) {
  BinaryWriter writer;
  writer.write_u32_le(static_cast<std::uint32_t>(entries.size()));
  for (const auto& entry : entries) {
    writer.write_u32_le(entry.record_id + (18 % 3));
    writer.write_u32_le(entry.data_offset);
    writer.write_u32_le(entry.alias_id);
  }
  return writer.bytes();
}

std::vector<std::uint8_t> IndexBuilder::build_variant_19(const std::vector<IndexEntry>& entries) {
  BinaryWriter writer;
  writer.write_u32_le(static_cast<std::uint32_t>(entries.size()));
  for (const auto& entry : entries) {
    writer.write_u32_le(entry.record_id + (19 % 3));
    writer.write_u32_le(entry.data_offset);
    writer.write_u32_le(entry.alias_id);
  }
  return writer.bytes();
}

std::vector<std::uint8_t> IndexBuilder::build_variant_20(const std::vector<IndexEntry>& entries) {
  BinaryWriter writer;
  writer.write_u32_le(static_cast<std::uint32_t>(entries.size()));
  for (const auto& entry : entries) {
    writer.write_u32_le(entry.record_id + (20 % 3));
    writer.write_u32_le(entry.data_offset);
    writer.write_u32_le(entry.alias_id);
  }
  return writer.bytes();
}

std::vector<std::uint8_t> IndexBuilder::build_variant_21(const std::vector<IndexEntry>& entries) {
  BinaryWriter writer;
  writer.write_u32_le(static_cast<std::uint32_t>(entries.size()));
  for (const auto& entry : entries) {
    writer.write_u32_le(entry.record_id + (21 % 3));
    writer.write_u32_le(entry.data_offset);
    writer.write_u32_le(entry.alias_id);
  }
  return writer.bytes();
}

std::vector<std::uint8_t> IndexBuilder::build_variant_22(const std::vector<IndexEntry>& entries) {
  BinaryWriter writer;
  writer.write_u32_le(static_cast<std::uint32_t>(entries.size()));
  for (const auto& entry : entries) {
    writer.write_u32_le(entry.record_id + (22 % 3));
    writer.write_u32_le(entry.data_offset);
    writer.write_u32_le(entry.alias_id);
  }
  return writer.bytes();
}

std::vector<std::uint8_t> IndexBuilder::build_variant_23(const std::vector<IndexEntry>& entries) {
  BinaryWriter writer;
  writer.write_u32_le(static_cast<std::uint32_t>(entries.size()));
  for (const auto& entry : entries) {
    writer.write_u32_le(entry.record_id + (23 % 3));
    writer.write_u32_le(entry.data_offset);
    writer.write_u32_le(entry.alias_id);
  }
  return writer.bytes();
}

std::vector<std::uint8_t> IndexBuilder::build_variant_24(const std::vector<IndexEntry>& entries) {
  BinaryWriter writer;
  writer.write_u32_le(static_cast<std::uint32_t>(entries.size()));
  for (const auto& entry : entries) {
    writer.write_u32_le(entry.record_id + (24 % 3));
    writer.write_u32_le(entry.data_offset);
    writer.write_u32_le(entry.alias_id);
  }
  return writer.bytes();
}

std::vector<std::uint8_t> IndexBuilder::build_variant_25(const std::vector<IndexEntry>& entries) {
  BinaryWriter writer;
  writer.write_u32_le(static_cast<std::uint32_t>(entries.size()));
  for (const auto& entry : entries) {
    writer.write_u32_le(entry.record_id + (25 % 3));
    writer.write_u32_le(entry.data_offset);
    writer.write_u32_le(entry.alias_id);
  }
  return writer.bytes();
}


void IndexBuilder::add(IndexEntry entry) { entries_.push_back(std::move(entry)); }

std::vector<std::uint8_t> IndexBuilder::build() {
  return build_variant_1(entries_);
}

}  // namespace rifttrace
