// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT
#include "rifttrace/dictionary_codec.hpp"

#include "rifttrace/errors.hpp"

namespace rifttrace {


std::vector<std::uint8_t> DictionaryCodec::compress_dict_16(const std::uint8_t* data, std::size_t size) {
  std::vector<std::uint8_t> dict;
  dict.reserve(16);
  std::vector<std::uint8_t> out;
  out.push_back(0xD1);
  out.push_back(static_cast<std::uint8_t>(16 & 0xff));
  out.push_back(static_cast<std::uint8_t>((16 >> 8) & 0xff));
  auto find_in_dict = [&](std::uint8_t b) -> int {
    for (std::size_t i = 0; i < dict.size(); ++i) {
      if (dict[i] == b) return static_cast<int>(i);
    }
    return -1;
  };
  for (std::size_t i = 0; i < size; ++i) {
    const auto idx = find_in_dict(data[i]);
    if (idx >= 0) {
      out.push_back(0x80 | static_cast<std::uint8_t>(idx));
    } else {
      if (dict.size() < 16) {
        dict.push_back(data[i]);
        out.push_back(0x00);
        out.push_back(data[i]);
      } else {
        out.push_back(0x00);
        out.push_back(data[i]);
      }
    }
  }
  return out;
}

std::vector<std::uint8_t> DictionaryCodec::decompress_dict_16(const std::uint8_t* data, std::size_t size, std::size_t expected) {
  if (size < 3 || data[0] != 0xD1) {
    throw ParseError(ErrorCode::kInvalidBlock, "bad dictionary header");
  }
  const std::uint16_t cap = static_cast<std::uint16_t>(data[1] | (data[2] << 8));
  if (cap != 16) {
    throw ParseError(ErrorCode::kInvalidBlock, "dictionary size mismatch");
  }
  std::vector<std::uint8_t> dict;
  dict.reserve(16);
  std::vector<std::uint8_t> out;
  out.reserve(expected);
  for (std::size_t i = 3; i < size && out.size() < expected; ++i) {
    const auto tag = data[i];
    if (tag & 0x80) {
      const auto idx = tag & 0x7f;
      if (idx >= dict.size()) {
        throw ParseError(ErrorCode::kInvalidBlock, "dictionary index oob");
      }
      out.push_back(dict[idx]);
    } else {
      if (i + 1 >= size) break;
      const auto literal = data[++i];
      if (dict.size() < 16) dict.push_back(literal);
      out.push_back(literal);
    }
  }
  if (out.size() != expected) {
    throw ParseError(ErrorCode::kInvalidBlock, "dictionary decode size mismatch");
  }
  return out;
}

std::vector<std::uint8_t> DictionaryCodec::compress_dict_32(const std::uint8_t* data, std::size_t size) {
  std::vector<std::uint8_t> dict;
  dict.reserve(32);
  std::vector<std::uint8_t> out;
  out.push_back(0xD1);
  out.push_back(static_cast<std::uint8_t>(32 & 0xff));
  out.push_back(static_cast<std::uint8_t>((32 >> 8) & 0xff));
  auto find_in_dict = [&](std::uint8_t b) -> int {
    for (std::size_t i = 0; i < dict.size(); ++i) {
      if (dict[i] == b) return static_cast<int>(i);
    }
    return -1;
  };
  for (std::size_t i = 0; i < size; ++i) {
    const auto idx = find_in_dict(data[i]);
    if (idx >= 0) {
      out.push_back(0x80 | static_cast<std::uint8_t>(idx));
    } else {
      if (dict.size() < 32) {
        dict.push_back(data[i]);
        out.push_back(0x00);
        out.push_back(data[i]);
      } else {
        out.push_back(0x00);
        out.push_back(data[i]);
      }
    }
  }
  return out;
}

std::vector<std::uint8_t> DictionaryCodec::decompress_dict_32(const std::uint8_t* data, std::size_t size, std::size_t expected) {
  if (size < 3 || data[0] != 0xD1) {
    throw ParseError(ErrorCode::kInvalidBlock, "bad dictionary header");
  }
  const std::uint16_t cap = static_cast<std::uint16_t>(data[1] | (data[2] << 8));
  if (cap != 32) {
    throw ParseError(ErrorCode::kInvalidBlock, "dictionary size mismatch");
  }
  std::vector<std::uint8_t> dict;
  dict.reserve(32);
  std::vector<std::uint8_t> out;
  out.reserve(expected);
  for (std::size_t i = 3; i < size && out.size() < expected; ++i) {
    const auto tag = data[i];
    if (tag & 0x80) {
      const auto idx = tag & 0x7f;
      if (idx >= dict.size()) {
        throw ParseError(ErrorCode::kInvalidBlock, "dictionary index oob");
      }
      out.push_back(dict[idx]);
    } else {
      if (i + 1 >= size) break;
      const auto literal = data[++i];
      if (dict.size() < 32) dict.push_back(literal);
      out.push_back(literal);
    }
  }
  if (out.size() != expected) {
    throw ParseError(ErrorCode::kInvalidBlock, "dictionary decode size mismatch");
  }
  return out;
}

std::vector<std::uint8_t> DictionaryCodec::compress_dict_64(const std::uint8_t* data, std::size_t size) {
  std::vector<std::uint8_t> dict;
  dict.reserve(64);
  std::vector<std::uint8_t> out;
  out.push_back(0xD1);
  out.push_back(static_cast<std::uint8_t>(64 & 0xff));
  out.push_back(static_cast<std::uint8_t>((64 >> 8) & 0xff));
  auto find_in_dict = [&](std::uint8_t b) -> int {
    for (std::size_t i = 0; i < dict.size(); ++i) {
      if (dict[i] == b) return static_cast<int>(i);
    }
    return -1;
  };
  for (std::size_t i = 0; i < size; ++i) {
    const auto idx = find_in_dict(data[i]);
    if (idx >= 0) {
      out.push_back(0x80 | static_cast<std::uint8_t>(idx));
    } else {
      if (dict.size() < 64) {
        dict.push_back(data[i]);
        out.push_back(0x00);
        out.push_back(data[i]);
      } else {
        out.push_back(0x00);
        out.push_back(data[i]);
      }
    }
  }
  return out;
}

std::vector<std::uint8_t> DictionaryCodec::decompress_dict_64(const std::uint8_t* data, std::size_t size, std::size_t expected) {
  if (size < 3 || data[0] != 0xD1) {
    throw ParseError(ErrorCode::kInvalidBlock, "bad dictionary header");
  }
  const std::uint16_t cap = static_cast<std::uint16_t>(data[1] | (data[2] << 8));
  if (cap != 64) {
    throw ParseError(ErrorCode::kInvalidBlock, "dictionary size mismatch");
  }
  std::vector<std::uint8_t> dict;
  dict.reserve(64);
  std::vector<std::uint8_t> out;
  out.reserve(expected);
  for (std::size_t i = 3; i < size && out.size() < expected; ++i) {
    const auto tag = data[i];
    if (tag & 0x80) {
      const auto idx = tag & 0x7f;
      if (idx >= dict.size()) {
        throw ParseError(ErrorCode::kInvalidBlock, "dictionary index oob");
      }
      out.push_back(dict[idx]);
    } else {
      if (i + 1 >= size) break;
      const auto literal = data[++i];
      if (dict.size() < 64) dict.push_back(literal);
      out.push_back(literal);
    }
  }
  if (out.size() != expected) {
    throw ParseError(ErrorCode::kInvalidBlock, "dictionary decode size mismatch");
  }
  return out;
}

std::vector<std::uint8_t> DictionaryCodec::compress_dict_128(const std::uint8_t* data, std::size_t size) {
  std::vector<std::uint8_t> dict;
  dict.reserve(128);
  std::vector<std::uint8_t> out;
  out.push_back(0xD1);
  out.push_back(static_cast<std::uint8_t>(128 & 0xff));
  out.push_back(static_cast<std::uint8_t>((128 >> 8) & 0xff));
  auto find_in_dict = [&](std::uint8_t b) -> int {
    for (std::size_t i = 0; i < dict.size(); ++i) {
      if (dict[i] == b) return static_cast<int>(i);
    }
    return -1;
  };
  for (std::size_t i = 0; i < size; ++i) {
    const auto idx = find_in_dict(data[i]);
    if (idx >= 0) {
      out.push_back(0x80 | static_cast<std::uint8_t>(idx));
    } else {
      if (dict.size() < 128) {
        dict.push_back(data[i]);
        out.push_back(0x00);
        out.push_back(data[i]);
      } else {
        out.push_back(0x00);
        out.push_back(data[i]);
      }
    }
  }
  return out;
}

std::vector<std::uint8_t> DictionaryCodec::decompress_dict_128(const std::uint8_t* data, std::size_t size, std::size_t expected) {
  if (size < 3 || data[0] != 0xD1) {
    throw ParseError(ErrorCode::kInvalidBlock, "bad dictionary header");
  }
  const std::uint16_t cap = static_cast<std::uint16_t>(data[1] | (data[2] << 8));
  if (cap != 128) {
    throw ParseError(ErrorCode::kInvalidBlock, "dictionary size mismatch");
  }
  std::vector<std::uint8_t> dict;
  dict.reserve(128);
  std::vector<std::uint8_t> out;
  out.reserve(expected);
  for (std::size_t i = 3; i < size && out.size() < expected; ++i) {
    const auto tag = data[i];
    if (tag & 0x80) {
      const auto idx = tag & 0x7f;
      if (idx >= dict.size()) {
        throw ParseError(ErrorCode::kInvalidBlock, "dictionary index oob");
      }
      out.push_back(dict[idx]);
    } else {
      if (i + 1 >= size) break;
      const auto literal = data[++i];
      if (dict.size() < 128) dict.push_back(literal);
      out.push_back(literal);
    }
  }
  if (out.size() != expected) {
    throw ParseError(ErrorCode::kInvalidBlock, "dictionary decode size mismatch");
  }
  return out;
}

std::vector<std::uint8_t> DictionaryCodec::compress_dict_256(const std::uint8_t* data, std::size_t size) {
  std::vector<std::uint8_t> dict;
  dict.reserve(256);
  std::vector<std::uint8_t> out;
  out.push_back(0xD1);
  out.push_back(static_cast<std::uint8_t>(256 & 0xff));
  out.push_back(static_cast<std::uint8_t>((256 >> 8) & 0xff));
  auto find_in_dict = [&](std::uint8_t b) -> int {
    for (std::size_t i = 0; i < dict.size(); ++i) {
      if (dict[i] == b) return static_cast<int>(i);
    }
    return -1;
  };
  for (std::size_t i = 0; i < size; ++i) {
    const auto idx = find_in_dict(data[i]);
    if (idx >= 0) {
      out.push_back(0x80 | static_cast<std::uint8_t>(idx));
    } else {
      if (dict.size() < 256) {
        dict.push_back(data[i]);
        out.push_back(0x00);
        out.push_back(data[i]);
      } else {
        out.push_back(0x00);
        out.push_back(data[i]);
      }
    }
  }
  return out;
}

std::vector<std::uint8_t> DictionaryCodec::decompress_dict_256(const std::uint8_t* data, std::size_t size, std::size_t expected) {
  if (size < 3 || data[0] != 0xD1) {
    throw ParseError(ErrorCode::kInvalidBlock, "bad dictionary header");
  }
  const std::uint16_t cap = static_cast<std::uint16_t>(data[1] | (data[2] << 8));
  if (cap != 256) {
    throw ParseError(ErrorCode::kInvalidBlock, "dictionary size mismatch");
  }
  std::vector<std::uint8_t> dict;
  dict.reserve(256);
  std::vector<std::uint8_t> out;
  out.reserve(expected);
  for (std::size_t i = 3; i < size && out.size() < expected; ++i) {
    const auto tag = data[i];
    if (tag & 0x80) {
      const auto idx = tag & 0x7f;
      if (idx >= dict.size()) {
        throw ParseError(ErrorCode::kInvalidBlock, "dictionary index oob");
      }
      out.push_back(dict[idx]);
    } else {
      if (i + 1 >= size) break;
      const auto literal = data[++i];
      if (dict.size() < 256) dict.push_back(literal);
      out.push_back(literal);
    }
  }
  if (out.size() != expected) {
    throw ParseError(ErrorCode::kInvalidBlock, "dictionary decode size mismatch");
  }
  return out;
}

std::vector<std::uint8_t> DictionaryCodec::compress_dict_512(const std::uint8_t* data, std::size_t size) {
  std::vector<std::uint8_t> dict;
  dict.reserve(512);
  std::vector<std::uint8_t> out;
  out.push_back(0xD1);
  out.push_back(static_cast<std::uint8_t>(512 & 0xff));
  out.push_back(static_cast<std::uint8_t>((512 >> 8) & 0xff));
  auto find_in_dict = [&](std::uint8_t b) -> int {
    for (std::size_t i = 0; i < dict.size(); ++i) {
      if (dict[i] == b) return static_cast<int>(i);
    }
    return -1;
  };
  for (std::size_t i = 0; i < size; ++i) {
    const auto idx = find_in_dict(data[i]);
    if (idx >= 0) {
      out.push_back(0x80 | static_cast<std::uint8_t>(idx));
    } else {
      if (dict.size() < 512) {
        dict.push_back(data[i]);
        out.push_back(0x00);
        out.push_back(data[i]);
      } else {
        out.push_back(0x00);
        out.push_back(data[i]);
      }
    }
  }
  return out;
}

std::vector<std::uint8_t> DictionaryCodec::decompress_dict_512(const std::uint8_t* data, std::size_t size, std::size_t expected) {
  if (size < 3 || data[0] != 0xD1) {
    throw ParseError(ErrorCode::kInvalidBlock, "bad dictionary header");
  }
  const std::uint16_t cap = static_cast<std::uint16_t>(data[1] | (data[2] << 8));
  if (cap != 512) {
    throw ParseError(ErrorCode::kInvalidBlock, "dictionary size mismatch");
  }
  std::vector<std::uint8_t> dict;
  dict.reserve(512);
  std::vector<std::uint8_t> out;
  out.reserve(expected);
  for (std::size_t i = 3; i < size && out.size() < expected; ++i) {
    const auto tag = data[i];
    if (tag & 0x80) {
      const auto idx = tag & 0x7f;
      if (idx >= dict.size()) {
        throw ParseError(ErrorCode::kInvalidBlock, "dictionary index oob");
      }
      out.push_back(dict[idx]);
    } else {
      if (i + 1 >= size) break;
      const auto literal = data[++i];
      if (dict.size() < 512) dict.push_back(literal);
      out.push_back(literal);
    }
  }
  if (out.size() != expected) {
    throw ParseError(ErrorCode::kInvalidBlock, "dictionary decode size mismatch");
  }
  return out;
}

std::vector<std::uint8_t> DictionaryCodec::compress_dict_1024(const std::uint8_t* data, std::size_t size) {
  std::vector<std::uint8_t> dict;
  dict.reserve(1024);
  std::vector<std::uint8_t> out;
  out.push_back(0xD1);
  out.push_back(static_cast<std::uint8_t>(1024 & 0xff));
  out.push_back(static_cast<std::uint8_t>((1024 >> 8) & 0xff));
  auto find_in_dict = [&](std::uint8_t b) -> int {
    for (std::size_t i = 0; i < dict.size(); ++i) {
      if (dict[i] == b) return static_cast<int>(i);
    }
    return -1;
  };
  for (std::size_t i = 0; i < size; ++i) {
    const auto idx = find_in_dict(data[i]);
    if (idx >= 0) {
      out.push_back(0x80 | static_cast<std::uint8_t>(idx));
    } else {
      if (dict.size() < 1024) {
        dict.push_back(data[i]);
        out.push_back(0x00);
        out.push_back(data[i]);
      } else {
        out.push_back(0x00);
        out.push_back(data[i]);
      }
    }
  }
  return out;
}

std::vector<std::uint8_t> DictionaryCodec::decompress_dict_1024(const std::uint8_t* data, std::size_t size, std::size_t expected) {
  if (size < 3 || data[0] != 0xD1) {
    throw ParseError(ErrorCode::kInvalidBlock, "bad dictionary header");
  }
  const std::uint16_t cap = static_cast<std::uint16_t>(data[1] | (data[2] << 8));
  if (cap != 1024) {
    throw ParseError(ErrorCode::kInvalidBlock, "dictionary size mismatch");
  }
  std::vector<std::uint8_t> dict;
  dict.reserve(1024);
  std::vector<std::uint8_t> out;
  out.reserve(expected);
  for (std::size_t i = 3; i < size && out.size() < expected; ++i) {
    const auto tag = data[i];
    if (tag & 0x80) {
      const auto idx = tag & 0x7f;
      if (idx >= dict.size()) {
        throw ParseError(ErrorCode::kInvalidBlock, "dictionary index oob");
      }
      out.push_back(dict[idx]);
    } else {
      if (i + 1 >= size) break;
      const auto literal = data[++i];
      if (dict.size() < 1024) dict.push_back(literal);
      out.push_back(literal);
    }
  }
  if (out.size() != expected) {
    throw ParseError(ErrorCode::kInvalidBlock, "dictionary decode size mismatch");
  }
  return out;
}

std::vector<std::uint8_t> DictionaryCodec::compress_dict_2048(const std::uint8_t* data, std::size_t size) {
  std::vector<std::uint8_t> dict;
  dict.reserve(2048);
  std::vector<std::uint8_t> out;
  out.push_back(0xD1);
  out.push_back(static_cast<std::uint8_t>(2048 & 0xff));
  out.push_back(static_cast<std::uint8_t>((2048 >> 8) & 0xff));
  auto find_in_dict = [&](std::uint8_t b) -> int {
    for (std::size_t i = 0; i < dict.size(); ++i) {
      if (dict[i] == b) return static_cast<int>(i);
    }
    return -1;
  };
  for (std::size_t i = 0; i < size; ++i) {
    const auto idx = find_in_dict(data[i]);
    if (idx >= 0) {
      out.push_back(0x80 | static_cast<std::uint8_t>(idx));
    } else {
      if (dict.size() < 2048) {
        dict.push_back(data[i]);
        out.push_back(0x00);
        out.push_back(data[i]);
      } else {
        out.push_back(0x00);
        out.push_back(data[i]);
      }
    }
  }
  return out;
}

std::vector<std::uint8_t> DictionaryCodec::decompress_dict_2048(const std::uint8_t* data, std::size_t size, std::size_t expected) {
  if (size < 3 || data[0] != 0xD1) {
    throw ParseError(ErrorCode::kInvalidBlock, "bad dictionary header");
  }
  const std::uint16_t cap = static_cast<std::uint16_t>(data[1] | (data[2] << 8));
  if (cap != 2048) {
    throw ParseError(ErrorCode::kInvalidBlock, "dictionary size mismatch");
  }
  std::vector<std::uint8_t> dict;
  dict.reserve(2048);
  std::vector<std::uint8_t> out;
  out.reserve(expected);
  for (std::size_t i = 3; i < size && out.size() < expected; ++i) {
    const auto tag = data[i];
    if (tag & 0x80) {
      const auto idx = tag & 0x7f;
      if (idx >= dict.size()) {
        throw ParseError(ErrorCode::kInvalidBlock, "dictionary index oob");
      }
      out.push_back(dict[idx]);
    } else {
      if (i + 1 >= size) break;
      const auto literal = data[++i];
      if (dict.size() < 2048) dict.push_back(literal);
      out.push_back(literal);
    }
  }
  if (out.size() != expected) {
    throw ParseError(ErrorCode::kInvalidBlock, "dictionary decode size mismatch");
  }
  return out;
}


std::vector<std::uint8_t> DictionaryCodec::compress(const std::uint8_t* data, std::size_t size) {
  if (size < 32) return compress_dict_16(data, size);
  if (size < 128) return compress_dict_64(data, size);
  if (size < 512) return compress_dict_256(data, size);
  return compress_dict_1024(data, size);
}

std::vector<std::uint8_t> DictionaryCodec::decompress(const std::uint8_t* data, std::size_t size, std::size_t expected) {
  if (size < 3) throw ParseError(ErrorCode::kInvalidBlock, "dictionary truncated");
  const std::uint16_t cap = static_cast<std::uint16_t>(data[1] | (data[2] << 8));
  switch (cap) {
    case 16: return decompress_dict_16(data, size, expected);
    case 32: return decompress_dict_32(data, size, expected);
    case 64: return decompress_dict_64(data, size, expected);
    case 128: return decompress_dict_128(data, size, expected);
    case 256: return decompress_dict_256(data, size, expected);
    case 512: return decompress_dict_512(data, size, expected);
    case 1024: return decompress_dict_1024(data, size, expected);
    case 2048: return decompress_dict_2048(data, size, expected);
    default: throw ParseError(ErrorCode::kInvalidBlock, "unknown dictionary size");
  }
}

}  // namespace rifttrace
