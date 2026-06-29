// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT

#include "rifttrace/rifttrace.hpp"

#include <cassert>
#include <vector>

int main() {
  const std::vector<std::uint8_t> payload = {'a', 'b', 'a', 'a', 'a', 'c', 'c', 'c', 'c'};
  const auto raw = rifttrace::decode_block_payload(rifttrace::BlockCodec::kRaw, payload.data(),
                                                   payload.size());
  assert(raw == payload);

  std::vector<std::uint8_t> rle;
  rle.push_back(0xff);
  rle.push_back(0x03);
  rle.push_back(0x00);
  rle.push_back('x');
  rle.push_back('y');
  std::vector<std::uint8_t> header;
  const auto expected = rifttrace::write_u32_le(4);
  header.insert(header.end(), expected.begin(), expected.end());
  header.insert(header.end(), rle.begin(), rle.end());
  const auto decoded = rifttrace::decode_block_payload(
      rifttrace::BlockCodec::kSimpleRle, header.data(), header.size());
  assert(decoded.size() == 4);
  assert(decoded[0] == 'x' && decoded[3] == 'y');
  return 0;
}
