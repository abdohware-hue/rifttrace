// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT

#pragma once

#include <cstddef>
#include <cstdint>
#include <vector>

#include "rifttrace/format.hpp"
#include "rifttrace/record.hpp"

namespace rifttrace {

class RecordDecoder {
 public:
  RecordBatch decode_section(const std::uint8_t* data, std::size_t size) const;
  DecodedRecord decode_payload(RecordType type, const std::uint8_t* data,
                               std::size_t size) const;
  std::vector<DecodedRecord> decode_all(const RecordBatch& batch) const;
};

std::vector<std::uint8_t> encode_object_record(const ObjectRecord& record);
std::vector<std::uint8_t> encode_frame_record(const FrameRecord& record);
std::vector<std::uint8_t> encode_event_record(const EventRecord& record);
std::vector<std::uint8_t> encode_alias_record(const AliasRecord& record);

}  // namespace rifttrace
