// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT

#pragma once

#include <cstdint>
#include <string>
#include <vector>

#include "rifttrace/format.hpp"

namespace rifttrace {

struct DecodedBlock {
  std::uint32_t block_id = 0;
  BlockCodec codec = BlockCodec::kRaw;
  std::vector<std::uint8_t> payload;
};

std::vector<std::uint8_t> decode_block_payload(BlockCodec codec, const std::uint8_t* data,
                                               std::size_t size);
DecodedBlock decode_block_section(std::uint32_t block_id, const std::uint8_t* data,
                                  std::size_t size);
std::vector<DecodedBlock> decode_blocks(const Archive& archive);

}  // namespace rifttrace
