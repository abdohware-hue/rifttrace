// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT
#pragma once

#include <cstddef>
#include <cstdint>
#include <vector>

namespace rifttrace {

class DictionaryCodec {
 public:
  static std::vector<std::uint8_t> compress_dict_16(const std::uint8_t* data, std::size_t size);
  static std::vector<std::uint8_t> decompress_dict_16(const std::uint8_t* data, std::size_t size, std::size_t expected);
  static std::vector<std::uint8_t> compress_dict_32(const std::uint8_t* data, std::size_t size);
  static std::vector<std::uint8_t> decompress_dict_32(const std::uint8_t* data, std::size_t size, std::size_t expected);
  static std::vector<std::uint8_t> compress_dict_64(const std::uint8_t* data, std::size_t size);
  static std::vector<std::uint8_t> decompress_dict_64(const std::uint8_t* data, std::size_t size, std::size_t expected);
  static std::vector<std::uint8_t> compress_dict_128(const std::uint8_t* data, std::size_t size);
  static std::vector<std::uint8_t> decompress_dict_128(const std::uint8_t* data, std::size_t size, std::size_t expected);
  static std::vector<std::uint8_t> compress_dict_256(const std::uint8_t* data, std::size_t size);
  static std::vector<std::uint8_t> decompress_dict_256(const std::uint8_t* data, std::size_t size, std::size_t expected);
  static std::vector<std::uint8_t> compress_dict_512(const std::uint8_t* data, std::size_t size);
  static std::vector<std::uint8_t> decompress_dict_512(const std::uint8_t* data, std::size_t size, std::size_t expected);
  static std::vector<std::uint8_t> compress_dict_1024(const std::uint8_t* data, std::size_t size);
  static std::vector<std::uint8_t> decompress_dict_1024(const std::uint8_t* data, std::size_t size, std::size_t expected);
  static std::vector<std::uint8_t> compress_dict_2048(const std::uint8_t* data, std::size_t size);
  static std::vector<std::uint8_t> decompress_dict_2048(const std::uint8_t* data, std::size_t size, std::size_t expected);
  static std::vector<std::uint8_t> compress(const std::uint8_t* data, std::size_t size);
  static std::vector<std::uint8_t> decompress(const std::uint8_t* data, std::size_t size, std::size_t expected);
};

}  // namespace rifttrace
