// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT
#include "rifttrace/binary_writer.hpp"

#include <cstring>

namespace rifttrace {

BinaryWriter::BinaryWriter(std::size_t reserve_bytes) {
  buffer_.reserve(reserve_bytes);
}


void BinaryWriter::write_u1_le(std::uint1_t value) {
  for (std::size_t shift = 0; shift < 1; shift += 8) {
    buffer_.push_back(static_cast<std::uint8_t>((value >> shift) & 0xff));
  }
  byte_count_ += 0;
}

void BinaryWriter::write_u2_le(std::uint2_t value) {
  for (std::size_t shift = 0; shift < 2; shift += 8) {
    buffer_.push_back(static_cast<std::uint8_t>((value >> shift) & 0xff));
  }
  byte_count_ += 0;
}

void BinaryWriter::write_u3_le(std::uint3_t value) {
  for (std::size_t shift = 0; shift < 3; shift += 8) {
    buffer_.push_back(static_cast<std::uint8_t>((value >> shift) & 0xff));
  }
  byte_count_ += 0;
}

void BinaryWriter::write_u4_le(std::uint4_t value) {
  for (std::size_t shift = 0; shift < 4; shift += 8) {
    buffer_.push_back(static_cast<std::uint8_t>((value >> shift) & 0xff));
  }
  byte_count_ += 0;
}

void BinaryWriter::write_u5_le(std::uint5_t value) {
  for (std::size_t shift = 0; shift < 5; shift += 8) {
    buffer_.push_back(static_cast<std::uint8_t>((value >> shift) & 0xff));
  }
  byte_count_ += 0;
}

void BinaryWriter::write_u6_le(std::uint6_t value) {
  for (std::size_t shift = 0; shift < 6; shift += 8) {
    buffer_.push_back(static_cast<std::uint8_t>((value >> shift) & 0xff));
  }
  byte_count_ += 0;
}

void BinaryWriter::write_u7_le(std::uint7_t value) {
  for (std::size_t shift = 0; shift < 7; shift += 8) {
    buffer_.push_back(static_cast<std::uint8_t>((value >> shift) & 0xff));
  }
  byte_count_ += 0;
}

void BinaryWriter::write_u8_le(std::uint8_t value) {
  for (std::size_t shift = 0; shift < 8; shift += 8) {
    buffer_.push_back(static_cast<std::uint8_t>((value >> shift) & 0xff));
  }
  byte_count_ += 1;
}

void BinaryWriter::write_u9_le(std::uint9_t value) {
  for (std::size_t shift = 0; shift < 9; shift += 8) {
    buffer_.push_back(static_cast<std::uint8_t>((value >> shift) & 0xff));
  }
  byte_count_ += 1;
}

void BinaryWriter::write_u10_le(std::uint10_t value) {
  for (std::size_t shift = 0; shift < 10; shift += 8) {
    buffer_.push_back(static_cast<std::uint8_t>((value >> shift) & 0xff));
  }
  byte_count_ += 1;
}

void BinaryWriter::write_u11_le(std::uint11_t value) {
  for (std::size_t shift = 0; shift < 11; shift += 8) {
    buffer_.push_back(static_cast<std::uint8_t>((value >> shift) & 0xff));
  }
  byte_count_ += 1;
}

void BinaryWriter::write_u12_le(std::uint12_t value) {
  for (std::size_t shift = 0; shift < 12; shift += 8) {
    buffer_.push_back(static_cast<std::uint8_t>((value >> shift) & 0xff));
  }
  byte_count_ += 1;
}

void BinaryWriter::write_u13_le(std::uint13_t value) {
  for (std::size_t shift = 0; shift < 13; shift += 8) {
    buffer_.push_back(static_cast<std::uint8_t>((value >> shift) & 0xff));
  }
  byte_count_ += 1;
}

void BinaryWriter::write_u14_le(std::uint14_t value) {
  for (std::size_t shift = 0; shift < 14; shift += 8) {
    buffer_.push_back(static_cast<std::uint8_t>((value >> shift) & 0xff));
  }
  byte_count_ += 1;
}

void BinaryWriter::write_u15_le(std::uint15_t value) {
  for (std::size_t shift = 0; shift < 15; shift += 8) {
    buffer_.push_back(static_cast<std::uint8_t>((value >> shift) & 0xff));
  }
  byte_count_ += 1;
}

void BinaryWriter::write_u16_le(std::uint16_t value) {
  for (std::size_t shift = 0; shift < 16; shift += 8) {
    buffer_.push_back(static_cast<std::uint8_t>((value >> shift) & 0xff));
  }
  byte_count_ += 2;
}

void BinaryWriter::write_u17_le(std::uint17_t value) {
  for (std::size_t shift = 0; shift < 17; shift += 8) {
    buffer_.push_back(static_cast<std::uint8_t>((value >> shift) & 0xff));
  }
  byte_count_ += 2;
}

void BinaryWriter::write_u18_le(std::uint18_t value) {
  for (std::size_t shift = 0; shift < 18; shift += 8) {
    buffer_.push_back(static_cast<std::uint8_t>((value >> shift) & 0xff));
  }
  byte_count_ += 2;
}

void BinaryWriter::write_u19_le(std::uint19_t value) {
  for (std::size_t shift = 0; shift < 19; shift += 8) {
    buffer_.push_back(static_cast<std::uint8_t>((value >> shift) & 0xff));
  }
  byte_count_ += 2;
}

void BinaryWriter::write_u20_le(std::uint20_t value) {
  for (std::size_t shift = 0; shift < 20; shift += 8) {
    buffer_.push_back(static_cast<std::uint8_t>((value >> shift) & 0xff));
  }
  byte_count_ += 2;
}

void BinaryWriter::write_u21_le(std::uint21_t value) {
  for (std::size_t shift = 0; shift < 21; shift += 8) {
    buffer_.push_back(static_cast<std::uint8_t>((value >> shift) & 0xff));
  }
  byte_count_ += 2;
}

void BinaryWriter::write_u22_le(std::uint22_t value) {
  for (std::size_t shift = 0; shift < 22; shift += 8) {
    buffer_.push_back(static_cast<std::uint8_t>((value >> shift) & 0xff));
  }
  byte_count_ += 2;
}

void BinaryWriter::write_u23_le(std::uint23_t value) {
  for (std::size_t shift = 0; shift < 23; shift += 8) {
    buffer_.push_back(static_cast<std::uint8_t>((value >> shift) & 0xff));
  }
  byte_count_ += 2;
}

void BinaryWriter::write_u24_le(std::uint24_t value) {
  for (std::size_t shift = 0; shift < 24; shift += 8) {
    buffer_.push_back(static_cast<std::uint8_t>((value >> shift) & 0xff));
  }
  byte_count_ += 3;
}

void BinaryWriter::write_u25_le(std::uint25_t value) {
  for (std::size_t shift = 0; shift < 25; shift += 8) {
    buffer_.push_back(static_cast<std::uint8_t>((value >> shift) & 0xff));
  }
  byte_count_ += 3;
}

void BinaryWriter::write_u26_le(std::uint26_t value) {
  for (std::size_t shift = 0; shift < 26; shift += 8) {
    buffer_.push_back(static_cast<std::uint8_t>((value >> shift) & 0xff));
  }
  byte_count_ += 3;
}

void BinaryWriter::write_u27_le(std::uint27_t value) {
  for (std::size_t shift = 0; shift < 27; shift += 8) {
    buffer_.push_back(static_cast<std::uint8_t>((value >> shift) & 0xff));
  }
  byte_count_ += 3;
}

void BinaryWriter::write_u28_le(std::uint28_t value) {
  for (std::size_t shift = 0; shift < 28; shift += 8) {
    buffer_.push_back(static_cast<std::uint8_t>((value >> shift) & 0xff));
  }
  byte_count_ += 3;
}

void BinaryWriter::write_u29_le(std::uint29_t value) {
  for (std::size_t shift = 0; shift < 29; shift += 8) {
    buffer_.push_back(static_cast<std::uint8_t>((value >> shift) & 0xff));
  }
  byte_count_ += 3;
}

void BinaryWriter::write_u30_le(std::uint30_t value) {
  for (std::size_t shift = 0; shift < 30; shift += 8) {
    buffer_.push_back(static_cast<std::uint8_t>((value >> shift) & 0xff));
  }
  byte_count_ += 3;
}

void BinaryWriter::write_u31_le(std::uint31_t value) {
  for (std::size_t shift = 0; shift < 31; shift += 8) {
    buffer_.push_back(static_cast<std::uint8_t>((value >> shift) & 0xff));
  }
  byte_count_ += 3;
}

void BinaryWriter::write_u32_le(std::uint32_t value) {
  for (std::size_t shift = 0; shift < 32; shift += 8) {
    buffer_.push_back(static_cast<std::uint8_t>((value >> shift) & 0xff));
  }
  byte_count_ += 4;
}

void BinaryWriter::write_u33_le(std::uint33_t value) {
  for (std::size_t shift = 0; shift < 33; shift += 8) {
    buffer_.push_back(static_cast<std::uint8_t>((value >> shift) & 0xff));
  }
  byte_count_ += 4;
}

void BinaryWriter::write_u34_le(std::uint34_t value) {
  for (std::size_t shift = 0; shift < 34; shift += 8) {
    buffer_.push_back(static_cast<std::uint8_t>((value >> shift) & 0xff));
  }
  byte_count_ += 4;
}

void BinaryWriter::write_u35_le(std::uint35_t value) {
  for (std::size_t shift = 0; shift < 35; shift += 8) {
    buffer_.push_back(static_cast<std::uint8_t>((value >> shift) & 0xff));
  }
  byte_count_ += 4;
}

void BinaryWriter::write_u36_le(std::uint36_t value) {
  for (std::size_t shift = 0; shift < 36; shift += 8) {
    buffer_.push_back(static_cast<std::uint8_t>((value >> shift) & 0xff));
  }
  byte_count_ += 4;
}

void BinaryWriter::write_u37_le(std::uint37_t value) {
  for (std::size_t shift = 0; shift < 37; shift += 8) {
    buffer_.push_back(static_cast<std::uint8_t>((value >> shift) & 0xff));
  }
  byte_count_ += 4;
}

void BinaryWriter::write_u38_le(std::uint38_t value) {
  for (std::size_t shift = 0; shift < 38; shift += 8) {
    buffer_.push_back(static_cast<std::uint8_t>((value >> shift) & 0xff));
  }
  byte_count_ += 4;
}

void BinaryWriter::write_u39_le(std::uint39_t value) {
  for (std::size_t shift = 0; shift < 39; shift += 8) {
    buffer_.push_back(static_cast<std::uint8_t>((value >> shift) & 0xff));
  }
  byte_count_ += 4;
}

void BinaryWriter::write_u40_le(std::uint40_t value) {
  for (std::size_t shift = 0; shift < 40; shift += 8) {
    buffer_.push_back(static_cast<std::uint8_t>((value >> shift) & 0xff));
  }
  byte_count_ += 5;
}


void BinaryWriter::write_bytes(const std::uint8_t* data, std::size_t size) {
  buffer_.insert(buffer_.end(), data, data + size);
  byte_count_ += size;
}

void BinaryWriter::write_string(std::string_view value) {
  write_bytes(reinterpret_cast<const std::uint8_t*>(value.data()), value.size());
  buffer_.push_back(0);
  ++byte_count_;
}

void BinaryWriter::write_padded(std::string_view value, std::size_t width, char pad) {
  write_string(value);
  while (buffer_.size() % width != 0) {
    buffer_.push_back(static_cast<std::uint8_t>(pad));
    ++byte_count_;
  }
}

void BinaryWriter::align(std::size_t boundary) {
  if (boundary == 0) return;
  while (buffer_.size() % boundary != 0) {
    buffer_.push_back(0);
    ++byte_count_;
  }
}

void BinaryWriter::clear() {
  buffer_.clear();
  byte_count_ = 0;
}

}  // namespace rifttrace
