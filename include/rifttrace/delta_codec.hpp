// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT
#pragma once

#include <cstddef>
#include <cstdint>
#include <vector>

namespace rifttrace {

class DeltaCodec {
 public:
  static std::vector<std::uint8_t> encode_window_4(const std::uint8_t* data, std::size_t size);
  static std::vector<std::uint8_t> decode_window_4(const std::uint8_t* data, std::size_t size, std::size_t expected);
  static std::vector<std::uint8_t> encode_window_8(const std::uint8_t* data, std::size_t size);
  static std::vector<std::uint8_t> decode_window_8(const std::uint8_t* data, std::size_t size, std::size_t expected);
  static std::vector<std::uint8_t> encode_window_16(const std::uint8_t* data, std::size_t size);
  static std::vector<std::uint8_t> decode_window_16(const std::uint8_t* data, std::size_t size, std::size_t expected);
  static std::vector<std::uint8_t> encode_window_32(const std::uint8_t* data, std::size_t size);
  static std::vector<std::uint8_t> decode_window_32(const std::uint8_t* data, std::size_t size, std::size_t expected);
  static std::vector<std::uint8_t> encode_window_64(const std::uint8_t* data, std::size_t size);
  static std::vector<std::uint8_t> decode_window_64(const std::uint8_t* data, std::size_t size, std::size_t expected);
  static std::vector<std::uint8_t> encode_window_128(const std::uint8_t* data, std::size_t size);
  static std::vector<std::uint8_t> decode_window_128(const std::uint8_t* data, std::size_t size, std::size_t expected);
  static std::vector<std::uint8_t> encode_window_256(const std::uint8_t* data, std::size_t size);
  static std::vector<std::uint8_t> decode_window_256(const std::uint8_t* data, std::size_t size, std::size_t expected);
  static std::vector<std::uint8_t> encode_window_512(const std::uint8_t* data, std::size_t size);
  static std::vector<std::uint8_t> decode_window_512(const std::uint8_t* data, std::size_t size, std::size_t expected);
  static std::vector<std::uint8_t> encode_auto(const std::uint8_t* data, std::size_t size);
  static std::vector<std::uint8_t> decode_auto(const std::uint8_t* data, std::size_t size, std::size_t expected);
};

}  // namespace rifttrace
