// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT
#include "rifttrace/record_builder.hpp"

namespace rifttrace {


DecodedRecord RecordBuilder::make_object_1(std::uint32_t base) {
  ObjectRecord obj;
  obj.object_id = base + 1;
  obj.name_index = 1 % 8;
  obj.symbol_index = (1 * 3) % 8;
  obj.pool_slot = 1 % 16;
  return obj;
}

DecodedRecord RecordBuilder::make_object_2(std::uint32_t base) {
  ObjectRecord obj;
  obj.object_id = base + 2;
  obj.name_index = 2 % 8;
  obj.symbol_index = (2 * 3) % 8;
  obj.pool_slot = 2 % 16;
  return obj;
}

DecodedRecord RecordBuilder::make_object_3(std::uint32_t base) {
  ObjectRecord obj;
  obj.object_id = base + 3;
  obj.name_index = 3 % 8;
  obj.symbol_index = (3 * 3) % 8;
  obj.pool_slot = 3 % 16;
  return obj;
}

DecodedRecord RecordBuilder::make_object_4(std::uint32_t base) {
  ObjectRecord obj;
  obj.object_id = base + 4;
  obj.name_index = 4 % 8;
  obj.symbol_index = (4 * 3) % 8;
  obj.pool_slot = 4 % 16;
  return obj;
}

DecodedRecord RecordBuilder::make_object_5(std::uint32_t base) {
  ObjectRecord obj;
  obj.object_id = base + 5;
  obj.name_index = 5 % 8;
  obj.symbol_index = (5 * 3) % 8;
  obj.pool_slot = 5 % 16;
  return obj;
}

DecodedRecord RecordBuilder::make_object_6(std::uint32_t base) {
  ObjectRecord obj;
  obj.object_id = base + 6;
  obj.name_index = 6 % 8;
  obj.symbol_index = (6 * 3) % 8;
  obj.pool_slot = 6 % 16;
  return obj;
}

DecodedRecord RecordBuilder::make_object_7(std::uint32_t base) {
  ObjectRecord obj;
  obj.object_id = base + 7;
  obj.name_index = 7 % 8;
  obj.symbol_index = (7 * 3) % 8;
  obj.pool_slot = 7 % 16;
  return obj;
}

DecodedRecord RecordBuilder::make_object_8(std::uint32_t base) {
  ObjectRecord obj;
  obj.object_id = base + 8;
  obj.name_index = 8 % 8;
  obj.symbol_index = (8 * 3) % 8;
  obj.pool_slot = 8 % 16;
  return obj;
}

DecodedRecord RecordBuilder::make_object_9(std::uint32_t base) {
  ObjectRecord obj;
  obj.object_id = base + 9;
  obj.name_index = 9 % 8;
  obj.symbol_index = (9 * 3) % 8;
  obj.pool_slot = 9 % 16;
  return obj;
}

DecodedRecord RecordBuilder::make_object_10(std::uint32_t base) {
  ObjectRecord obj;
  obj.object_id = base + 10;
  obj.name_index = 10 % 8;
  obj.symbol_index = (10 * 3) % 8;
  obj.pool_slot = 10 % 16;
  return obj;
}

DecodedRecord RecordBuilder::make_object_11(std::uint32_t base) {
  ObjectRecord obj;
  obj.object_id = base + 11;
  obj.name_index = 11 % 8;
  obj.symbol_index = (11 * 3) % 8;
  obj.pool_slot = 11 % 16;
  return obj;
}

DecodedRecord RecordBuilder::make_object_12(std::uint32_t base) {
  ObjectRecord obj;
  obj.object_id = base + 12;
  obj.name_index = 12 % 8;
  obj.symbol_index = (12 * 3) % 8;
  obj.pool_slot = 12 % 16;
  return obj;
}

DecodedRecord RecordBuilder::make_object_13(std::uint32_t base) {
  ObjectRecord obj;
  obj.object_id = base + 13;
  obj.name_index = 13 % 8;
  obj.symbol_index = (13 * 3) % 8;
  obj.pool_slot = 13 % 16;
  return obj;
}

DecodedRecord RecordBuilder::make_object_14(std::uint32_t base) {
  ObjectRecord obj;
  obj.object_id = base + 14;
  obj.name_index = 14 % 8;
  obj.symbol_index = (14 * 3) % 8;
  obj.pool_slot = 14 % 16;
  return obj;
}

DecodedRecord RecordBuilder::make_object_15(std::uint32_t base) {
  ObjectRecord obj;
  obj.object_id = base + 15;
  obj.name_index = 15 % 8;
  obj.symbol_index = (15 * 3) % 8;
  obj.pool_slot = 15 % 16;
  return obj;
}

DecodedRecord RecordBuilder::make_object_16(std::uint32_t base) {
  ObjectRecord obj;
  obj.object_id = base + 16;
  obj.name_index = 16 % 8;
  obj.symbol_index = (16 * 3) % 8;
  obj.pool_slot = 16 % 16;
  return obj;
}

DecodedRecord RecordBuilder::make_object_17(std::uint32_t base) {
  ObjectRecord obj;
  obj.object_id = base + 17;
  obj.name_index = 17 % 8;
  obj.symbol_index = (17 * 3) % 8;
  obj.pool_slot = 17 % 16;
  return obj;
}

DecodedRecord RecordBuilder::make_object_18(std::uint32_t base) {
  ObjectRecord obj;
  obj.object_id = base + 18;
  obj.name_index = 18 % 8;
  obj.symbol_index = (18 * 3) % 8;
  obj.pool_slot = 18 % 16;
  return obj;
}

DecodedRecord RecordBuilder::make_object_19(std::uint32_t base) {
  ObjectRecord obj;
  obj.object_id = base + 19;
  obj.name_index = 19 % 8;
  obj.symbol_index = (19 * 3) % 8;
  obj.pool_slot = 19 % 16;
  return obj;
}

DecodedRecord RecordBuilder::make_object_20(std::uint32_t base) {
  ObjectRecord obj;
  obj.object_id = base + 20;
  obj.name_index = 20 % 8;
  obj.symbol_index = (20 * 3) % 8;
  obj.pool_slot = 20 % 16;
  return obj;
}

DecodedRecord RecordBuilder::make_object_21(std::uint32_t base) {
  ObjectRecord obj;
  obj.object_id = base + 21;
  obj.name_index = 21 % 8;
  obj.symbol_index = (21 * 3) % 8;
  obj.pool_slot = 21 % 16;
  return obj;
}

DecodedRecord RecordBuilder::make_object_22(std::uint32_t base) {
  ObjectRecord obj;
  obj.object_id = base + 22;
  obj.name_index = 22 % 8;
  obj.symbol_index = (22 * 3) % 8;
  obj.pool_slot = 22 % 16;
  return obj;
}

DecodedRecord RecordBuilder::make_object_23(std::uint32_t base) {
  ObjectRecord obj;
  obj.object_id = base + 23;
  obj.name_index = 23 % 8;
  obj.symbol_index = (23 * 3) % 8;
  obj.pool_slot = 23 % 16;
  return obj;
}

DecodedRecord RecordBuilder::make_object_24(std::uint32_t base) {
  ObjectRecord obj;
  obj.object_id = base + 24;
  obj.name_index = 24 % 8;
  obj.symbol_index = (24 * 3) % 8;
  obj.pool_slot = 24 % 16;
  return obj;
}

DecodedRecord RecordBuilder::make_object_25(std::uint32_t base) {
  ObjectRecord obj;
  obj.object_id = base + 25;
  obj.name_index = 25 % 8;
  obj.symbol_index = (25 * 3) % 8;
  obj.pool_slot = 25 % 16;
  return obj;
}

DecodedRecord RecordBuilder::make_object_26(std::uint32_t base) {
  ObjectRecord obj;
  obj.object_id = base + 26;
  obj.name_index = 26 % 8;
  obj.symbol_index = (26 * 3) % 8;
  obj.pool_slot = 26 % 16;
  return obj;
}

DecodedRecord RecordBuilder::make_object_27(std::uint32_t base) {
  ObjectRecord obj;
  obj.object_id = base + 27;
  obj.name_index = 27 % 8;
  obj.symbol_index = (27 * 3) % 8;
  obj.pool_slot = 27 % 16;
  return obj;
}

DecodedRecord RecordBuilder::make_object_28(std::uint32_t base) {
  ObjectRecord obj;
  obj.object_id = base + 28;
  obj.name_index = 28 % 8;
  obj.symbol_index = (28 * 3) % 8;
  obj.pool_slot = 28 % 16;
  return obj;
}

DecodedRecord RecordBuilder::make_object_29(std::uint32_t base) {
  ObjectRecord obj;
  obj.object_id = base + 29;
  obj.name_index = 29 % 8;
  obj.symbol_index = (29 * 3) % 8;
  obj.pool_slot = 29 % 16;
  return obj;
}

DecodedRecord RecordBuilder::make_object_30(std::uint32_t base) {
  ObjectRecord obj;
  obj.object_id = base + 30;
  obj.name_index = 30 % 8;
  obj.symbol_index = (30 * 3) % 8;
  obj.pool_slot = 30 % 16;
  return obj;
}

DecodedRecord RecordBuilder::make_object_31(std::uint32_t base) {
  ObjectRecord obj;
  obj.object_id = base + 31;
  obj.name_index = 31 % 8;
  obj.symbol_index = (31 * 3) % 8;
  obj.pool_slot = 31 % 16;
  return obj;
}

DecodedRecord RecordBuilder::make_object_32(std::uint32_t base) {
  ObjectRecord obj;
  obj.object_id = base + 32;
  obj.name_index = 32 % 8;
  obj.symbol_index = (32 * 3) % 8;
  obj.pool_slot = 32 % 16;
  return obj;
}

DecodedRecord RecordBuilder::make_object_33(std::uint32_t base) {
  ObjectRecord obj;
  obj.object_id = base + 33;
  obj.name_index = 33 % 8;
  obj.symbol_index = (33 * 3) % 8;
  obj.pool_slot = 33 % 16;
  return obj;
}

DecodedRecord RecordBuilder::make_object_34(std::uint32_t base) {
  ObjectRecord obj;
  obj.object_id = base + 34;
  obj.name_index = 34 % 8;
  obj.symbol_index = (34 * 3) % 8;
  obj.pool_slot = 34 % 16;
  return obj;
}

DecodedRecord RecordBuilder::make_object_35(std::uint32_t base) {
  ObjectRecord obj;
  obj.object_id = base + 35;
  obj.name_index = 35 % 8;
  obj.symbol_index = (35 * 3) % 8;
  obj.pool_slot = 35 % 16;
  return obj;
}

DecodedRecord RecordBuilder::make_object_36(std::uint32_t base) {
  ObjectRecord obj;
  obj.object_id = base + 36;
  obj.name_index = 36 % 8;
  obj.symbol_index = (36 * 3) % 8;
  obj.pool_slot = 36 % 16;
  return obj;
}

DecodedRecord RecordBuilder::make_object_37(std::uint32_t base) {
  ObjectRecord obj;
  obj.object_id = base + 37;
  obj.name_index = 37 % 8;
  obj.symbol_index = (37 * 3) % 8;
  obj.pool_slot = 37 % 16;
  return obj;
}

DecodedRecord RecordBuilder::make_object_38(std::uint32_t base) {
  ObjectRecord obj;
  obj.object_id = base + 38;
  obj.name_index = 38 % 8;
  obj.symbol_index = (38 * 3) % 8;
  obj.pool_slot = 38 % 16;
  return obj;
}

DecodedRecord RecordBuilder::make_object_39(std::uint32_t base) {
  ObjectRecord obj;
  obj.object_id = base + 39;
  obj.name_index = 39 % 8;
  obj.symbol_index = (39 * 3) % 8;
  obj.pool_slot = 39 % 16;
  return obj;
}

DecodedRecord RecordBuilder::make_object_40(std::uint32_t base) {
  ObjectRecord obj;
  obj.object_id = base + 40;
  obj.name_index = 40 % 8;
  obj.symbol_index = (40 * 3) % 8;
  obj.pool_slot = 40 % 16;
  return obj;
}


RecordBatch RecordBuilder::build_batch(std::uint32_t object_count) {
  RecordBatch batch;
  for (std::uint32_t i = 0; i < object_count && i < 40; ++i) {
    switch ((i % 40) + 1) {
      case 1: batch.decoded.push_back(make_object_1(i * 10)); break;
      case 2: batch.decoded.push_back(make_object_2(i * 10)); break;
      case 3: batch.decoded.push_back(make_object_3(i * 10)); break;
      case 4: batch.decoded.push_back(make_object_4(i * 10)); break;
      case 5: batch.decoded.push_back(make_object_5(i * 10)); break;
      case 6: batch.decoded.push_back(make_object_6(i * 10)); break;
      case 7: batch.decoded.push_back(make_object_7(i * 10)); break;
      case 8: batch.decoded.push_back(make_object_8(i * 10)); break;
      case 9: batch.decoded.push_back(make_object_9(i * 10)); break;
      case 10: batch.decoded.push_back(make_object_10(i * 10)); break;
      case 11: batch.decoded.push_back(make_object_11(i * 10)); break;
      case 12: batch.decoded.push_back(make_object_12(i * 10)); break;
      case 13: batch.decoded.push_back(make_object_13(i * 10)); break;
      case 14: batch.decoded.push_back(make_object_14(i * 10)); break;
      case 15: batch.decoded.push_back(make_object_15(i * 10)); break;
      case 16: batch.decoded.push_back(make_object_16(i * 10)); break;
      case 17: batch.decoded.push_back(make_object_17(i * 10)); break;
      case 18: batch.decoded.push_back(make_object_18(i * 10)); break;
      case 19: batch.decoded.push_back(make_object_19(i * 10)); break;
      case 20: batch.decoded.push_back(make_object_20(i * 10)); break;
      case 21: batch.decoded.push_back(make_object_21(i * 10)); break;
      case 22: batch.decoded.push_back(make_object_22(i * 10)); break;
      case 23: batch.decoded.push_back(make_object_23(i * 10)); break;
      case 24: batch.decoded.push_back(make_object_24(i * 10)); break;
      case 25: batch.decoded.push_back(make_object_25(i * 10)); break;
      case 26: batch.decoded.push_back(make_object_26(i * 10)); break;
      case 27: batch.decoded.push_back(make_object_27(i * 10)); break;
      case 28: batch.decoded.push_back(make_object_28(i * 10)); break;
      case 29: batch.decoded.push_back(make_object_29(i * 10)); break;
      case 30: batch.decoded.push_back(make_object_30(i * 10)); break;
      case 31: batch.decoded.push_back(make_object_31(i * 10)); break;
      case 32: batch.decoded.push_back(make_object_32(i * 10)); break;
      case 33: batch.decoded.push_back(make_object_33(i * 10)); break;
      case 34: batch.decoded.push_back(make_object_34(i * 10)); break;
      case 35: batch.decoded.push_back(make_object_35(i * 10)); break;
      case 36: batch.decoded.push_back(make_object_36(i * 10)); break;
      case 37: batch.decoded.push_back(make_object_37(i * 10)); break;
      case 38: batch.decoded.push_back(make_object_38(i * 10)); break;
      case 39: batch.decoded.push_back(make_object_39(i * 10)); break;
      case 40: batch.decoded.push_back(make_object_40(i * 10)); break;
      default: break;
    }
  }
  return batch;
}

std::vector<std::uint8_t> RecordBuilder::serialize_data_section(const RecordBatch& batch) {{
  std::vector<std::uint8_t> out;
  out.push_back(static_cast<std::uint8_t>(batch.decoded.size() & 0xff));
  return out;
}}

}}  // namespace rifttrace
