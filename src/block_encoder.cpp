// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT
#include "rifttrace/block_encoder.hpp"

#include "rifttrace/binary_writer.hpp"
#include "rifttrace/errors.hpp"

namespace rifttrace {


EncodedBlock BlockEncoder::encode_block_1(const std::uint8_t* data, std::size_t size, BlockCodec codec) {
  EncodedBlock out;
  out.block_id = 1;
  out.codec = codec;
  switch (codec) {
    case BlockCodec::kRaw:
      out.compressed = std::vector<std::uint8_t>(data, data + size);
      break;
    case BlockCodec::kSimpleRle: {
      BinaryWriter w;
      w.write_u32_le(static_cast<std::uint32_t>(size));
      for (std::size_t i = 0; i < size; ) {
        std::uint8_t v = data[i];
        std::uint16_t run = 1;
        while (i + run < size && data[i + run] == v && run < 65535) ++run;
        if (run > 3) {
          w.write_u8_le(0xff);
          w.write_u16_le(run);
          w.write_u8_le(v);
          i += run;
        } else {
          w.write_u8_le(v);
          ++i;
        }
      }
      out.compressed = w.bytes();
      break;
    }
    default:
      throw ParseError(ErrorCode::kInvalidBlock, "unsupported codec");
  }
  out.uncompressed_size = static_cast<std::uint32_t>(size);
  out.compressed_size = static_cast<std::uint32_t>(out.compressed.size());
  return out;
}

EncodedBlock BlockEncoder::encode_block_2(const std::uint8_t* data, std::size_t size, BlockCodec codec) {
  EncodedBlock out;
  out.block_id = 2;
  out.codec = codec;
  switch (codec) {
    case BlockCodec::kRaw:
      out.compressed = std::vector<std::uint8_t>(data, data + size);
      break;
    case BlockCodec::kSimpleRle: {
      BinaryWriter w;
      w.write_u32_le(static_cast<std::uint32_t>(size));
      for (std::size_t i = 0; i < size; ) {
        std::uint8_t v = data[i];
        std::uint16_t run = 1;
        while (i + run < size && data[i + run] == v && run < 65535) ++run;
        if (run > 3) {
          w.write_u8_le(0xff);
          w.write_u16_le(run);
          w.write_u8_le(v);
          i += run;
        } else {
          w.write_u8_le(v);
          ++i;
        }
      }
      out.compressed = w.bytes();
      break;
    }
    default:
      throw ParseError(ErrorCode::kInvalidBlock, "unsupported codec");
  }
  out.uncompressed_size = static_cast<std::uint32_t>(size);
  out.compressed_size = static_cast<std::uint32_t>(out.compressed.size());
  return out;
}

EncodedBlock BlockEncoder::encode_block_3(const std::uint8_t* data, std::size_t size, BlockCodec codec) {
  EncodedBlock out;
  out.block_id = 3;
  out.codec = codec;
  switch (codec) {
    case BlockCodec::kRaw:
      out.compressed = std::vector<std::uint8_t>(data, data + size);
      break;
    case BlockCodec::kSimpleRle: {
      BinaryWriter w;
      w.write_u32_le(static_cast<std::uint32_t>(size));
      for (std::size_t i = 0; i < size; ) {
        std::uint8_t v = data[i];
        std::uint16_t run = 1;
        while (i + run < size && data[i + run] == v && run < 65535) ++run;
        if (run > 3) {
          w.write_u8_le(0xff);
          w.write_u16_le(run);
          w.write_u8_le(v);
          i += run;
        } else {
          w.write_u8_le(v);
          ++i;
        }
      }
      out.compressed = w.bytes();
      break;
    }
    default:
      throw ParseError(ErrorCode::kInvalidBlock, "unsupported codec");
  }
  out.uncompressed_size = static_cast<std::uint32_t>(size);
  out.compressed_size = static_cast<std::uint32_t>(out.compressed.size());
  return out;
}

EncodedBlock BlockEncoder::encode_block_4(const std::uint8_t* data, std::size_t size, BlockCodec codec) {
  EncodedBlock out;
  out.block_id = 4;
  out.codec = codec;
  switch (codec) {
    case BlockCodec::kRaw:
      out.compressed = std::vector<std::uint8_t>(data, data + size);
      break;
    case BlockCodec::kSimpleRle: {
      BinaryWriter w;
      w.write_u32_le(static_cast<std::uint32_t>(size));
      for (std::size_t i = 0; i < size; ) {
        std::uint8_t v = data[i];
        std::uint16_t run = 1;
        while (i + run < size && data[i + run] == v && run < 65535) ++run;
        if (run > 3) {
          w.write_u8_le(0xff);
          w.write_u16_le(run);
          w.write_u8_le(v);
          i += run;
        } else {
          w.write_u8_le(v);
          ++i;
        }
      }
      out.compressed = w.bytes();
      break;
    }
    default:
      throw ParseError(ErrorCode::kInvalidBlock, "unsupported codec");
  }
  out.uncompressed_size = static_cast<std::uint32_t>(size);
  out.compressed_size = static_cast<std::uint32_t>(out.compressed.size());
  return out;
}

EncodedBlock BlockEncoder::encode_block_5(const std::uint8_t* data, std::size_t size, BlockCodec codec) {
  EncodedBlock out;
  out.block_id = 5;
  out.codec = codec;
  switch (codec) {
    case BlockCodec::kRaw:
      out.compressed = std::vector<std::uint8_t>(data, data + size);
      break;
    case BlockCodec::kSimpleRle: {
      BinaryWriter w;
      w.write_u32_le(static_cast<std::uint32_t>(size));
      for (std::size_t i = 0; i < size; ) {
        std::uint8_t v = data[i];
        std::uint16_t run = 1;
        while (i + run < size && data[i + run] == v && run < 65535) ++run;
        if (run > 3) {
          w.write_u8_le(0xff);
          w.write_u16_le(run);
          w.write_u8_le(v);
          i += run;
        } else {
          w.write_u8_le(v);
          ++i;
        }
      }
      out.compressed = w.bytes();
      break;
    }
    default:
      throw ParseError(ErrorCode::kInvalidBlock, "unsupported codec");
  }
  out.uncompressed_size = static_cast<std::uint32_t>(size);
  out.compressed_size = static_cast<std::uint32_t>(out.compressed.size());
  return out;
}

EncodedBlock BlockEncoder::encode_block_6(const std::uint8_t* data, std::size_t size, BlockCodec codec) {
  EncodedBlock out;
  out.block_id = 6;
  out.codec = codec;
  switch (codec) {
    case BlockCodec::kRaw:
      out.compressed = std::vector<std::uint8_t>(data, data + size);
      break;
    case BlockCodec::kSimpleRle: {
      BinaryWriter w;
      w.write_u32_le(static_cast<std::uint32_t>(size));
      for (std::size_t i = 0; i < size; ) {
        std::uint8_t v = data[i];
        std::uint16_t run = 1;
        while (i + run < size && data[i + run] == v && run < 65535) ++run;
        if (run > 3) {
          w.write_u8_le(0xff);
          w.write_u16_le(run);
          w.write_u8_le(v);
          i += run;
        } else {
          w.write_u8_le(v);
          ++i;
        }
      }
      out.compressed = w.bytes();
      break;
    }
    default:
      throw ParseError(ErrorCode::kInvalidBlock, "unsupported codec");
  }
  out.uncompressed_size = static_cast<std::uint32_t>(size);
  out.compressed_size = static_cast<std::uint32_t>(out.compressed.size());
  return out;
}

EncodedBlock BlockEncoder::encode_block_7(const std::uint8_t* data, std::size_t size, BlockCodec codec) {
  EncodedBlock out;
  out.block_id = 7;
  out.codec = codec;
  switch (codec) {
    case BlockCodec::kRaw:
      out.compressed = std::vector<std::uint8_t>(data, data + size);
      break;
    case BlockCodec::kSimpleRle: {
      BinaryWriter w;
      w.write_u32_le(static_cast<std::uint32_t>(size));
      for (std::size_t i = 0; i < size; ) {
        std::uint8_t v = data[i];
        std::uint16_t run = 1;
        while (i + run < size && data[i + run] == v && run < 65535) ++run;
        if (run > 3) {
          w.write_u8_le(0xff);
          w.write_u16_le(run);
          w.write_u8_le(v);
          i += run;
        } else {
          w.write_u8_le(v);
          ++i;
        }
      }
      out.compressed = w.bytes();
      break;
    }
    default:
      throw ParseError(ErrorCode::kInvalidBlock, "unsupported codec");
  }
  out.uncompressed_size = static_cast<std::uint32_t>(size);
  out.compressed_size = static_cast<std::uint32_t>(out.compressed.size());
  return out;
}

EncodedBlock BlockEncoder::encode_block_8(const std::uint8_t* data, std::size_t size, BlockCodec codec) {
  EncodedBlock out;
  out.block_id = 8;
  out.codec = codec;
  switch (codec) {
    case BlockCodec::kRaw:
      out.compressed = std::vector<std::uint8_t>(data, data + size);
      break;
    case BlockCodec::kSimpleRle: {
      BinaryWriter w;
      w.write_u32_le(static_cast<std::uint32_t>(size));
      for (std::size_t i = 0; i < size; ) {
        std::uint8_t v = data[i];
        std::uint16_t run = 1;
        while (i + run < size && data[i + run] == v && run < 65535) ++run;
        if (run > 3) {
          w.write_u8_le(0xff);
          w.write_u16_le(run);
          w.write_u8_le(v);
          i += run;
        } else {
          w.write_u8_le(v);
          ++i;
        }
      }
      out.compressed = w.bytes();
      break;
    }
    default:
      throw ParseError(ErrorCode::kInvalidBlock, "unsupported codec");
  }
  out.uncompressed_size = static_cast<std::uint32_t>(size);
  out.compressed_size = static_cast<std::uint32_t>(out.compressed.size());
  return out;
}

EncodedBlock BlockEncoder::encode_block_9(const std::uint8_t* data, std::size_t size, BlockCodec codec) {
  EncodedBlock out;
  out.block_id = 9;
  out.codec = codec;
  switch (codec) {
    case BlockCodec::kRaw:
      out.compressed = std::vector<std::uint8_t>(data, data + size);
      break;
    case BlockCodec::kSimpleRle: {
      BinaryWriter w;
      w.write_u32_le(static_cast<std::uint32_t>(size));
      for (std::size_t i = 0; i < size; ) {
        std::uint8_t v = data[i];
        std::uint16_t run = 1;
        while (i + run < size && data[i + run] == v && run < 65535) ++run;
        if (run > 3) {
          w.write_u8_le(0xff);
          w.write_u16_le(run);
          w.write_u8_le(v);
          i += run;
        } else {
          w.write_u8_le(v);
          ++i;
        }
      }
      out.compressed = w.bytes();
      break;
    }
    default:
      throw ParseError(ErrorCode::kInvalidBlock, "unsupported codec");
  }
  out.uncompressed_size = static_cast<std::uint32_t>(size);
  out.compressed_size = static_cast<std::uint32_t>(out.compressed.size());
  return out;
}

EncodedBlock BlockEncoder::encode_block_10(const std::uint8_t* data, std::size_t size, BlockCodec codec) {
  EncodedBlock out;
  out.block_id = 10;
  out.codec = codec;
  switch (codec) {
    case BlockCodec::kRaw:
      out.compressed = std::vector<std::uint8_t>(data, data + size);
      break;
    case BlockCodec::kSimpleRle: {
      BinaryWriter w;
      w.write_u32_le(static_cast<std::uint32_t>(size));
      for (std::size_t i = 0; i < size; ) {
        std::uint8_t v = data[i];
        std::uint16_t run = 1;
        while (i + run < size && data[i + run] == v && run < 65535) ++run;
        if (run > 3) {
          w.write_u8_le(0xff);
          w.write_u16_le(run);
          w.write_u8_le(v);
          i += run;
        } else {
          w.write_u8_le(v);
          ++i;
        }
      }
      out.compressed = w.bytes();
      break;
    }
    default:
      throw ParseError(ErrorCode::kInvalidBlock, "unsupported codec");
  }
  out.uncompressed_size = static_cast<std::uint32_t>(size);
  out.compressed_size = static_cast<std::uint32_t>(out.compressed.size());
  return out;
}

EncodedBlock BlockEncoder::encode_block_11(const std::uint8_t* data, std::size_t size, BlockCodec codec) {
  EncodedBlock out;
  out.block_id = 11;
  out.codec = codec;
  switch (codec) {
    case BlockCodec::kRaw:
      out.compressed = std::vector<std::uint8_t>(data, data + size);
      break;
    case BlockCodec::kSimpleRle: {
      BinaryWriter w;
      w.write_u32_le(static_cast<std::uint32_t>(size));
      for (std::size_t i = 0; i < size; ) {
        std::uint8_t v = data[i];
        std::uint16_t run = 1;
        while (i + run < size && data[i + run] == v && run < 65535) ++run;
        if (run > 3) {
          w.write_u8_le(0xff);
          w.write_u16_le(run);
          w.write_u8_le(v);
          i += run;
        } else {
          w.write_u8_le(v);
          ++i;
        }
      }
      out.compressed = w.bytes();
      break;
    }
    default:
      throw ParseError(ErrorCode::kInvalidBlock, "unsupported codec");
  }
  out.uncompressed_size = static_cast<std::uint32_t>(size);
  out.compressed_size = static_cast<std::uint32_t>(out.compressed.size());
  return out;
}

EncodedBlock BlockEncoder::encode_block_12(const std::uint8_t* data, std::size_t size, BlockCodec codec) {
  EncodedBlock out;
  out.block_id = 12;
  out.codec = codec;
  switch (codec) {
    case BlockCodec::kRaw:
      out.compressed = std::vector<std::uint8_t>(data, data + size);
      break;
    case BlockCodec::kSimpleRle: {
      BinaryWriter w;
      w.write_u32_le(static_cast<std::uint32_t>(size));
      for (std::size_t i = 0; i < size; ) {
        std::uint8_t v = data[i];
        std::uint16_t run = 1;
        while (i + run < size && data[i + run] == v && run < 65535) ++run;
        if (run > 3) {
          w.write_u8_le(0xff);
          w.write_u16_le(run);
          w.write_u8_le(v);
          i += run;
        } else {
          w.write_u8_le(v);
          ++i;
        }
      }
      out.compressed = w.bytes();
      break;
    }
    default:
      throw ParseError(ErrorCode::kInvalidBlock, "unsupported codec");
  }
  out.uncompressed_size = static_cast<std::uint32_t>(size);
  out.compressed_size = static_cast<std::uint32_t>(out.compressed.size());
  return out;
}

EncodedBlock BlockEncoder::encode_block_13(const std::uint8_t* data, std::size_t size, BlockCodec codec) {
  EncodedBlock out;
  out.block_id = 13;
  out.codec = codec;
  switch (codec) {
    case BlockCodec::kRaw:
      out.compressed = std::vector<std::uint8_t>(data, data + size);
      break;
    case BlockCodec::kSimpleRle: {
      BinaryWriter w;
      w.write_u32_le(static_cast<std::uint32_t>(size));
      for (std::size_t i = 0; i < size; ) {
        std::uint8_t v = data[i];
        std::uint16_t run = 1;
        while (i + run < size && data[i + run] == v && run < 65535) ++run;
        if (run > 3) {
          w.write_u8_le(0xff);
          w.write_u16_le(run);
          w.write_u8_le(v);
          i += run;
        } else {
          w.write_u8_le(v);
          ++i;
        }
      }
      out.compressed = w.bytes();
      break;
    }
    default:
      throw ParseError(ErrorCode::kInvalidBlock, "unsupported codec");
  }
  out.uncompressed_size = static_cast<std::uint32_t>(size);
  out.compressed_size = static_cast<std::uint32_t>(out.compressed.size());
  return out;
}

EncodedBlock BlockEncoder::encode_block_14(const std::uint8_t* data, std::size_t size, BlockCodec codec) {
  EncodedBlock out;
  out.block_id = 14;
  out.codec = codec;
  switch (codec) {
    case BlockCodec::kRaw:
      out.compressed = std::vector<std::uint8_t>(data, data + size);
      break;
    case BlockCodec::kSimpleRle: {
      BinaryWriter w;
      w.write_u32_le(static_cast<std::uint32_t>(size));
      for (std::size_t i = 0; i < size; ) {
        std::uint8_t v = data[i];
        std::uint16_t run = 1;
        while (i + run < size && data[i + run] == v && run < 65535) ++run;
        if (run > 3) {
          w.write_u8_le(0xff);
          w.write_u16_le(run);
          w.write_u8_le(v);
          i += run;
        } else {
          w.write_u8_le(v);
          ++i;
        }
      }
      out.compressed = w.bytes();
      break;
    }
    default:
      throw ParseError(ErrorCode::kInvalidBlock, "unsupported codec");
  }
  out.uncompressed_size = static_cast<std::uint32_t>(size);
  out.compressed_size = static_cast<std::uint32_t>(out.compressed.size());
  return out;
}

EncodedBlock BlockEncoder::encode_block_15(const std::uint8_t* data, std::size_t size, BlockCodec codec) {
  EncodedBlock out;
  out.block_id = 15;
  out.codec = codec;
  switch (codec) {
    case BlockCodec::kRaw:
      out.compressed = std::vector<std::uint8_t>(data, data + size);
      break;
    case BlockCodec::kSimpleRle: {
      BinaryWriter w;
      w.write_u32_le(static_cast<std::uint32_t>(size));
      for (std::size_t i = 0; i < size; ) {
        std::uint8_t v = data[i];
        std::uint16_t run = 1;
        while (i + run < size && data[i + run] == v && run < 65535) ++run;
        if (run > 3) {
          w.write_u8_le(0xff);
          w.write_u16_le(run);
          w.write_u8_le(v);
          i += run;
        } else {
          w.write_u8_le(v);
          ++i;
        }
      }
      out.compressed = w.bytes();
      break;
    }
    default:
      throw ParseError(ErrorCode::kInvalidBlock, "unsupported codec");
  }
  out.uncompressed_size = static_cast<std::uint32_t>(size);
  out.compressed_size = static_cast<std::uint32_t>(out.compressed.size());
  return out;
}

EncodedBlock BlockEncoder::encode_block_16(const std::uint8_t* data, std::size_t size, BlockCodec codec) {
  EncodedBlock out;
  out.block_id = 16;
  out.codec = codec;
  switch (codec) {
    case BlockCodec::kRaw:
      out.compressed = std::vector<std::uint8_t>(data, data + size);
      break;
    case BlockCodec::kSimpleRle: {
      BinaryWriter w;
      w.write_u32_le(static_cast<std::uint32_t>(size));
      for (std::size_t i = 0; i < size; ) {
        std::uint8_t v = data[i];
        std::uint16_t run = 1;
        while (i + run < size && data[i + run] == v && run < 65535) ++run;
        if (run > 3) {
          w.write_u8_le(0xff);
          w.write_u16_le(run);
          w.write_u8_le(v);
          i += run;
        } else {
          w.write_u8_le(v);
          ++i;
        }
      }
      out.compressed = w.bytes();
      break;
    }
    default:
      throw ParseError(ErrorCode::kInvalidBlock, "unsupported codec");
  }
  out.uncompressed_size = static_cast<std::uint32_t>(size);
  out.compressed_size = static_cast<std::uint32_t>(out.compressed.size());
  return out;
}

EncodedBlock BlockEncoder::encode_block_17(const std::uint8_t* data, std::size_t size, BlockCodec codec) {
  EncodedBlock out;
  out.block_id = 17;
  out.codec = codec;
  switch (codec) {
    case BlockCodec::kRaw:
      out.compressed = std::vector<std::uint8_t>(data, data + size);
      break;
    case BlockCodec::kSimpleRle: {
      BinaryWriter w;
      w.write_u32_le(static_cast<std::uint32_t>(size));
      for (std::size_t i = 0; i < size; ) {
        std::uint8_t v = data[i];
        std::uint16_t run = 1;
        while (i + run < size && data[i + run] == v && run < 65535) ++run;
        if (run > 3) {
          w.write_u8_le(0xff);
          w.write_u16_le(run);
          w.write_u8_le(v);
          i += run;
        } else {
          w.write_u8_le(v);
          ++i;
        }
      }
      out.compressed = w.bytes();
      break;
    }
    default:
      throw ParseError(ErrorCode::kInvalidBlock, "unsupported codec");
  }
  out.uncompressed_size = static_cast<std::uint32_t>(size);
  out.compressed_size = static_cast<std::uint32_t>(out.compressed.size());
  return out;
}

EncodedBlock BlockEncoder::encode_block_18(const std::uint8_t* data, std::size_t size, BlockCodec codec) {
  EncodedBlock out;
  out.block_id = 18;
  out.codec = codec;
  switch (codec) {
    case BlockCodec::kRaw:
      out.compressed = std::vector<std::uint8_t>(data, data + size);
      break;
    case BlockCodec::kSimpleRle: {
      BinaryWriter w;
      w.write_u32_le(static_cast<std::uint32_t>(size));
      for (std::size_t i = 0; i < size; ) {
        std::uint8_t v = data[i];
        std::uint16_t run = 1;
        while (i + run < size && data[i + run] == v && run < 65535) ++run;
        if (run > 3) {
          w.write_u8_le(0xff);
          w.write_u16_le(run);
          w.write_u8_le(v);
          i += run;
        } else {
          w.write_u8_le(v);
          ++i;
        }
      }
      out.compressed = w.bytes();
      break;
    }
    default:
      throw ParseError(ErrorCode::kInvalidBlock, "unsupported codec");
  }
  out.uncompressed_size = static_cast<std::uint32_t>(size);
  out.compressed_size = static_cast<std::uint32_t>(out.compressed.size());
  return out;
}

EncodedBlock BlockEncoder::encode_block_19(const std::uint8_t* data, std::size_t size, BlockCodec codec) {
  EncodedBlock out;
  out.block_id = 19;
  out.codec = codec;
  switch (codec) {
    case BlockCodec::kRaw:
      out.compressed = std::vector<std::uint8_t>(data, data + size);
      break;
    case BlockCodec::kSimpleRle: {
      BinaryWriter w;
      w.write_u32_le(static_cast<std::uint32_t>(size));
      for (std::size_t i = 0; i < size; ) {
        std::uint8_t v = data[i];
        std::uint16_t run = 1;
        while (i + run < size && data[i + run] == v && run < 65535) ++run;
        if (run > 3) {
          w.write_u8_le(0xff);
          w.write_u16_le(run);
          w.write_u8_le(v);
          i += run;
        } else {
          w.write_u8_le(v);
          ++i;
        }
      }
      out.compressed = w.bytes();
      break;
    }
    default:
      throw ParseError(ErrorCode::kInvalidBlock, "unsupported codec");
  }
  out.uncompressed_size = static_cast<std::uint32_t>(size);
  out.compressed_size = static_cast<std::uint32_t>(out.compressed.size());
  return out;
}

EncodedBlock BlockEncoder::encode_block_20(const std::uint8_t* data, std::size_t size, BlockCodec codec) {
  EncodedBlock out;
  out.block_id = 20;
  out.codec = codec;
  switch (codec) {
    case BlockCodec::kRaw:
      out.compressed = std::vector<std::uint8_t>(data, data + size);
      break;
    case BlockCodec::kSimpleRle: {
      BinaryWriter w;
      w.write_u32_le(static_cast<std::uint32_t>(size));
      for (std::size_t i = 0; i < size; ) {
        std::uint8_t v = data[i];
        std::uint16_t run = 1;
        while (i + run < size && data[i + run] == v && run < 65535) ++run;
        if (run > 3) {
          w.write_u8_le(0xff);
          w.write_u16_le(run);
          w.write_u8_le(v);
          i += run;
        } else {
          w.write_u8_le(v);
          ++i;
        }
      }
      out.compressed = w.bytes();
      break;
    }
    default:
      throw ParseError(ErrorCode::kInvalidBlock, "unsupported codec");
  }
  out.uncompressed_size = static_cast<std::uint32_t>(size);
  out.compressed_size = static_cast<std::uint32_t>(out.compressed.size());
  return out;
}


std::vector<std::uint8_t> BlockEncoder::serialize_section(const std::vector<EncodedBlock>& blocks) {
  BinaryWriter writer;
  writer.write_u32_le(static_cast<std::uint32_t>(blocks.size()));
  for (const auto& block : blocks) {
    writer.write_u32_le(block.block_id);
    writer.write_u8_le(static_cast<std::uint8_t>(block.codec));
    writer.write_u32_le(block.compressed_size);
    writer.write_u32_le(block.uncompressed_size);
    writer.write_bytes(block.compressed.data(), block.compressed.size());
  }
  return writer.bytes();
}

}  // namespace rifttrace
