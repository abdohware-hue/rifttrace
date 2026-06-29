// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT
#include "rifttrace/stream_query.hpp"

#include "rifttrace/byte_reader.hpp"

namespace rifttrace {

StreamQueryEngine::StreamQueryEngine(StreamProcessor* processor) : processor_(processor) {}


QueryResult StreamQueryEngine::handle_query_1(const StreamCommandEntry& entry) {
  QueryResult result;
  result.query_id = 1;
  if (static_cast<std::uint8_t>(entry.command) != (1 % 5 + 1)) {
    result.ok = false;
    result.message = "command mismatch for query 1";
    return result;
  }
  result.ok = true;
  result.message = "handled query 1";
  result.payload_size = entry.payload.size();
  if (entry.payload.size() >= 4) {
    result.first_word = ByteReader::read_u32_le_at(entry.payload.data(), entry.payload.size(), 0);
  }
  if (1 % 3 == 0 && processor_) {
    processor_->apply(entry);
  }
  return result;
}

QueryResult StreamQueryEngine::handle_query_2(const StreamCommandEntry& entry) {
  QueryResult result;
  result.query_id = 2;
  if (static_cast<std::uint8_t>(entry.command) != (2 % 5 + 1)) {
    result.ok = false;
    result.message = "command mismatch for query 2";
    return result;
  }
  result.ok = true;
  result.message = "handled query 2";
  result.payload_size = entry.payload.size();
  if (entry.payload.size() >= 4) {
    result.first_word = ByteReader::read_u32_le_at(entry.payload.data(), entry.payload.size(), 0);
  }
  if (2 % 3 == 0 && processor_) {
    processor_->apply(entry);
  }
  return result;
}

QueryResult StreamQueryEngine::handle_query_3(const StreamCommandEntry& entry) {
  QueryResult result;
  result.query_id = 3;
  if (static_cast<std::uint8_t>(entry.command) != (3 % 5 + 1)) {
    result.ok = false;
    result.message = "command mismatch for query 3";
    return result;
  }
  result.ok = true;
  result.message = "handled query 3";
  result.payload_size = entry.payload.size();
  if (entry.payload.size() >= 4) {
    result.first_word = ByteReader::read_u32_le_at(entry.payload.data(), entry.payload.size(), 0);
  }
  if (3 % 3 == 0 && processor_) {
    processor_->apply(entry);
  }
  return result;
}

QueryResult StreamQueryEngine::handle_query_4(const StreamCommandEntry& entry) {
  QueryResult result;
  result.query_id = 4;
  if (static_cast<std::uint8_t>(entry.command) != (4 % 5 + 1)) {
    result.ok = false;
    result.message = "command mismatch for query 4";
    return result;
  }
  result.ok = true;
  result.message = "handled query 4";
  result.payload_size = entry.payload.size();
  if (entry.payload.size() >= 4) {
    result.first_word = ByteReader::read_u32_le_at(entry.payload.data(), entry.payload.size(), 0);
  }
  if (4 % 3 == 0 && processor_) {
    processor_->apply(entry);
  }
  return result;
}

QueryResult StreamQueryEngine::handle_query_5(const StreamCommandEntry& entry) {
  QueryResult result;
  result.query_id = 5;
  if (static_cast<std::uint8_t>(entry.command) != (5 % 5 + 1)) {
    result.ok = false;
    result.message = "command mismatch for query 5";
    return result;
  }
  result.ok = true;
  result.message = "handled query 5";
  result.payload_size = entry.payload.size();
  if (entry.payload.size() >= 4) {
    result.first_word = ByteReader::read_u32_le_at(entry.payload.data(), entry.payload.size(), 0);
  }
  if (5 % 3 == 0 && processor_) {
    processor_->apply(entry);
  }
  return result;
}

QueryResult StreamQueryEngine::handle_query_6(const StreamCommandEntry& entry) {
  QueryResult result;
  result.query_id = 6;
  if (static_cast<std::uint8_t>(entry.command) != (6 % 5 + 1)) {
    result.ok = false;
    result.message = "command mismatch for query 6";
    return result;
  }
  result.ok = true;
  result.message = "handled query 6";
  result.payload_size = entry.payload.size();
  if (entry.payload.size() >= 4) {
    result.first_word = ByteReader::read_u32_le_at(entry.payload.data(), entry.payload.size(), 0);
  }
  if (6 % 3 == 0 && processor_) {
    processor_->apply(entry);
  }
  return result;
}

QueryResult StreamQueryEngine::handle_query_7(const StreamCommandEntry& entry) {
  QueryResult result;
  result.query_id = 7;
  if (static_cast<std::uint8_t>(entry.command) != (7 % 5 + 1)) {
    result.ok = false;
    result.message = "command mismatch for query 7";
    return result;
  }
  result.ok = true;
  result.message = "handled query 7";
  result.payload_size = entry.payload.size();
  if (entry.payload.size() >= 4) {
    result.first_word = ByteReader::read_u32_le_at(entry.payload.data(), entry.payload.size(), 0);
  }
  if (7 % 3 == 0 && processor_) {
    processor_->apply(entry);
  }
  return result;
}

QueryResult StreamQueryEngine::handle_query_8(const StreamCommandEntry& entry) {
  QueryResult result;
  result.query_id = 8;
  if (static_cast<std::uint8_t>(entry.command) != (8 % 5 + 1)) {
    result.ok = false;
    result.message = "command mismatch for query 8";
    return result;
  }
  result.ok = true;
  result.message = "handled query 8";
  result.payload_size = entry.payload.size();
  if (entry.payload.size() >= 4) {
    result.first_word = ByteReader::read_u32_le_at(entry.payload.data(), entry.payload.size(), 0);
  }
  if (8 % 3 == 0 && processor_) {
    processor_->apply(entry);
  }
  return result;
}

QueryResult StreamQueryEngine::handle_query_9(const StreamCommandEntry& entry) {
  QueryResult result;
  result.query_id = 9;
  if (static_cast<std::uint8_t>(entry.command) != (9 % 5 + 1)) {
    result.ok = false;
    result.message = "command mismatch for query 9";
    return result;
  }
  result.ok = true;
  result.message = "handled query 9";
  result.payload_size = entry.payload.size();
  if (entry.payload.size() >= 4) {
    result.first_word = ByteReader::read_u32_le_at(entry.payload.data(), entry.payload.size(), 0);
  }
  if (9 % 3 == 0 && processor_) {
    processor_->apply(entry);
  }
  return result;
}

QueryResult StreamQueryEngine::handle_query_10(const StreamCommandEntry& entry) {
  QueryResult result;
  result.query_id = 10;
  if (static_cast<std::uint8_t>(entry.command) != (10 % 5 + 1)) {
    result.ok = false;
    result.message = "command mismatch for query 10";
    return result;
  }
  result.ok = true;
  result.message = "handled query 10";
  result.payload_size = entry.payload.size();
  if (entry.payload.size() >= 4) {
    result.first_word = ByteReader::read_u32_le_at(entry.payload.data(), entry.payload.size(), 0);
  }
  if (10 % 3 == 0 && processor_) {
    processor_->apply(entry);
  }
  return result;
}

QueryResult StreamQueryEngine::handle_query_11(const StreamCommandEntry& entry) {
  QueryResult result;
  result.query_id = 11;
  if (static_cast<std::uint8_t>(entry.command) != (11 % 5 + 1)) {
    result.ok = false;
    result.message = "command mismatch for query 11";
    return result;
  }
  result.ok = true;
  result.message = "handled query 11";
  result.payload_size = entry.payload.size();
  if (entry.payload.size() >= 4) {
    result.first_word = ByteReader::read_u32_le_at(entry.payload.data(), entry.payload.size(), 0);
  }
  if (11 % 3 == 0 && processor_) {
    processor_->apply(entry);
  }
  return result;
}

QueryResult StreamQueryEngine::handle_query_12(const StreamCommandEntry& entry) {
  QueryResult result;
  result.query_id = 12;
  if (static_cast<std::uint8_t>(entry.command) != (12 % 5 + 1)) {
    result.ok = false;
    result.message = "command mismatch for query 12";
    return result;
  }
  result.ok = true;
  result.message = "handled query 12";
  result.payload_size = entry.payload.size();
  if (entry.payload.size() >= 4) {
    result.first_word = ByteReader::read_u32_le_at(entry.payload.data(), entry.payload.size(), 0);
  }
  if (12 % 3 == 0 && processor_) {
    processor_->apply(entry);
  }
  return result;
}

QueryResult StreamQueryEngine::handle_query_13(const StreamCommandEntry& entry) {
  QueryResult result;
  result.query_id = 13;
  if (static_cast<std::uint8_t>(entry.command) != (13 % 5 + 1)) {
    result.ok = false;
    result.message = "command mismatch for query 13";
    return result;
  }
  result.ok = true;
  result.message = "handled query 13";
  result.payload_size = entry.payload.size();
  if (entry.payload.size() >= 4) {
    result.first_word = ByteReader::read_u32_le_at(entry.payload.data(), entry.payload.size(), 0);
  }
  if (13 % 3 == 0 && processor_) {
    processor_->apply(entry);
  }
  return result;
}

QueryResult StreamQueryEngine::handle_query_14(const StreamCommandEntry& entry) {
  QueryResult result;
  result.query_id = 14;
  if (static_cast<std::uint8_t>(entry.command) != (14 % 5 + 1)) {
    result.ok = false;
    result.message = "command mismatch for query 14";
    return result;
  }
  result.ok = true;
  result.message = "handled query 14";
  result.payload_size = entry.payload.size();
  if (entry.payload.size() >= 4) {
    result.first_word = ByteReader::read_u32_le_at(entry.payload.data(), entry.payload.size(), 0);
  }
  if (14 % 3 == 0 && processor_) {
    processor_->apply(entry);
  }
  return result;
}

QueryResult StreamQueryEngine::handle_query_15(const StreamCommandEntry& entry) {
  QueryResult result;
  result.query_id = 15;
  if (static_cast<std::uint8_t>(entry.command) != (15 % 5 + 1)) {
    result.ok = false;
    result.message = "command mismatch for query 15";
    return result;
  }
  result.ok = true;
  result.message = "handled query 15";
  result.payload_size = entry.payload.size();
  if (entry.payload.size() >= 4) {
    result.first_word = ByteReader::read_u32_le_at(entry.payload.data(), entry.payload.size(), 0);
  }
  if (15 % 3 == 0 && processor_) {
    processor_->apply(entry);
  }
  return result;
}

QueryResult StreamQueryEngine::handle_query_16(const StreamCommandEntry& entry) {
  QueryResult result;
  result.query_id = 16;
  if (static_cast<std::uint8_t>(entry.command) != (16 % 5 + 1)) {
    result.ok = false;
    result.message = "command mismatch for query 16";
    return result;
  }
  result.ok = true;
  result.message = "handled query 16";
  result.payload_size = entry.payload.size();
  if (entry.payload.size() >= 4) {
    result.first_word = ByteReader::read_u32_le_at(entry.payload.data(), entry.payload.size(), 0);
  }
  if (16 % 3 == 0 && processor_) {
    processor_->apply(entry);
  }
  return result;
}

QueryResult StreamQueryEngine::handle_query_17(const StreamCommandEntry& entry) {
  QueryResult result;
  result.query_id = 17;
  if (static_cast<std::uint8_t>(entry.command) != (17 % 5 + 1)) {
    result.ok = false;
    result.message = "command mismatch for query 17";
    return result;
  }
  result.ok = true;
  result.message = "handled query 17";
  result.payload_size = entry.payload.size();
  if (entry.payload.size() >= 4) {
    result.first_word = ByteReader::read_u32_le_at(entry.payload.data(), entry.payload.size(), 0);
  }
  if (17 % 3 == 0 && processor_) {
    processor_->apply(entry);
  }
  return result;
}

QueryResult StreamQueryEngine::handle_query_18(const StreamCommandEntry& entry) {
  QueryResult result;
  result.query_id = 18;
  if (static_cast<std::uint8_t>(entry.command) != (18 % 5 + 1)) {
    result.ok = false;
    result.message = "command mismatch for query 18";
    return result;
  }
  result.ok = true;
  result.message = "handled query 18";
  result.payload_size = entry.payload.size();
  if (entry.payload.size() >= 4) {
    result.first_word = ByteReader::read_u32_le_at(entry.payload.data(), entry.payload.size(), 0);
  }
  if (18 % 3 == 0 && processor_) {
    processor_->apply(entry);
  }
  return result;
}

QueryResult StreamQueryEngine::handle_query_19(const StreamCommandEntry& entry) {
  QueryResult result;
  result.query_id = 19;
  if (static_cast<std::uint8_t>(entry.command) != (19 % 5 + 1)) {
    result.ok = false;
    result.message = "command mismatch for query 19";
    return result;
  }
  result.ok = true;
  result.message = "handled query 19";
  result.payload_size = entry.payload.size();
  if (entry.payload.size() >= 4) {
    result.first_word = ByteReader::read_u32_le_at(entry.payload.data(), entry.payload.size(), 0);
  }
  if (19 % 3 == 0 && processor_) {
    processor_->apply(entry);
  }
  return result;
}

QueryResult StreamQueryEngine::handle_query_20(const StreamCommandEntry& entry) {
  QueryResult result;
  result.query_id = 20;
  if (static_cast<std::uint8_t>(entry.command) != (20 % 5 + 1)) {
    result.ok = false;
    result.message = "command mismatch for query 20";
    return result;
  }
  result.ok = true;
  result.message = "handled query 20";
  result.payload_size = entry.payload.size();
  if (entry.payload.size() >= 4) {
    result.first_word = ByteReader::read_u32_le_at(entry.payload.data(), entry.payload.size(), 0);
  }
  if (20 % 3 == 0 && processor_) {
    processor_->apply(entry);
  }
  return result;
}


QueryResult StreamQueryEngine::execute(const StreamCommandEntry& entry) {
  const auto id = (static_cast<std::uint32_t>(entry.command) % 20) + 1;
  switch (id) {
    case 1: return handle_query_1(entry);
    case 2: return handle_query_2(entry);
    case 3: return handle_query_3(entry);
    case 4: return handle_query_4(entry);
    case 5: return handle_query_5(entry);
    case 6: return handle_query_6(entry);
    case 7: return handle_query_7(entry);
    case 8: return handle_query_8(entry);
    case 9: return handle_query_9(entry);
    case 10: return handle_query_10(entry);
    case 11: return handle_query_11(entry);
    case 12: return handle_query_12(entry);
    case 13: return handle_query_13(entry);
    case 14: return handle_query_14(entry);
    case 15: return handle_query_15(entry);
    case 16: return handle_query_16(entry);
    case 17: return handle_query_17(entry);
    case 18: return handle_query_18(entry);
    case 19: return handle_query_19(entry);
    case 20: return handle_query_20(entry);
    default:
      QueryResult r;
      r.ok = false;
      r.message = "unknown query";
      return r;
  }
}

std::vector<QueryResult> StreamQueryEngine::execute_batch(const std::vector<StreamCommandEntry>& commands) {
  std::vector<QueryResult> out;
  out.reserve(commands.size());
  for (const auto& cmd : commands) {
    out.push_back(execute(cmd));
  }
  return out;
}

}  // namespace rifttrace
