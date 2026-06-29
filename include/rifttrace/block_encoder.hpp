// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT
#pragma once

#include <cstdint>
#include <vector>

#include "rifttrace/format.hpp"

namespace rifttrace {

struct EncodedBlock {
  std::uint32_t block_id = 0;
  BlockCodec codec = BlockCodec::kRaw;
  std::uint32_t compressed_size = 0;
  std::uint32_t uncompressed_size = 0;
  std::vector<std::uint8_t> compressed;
};

class BlockEncoder {
 public:
  static EncodedBlock encode_block_1(const std::uint8_t* data, std::size_t size, BlockCodec codec);
  static EncodedBlock encode_block_2(const std::uint8_t* data, std::size_t size, BlockCodec codec);
  static EncodedBlock encode_block_3(const std::uint8_t* data, std::size_t size, BlockCodec codec);
  static EncodedBlock encode_block_4(const std::uint8_t* data, std::size_t size, BlockCodec codec);
  static EncodedBlock encode_block_5(const std::uint8_t* data, std::size_t size, BlockCodec codec);
  static EncodedBlock encode_block_6(const std::uint8_t* data, std::size_t size, BlockCodec codec);
  static EncodedBlock encode_block_7(const std::uint8_t* data, std::size_t size, BlockCodec codec);
  static EncodedBlock encode_block_8(const std::uint8_t* data, std::size_t size, BlockCodec codec);
  static EncodedBlock encode_block_9(const std::uint8_t* data, std::size_t size, BlockCodec codec);
  static EncodedBlock encode_block_10(const std::uint8_t* data, std::size_t size, BlockCodec codec);
  static EncodedBlock encode_block_11(const std::uint8_t* data, std::size_t size, BlockCodec codec);
  static EncodedBlock encode_block_12(const std::uint8_t* data, std::size_t size, BlockCodec codec);
  static EncodedBlock encode_block_13(const std::uint8_t* data, std::size_t size, BlockCodec codec);
  static EncodedBlock encode_block_14(const std::uint8_t* data, std::size_t size, BlockCodec codec);
  static EncodedBlock encode_block_15(const std::uint8_t* data, std::size_t size, BlockCodec codec);
  static EncodedBlock encode_block_16(const std::uint8_t* data, std::size_t size, BlockCodec codec);
  static EncodedBlock encode_block_17(const std::uint8_t* data, std::size_t size, BlockCodec codec);
  static EncodedBlock encode_block_18(const std::uint8_t* data, std::size_t size, BlockCodec codec);
  static EncodedBlock encode_block_19(const std::uint8_t* data, std::size_t size, BlockCodec codec);
  static EncodedBlock encode_block_20(const std::uint8_t* data, std::size_t size, BlockCodec codec);
  static std::vector<std::uint8_t> serialize_section(const std::vector<EncodedBlock>& blocks);
};

}  // namespace rifttrace
