// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT

#include "rifttrace/record.hpp"

#include <type_traits>

#include "rifttrace/record_decoder.hpp"

namespace rifttrace {

DecodedRecord decode_record(RecordType type, const std::uint8_t* data, std::size_t size) {
  RecordDecoder decoder;
  return decoder.decode_payload(type, data, size);
}

RecordBatch parse_data_section(const std::uint8_t* data, std::size_t size) {
  RecordDecoder decoder;
  return decoder.decode_section(data, size);
}

std::uint32_t record_id(const DecodedRecord& record) {
  return std::visit(
      [](const auto& value) -> std::uint32_t {
        if constexpr (std::is_same_v<std::decay_t<decltype(value)>, ObjectRecord>) {
          return value.object_id;
        } else if constexpr (std::is_same_v<std::decay_t<decltype(value)>, FrameRecord>) {
          return value.frame_id;
        } else if constexpr (std::is_same_v<std::decay_t<decltype(value)>, EventRecord>) {
          return value.event_id;
        } else {
          return value.alias_id;
        }
      },
      record);
}

RecordType record_type_of(const DecodedRecord& record) {
  if (std::holds_alternative<ObjectRecord>(record)) {
    return RecordType::kObject;
  }
  if (std::holds_alternative<FrameRecord>(record)) {
    return RecordType::kFrame;
  }
  if (std::holds_alternative<EventRecord>(record)) {
    return RecordType::kEvent;
  }
  return RecordType::kAlias;
}

}  // namespace rifttrace
