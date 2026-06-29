// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT

#include "rifttrace/block_decoder.hpp"

#include "rifttrace/byte_reader.hpp"
#include "rifttrace/section_table.hpp"

namespace rifttrace {

namespace {

std::vector<std::uint8_t> decode_simple_rle(const std::uint8_t* data, std::size_t size,
                                            std::size_t expected) {
  std::vector<std::uint8_t> out;
  out.reserve(expected);
  ByteReader reader(data, size);
  while (!reader.eof() && out.size() < expected) {
    const auto tag = reader.read_u8();
    if (tag == 0xff) {
      if (reader.remaining() < 3) {
        throw ParseError(ErrorCode::kInvalidBlock, "truncated RLE run");
      }
      const auto count = reader.read_u16_le();
      const auto value = reader.read_u8();
      for (std::uint16_t i = 0; i < count && out.size() < expected; ++i) {
        out.push_back(value);
      }
    } else {
      out.push_back(tag);
    }
  }
  if (out.size() != expected) {
    throw ParseError(ErrorCode::kInvalidBlock, "RLE output size mismatch");
  }
  return out;
}

}  // namespace

std::vector<std::uint8_t> decode_block_payload(BlockCodec codec, const std::uint8_t* data,
                                               std::size_t size) {
  switch (codec) {
    case BlockCodec::kRaw:
      return std::vector<std::uint8_t>(data, data + size);
    case BlockCodec::kSimpleRle: {
      if (size < 4) {
        throw ParseError(ErrorCode::kInvalidBlock, "RLE header truncated");
      }
      const auto expected = ByteReader::read_u32_le_at(data, size, 0);
      return decode_simple_rle(data + 4, size - 4, expected);
    }
    default:
      throw ParseError(ErrorCode::kInvalidBlock, "unknown block codec");
  }
}

DecodedBlock decode_block_section(std::uint32_t block_id, const std::uint8_t* data,
                                  std::size_t size) {
  ByteReader reader(data, size);
  DecodedBlock block;
  block.block_id = block_id;
  const auto codec = static_cast<BlockCodec>(reader.read_u8());
  block.codec = codec;
  const auto payload_size = reader.read_u32_le();
  if (reader.remaining() < payload_size) {
    throw ParseError(ErrorCode::kInvalidBlock, "block payload truncated");
  }
  block.payload =
      decode_block_payload(codec, reader.data() + reader.position(), payload_size);
  return block;
}

std::vector<DecodedBlock> decode_blocks(const Archive& archive) {
  SectionTable table = SectionTable::parse(archive);
  std::vector<DecodedBlock> blocks;
  for (const auto& section : table.find_all(kSectionCmp0)) {
    ByteReader reader(table.payload_data(archive, section), section.size);
    const auto block_count = reader.read_u32_le();
    for (std::uint32_t i = 0; i < block_count; ++i) {
      const auto block_id = reader.read_u32_le();
      const auto codec = static_cast<BlockCodec>(reader.read_u8());
      const auto compressed_size = reader.read_u32_le();
      const auto uncompressed_size = reader.read_u32_le();
      if (reader.remaining() < compressed_size) {
        throw ParseError(ErrorCode::kInvalidBlock, "compressed block truncated");
      }
      DecodedBlock block;
      block.block_id = block_id;
      block.codec = codec;
      block.payload = decode_block_payload(codec, reader.data() + reader.position(),
                                           compressed_size);
      if (block.payload.size() != uncompressed_size) {
        throw ParseError(ErrorCode::kInvalidBlock, "uncompressed size mismatch");
      }
      reader.skip(compressed_size);
      blocks.push_back(std::move(block));
    }
  }
  return blocks;
}

}  // namespace rifttrace
