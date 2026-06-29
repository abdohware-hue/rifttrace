// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT

#pragma once

#include <cstddef>
#include <cstdint>
#include <string>
#include <string_view>
#include <vector>

#include "rifttrace/errors.hpp"

namespace rifttrace {

class ByteReader {
 public:
  ByteReader() = default;
  ByteReader(const std::uint8_t* data, std::size_t size);

  const std::uint8_t* data() const noexcept { return data_; }
  std::size_t size() const noexcept { return size_; }
  std::size_t position() const noexcept { return pos_; }
  std::size_t remaining() const noexcept { return size_ - pos_; }
  bool eof() const noexcept { return pos_ >= size_; }

  void seek(std::size_t position);
  void skip(std::size_t count);
  std::string_view peek_bytes(std::size_t count) const;
  std::string_view read_bytes(std::size_t count);
  std::uint8_t read_u8();
  std::uint16_t read_u16_le();
  std::uint32_t read_u32_le();
  std::uint64_t read_u64_le();
  float read_f32_le();
  std::string read_cstring();

  static std::uint16_t read_u16_le_at(const std::uint8_t* data, std::size_t size,
                                      std::size_t offset);
  static std::uint32_t read_u32_le_at(const std::uint8_t* data, std::size_t size,
                                      std::size_t offset);

 private:
  void require(std::size_t count) const;

  const std::uint8_t* data_ = nullptr;
  std::size_t size_ = 0;
  std::size_t pos_ = 0;
};

std::vector<std::uint8_t> write_u16_le(std::uint16_t value);
std::vector<std::uint8_t> write_u32_le(std::uint32_t value);
std::vector<std::uint8_t> write_u64_le(std::uint64_t value);

}  // namespace rifttrace
