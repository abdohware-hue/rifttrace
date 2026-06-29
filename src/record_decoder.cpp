// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT

#include "rifttrace/record_decoder.hpp"

#include "rifttrace/byte_reader.hpp"

namespace rifttrace {

namespace {

ObjectRecord read_object(ByteReader& reader) {
  ObjectRecord record;
  record.object_id = reader.read_u32_le();
  record.name_index = reader.read_u32_le();
  record.symbol_index = reader.read_u32_le();
  record.pool_slot = reader.read_u32_le();
  return record;
}

FrameRecord read_frame(ByteReader& reader) {
  FrameRecord record;
  record.frame_id = reader.read_u32_le();
  record.timestamp_ns = reader.read_u64_le();
  record.parent_frame = reader.read_u32_le();
  record.object_count = reader.read_u32_le();
  return record;
}

EventRecord read_event(ByteReader& reader) {
  EventRecord record;
  record.event_id = reader.read_u32_le();
  record.frame_id = reader.read_u32_le();
  record.name_index = reader.read_u32_le();
  record.severity = reader.read_u8();
  return record;
}

AliasRecord read_alias(ByteReader& reader) {
  AliasRecord record;
  record.alias_id = reader.read_u32_le();
  record.target_id = reader.read_u32_le();
  record.name_index = reader.read_u32_le();
  return record;
}

}  // namespace

RecordBatch RecordDecoder::decode_section(const std::uint8_t* data, std::size_t size) const {
  RecordBatch batch;
  ByteReader reader(data, size);
  if (size == 0) {
    return batch;
  }
  const auto record_count = reader.read_u32_le();
  for (std::uint32_t i = 0; i < record_count; ++i) {
    RawRecord raw;
    raw.type = static_cast<RecordType>(reader.read_u8());
    const auto payload_len = reader.read_u32_le();
    raw.offset = static_cast<std::uint32_t>(reader.position());
    if (reader.remaining() < payload_len) {
      throw ParseError(ErrorCode::kInvalidRecord, "record payload truncated");
    }
    raw.payload.assign(reader.data() + reader.position(),
                       reader.data() + reader.position() + payload_len);
    reader.skip(payload_len);
    batch.raw.push_back(std::move(raw));
    batch.decoded.push_back(decode_payload(batch.raw.back().type, batch.raw.back().payload.data(),
                                           batch.raw.back().payload.size()));
  }
  return batch;
}

DecodedRecord RecordDecoder::decode_payload(RecordType type, const std::uint8_t* data,
                                            std::size_t size) const {
  ByteReader reader(data, size);
  switch (type) {
    case RecordType::kObject:
      if (size < 16) {
        throw ParseError(ErrorCode::kInvalidRecord, "object record too small");
      }
      return read_object(reader);
    case RecordType::kFrame:
      if (size < 20) {
        throw ParseError(ErrorCode::kInvalidRecord, "frame record too small");
      }
      return read_frame(reader);
    case RecordType::kEvent:
      if (size < 13) {
        throw ParseError(ErrorCode::kInvalidRecord, "event record too small");
      }
      return read_event(reader);
    case RecordType::kAlias:
      if (size < 12) {
        throw ParseError(ErrorCode::kInvalidRecord, "alias record too small");
      }
      return read_alias(reader);
    default:
      throw ParseError(ErrorCode::kInvalidRecord, "unknown record type");
  }
}

std::vector<DecodedRecord> RecordDecoder::decode_all(const RecordBatch& batch) const {
  std::vector<DecodedRecord> decoded;
  decoded.reserve(batch.raw.size());
  for (const auto& raw : batch.raw) {
    decoded.push_back(decode_payload(raw.type, raw.payload.data(), raw.payload.size()));
  }
  return decoded;
}

std::vector<std::uint8_t> encode_object_record(const ObjectRecord& record) {
  auto out = write_u32_le(record.object_id);
  auto n = write_u32_le(record.name_index);
  auto s = write_u32_le(record.symbol_index);
  auto p = write_u32_le(record.pool_slot);
  out.insert(out.end(), n.begin(), n.end());
  out.insert(out.end(), s.begin(), s.end());
  out.insert(out.end(), p.begin(), p.end());
  return out;
}

std::vector<std::uint8_t> encode_frame_record(const FrameRecord& record) {
  auto out = write_u32_le(record.frame_id);
  auto ts = write_u64_le(record.timestamp_ns);
  auto parent = write_u32_le(record.parent_frame);
  auto count = write_u32_le(record.object_count);
  out.insert(out.end(), ts.begin(), ts.end());
  out.insert(out.end(), parent.begin(), parent.end());
  out.insert(out.end(), count.begin(), count.end());
  return out;
}

std::vector<std::uint8_t> encode_event_record(const EventRecord& record) {
  auto out = write_u32_le(record.event_id);
  auto frame = write_u32_le(record.frame_id);
  auto name = write_u32_le(record.name_index);
  out.insert(out.end(), frame.begin(), frame.end());
  out.insert(out.end(), name.begin(), name.end());
  out.push_back(record.severity);
  return out;
}

std::vector<std::uint8_t> encode_alias_record(const AliasRecord& record) {
  auto out = write_u32_le(record.alias_id);
  auto target = write_u32_le(record.target_id);
  auto name = write_u32_le(record.name_index);
  out.insert(out.end(), target.begin(), target.end());
  out.insert(out.end(), name.begin(), name.end());
  return out;
}

}  // namespace rifttrace
