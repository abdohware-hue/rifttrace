// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT
#pragma once

#include <cstdint>
#include <unordered_map>
#include <vector>

#include "rifttrace/archive_writer.hpp"
#include "rifttrace/format.hpp"

namespace rifttrace {

class ArchiveBuilder {
 public:
  ArchiveBuilder();
  ArchiveBuilder& step_1(std::uint32_t value);
  ArchiveBuilder& step_2(std::uint32_t value);
  ArchiveBuilder& step_3(std::uint32_t value);
  ArchiveBuilder& step_4(std::uint32_t value);
  ArchiveBuilder& step_5(std::uint32_t value);
  ArchiveBuilder& step_6(std::uint32_t value);
  ArchiveBuilder& step_7(std::uint32_t value);
  ArchiveBuilder& step_8(std::uint32_t value);
  ArchiveBuilder& step_9(std::uint32_t value);
  ArchiveBuilder& step_10(std::uint32_t value);
  ArchiveBuilder& step_11(std::uint32_t value);
  ArchiveBuilder& step_12(std::uint32_t value);
  ArchiveBuilder& step_13(std::uint32_t value);
  ArchiveBuilder& step_14(std::uint32_t value);
  ArchiveBuilder& step_15(std::uint32_t value);
  ArchiveBuilder& step_16(std::uint32_t value);
  ArchiveBuilder& step_17(std::uint32_t value);
  ArchiveBuilder& step_18(std::uint32_t value);
  ArchiveBuilder& step_19(std::uint32_t value);
  ArchiveBuilder& step_20(std::uint32_t value);
  ArchiveBuilder& step_21(std::uint32_t value);
  ArchiveBuilder& step_22(std::uint32_t value);
  ArchiveBuilder& step_23(std::uint32_t value);
  ArchiveBuilder& step_24(std::uint32_t value);
  ArchiveBuilder& step_25(std::uint32_t value);
  ArchiveBuilder& step_26(std::uint32_t value);
  ArchiveBuilder& step_27(std::uint32_t value);
  ArchiveBuilder& step_28(std::uint32_t value);
  ArchiveBuilder& step_29(std::uint32_t value);
  ArchiveBuilder& step_30(std::uint32_t value);
  ArchiveBuilder& with_strings(const StringTable& strings);
  ArchiveBuilder& with_object(const ObjectRecord& object);
  ArchiveBuilder& with_frame(const FrameRecord& frame);
  ArchiveBuilder& with_event(const EventRecord& event);
  ArchiveBuilder& with_alias(const AliasRecord& alias);
  Archive build();
 private:
  ArchiveWriter writer_;
  StringTable strings_;
  std::vector<std::uint8_t> data_;
  std::vector<std::uint8_t> scratch_;
  std::unordered_map<std::uint32_t, std::size_t> markers_;
};

}  // namespace rifttrace
