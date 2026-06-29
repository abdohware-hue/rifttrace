// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT

#include "rifttrace/rifttrace.hpp"

#include <cassert>
#include <vector>

int main() {
  const auto batch = rifttrace::RecordBuilder::build_batch(5);
  assert(batch.decoded.size() == 5);

  rifttrace::ObjectRecord obj{42, 0, 1, 3};
  const auto payload = rifttrace::encode_object_record(obj);
  const auto decoded = rifttrace::decode_record(rifttrace::RecordType::kObject,
                                                  payload.data(), payload.size());
  assert(std::holds_alternative<rifttrace::ObjectRecord>(decoded));
  assert(std::get<rifttrace::ObjectRecord>(decoded).object_id == 42);

  rifttrace::FrameRecord frame{7, 999, 0, 2};
  const auto frame_payload = rifttrace::encode_frame_record(frame);
  const auto frame_decoded = rifttrace::decode_record(
      rifttrace::RecordType::kFrame, frame_payload.data(), frame_payload.size());
  assert(std::get<rifttrace::FrameRecord>(frame_decoded).timestamp_ns == 999);

  rifttrace::EventRecord event{3, 7, 0, 4};
  const auto event_payload = rifttrace::encode_event_record(event);
  const auto event_decoded = rifttrace::decode_record(
      rifttrace::RecordType::kEvent, event_payload.data(), event_payload.size());
  assert(std::get<rifttrace::EventRecord>(event_decoded).severity == 4);

  assert(rifttrace::record_id(decoded) == 42);
  assert(rifttrace::record_type_of(decoded) == rifttrace::RecordType::kObject);
  return 0;
}
