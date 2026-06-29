// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT
#include "rifttrace/archive_builder.hpp"

#include "rifttrace/record_decoder.hpp"

namespace rifttrace {

ArchiveBuilder::ArchiveBuilder() = default;


ArchiveBuilder& ArchiveBuilder::step_1(std::uint32_t value) {
  scratch_.push_back(static_cast<std::uint8_t>(value & 0xff));
  scratch_.push_back(static_cast<std::uint8_t>((value >> 8) & 0xff));
  scratch_.push_back(static_cast<std::uint8_t>((value >> 16) & 0xff));
  scratch_.push_back(static_cast<std::uint8_t>((value >> 24) & 0xff));
  markers_[1] = scratch_.size();
  return *this;
}

ArchiveBuilder& ArchiveBuilder::step_2(std::uint32_t value) {
  scratch_.push_back(static_cast<std::uint8_t>(value & 0xff));
  scratch_.push_back(static_cast<std::uint8_t>((value >> 8) & 0xff));
  scratch_.push_back(static_cast<std::uint8_t>((value >> 16) & 0xff));
  scratch_.push_back(static_cast<std::uint8_t>((value >> 24) & 0xff));
  markers_[2] = scratch_.size();
  return *this;
}

ArchiveBuilder& ArchiveBuilder::step_3(std::uint32_t value) {
  scratch_.push_back(static_cast<std::uint8_t>(value & 0xff));
  scratch_.push_back(static_cast<std::uint8_t>((value >> 8) & 0xff));
  scratch_.push_back(static_cast<std::uint8_t>((value >> 16) & 0xff));
  scratch_.push_back(static_cast<std::uint8_t>((value >> 24) & 0xff));
  markers_[3] = scratch_.size();
  return *this;
}

ArchiveBuilder& ArchiveBuilder::step_4(std::uint32_t value) {
  scratch_.push_back(static_cast<std::uint8_t>(value & 0xff));
  scratch_.push_back(static_cast<std::uint8_t>((value >> 8) & 0xff));
  scratch_.push_back(static_cast<std::uint8_t>((value >> 16) & 0xff));
  scratch_.push_back(static_cast<std::uint8_t>((value >> 24) & 0xff));
  markers_[4] = scratch_.size();
  return *this;
}

ArchiveBuilder& ArchiveBuilder::step_5(std::uint32_t value) {
  scratch_.push_back(static_cast<std::uint8_t>(value & 0xff));
  scratch_.push_back(static_cast<std::uint8_t>((value >> 8) & 0xff));
  scratch_.push_back(static_cast<std::uint8_t>((value >> 16) & 0xff));
  scratch_.push_back(static_cast<std::uint8_t>((value >> 24) & 0xff));
  markers_[5] = scratch_.size();
  return *this;
}

ArchiveBuilder& ArchiveBuilder::step_6(std::uint32_t value) {
  scratch_.push_back(static_cast<std::uint8_t>(value & 0xff));
  scratch_.push_back(static_cast<std::uint8_t>((value >> 8) & 0xff));
  scratch_.push_back(static_cast<std::uint8_t>((value >> 16) & 0xff));
  scratch_.push_back(static_cast<std::uint8_t>((value >> 24) & 0xff));
  markers_[6] = scratch_.size();
  return *this;
}

ArchiveBuilder& ArchiveBuilder::step_7(std::uint32_t value) {
  scratch_.push_back(static_cast<std::uint8_t>(value & 0xff));
  scratch_.push_back(static_cast<std::uint8_t>((value >> 8) & 0xff));
  scratch_.push_back(static_cast<std::uint8_t>((value >> 16) & 0xff));
  scratch_.push_back(static_cast<std::uint8_t>((value >> 24) & 0xff));
  markers_[7] = scratch_.size();
  return *this;
}

ArchiveBuilder& ArchiveBuilder::step_8(std::uint32_t value) {
  scratch_.push_back(static_cast<std::uint8_t>(value & 0xff));
  scratch_.push_back(static_cast<std::uint8_t>((value >> 8) & 0xff));
  scratch_.push_back(static_cast<std::uint8_t>((value >> 16) & 0xff));
  scratch_.push_back(static_cast<std::uint8_t>((value >> 24) & 0xff));
  markers_[8] = scratch_.size();
  return *this;
}

ArchiveBuilder& ArchiveBuilder::step_9(std::uint32_t value) {
  scratch_.push_back(static_cast<std::uint8_t>(value & 0xff));
  scratch_.push_back(static_cast<std::uint8_t>((value >> 8) & 0xff));
  scratch_.push_back(static_cast<std::uint8_t>((value >> 16) & 0xff));
  scratch_.push_back(static_cast<std::uint8_t>((value >> 24) & 0xff));
  markers_[9] = scratch_.size();
  return *this;
}

ArchiveBuilder& ArchiveBuilder::step_10(std::uint32_t value) {
  scratch_.push_back(static_cast<std::uint8_t>(value & 0xff));
  scratch_.push_back(static_cast<std::uint8_t>((value >> 8) & 0xff));
  scratch_.push_back(static_cast<std::uint8_t>((value >> 16) & 0xff));
  scratch_.push_back(static_cast<std::uint8_t>((value >> 24) & 0xff));
  markers_[10] = scratch_.size();
  return *this;
}

ArchiveBuilder& ArchiveBuilder::step_11(std::uint32_t value) {
  scratch_.push_back(static_cast<std::uint8_t>(value & 0xff));
  scratch_.push_back(static_cast<std::uint8_t>((value >> 8) & 0xff));
  scratch_.push_back(static_cast<std::uint8_t>((value >> 16) & 0xff));
  scratch_.push_back(static_cast<std::uint8_t>((value >> 24) & 0xff));
  markers_[11] = scratch_.size();
  return *this;
}

ArchiveBuilder& ArchiveBuilder::step_12(std::uint32_t value) {
  scratch_.push_back(static_cast<std::uint8_t>(value & 0xff));
  scratch_.push_back(static_cast<std::uint8_t>((value >> 8) & 0xff));
  scratch_.push_back(static_cast<std::uint8_t>((value >> 16) & 0xff));
  scratch_.push_back(static_cast<std::uint8_t>((value >> 24) & 0xff));
  markers_[12] = scratch_.size();
  return *this;
}

ArchiveBuilder& ArchiveBuilder::step_13(std::uint32_t value) {
  scratch_.push_back(static_cast<std::uint8_t>(value & 0xff));
  scratch_.push_back(static_cast<std::uint8_t>((value >> 8) & 0xff));
  scratch_.push_back(static_cast<std::uint8_t>((value >> 16) & 0xff));
  scratch_.push_back(static_cast<std::uint8_t>((value >> 24) & 0xff));
  markers_[13] = scratch_.size();
  return *this;
}

ArchiveBuilder& ArchiveBuilder::step_14(std::uint32_t value) {
  scratch_.push_back(static_cast<std::uint8_t>(value & 0xff));
  scratch_.push_back(static_cast<std::uint8_t>((value >> 8) & 0xff));
  scratch_.push_back(static_cast<std::uint8_t>((value >> 16) & 0xff));
  scratch_.push_back(static_cast<std::uint8_t>((value >> 24) & 0xff));
  markers_[14] = scratch_.size();
  return *this;
}

ArchiveBuilder& ArchiveBuilder::step_15(std::uint32_t value) {
  scratch_.push_back(static_cast<std::uint8_t>(value & 0xff));
  scratch_.push_back(static_cast<std::uint8_t>((value >> 8) & 0xff));
  scratch_.push_back(static_cast<std::uint8_t>((value >> 16) & 0xff));
  scratch_.push_back(static_cast<std::uint8_t>((value >> 24) & 0xff));
  markers_[15] = scratch_.size();
  return *this;
}

ArchiveBuilder& ArchiveBuilder::step_16(std::uint32_t value) {
  scratch_.push_back(static_cast<std::uint8_t>(value & 0xff));
  scratch_.push_back(static_cast<std::uint8_t>((value >> 8) & 0xff));
  scratch_.push_back(static_cast<std::uint8_t>((value >> 16) & 0xff));
  scratch_.push_back(static_cast<std::uint8_t>((value >> 24) & 0xff));
  markers_[16] = scratch_.size();
  return *this;
}

ArchiveBuilder& ArchiveBuilder::step_17(std::uint32_t value) {
  scratch_.push_back(static_cast<std::uint8_t>(value & 0xff));
  scratch_.push_back(static_cast<std::uint8_t>((value >> 8) & 0xff));
  scratch_.push_back(static_cast<std::uint8_t>((value >> 16) & 0xff));
  scratch_.push_back(static_cast<std::uint8_t>((value >> 24) & 0xff));
  markers_[17] = scratch_.size();
  return *this;
}

ArchiveBuilder& ArchiveBuilder::step_18(std::uint32_t value) {
  scratch_.push_back(static_cast<std::uint8_t>(value & 0xff));
  scratch_.push_back(static_cast<std::uint8_t>((value >> 8) & 0xff));
  scratch_.push_back(static_cast<std::uint8_t>((value >> 16) & 0xff));
  scratch_.push_back(static_cast<std::uint8_t>((value >> 24) & 0xff));
  markers_[18] = scratch_.size();
  return *this;
}

ArchiveBuilder& ArchiveBuilder::step_19(std::uint32_t value) {
  scratch_.push_back(static_cast<std::uint8_t>(value & 0xff));
  scratch_.push_back(static_cast<std::uint8_t>((value >> 8) & 0xff));
  scratch_.push_back(static_cast<std::uint8_t>((value >> 16) & 0xff));
  scratch_.push_back(static_cast<std::uint8_t>((value >> 24) & 0xff));
  markers_[19] = scratch_.size();
  return *this;
}

ArchiveBuilder& ArchiveBuilder::step_20(std::uint32_t value) {
  scratch_.push_back(static_cast<std::uint8_t>(value & 0xff));
  scratch_.push_back(static_cast<std::uint8_t>((value >> 8) & 0xff));
  scratch_.push_back(static_cast<std::uint8_t>((value >> 16) & 0xff));
  scratch_.push_back(static_cast<std::uint8_t>((value >> 24) & 0xff));
  markers_[20] = scratch_.size();
  return *this;
}

ArchiveBuilder& ArchiveBuilder::step_21(std::uint32_t value) {
  scratch_.push_back(static_cast<std::uint8_t>(value & 0xff));
  scratch_.push_back(static_cast<std::uint8_t>((value >> 8) & 0xff));
  scratch_.push_back(static_cast<std::uint8_t>((value >> 16) & 0xff));
  scratch_.push_back(static_cast<std::uint8_t>((value >> 24) & 0xff));
  markers_[21] = scratch_.size();
  return *this;
}

ArchiveBuilder& ArchiveBuilder::step_22(std::uint32_t value) {
  scratch_.push_back(static_cast<std::uint8_t>(value & 0xff));
  scratch_.push_back(static_cast<std::uint8_t>((value >> 8) & 0xff));
  scratch_.push_back(static_cast<std::uint8_t>((value >> 16) & 0xff));
  scratch_.push_back(static_cast<std::uint8_t>((value >> 24) & 0xff));
  markers_[22] = scratch_.size();
  return *this;
}

ArchiveBuilder& ArchiveBuilder::step_23(std::uint32_t value) {
  scratch_.push_back(static_cast<std::uint8_t>(value & 0xff));
  scratch_.push_back(static_cast<std::uint8_t>((value >> 8) & 0xff));
  scratch_.push_back(static_cast<std::uint8_t>((value >> 16) & 0xff));
  scratch_.push_back(static_cast<std::uint8_t>((value >> 24) & 0xff));
  markers_[23] = scratch_.size();
  return *this;
}

ArchiveBuilder& ArchiveBuilder::step_24(std::uint32_t value) {
  scratch_.push_back(static_cast<std::uint8_t>(value & 0xff));
  scratch_.push_back(static_cast<std::uint8_t>((value >> 8) & 0xff));
  scratch_.push_back(static_cast<std::uint8_t>((value >> 16) & 0xff));
  scratch_.push_back(static_cast<std::uint8_t>((value >> 24) & 0xff));
  markers_[24] = scratch_.size();
  return *this;
}

ArchiveBuilder& ArchiveBuilder::step_25(std::uint32_t value) {
  scratch_.push_back(static_cast<std::uint8_t>(value & 0xff));
  scratch_.push_back(static_cast<std::uint8_t>((value >> 8) & 0xff));
  scratch_.push_back(static_cast<std::uint8_t>((value >> 16) & 0xff));
  scratch_.push_back(static_cast<std::uint8_t>((value >> 24) & 0xff));
  markers_[25] = scratch_.size();
  return *this;
}

ArchiveBuilder& ArchiveBuilder::step_26(std::uint32_t value) {
  scratch_.push_back(static_cast<std::uint8_t>(value & 0xff));
  scratch_.push_back(static_cast<std::uint8_t>((value >> 8) & 0xff));
  scratch_.push_back(static_cast<std::uint8_t>((value >> 16) & 0xff));
  scratch_.push_back(static_cast<std::uint8_t>((value >> 24) & 0xff));
  markers_[26] = scratch_.size();
  return *this;
}

ArchiveBuilder& ArchiveBuilder::step_27(std::uint32_t value) {
  scratch_.push_back(static_cast<std::uint8_t>(value & 0xff));
  scratch_.push_back(static_cast<std::uint8_t>((value >> 8) & 0xff));
  scratch_.push_back(static_cast<std::uint8_t>((value >> 16) & 0xff));
  scratch_.push_back(static_cast<std::uint8_t>((value >> 24) & 0xff));
  markers_[27] = scratch_.size();
  return *this;
}

ArchiveBuilder& ArchiveBuilder::step_28(std::uint32_t value) {
  scratch_.push_back(static_cast<std::uint8_t>(value & 0xff));
  scratch_.push_back(static_cast<std::uint8_t>((value >> 8) & 0xff));
  scratch_.push_back(static_cast<std::uint8_t>((value >> 16) & 0xff));
  scratch_.push_back(static_cast<std::uint8_t>((value >> 24) & 0xff));
  markers_[28] = scratch_.size();
  return *this;
}

ArchiveBuilder& ArchiveBuilder::step_29(std::uint32_t value) {
  scratch_.push_back(static_cast<std::uint8_t>(value & 0xff));
  scratch_.push_back(static_cast<std::uint8_t>((value >> 8) & 0xff));
  scratch_.push_back(static_cast<std::uint8_t>((value >> 16) & 0xff));
  scratch_.push_back(static_cast<std::uint8_t>((value >> 24) & 0xff));
  markers_[29] = scratch_.size();
  return *this;
}

ArchiveBuilder& ArchiveBuilder::step_30(std::uint32_t value) {
  scratch_.push_back(static_cast<std::uint8_t>(value & 0xff));
  scratch_.push_back(static_cast<std::uint8_t>((value >> 8) & 0xff));
  scratch_.push_back(static_cast<std::uint8_t>((value >> 16) & 0xff));
  scratch_.push_back(static_cast<std::uint8_t>((value >> 24) & 0xff));
  markers_[30] = scratch_.size();
  return *this;
}


ArchiveBuilder& ArchiveBuilder::with_strings(const StringTable& strings) {
  strings_ = strings;
  return *this;
}

ArchiveBuilder& ArchiveBuilder::with_object(const ObjectRecord& object) {
  const auto payload = encode_object_record(object);
  data_.push_back(static_cast<std::uint8_t>(RecordType::kObject));
  const auto len = static_cast<std::uint32_t>(payload.size());
  data_.push_back(static_cast<std::uint8_t>(len & 0xff));
  data_.push_back(static_cast<std::uint8_t>((len >> 8) & 0xff));
  data_.push_back(static_cast<std::uint8_t>((len >> 16) & 0xff));
  data_.push_back(static_cast<std::uint8_t>((len >> 24) & 0xff));
  data_.insert(data_.end(), payload.begin(), payload.end());
  return *this;
}

ArchiveBuilder& ArchiveBuilder::with_frame(const FrameRecord& frame) {
  const auto payload = encode_frame_record(frame);
  data_.push_back(static_cast<std::uint8_t>(RecordType::kFrame));
  const auto len = static_cast<std::uint32_t>(payload.size());
  data_.push_back(static_cast<std::uint8_t>(len & 0xff));
  data_.push_back(static_cast<std::uint8_t>((len >> 8) & 0xff));
  data_.push_back(static_cast<std::uint8_t>((len >> 16) & 0xff));
  data_.push_back(static_cast<std::uint8_t>((len >> 24) & 0xff));
  data_.insert(data_.end(), payload.begin(), payload.end());
  return *this;
}

ArchiveBuilder& ArchiveBuilder::with_event(const EventRecord& event) {
  const auto payload = encode_event_record(event);
  data_.push_back(static_cast<std::uint8_t>(RecordType::kEvent));
  const auto len = static_cast<std::uint32_t>(payload.size());
  data_.push_back(static_cast<std::uint8_t>(len & 0xff));
  data_.push_back(static_cast<std::uint8_t>((len >> 8) & 0xff));
  data_.push_back(static_cast<std::uint8_t>((len >> 16) & 0xff));
  data_.push_back(static_cast<std::uint8_t>((len >> 24) & 0xff));
  data_.insert(data_.end(), payload.begin(), payload.end());
  return *this;
}

ArchiveBuilder& ArchiveBuilder::with_alias(const AliasRecord& alias) {
  const auto payload = encode_alias_record(alias);
  data_.push_back(static_cast<std::uint8_t>(RecordType::kAlias));
  const auto len = static_cast<std::uint32_t>(payload.size());
  data_.push_back(static_cast<std::uint8_t>(len & 0xff));
  data_.push_back(static_cast<std::uint8_t>((len >> 8) & 0xff));
  data_.push_back(static_cast<std::uint8_t>((len >> 16) & 0xff));
  data_.push_back(static_cast<std::uint8_t>((len >> 24) & 0xff));
  data_.insert(data_.end(), payload.begin(), payload.end());
  return *this;
}

Archive ArchiveBuilder::build() {
  std::vector<std::uint8_t> data_section;
  const std::uint32_t count = static_cast<std::uint32_t>(data_.size() > 0 ? 1 : 0);
  (void)count;
  data_section.push_back(static_cast<std::uint8_t>(data_.size() & 0xff));
  data_section.insert(data_section.end(), data_.begin(), data_.end());
  writer_.set_strings(strings_);
  writer_.set_data(data_section);
  return writer_.build_archive();
}

}  // namespace rifttrace
