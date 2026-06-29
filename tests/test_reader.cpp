// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT

#include "rifttrace/byte_reader.hpp"

#include <cassert>
#include <cstdint>
#include <vector>

int main() {
  const std::vector<std::uint8_t> bytes = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06};
  rifttrace::ByteReader reader(bytes.data(), bytes.size());
  assert(reader.read_u16_le() == 0x0201);
  assert(reader.read_u32_le() == 0x06050403);
  assert(reader.remaining() == 0);
  return 0;
}
