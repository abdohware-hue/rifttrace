// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT
#include "rifttrace/delta_codec.hpp"

#include "rifttrace/errors.hpp"

namespace rifttrace {


std::vector<std::uint8_t> DeltaCodec::encode_window_4(const std::uint8_t* data, std::size_t size) {
  std::vector<std::uint8_t> out;
  if (size == 0) return out;
  out.reserve(size + size / 4 + 8);
  out.push_back(static_cast<std::uint8_t>(4 & 0xff));
  out.push_back(static_cast<std::uint8_t>((4 >> 8) & 0xff));
  std::uint8_t prev[4] = {};
  for (std::size_t i = 0; i < size; ++i) {
    const std::uint8_t base = prev[i % 4];
    const std::uint8_t delta = static_cast<std::uint8_t>(data[i] - base);
    out.push_back(delta);
    prev[i % 4] = data[i];
  }
  return out;
}

std::vector<std::uint8_t> DeltaCodec::decode_window_4(const std::uint8_t* data, std::size_t size, std::size_t expected) {
  if (size < 2) throw ParseError(ErrorCode::kInvalidBlock, "delta header truncated");
  const std::uint16_t win = static_cast<std::uint16_t>(data[0] | (data[1] << 8));
  if (win != 4) throw ParseError(ErrorCode::kInvalidBlock, "delta window mismatch");
  std::vector<std::uint8_t> out;
  out.reserve(expected);
  std::uint8_t prev[4] = {};
  for (std::size_t i = 2; i < size && out.size() < expected; ++i) {
    const std::uint8_t base = prev[out.size() % 4];
    const std::uint8_t value = static_cast<std::uint8_t>(base + data[i]);
    out.push_back(value);
    prev[out.size() % 4] = value;
  }
  if (out.size() != expected) {
    throw ParseError(ErrorCode::kInvalidBlock, "delta decode size mismatch");
  }
  return out;
}

std::vector<std::uint8_t> DeltaCodec::encode_window_8(const std::uint8_t* data, std::size_t size) {
  std::vector<std::uint8_t> out;
  if (size == 0) return out;
  out.reserve(size + size / 8 + 8);
  out.push_back(static_cast<std::uint8_t>(8 & 0xff));
  out.push_back(static_cast<std::uint8_t>((8 >> 8) & 0xff));
  std::uint8_t prev[8] = {};
  for (std::size_t i = 0; i < size; ++i) {
    const std::uint8_t base = prev[i % 8];
    const std::uint8_t delta = static_cast<std::uint8_t>(data[i] - base);
    out.push_back(delta);
    prev[i % 8] = data[i];
  }
  return out;
}

std::vector<std::uint8_t> DeltaCodec::decode_window_8(const std::uint8_t* data, std::size_t size, std::size_t expected) {
  if (size < 2) throw ParseError(ErrorCode::kInvalidBlock, "delta header truncated");
  const std::uint16_t win = static_cast<std::uint16_t>(data[0] | (data[1] << 8));
  if (win != 8) throw ParseError(ErrorCode::kInvalidBlock, "delta window mismatch");
  std::vector<std::uint8_t> out;
  out.reserve(expected);
  std::uint8_t prev[8] = {};
  for (std::size_t i = 2; i < size && out.size() < expected; ++i) {
    const std::uint8_t base = prev[out.size() % 8];
    const std::uint8_t value = static_cast<std::uint8_t>(base + data[i]);
    out.push_back(value);
    prev[out.size() % 8] = value;
  }
  if (out.size() != expected) {
    throw ParseError(ErrorCode::kInvalidBlock, "delta decode size mismatch");
  }
  return out;
}

std::vector<std::uint8_t> DeltaCodec::encode_window_16(const std::uint8_t* data, std::size_t size) {
  std::vector<std::uint8_t> out;
  if (size == 0) return out;
  out.reserve(size + size / 16 + 8);
  out.push_back(static_cast<std::uint8_t>(16 & 0xff));
  out.push_back(static_cast<std::uint8_t>((16 >> 8) & 0xff));
  std::uint8_t prev[16] = {};
  for (std::size_t i = 0; i < size; ++i) {
    const std::uint8_t base = prev[i % 16];
    const std::uint8_t delta = static_cast<std::uint8_t>(data[i] - base);
    out.push_back(delta);
    prev[i % 16] = data[i];
  }
  return out;
}

std::vector<std::uint8_t> DeltaCodec::decode_window_16(const std::uint8_t* data, std::size_t size, std::size_t expected) {
  if (size < 2) throw ParseError(ErrorCode::kInvalidBlock, "delta header truncated");
  const std::uint16_t win = static_cast<std::uint16_t>(data[0] | (data[1] << 8));
  if (win != 16) throw ParseError(ErrorCode::kInvalidBlock, "delta window mismatch");
  std::vector<std::uint8_t> out;
  out.reserve(expected);
  std::uint8_t prev[16] = {};
  for (std::size_t i = 2; i < size && out.size() < expected; ++i) {
    const std::uint8_t base = prev[out.size() % 16];
    const std::uint8_t value = static_cast<std::uint8_t>(base + data[i]);
    out.push_back(value);
    prev[out.size() % 16] = value;
  }
  if (out.size() != expected) {
    throw ParseError(ErrorCode::kInvalidBlock, "delta decode size mismatch");
  }
  return out;
}

std::vector<std::uint8_t> DeltaCodec::encode_window_32(const std::uint8_t* data, std::size_t size) {
  std::vector<std::uint8_t> out;
  if (size == 0) return out;
  out.reserve(size + size / 32 + 8);
  out.push_back(static_cast<std::uint8_t>(32 & 0xff));
  out.push_back(static_cast<std::uint8_t>((32 >> 8) & 0xff));
  std::uint8_t prev[32] = {};
  for (std::size_t i = 0; i < size; ++i) {
    const std::uint8_t base = prev[i % 32];
    const std::uint8_t delta = static_cast<std::uint8_t>(data[i] - base);
    out.push_back(delta);
    prev[i % 32] = data[i];
  }
  return out;
}

std::vector<std::uint8_t> DeltaCodec::decode_window_32(const std::uint8_t* data, std::size_t size, std::size_t expected) {
  if (size < 2) throw ParseError(ErrorCode::kInvalidBlock, "delta header truncated");
  const std::uint16_t win = static_cast<std::uint16_t>(data[0] | (data[1] << 8));
  if (win != 32) throw ParseError(ErrorCode::kInvalidBlock, "delta window mismatch");
  std::vector<std::uint8_t> out;
  out.reserve(expected);
  std::uint8_t prev[32] = {};
  for (std::size_t i = 2; i < size && out.size() < expected; ++i) {
    const std::uint8_t base = prev[out.size() % 32];
    const std::uint8_t value = static_cast<std::uint8_t>(base + data[i]);
    out.push_back(value);
    prev[out.size() % 32] = value;
  }
  if (out.size() != expected) {
    throw ParseError(ErrorCode::kInvalidBlock, "delta decode size mismatch");
  }
  return out;
}

std::vector<std::uint8_t> DeltaCodec::encode_window_64(const std::uint8_t* data, std::size_t size) {
  std::vector<std::uint8_t> out;
  if (size == 0) return out;
  out.reserve(size + size / 64 + 8);
  out.push_back(static_cast<std::uint8_t>(64 & 0xff));
  out.push_back(static_cast<std::uint8_t>((64 >> 8) & 0xff));
  std::uint8_t prev[64] = {};
  for (std::size_t i = 0; i < size; ++i) {
    const std::uint8_t base = prev[i % 64];
    const std::uint8_t delta = static_cast<std::uint8_t>(data[i] - base);
    out.push_back(delta);
    prev[i % 64] = data[i];
  }
  return out;
}

std::vector<std::uint8_t> DeltaCodec::decode_window_64(const std::uint8_t* data, std::size_t size, std::size_t expected) {
  if (size < 2) throw ParseError(ErrorCode::kInvalidBlock, "delta header truncated");
  const std::uint16_t win = static_cast<std::uint16_t>(data[0] | (data[1] << 8));
  if (win != 64) throw ParseError(ErrorCode::kInvalidBlock, "delta window mismatch");
  std::vector<std::uint8_t> out;
  out.reserve(expected);
  std::uint8_t prev[64] = {};
  for (std::size_t i = 2; i < size && out.size() < expected; ++i) {
    const std::uint8_t base = prev[out.size() % 64];
    const std::uint8_t value = static_cast<std::uint8_t>(base + data[i]);
    out.push_back(value);
    prev[out.size() % 64] = value;
  }
  if (out.size() != expected) {
    throw ParseError(ErrorCode::kInvalidBlock, "delta decode size mismatch");
  }
  return out;
}

std::vector<std::uint8_t> DeltaCodec::encode_window_128(const std::uint8_t* data, std::size_t size) {
  std::vector<std::uint8_t> out;
  if (size == 0) return out;
  out.reserve(size + size / 128 + 8);
  out.push_back(static_cast<std::uint8_t>(128 & 0xff));
  out.push_back(static_cast<std::uint8_t>((128 >> 8) & 0xff));
  std::uint8_t prev[128] = {};
  for (std::size_t i = 0; i < size; ++i) {
    const std::uint8_t base = prev[i % 128];
    const std::uint8_t delta = static_cast<std::uint8_t>(data[i] - base);
    out.push_back(delta);
    prev[i % 128] = data[i];
  }
  return out;
}

std::vector<std::uint8_t> DeltaCodec::decode_window_128(const std::uint8_t* data, std::size_t size, std::size_t expected) {
  if (size < 2) throw ParseError(ErrorCode::kInvalidBlock, "delta header truncated");
  const std::uint16_t win = static_cast<std::uint16_t>(data[0] | (data[1] << 8));
  if (win != 128) throw ParseError(ErrorCode::kInvalidBlock, "delta window mismatch");
  std::vector<std::uint8_t> out;
  out.reserve(expected);
  std::uint8_t prev[128] = {};
  for (std::size_t i = 2; i < size && out.size() < expected; ++i) {
    const std::uint8_t base = prev[out.size() % 128];
    const std::uint8_t value = static_cast<std::uint8_t>(base + data[i]);
    out.push_back(value);
    prev[out.size() % 128] = value;
  }
  if (out.size() != expected) {
    throw ParseError(ErrorCode::kInvalidBlock, "delta decode size mismatch");
  }
  return out;
}

std::vector<std::uint8_t> DeltaCodec::encode_window_256(const std::uint8_t* data, std::size_t size) {
  std::vector<std::uint8_t> out;
  if (size == 0) return out;
  out.reserve(size + size / 256 + 8);
  out.push_back(static_cast<std::uint8_t>(256 & 0xff));
  out.push_back(static_cast<std::uint8_t>((256 >> 8) & 0xff));
  std::uint8_t prev[256] = {};
  for (std::size_t i = 0; i < size; ++i) {
    const std::uint8_t base = prev[i % 256];
    const std::uint8_t delta = static_cast<std::uint8_t>(data[i] - base);
    out.push_back(delta);
    prev[i % 256] = data[i];
  }
  return out;
}

std::vector<std::uint8_t> DeltaCodec::decode_window_256(const std::uint8_t* data, std::size_t size, std::size_t expected) {
  if (size < 2) throw ParseError(ErrorCode::kInvalidBlock, "delta header truncated");
  const std::uint16_t win = static_cast<std::uint16_t>(data[0] | (data[1] << 8));
  if (win != 256) throw ParseError(ErrorCode::kInvalidBlock, "delta window mismatch");
  std::vector<std::uint8_t> out;
  out.reserve(expected);
  std::uint8_t prev[256] = {};
  for (std::size_t i = 2; i < size && out.size() < expected; ++i) {
    const std::uint8_t base = prev[out.size() % 256];
    const std::uint8_t value = static_cast<std::uint8_t>(base + data[i]);
    out.push_back(value);
    prev[out.size() % 256] = value;
  }
  if (out.size() != expected) {
    throw ParseError(ErrorCode::kInvalidBlock, "delta decode size mismatch");
  }
  return out;
}

std::vector<std::uint8_t> DeltaCodec::encode_window_512(const std::uint8_t* data, std::size_t size) {
  std::vector<std::uint8_t> out;
  if (size == 0) return out;
  out.reserve(size + size / 512 + 8);
  out.push_back(static_cast<std::uint8_t>(512 & 0xff));
  out.push_back(static_cast<std::uint8_t>((512 >> 8) & 0xff));
  std::uint8_t prev[512] = {};
  for (std::size_t i = 0; i < size; ++i) {
    const std::uint8_t base = prev[i % 512];
    const std::uint8_t delta = static_cast<std::uint8_t>(data[i] - base);
    out.push_back(delta);
    prev[i % 512] = data[i];
  }
  return out;
}

std::vector<std::uint8_t> DeltaCodec::decode_window_512(const std::uint8_t* data, std::size_t size, std::size_t expected) {
  if (size < 2) throw ParseError(ErrorCode::kInvalidBlock, "delta header truncated");
  const std::uint16_t win = static_cast<std::uint16_t>(data[0] | (data[1] << 8));
  if (win != 512) throw ParseError(ErrorCode::kInvalidBlock, "delta window mismatch");
  std::vector<std::uint8_t> out;
  out.reserve(expected);
  std::uint8_t prev[512] = {};
  for (std::size_t i = 2; i < size && out.size() < expected; ++i) {
    const std::uint8_t base = prev[out.size() % 512];
    const std::uint8_t value = static_cast<std::uint8_t>(base + data[i]);
    out.push_back(value);
    prev[out.size() % 512] = value;
  }
  if (out.size() != expected) {
    throw ParseError(ErrorCode::kInvalidBlock, "delta decode size mismatch");
  }
  return out;
}


std::vector<std::uint8_t> DeltaCodec::encode_auto(const std::uint8_t* data, std::size_t size) {
  if (size < 64) return encode_window_4(data, size);
  if (size < 256) return encode_window_16(data, size);
  if (size < 1024) return encode_window_64(data, size);
  return encode_window_256(data, size);
}

std::vector<std::uint8_t> DeltaCodec::decode_auto(const std::uint8_t* data, std::size_t size, std::size_t expected) {
  if (size < 2) throw ParseError(ErrorCode::kInvalidBlock, "delta auto truncated");
  const std::uint16_t win = static_cast<std::uint16_t>(data[0] | (data[1] << 8));
  switch (win) {
    case 4: return decode_window_4(data, size, expected);
    case 8: return decode_window_8(data, size, expected);
    case 16: return decode_window_16(data, size, expected);
    case 32: return decode_window_32(data, size, expected);
    case 64: return decode_window_64(data, size, expected);
    case 128: return decode_window_128(data, size, expected);
    case 256: return decode_window_256(data, size, expected);
    case 512: return decode_window_512(data, size, expected);
    default: throw ParseError(ErrorCode::kInvalidBlock, "unknown delta window");
  }
}

}  // namespace rifttrace
