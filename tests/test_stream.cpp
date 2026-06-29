// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT

#include "rifttrace/rifttrace.hpp"

#include <cassert>
#include <vector>

int main() {
  rifttrace::StringTable strings;
  strings.intern("stream.object");
  strings.intern("SymStream");

  rifttrace::TelemetryModel model;
  model.strings = strings;
  model.symbols.rebuild_from_strings(model.strings.storage());

  rifttrace::StreamProcessor processor(&model);

  std::vector<std::uint8_t> append_payload;
  append_payload.push_back(static_cast<std::uint8_t>(rifttrace::RecordType::kObject));
  const auto obj = rifttrace::encode_object_record({5, 0, 1, 2});
  const auto len = rifttrace::write_u32_le(static_cast<std::uint32_t>(obj.size()));
  append_payload.insert(append_payload.end(), len.begin(), len.end());
  append_payload.insert(append_payload.end(), obj.begin(), obj.end());

  rifttrace::StreamCommandEntry append;
  append.command = rifttrace::StreamCommand::kAppendRecord;
  append.payload = append_payload;
  processor.apply(append);
  processor.finalize();
  assert(processor.is_finalized());
  assert(model.records.decoded.size() == 1);

  std::vector<std::uint8_t> stream_bytes;
  const auto count = rifttrace::write_u32_le(1);
  stream_bytes.insert(stream_bytes.end(), count.begin(), count.end());
  stream_bytes.push_back(static_cast<std::uint8_t>(rifttrace::StreamCommand::kFinalize));
  const auto zero = rifttrace::write_u32_le(0);
  stream_bytes.insert(stream_bytes.end(), zero.begin(), zero.end());

  const auto commands =
      rifttrace::parse_stream_commands(stream_bytes.data(), stream_bytes.size());
  assert(commands.size() == 1);

  rifttrace::StreamQueryEngine query(&processor);
  const auto result = query.execute(commands.front());
  assert(result.query_id != 0);

  return 0;
}
