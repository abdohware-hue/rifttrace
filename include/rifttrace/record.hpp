// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT

#pragma once

#include <cstdint>
#include <string>
#include <variant>
#include <vector>

#include "rifttrace/format.hpp"

namespace rifttrace {

struct RawRecord {
  RecordType type = RecordType::kObject;
  std::uint32_t offset = 0;
  std::vector<std::uint8_t> payload;
};

using DecodedRecord = std::variant<ObjectRecord, FrameRecord, EventRecord, AliasRecord>;

struct RecordBatch {
  std::vector<RawRecord> raw;
  std::vector<DecodedRecord> decoded;
};

RecordBatch parse_data_section(const std::uint8_t* data, std::size_t size);
DecodedRecord decode_record(RecordType type, const std::uint8_t* data, std::size_t size);

std::uint32_t record_id(const DecodedRecord& record);
RecordType record_type_of(const DecodedRecord& record);

}  // namespace rifttrace
