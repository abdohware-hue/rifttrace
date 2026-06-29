// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT
#pragma once

#include <cstdint>
#include <vector>

#include "rifttrace/format.hpp"
#include "rifttrace/record.hpp"

namespace rifttrace {

class RecordBuilder {
 public:
  static DecodedRecord make_object_1(std::uint32_t base);
  static DecodedRecord make_object_2(std::uint32_t base);
  static DecodedRecord make_object_3(std::uint32_t base);
  static DecodedRecord make_object_4(std::uint32_t base);
  static DecodedRecord make_object_5(std::uint32_t base);
  static DecodedRecord make_object_6(std::uint32_t base);
  static DecodedRecord make_object_7(std::uint32_t base);
  static DecodedRecord make_object_8(std::uint32_t base);
  static DecodedRecord make_object_9(std::uint32_t base);
  static DecodedRecord make_object_10(std::uint32_t base);
  static DecodedRecord make_object_11(std::uint32_t base);
  static DecodedRecord make_object_12(std::uint32_t base);
  static DecodedRecord make_object_13(std::uint32_t base);
  static DecodedRecord make_object_14(std::uint32_t base);
  static DecodedRecord make_object_15(std::uint32_t base);
  static DecodedRecord make_object_16(std::uint32_t base);
  static DecodedRecord make_object_17(std::uint32_t base);
  static DecodedRecord make_object_18(std::uint32_t base);
  static DecodedRecord make_object_19(std::uint32_t base);
  static DecodedRecord make_object_20(std::uint32_t base);
  static DecodedRecord make_object_21(std::uint32_t base);
  static DecodedRecord make_object_22(std::uint32_t base);
  static DecodedRecord make_object_23(std::uint32_t base);
  static DecodedRecord make_object_24(std::uint32_t base);
  static DecodedRecord make_object_25(std::uint32_t base);
  static DecodedRecord make_object_26(std::uint32_t base);
  static DecodedRecord make_object_27(std::uint32_t base);
  static DecodedRecord make_object_28(std::uint32_t base);
  static DecodedRecord make_object_29(std::uint32_t base);
  static DecodedRecord make_object_30(std::uint32_t base);
  static DecodedRecord make_object_31(std::uint32_t base);
  static DecodedRecord make_object_32(std::uint32_t base);
  static DecodedRecord make_object_33(std::uint32_t base);
  static DecodedRecord make_object_34(std::uint32_t base);
  static DecodedRecord make_object_35(std::uint32_t base);
  static DecodedRecord make_object_36(std::uint32_t base);
  static DecodedRecord make_object_37(std::uint32_t base);
  static DecodedRecord make_object_38(std::uint32_t base);
  static DecodedRecord make_object_39(std::uint32_t base);
  static DecodedRecord make_object_40(std::uint32_t base);
  static RecordBatch build_batch(std::uint32_t object_count);
  static std::vector<std::uint8_t> serialize_data_section(const RecordBatch& batch);
};

}  // namespace rifttrace
