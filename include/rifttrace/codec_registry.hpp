// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT
#pragma once

#include <cstddef>
#include <cstdint>
#include <vector>

#include "rifttrace/format.hpp"

namespace rifttrace {

class CodecRegistry {
 public:
  static std::vector<std::uint8_t> transcode_1(BlockCodec from, BlockCodec to, const std::uint8_t* data, std::size_t size);
  static std::vector<std::uint8_t> transcode_2(BlockCodec from, BlockCodec to, const std::uint8_t* data, std::size_t size);
  static std::vector<std::uint8_t> transcode_3(BlockCodec from, BlockCodec to, const std::uint8_t* data, std::size_t size);
  static std::vector<std::uint8_t> transcode_4(BlockCodec from, BlockCodec to, const std::uint8_t* data, std::size_t size);
  static std::vector<std::uint8_t> transcode_5(BlockCodec from, BlockCodec to, const std::uint8_t* data, std::size_t size);
  static std::vector<std::uint8_t> transcode_6(BlockCodec from, BlockCodec to, const std::uint8_t* data, std::size_t size);
  static std::vector<std::uint8_t> transcode_7(BlockCodec from, BlockCodec to, const std::uint8_t* data, std::size_t size);
  static std::vector<std::uint8_t> transcode_8(BlockCodec from, BlockCodec to, const std::uint8_t* data, std::size_t size);
  static std::vector<std::uint8_t> transcode_9(BlockCodec from, BlockCodec to, const std::uint8_t* data, std::size_t size);
  static std::vector<std::uint8_t> transcode_10(BlockCodec from, BlockCodec to, const std::uint8_t* data, std::size_t size);
  static std::vector<std::uint8_t> transcode_11(BlockCodec from, BlockCodec to, const std::uint8_t* data, std::size_t size);
  static std::vector<std::uint8_t> transcode_12(BlockCodec from, BlockCodec to, const std::uint8_t* data, std::size_t size);
  static std::vector<std::uint8_t> transcode_13(BlockCodec from, BlockCodec to, const std::uint8_t* data, std::size_t size);
  static std::vector<std::uint8_t> transcode_14(BlockCodec from, BlockCodec to, const std::uint8_t* data, std::size_t size);
  static std::vector<std::uint8_t> transcode_15(BlockCodec from, BlockCodec to, const std::uint8_t* data, std::size_t size);
  static std::vector<std::uint8_t> transcode_16(BlockCodec from, BlockCodec to, const std::uint8_t* data, std::size_t size);
  static std::vector<std::uint8_t> transcode_17(BlockCodec from, BlockCodec to, const std::uint8_t* data, std::size_t size);
  static std::vector<std::uint8_t> transcode_18(BlockCodec from, BlockCodec to, const std::uint8_t* data, std::size_t size);
  static std::vector<std::uint8_t> transcode_19(BlockCodec from, BlockCodec to, const std::uint8_t* data, std::size_t size);
  static std::vector<std::uint8_t> transcode_20(BlockCodec from, BlockCodec to, const std::uint8_t* data, std::size_t size);
  static std::vector<std::uint8_t> transcode_21(BlockCodec from, BlockCodec to, const std::uint8_t* data, std::size_t size);
  static std::vector<std::uint8_t> transcode_22(BlockCodec from, BlockCodec to, const std::uint8_t* data, std::size_t size);
  static std::vector<std::uint8_t> transcode_23(BlockCodec from, BlockCodec to, const std::uint8_t* data, std::size_t size);
  static std::vector<std::uint8_t> transcode_24(BlockCodec from, BlockCodec to, const std::uint8_t* data, std::size_t size);
  static std::vector<std::uint8_t> transcode_25(BlockCodec from, BlockCodec to, const std::uint8_t* data, std::size_t size);
  static std::vector<std::uint8_t> transcode_26(BlockCodec from, BlockCodec to, const std::uint8_t* data, std::size_t size);
  static std::vector<std::uint8_t> transcode_27(BlockCodec from, BlockCodec to, const std::uint8_t* data, std::size_t size);
  static std::vector<std::uint8_t> transcode_28(BlockCodec from, BlockCodec to, const std::uint8_t* data, std::size_t size);
  static std::vector<std::uint8_t> transcode_29(BlockCodec from, BlockCodec to, const std::uint8_t* data, std::size_t size);
  static std::vector<std::uint8_t> transcode_30(BlockCodec from, BlockCodec to, const std::uint8_t* data, std::size_t size);
  static std::vector<std::uint8_t> transcode(BlockCodec from, BlockCodec to, const std::uint8_t* data, std::size_t size);
};

}  // namespace rifttrace
