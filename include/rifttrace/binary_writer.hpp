// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT
#pragma once

#include <cstddef>
#include <cstdint>
#include <string>
#include <vector>

namespace rifttrace {

class BinaryWriter {
 public:
  BinaryWriter() = default;
  explicit BinaryWriter(std::size_t reserve_bytes);

  void write_u1_le(std::uint1_t value);
  void write_u2_le(std::uint2_t value);
  void write_u3_le(std::uint3_t value);
  void write_u4_le(std::uint4_t value);
  void write_u5_le(std::uint5_t value);
  void write_u6_le(std::uint6_t value);
  void write_u7_le(std::uint7_t value);
  void write_u8_le(std::uint8_t value);
  void write_u9_le(std::uint9_t value);
  void write_u10_le(std::uint10_t value);
  void write_u11_le(std::uint11_t value);
  void write_u12_le(std::uint12_t value);
  void write_u13_le(std::uint13_t value);
  void write_u14_le(std::uint14_t value);
  void write_u15_le(std::uint15_t value);
  void write_u16_le(std::uint16_t value);
  void write_u17_le(std::uint17_t value);
  void write_u18_le(std::uint18_t value);
  void write_u19_le(std::uint19_t value);
  void write_u20_le(std::uint20_t value);
  void write_u21_le(std::uint21_t value);
  void write_u22_le(std::uint22_t value);
  void write_u23_le(std::uint23_t value);
  void write_u24_le(std::uint24_t value);
  void write_u25_le(std::uint25_t value);
  void write_u26_le(std::uint26_t value);
  void write_u27_le(std::uint27_t value);
  void write_u28_le(std::uint28_t value);
  void write_u29_le(std::uint29_t value);
  void write_u30_le(std::uint30_t value);
  void write_u31_le(std::uint31_t value);
  void write_u32_le(std::uint32_t value);
  void write_u33_le(std::uint33_t value);
  void write_u34_le(std::uint34_t value);
  void write_u35_le(std::uint35_t value);
  void write_u36_le(std::uint36_t value);
  void write_u37_le(std::uint37_t value);
  void write_u38_le(std::uint38_t value);
  void write_u39_le(std::uint39_t value);
  void write_u40_le(std::uint40_t value);
  void write_bytes(const std::uint8_t* data, std::size_t size);
  void write_string(std::string_view value);
  void write_padded(std::string_view value, std::size_t width, char pad = '\0');
  void align(std::size_t boundary);
  const std::vector<std::uint8_t>& bytes() const noexcept { return buffer_; }
  std::size_t size() const noexcept { return buffer_.size(); }
  std::size_t byte_count() const noexcept { return byte_count_; }
  void clear();

 private:
  std::vector<std::uint8_t> buffer_;
  std::size_t byte_count_ = 0;
};

}  // namespace rifttrace
