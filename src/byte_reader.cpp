// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT

#include "rifttrace/byte_reader.hpp"

#include <cstring>

namespace rifttrace {

ByteReader::ByteReader(const std::uint8_t* data, std::size_t size)
    : data_(data), size_(size), pos_(0) {}

void ByteReader::seek(std::size_t position) {
  if (position > size_) {
    throw ParseError(ErrorCode::kTruncated, "seek past end of buffer");
  }
  pos_ = position;
}

void ByteReader::skip(std::size_t count) { seek(pos_ + count); }

void ByteReader::require(std::size_t count) const {
  if (pos_ + count > size_) {
    throw ParseError(ErrorCode::kTruncated, "unexpected end of input");
  }
}

std::string_view ByteReader::peek_bytes(std::size_t count) const {
  require(count);
  return std::string_view(reinterpret_cast<const char*>(data_ + pos_), count);
}

std::string_view ByteReader::read_bytes(std::size_t count) {
  auto view = peek_bytes(count);
  pos_ += count;
  return view;
}

std::uint8_t ByteReader::read_u8() {
  require(1);
  return data_[pos_++];
}

std::uint16_t ByteReader::read_u16_le() {
  require(2);
  std::uint16_t value = static_cast<std::uint16_t>(data_[pos_]) |
                        (static_cast<std::uint16_t>(data_[pos_ + 1]) << 8);
  pos_ += 2;
  return value;
}

std::uint32_t ByteReader::read_u32_le() {
  require(4);
  std::uint32_t value = static_cast<std::uint32_t>(data_[pos_]) |
                        (static_cast<std::uint32_t>(data_[pos_ + 1]) << 8) |
                        (static_cast<std::uint32_t>(data_[pos_ + 2]) << 16) |
                        (static_cast<std::uint32_t>(data_[pos_ + 3]) << 24);
  pos_ += 4;
  return value;
}

std::uint64_t ByteReader::read_u64_le() {
  require(8);
  std::uint64_t value = 0;
  for (int i = 0; i < 8; ++i) {
    value |= static_cast<std::uint64_t>(data_[pos_ + i]) << (8 * i);
  }
  pos_ += 8;
  return value;
}

float ByteReader::read_f32_le() {
  require(4);
  float value = 0.f;
  std::memcpy(&value, data_ + pos_, 4);
  pos_ += 4;
  return value;
}

std::string ByteReader::read_cstring() {
  std::size_t start = pos_;
  while (pos_ < size_ && data_[pos_] != 0) {
    ++pos_;
  }
  if (pos_ >= size_) {
    throw ParseError(ErrorCode::kTruncated, "unterminated cstring");
  }
  std::string value(reinterpret_cast<const char*>(data_ + start), pos_ - start);
  ++pos_;
  return value;
}

std::uint16_t ByteReader::read_u16_le_at(const std::uint8_t* data, std::size_t size,
                                         std::size_t offset) {
  ByteReader reader(data, size);
  reader.seek(offset);
  return reader.read_u16_le();
}

std::uint32_t ByteReader::read_u32_le_at(const std::uint8_t* data, std::size_t size,
                                         std::size_t offset) {
  ByteReader reader(data, size);
  reader.seek(offset);
  return reader.read_u32_le();
}

std::vector<std::uint8_t> write_u16_le(std::uint16_t value) {
  return {static_cast<std::uint8_t>(value & 0xff),
          static_cast<std::uint8_t>((value >> 8) & 0xff)};
}

std::vector<std::uint8_t> write_u32_le(std::uint32_t value) {
  return {static_cast<std::uint8_t>(value & 0xff),
          static_cast<std::uint8_t>((value >> 8) & 0xff),
          static_cast<std::uint8_t>((value >> 16) & 0xff),
          static_cast<std::uint8_t>((value >> 24) & 0xff)};
}

std::vector<std::uint8_t> write_u64_le(std::uint64_t value) {
  std::vector<std::uint8_t> out(8);
  for (int i = 0; i < 8; ++i) {
    out[static_cast<std::size_t>(i)] = static_cast<std::uint8_t>((value >> (8 * i)) & 0xff);
  }
  return out;
}

}  // namespace rifttrace
