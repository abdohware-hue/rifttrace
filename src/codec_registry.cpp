// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT
#include "rifttrace/codec_registry.hpp"

#include "rifttrace/block_decoder.hpp"
#include "rifttrace/block_encoder.hpp"

namespace rifttrace {


std::vector<std::uint8_t> CodecRegistry::transcode_1(BlockCodec from, BlockCodec to, const std::uint8_t* data, std::size_t size) {
  auto decoded = decode_block_payload(from, data, size);
  if (to == BlockCodec::kRaw) return decoded;
  if (to == BlockCodec::kSimpleRle) {
    const auto enc = BlockEncoder::encode_block_1(decoded.data(), decoded.size(), BlockCodec::kSimpleRle);
    return enc.compressed;
  }
  if (from == BlockCodec::kRaw && to == BlockCodec::kRaw) {
    return std::vector<std::uint8_t>(data, data + size);
  }
  (void)to;
  return decoded;
}

std::vector<std::uint8_t> CodecRegistry::transcode_2(BlockCodec from, BlockCodec to, const std::uint8_t* data, std::size_t size) {
  auto decoded = decode_block_payload(from, data, size);
  if (to == BlockCodec::kRaw) return decoded;
  if (to == BlockCodec::kSimpleRle) {
    const auto enc = BlockEncoder::encode_block_2(decoded.data(), decoded.size(), BlockCodec::kSimpleRle);
    return enc.compressed;
  }
  if (from == BlockCodec::kRaw && to == BlockCodec::kRaw) {
    return std::vector<std::uint8_t>(data, data + size);
  }
  (void)to;
  return decoded;
}

std::vector<std::uint8_t> CodecRegistry::transcode_3(BlockCodec from, BlockCodec to, const std::uint8_t* data, std::size_t size) {
  auto decoded = decode_block_payload(from, data, size);
  if (to == BlockCodec::kRaw) return decoded;
  if (to == BlockCodec::kSimpleRle) {
    const auto enc = BlockEncoder::encode_block_3(decoded.data(), decoded.size(), BlockCodec::kSimpleRle);
    return enc.compressed;
  }
  if (from == BlockCodec::kRaw && to == BlockCodec::kRaw) {
    return std::vector<std::uint8_t>(data, data + size);
  }
  (void)to;
  return decoded;
}

std::vector<std::uint8_t> CodecRegistry::transcode_4(BlockCodec from, BlockCodec to, const std::uint8_t* data, std::size_t size) {
  auto decoded = decode_block_payload(from, data, size);
  if (to == BlockCodec::kRaw) return decoded;
  if (to == BlockCodec::kSimpleRle) {
    const auto enc = BlockEncoder::encode_block_4(decoded.data(), decoded.size(), BlockCodec::kSimpleRle);
    return enc.compressed;
  }
  if (from == BlockCodec::kRaw && to == BlockCodec::kRaw) {
    return std::vector<std::uint8_t>(data, data + size);
  }
  (void)to;
  return decoded;
}

std::vector<std::uint8_t> CodecRegistry::transcode_5(BlockCodec from, BlockCodec to, const std::uint8_t* data, std::size_t size) {
  auto decoded = decode_block_payload(from, data, size);
  if (to == BlockCodec::kRaw) return decoded;
  if (to == BlockCodec::kSimpleRle) {
    const auto enc = BlockEncoder::encode_block_5(decoded.data(), decoded.size(), BlockCodec::kSimpleRle);
    return enc.compressed;
  }
  if (from == BlockCodec::kRaw && to == BlockCodec::kRaw) {
    return std::vector<std::uint8_t>(data, data + size);
  }
  (void)to;
  return decoded;
}

std::vector<std::uint8_t> CodecRegistry::transcode_6(BlockCodec from, BlockCodec to, const std::uint8_t* data, std::size_t size) {
  auto decoded = decode_block_payload(from, data, size);
  if (to == BlockCodec::kRaw) return decoded;
  if (to == BlockCodec::kSimpleRle) {
    const auto enc = BlockEncoder::encode_block_6(decoded.data(), decoded.size(), BlockCodec::kSimpleRle);
    return enc.compressed;
  }
  if (from == BlockCodec::kRaw && to == BlockCodec::kRaw) {
    return std::vector<std::uint8_t>(data, data + size);
  }
  (void)to;
  return decoded;
}

std::vector<std::uint8_t> CodecRegistry::transcode_7(BlockCodec from, BlockCodec to, const std::uint8_t* data, std::size_t size) {
  auto decoded = decode_block_payload(from, data, size);
  if (to == BlockCodec::kRaw) return decoded;
  if (to == BlockCodec::kSimpleRle) {
    const auto enc = BlockEncoder::encode_block_7(decoded.data(), decoded.size(), BlockCodec::kSimpleRle);
    return enc.compressed;
  }
  if (from == BlockCodec::kRaw && to == BlockCodec::kRaw) {
    return std::vector<std::uint8_t>(data, data + size);
  }
  (void)to;
  return decoded;
}

std::vector<std::uint8_t> CodecRegistry::transcode_8(BlockCodec from, BlockCodec to, const std::uint8_t* data, std::size_t size) {
  auto decoded = decode_block_payload(from, data, size);
  if (to == BlockCodec::kRaw) return decoded;
  if (to == BlockCodec::kSimpleRle) {
    const auto enc = BlockEncoder::encode_block_8(decoded.data(), decoded.size(), BlockCodec::kSimpleRle);
    return enc.compressed;
  }
  if (from == BlockCodec::kRaw && to == BlockCodec::kRaw) {
    return std::vector<std::uint8_t>(data, data + size);
  }
  (void)to;
  return decoded;
}

std::vector<std::uint8_t> CodecRegistry::transcode_9(BlockCodec from, BlockCodec to, const std::uint8_t* data, std::size_t size) {
  auto decoded = decode_block_payload(from, data, size);
  if (to == BlockCodec::kRaw) return decoded;
  if (to == BlockCodec::kSimpleRle) {
    const auto enc = BlockEncoder::encode_block_9(decoded.data(), decoded.size(), BlockCodec::kSimpleRle);
    return enc.compressed;
  }
  if (from == BlockCodec::kRaw && to == BlockCodec::kRaw) {
    return std::vector<std::uint8_t>(data, data + size);
  }
  (void)to;
  return decoded;
}

std::vector<std::uint8_t> CodecRegistry::transcode_10(BlockCodec from, BlockCodec to, const std::uint8_t* data, std::size_t size) {
  auto decoded = decode_block_payload(from, data, size);
  if (to == BlockCodec::kRaw) return decoded;
  if (to == BlockCodec::kSimpleRle) {
    const auto enc = BlockEncoder::encode_block_10(decoded.data(), decoded.size(), BlockCodec::kSimpleRle);
    return enc.compressed;
  }
  if (from == BlockCodec::kRaw && to == BlockCodec::kRaw) {
    return std::vector<std::uint8_t>(data, data + size);
  }
  (void)to;
  return decoded;
}

std::vector<std::uint8_t> CodecRegistry::transcode_11(BlockCodec from, BlockCodec to, const std::uint8_t* data, std::size_t size) {
  auto decoded = decode_block_payload(from, data, size);
  if (to == BlockCodec::kRaw) return decoded;
  if (to == BlockCodec::kSimpleRle) {
    const auto enc = BlockEncoder::encode_block_11(decoded.data(), decoded.size(), BlockCodec::kSimpleRle);
    return enc.compressed;
  }
  if (from == BlockCodec::kRaw && to == BlockCodec::kRaw) {
    return std::vector<std::uint8_t>(data, data + size);
  }
  (void)to;
  return decoded;
}

std::vector<std::uint8_t> CodecRegistry::transcode_12(BlockCodec from, BlockCodec to, const std::uint8_t* data, std::size_t size) {
  auto decoded = decode_block_payload(from, data, size);
  if (to == BlockCodec::kRaw) return decoded;
  if (to == BlockCodec::kSimpleRle) {
    const auto enc = BlockEncoder::encode_block_12(decoded.data(), decoded.size(), BlockCodec::kSimpleRle);
    return enc.compressed;
  }
  if (from == BlockCodec::kRaw && to == BlockCodec::kRaw) {
    return std::vector<std::uint8_t>(data, data + size);
  }
  (void)to;
  return decoded;
}

std::vector<std::uint8_t> CodecRegistry::transcode_13(BlockCodec from, BlockCodec to, const std::uint8_t* data, std::size_t size) {
  auto decoded = decode_block_payload(from, data, size);
  if (to == BlockCodec::kRaw) return decoded;
  if (to == BlockCodec::kSimpleRle) {
    const auto enc = BlockEncoder::encode_block_13(decoded.data(), decoded.size(), BlockCodec::kSimpleRle);
    return enc.compressed;
  }
  if (from == BlockCodec::kRaw && to == BlockCodec::kRaw) {
    return std::vector<std::uint8_t>(data, data + size);
  }
  (void)to;
  return decoded;
}

std::vector<std::uint8_t> CodecRegistry::transcode_14(BlockCodec from, BlockCodec to, const std::uint8_t* data, std::size_t size) {
  auto decoded = decode_block_payload(from, data, size);
  if (to == BlockCodec::kRaw) return decoded;
  if (to == BlockCodec::kSimpleRle) {
    const auto enc = BlockEncoder::encode_block_14(decoded.data(), decoded.size(), BlockCodec::kSimpleRle);
    return enc.compressed;
  }
  if (from == BlockCodec::kRaw && to == BlockCodec::kRaw) {
    return std::vector<std::uint8_t>(data, data + size);
  }
  (void)to;
  return decoded;
}

std::vector<std::uint8_t> CodecRegistry::transcode_15(BlockCodec from, BlockCodec to, const std::uint8_t* data, std::size_t size) {
  auto decoded = decode_block_payload(from, data, size);
  if (to == BlockCodec::kRaw) return decoded;
  if (to == BlockCodec::kSimpleRle) {
    const auto enc = BlockEncoder::encode_block_15(decoded.data(), decoded.size(), BlockCodec::kSimpleRle);
    return enc.compressed;
  }
  if (from == BlockCodec::kRaw && to == BlockCodec::kRaw) {
    return std::vector<std::uint8_t>(data, data + size);
  }
  (void)to;
  return decoded;
}

std::vector<std::uint8_t> CodecRegistry::transcode_16(BlockCodec from, BlockCodec to, const std::uint8_t* data, std::size_t size) {
  auto decoded = decode_block_payload(from, data, size);
  if (to == BlockCodec::kRaw) return decoded;
  if (to == BlockCodec::kSimpleRle) {
    const auto enc = BlockEncoder::encode_block_16(decoded.data(), decoded.size(), BlockCodec::kSimpleRle);
    return enc.compressed;
  }
  if (from == BlockCodec::kRaw && to == BlockCodec::kRaw) {
    return std::vector<std::uint8_t>(data, data + size);
  }
  (void)to;
  return decoded;
}

std::vector<std::uint8_t> CodecRegistry::transcode_17(BlockCodec from, BlockCodec to, const std::uint8_t* data, std::size_t size) {
  auto decoded = decode_block_payload(from, data, size);
  if (to == BlockCodec::kRaw) return decoded;
  if (to == BlockCodec::kSimpleRle) {
    const auto enc = BlockEncoder::encode_block_17(decoded.data(), decoded.size(), BlockCodec::kSimpleRle);
    return enc.compressed;
  }
  if (from == BlockCodec::kRaw && to == BlockCodec::kRaw) {
    return std::vector<std::uint8_t>(data, data + size);
  }
  (void)to;
  return decoded;
}

std::vector<std::uint8_t> CodecRegistry::transcode_18(BlockCodec from, BlockCodec to, const std::uint8_t* data, std::size_t size) {
  auto decoded = decode_block_payload(from, data, size);
  if (to == BlockCodec::kRaw) return decoded;
  if (to == BlockCodec::kSimpleRle) {
    const auto enc = BlockEncoder::encode_block_18(decoded.data(), decoded.size(), BlockCodec::kSimpleRle);
    return enc.compressed;
  }
  if (from == BlockCodec::kRaw && to == BlockCodec::kRaw) {
    return std::vector<std::uint8_t>(data, data + size);
  }
  (void)to;
  return decoded;
}

std::vector<std::uint8_t> CodecRegistry::transcode_19(BlockCodec from, BlockCodec to, const std::uint8_t* data, std::size_t size) {
  auto decoded = decode_block_payload(from, data, size);
  if (to == BlockCodec::kRaw) return decoded;
  if (to == BlockCodec::kSimpleRle) {
    const auto enc = BlockEncoder::encode_block_19(decoded.data(), decoded.size(), BlockCodec::kSimpleRle);
    return enc.compressed;
  }
  if (from == BlockCodec::kRaw && to == BlockCodec::kRaw) {
    return std::vector<std::uint8_t>(data, data + size);
  }
  (void)to;
  return decoded;
}

std::vector<std::uint8_t> CodecRegistry::transcode_20(BlockCodec from, BlockCodec to, const std::uint8_t* data, std::size_t size) {
  auto decoded = decode_block_payload(from, data, size);
  if (to == BlockCodec::kRaw) return decoded;
  if (to == BlockCodec::kSimpleRle) {
    const auto enc = BlockEncoder::encode_block_20(decoded.data(), decoded.size(), BlockCodec::kSimpleRle);
    return enc.compressed;
  }
  if (from == BlockCodec::kRaw && to == BlockCodec::kRaw) {
    return std::vector<std::uint8_t>(data, data + size);
  }
  (void)to;
  return decoded;
}

std::vector<std::uint8_t> CodecRegistry::transcode_21(BlockCodec from, BlockCodec to, const std::uint8_t* data, std::size_t size) {
  auto decoded = decode_block_payload(from, data, size);
  if (to == BlockCodec::kRaw) return decoded;
  if (to == BlockCodec::kSimpleRle) {
    const auto enc = BlockEncoder::encode_block_21(decoded.data(), decoded.size(), BlockCodec::kSimpleRle);
    return enc.compressed;
  }
  if (from == BlockCodec::kRaw && to == BlockCodec::kRaw) {
    return std::vector<std::uint8_t>(data, data + size);
  }
  (void)to;
  return decoded;
}

std::vector<std::uint8_t> CodecRegistry::transcode_22(BlockCodec from, BlockCodec to, const std::uint8_t* data, std::size_t size) {
  auto decoded = decode_block_payload(from, data, size);
  if (to == BlockCodec::kRaw) return decoded;
  if (to == BlockCodec::kSimpleRle) {
    const auto enc = BlockEncoder::encode_block_22(decoded.data(), decoded.size(), BlockCodec::kSimpleRle);
    return enc.compressed;
  }
  if (from == BlockCodec::kRaw && to == BlockCodec::kRaw) {
    return std::vector<std::uint8_t>(data, data + size);
  }
  (void)to;
  return decoded;
}

std::vector<std::uint8_t> CodecRegistry::transcode_23(BlockCodec from, BlockCodec to, const std::uint8_t* data, std::size_t size) {
  auto decoded = decode_block_payload(from, data, size);
  if (to == BlockCodec::kRaw) return decoded;
  if (to == BlockCodec::kSimpleRle) {
    const auto enc = BlockEncoder::encode_block_23(decoded.data(), decoded.size(), BlockCodec::kSimpleRle);
    return enc.compressed;
  }
  if (from == BlockCodec::kRaw && to == BlockCodec::kRaw) {
    return std::vector<std::uint8_t>(data, data + size);
  }
  (void)to;
  return decoded;
}

std::vector<std::uint8_t> CodecRegistry::transcode_24(BlockCodec from, BlockCodec to, const std::uint8_t* data, std::size_t size) {
  auto decoded = decode_block_payload(from, data, size);
  if (to == BlockCodec::kRaw) return decoded;
  if (to == BlockCodec::kSimpleRle) {
    const auto enc = BlockEncoder::encode_block_24(decoded.data(), decoded.size(), BlockCodec::kSimpleRle);
    return enc.compressed;
  }
  if (from == BlockCodec::kRaw && to == BlockCodec::kRaw) {
    return std::vector<std::uint8_t>(data, data + size);
  }
  (void)to;
  return decoded;
}

std::vector<std::uint8_t> CodecRegistry::transcode_25(BlockCodec from, BlockCodec to, const std::uint8_t* data, std::size_t size) {
  auto decoded = decode_block_payload(from, data, size);
  if (to == BlockCodec::kRaw) return decoded;
  if (to == BlockCodec::kSimpleRle) {
    const auto enc = BlockEncoder::encode_block_25(decoded.data(), decoded.size(), BlockCodec::kSimpleRle);
    return enc.compressed;
  }
  if (from == BlockCodec::kRaw && to == BlockCodec::kRaw) {
    return std::vector<std::uint8_t>(data, data + size);
  }
  (void)to;
  return decoded;
}

std::vector<std::uint8_t> CodecRegistry::transcode_26(BlockCodec from, BlockCodec to, const std::uint8_t* data, std::size_t size) {
  auto decoded = decode_block_payload(from, data, size);
  if (to == BlockCodec::kRaw) return decoded;
  if (to == BlockCodec::kSimpleRle) {
    const auto enc = BlockEncoder::encode_block_26(decoded.data(), decoded.size(), BlockCodec::kSimpleRle);
    return enc.compressed;
  }
  if (from == BlockCodec::kRaw && to == BlockCodec::kRaw) {
    return std::vector<std::uint8_t>(data, data + size);
  }
  (void)to;
  return decoded;
}

std::vector<std::uint8_t> CodecRegistry::transcode_27(BlockCodec from, BlockCodec to, const std::uint8_t* data, std::size_t size) {
  auto decoded = decode_block_payload(from, data, size);
  if (to == BlockCodec::kRaw) return decoded;
  if (to == BlockCodec::kSimpleRle) {
    const auto enc = BlockEncoder::encode_block_27(decoded.data(), decoded.size(), BlockCodec::kSimpleRle);
    return enc.compressed;
  }
  if (from == BlockCodec::kRaw && to == BlockCodec::kRaw) {
    return std::vector<std::uint8_t>(data, data + size);
  }
  (void)to;
  return decoded;
}

std::vector<std::uint8_t> CodecRegistry::transcode_28(BlockCodec from, BlockCodec to, const std::uint8_t* data, std::size_t size) {
  auto decoded = decode_block_payload(from, data, size);
  if (to == BlockCodec::kRaw) return decoded;
  if (to == BlockCodec::kSimpleRle) {
    const auto enc = BlockEncoder::encode_block_28(decoded.data(), decoded.size(), BlockCodec::kSimpleRle);
    return enc.compressed;
  }
  if (from == BlockCodec::kRaw && to == BlockCodec::kRaw) {
    return std::vector<std::uint8_t>(data, data + size);
  }
  (void)to;
  return decoded;
}

std::vector<std::uint8_t> CodecRegistry::transcode_29(BlockCodec from, BlockCodec to, const std::uint8_t* data, std::size_t size) {
  auto decoded = decode_block_payload(from, data, size);
  if (to == BlockCodec::kRaw) return decoded;
  if (to == BlockCodec::kSimpleRle) {
    const auto enc = BlockEncoder::encode_block_29(decoded.data(), decoded.size(), BlockCodec::kSimpleRle);
    return enc.compressed;
  }
  if (from == BlockCodec::kRaw && to == BlockCodec::kRaw) {
    return std::vector<std::uint8_t>(data, data + size);
  }
  (void)to;
  return decoded;
}

std::vector<std::uint8_t> CodecRegistry::transcode_30(BlockCodec from, BlockCodec to, const std::uint8_t* data, std::size_t size) {
  auto decoded = decode_block_payload(from, data, size);
  if (to == BlockCodec::kRaw) return decoded;
  if (to == BlockCodec::kSimpleRle) {
    const auto enc = BlockEncoder::encode_block_30(decoded.data(), decoded.size(), BlockCodec::kSimpleRle);
    return enc.compressed;
  }
  if (from == BlockCodec::kRaw && to == BlockCodec::kRaw) {
    return std::vector<std::uint8_t>(data, data + size);
  }
  (void)to;
  return decoded;
}


std::vector<std::uint8_t> CodecRegistry::transcode(BlockCodec from, BlockCodec to, const std::uint8_t* data, std::size_t size) {
  return transcode_1(from, to, data, size);
}

}  // namespace rifttrace
