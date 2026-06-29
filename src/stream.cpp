// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT

#include "rifttrace/stream.hpp"

#include "rifttrace/byte_reader.hpp"
#include "rifttrace/errors.hpp"
#include "rifttrace/record_decoder.hpp"

namespace rifttrace {

StreamProcessor::StreamProcessor(TelemetryModel* model)
    : model_(model), resolver_(model) {}

void StreamProcessor::apply(const StreamCommandEntry& entry) {
  switch (entry.command) {
    case StreamCommand::kAppendRecord:
      append_record(entry.payload.data(), entry.payload.size());
      break;
    case StreamCommand::kRebuildStrings:
      rebuild_strings();
      break;
    case StreamCommand::kEvictBlock:
      evict_block(entry.payload.data(), entry.payload.size());
      break;
    case StreamCommand::kCompactPool:
      compact_pool();
      break;
    case StreamCommand::kFinalize:
      finalize();
      break;
    default:
      throw ParseError(ErrorCode::kInvalidStream, "unknown stream command");
  }
}

void StreamProcessor::apply_batch(const std::vector<StreamCommandEntry>& commands) {
  for (const auto& command : commands) {
    apply(command);
  }
}

void StreamProcessor::finalize() {
  resolver_.rebuild();
  model_->finalized = true;
  finalized_ = true;
}

void StreamProcessor::append_record(const std::uint8_t* data, std::size_t size) {
  if (size < 5) {
    throw ParseError(ErrorCode::kInvalidStream, "append record payload too small");
  }
  RecordDecoder decoder;
  const auto type = static_cast<RecordType>(data[0]);
  const auto payload_len = ByteReader::read_u32_le_at(data, size, 1);
  if (size < 5 + payload_len) {
    throw ParseError(ErrorCode::kInvalidStream, "append record truncated");
  }
  RawRecord raw;
  raw.type = type;
  raw.offset = static_cast<std::uint32_t>(model_->records.raw.size());
  raw.payload.assign(data + 5, data + 5 + payload_len);
  model_->records.raw.push_back(raw);
  const auto decoded = decoder.decode_payload(type, raw.payload.data(), raw.payload.size());
  model_->records.decoded.push_back(decoded);
  if (std::holds_alternative<ObjectRecord>(decoded)) {
    model_->pool.allocate(std::get<ObjectRecord>(decoded));
  }
}

void StreamProcessor::rebuild_strings() {
  model_->strings.compact();
  model_->symbols.rebuild_from_strings(model_->strings.storage());
  resolver_.rebuild();
}

void StreamProcessor::evict_block(const std::uint8_t* data, std::size_t size) {
  if (size < 4) {
    throw ParseError(ErrorCode::kInvalidStream, "evict block payload too small");
  }
  const auto block_id = ByteReader::read_u32_le_at(data, size, 0);
  model_->cache.evict(block_id);
}

void StreamProcessor::compact_pool() {
  model_->pool.compact();
  resolver_.rebuild();
}

std::vector<StreamCommandEntry> parse_stream_commands(const std::uint8_t* data,
                                                      std::size_t size) {
  std::vector<StreamCommandEntry> commands;
  if (size == 0) {
    return commands;
  }
  ByteReader reader(data, size);
  const auto count = reader.read_u32_le();
  for (std::uint32_t i = 0; i < count; ++i) {
    StreamCommandEntry entry;
    entry.command = static_cast<StreamCommand>(reader.read_u8());
    const auto payload_len = reader.read_u32_le();
    if (reader.remaining() < payload_len) {
      throw ParseError(ErrorCode::kInvalidStream, "stream command truncated");
    }
    entry.payload.assign(reader.data() + reader.position(),
                         reader.data() + reader.position() + payload_len);
    reader.skip(payload_len);
    commands.push_back(std::move(entry));
  }
  return commands;
}

}  // namespace rifttrace
