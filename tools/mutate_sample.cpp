// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT

#include "rifttrace/rifttrace.hpp"

#include <cstring>
#include <fstream>
#include <iostream>
#include <random>
#include <vector>

namespace {

std::vector<std::uint8_t> read_file(const char* path) {
  std::ifstream input(path, std::ios::binary);
  if (!input) {
    return {};
  }
  return std::vector<std::uint8_t>((std::istreambuf_iterator<char>(input)),
                                   std::istreambuf_iterator<char>());
}

bool write_file(const char* path, const std::vector<std::uint8_t>& bytes) {
  std::ofstream out(path, std::ios::binary);
  if (!out) {
    return false;
  }
  out.write(reinterpret_cast<const char*>(bytes.data()),
            static_cast<std::streamsize>(bytes.size()));
  return static_cast<bool>(out);
}

void flip_bit(std::vector<std::uint8_t>& bytes, std::mt19937& rng) {
  if (bytes.empty()) {
    return;
  }
  const auto index = std::uniform_int_distribution<std::size_t>(0, bytes.size() - 1)(rng);
  const auto bit = std::uniform_int_distribution<int>(0, 7)(rng);
  bytes[index] ^= static_cast<std::uint8_t>(1u << bit);
}

void splice_section_size(std::vector<std::uint8_t>& bytes, std::mt19937& rng) {
  if (bytes.size() < 28) {
    return;
  }
  const auto delta = std::uniform_int_distribution<int>(-3, 3)(rng);
  const std::size_t size_offset = 20;
  const auto current = static_cast<std::int32_t>(bytes[size_offset]) +
                       (static_cast<std::int32_t>(bytes[size_offset + 1]) << 8) +
                       (static_cast<std::int32_t>(bytes[size_offset + 2]) << 16) +
                       (static_cast<std::int32_t>(bytes[size_offset + 3]) << 24);
  const auto adjusted = std::max<std::int32_t>(0, current + delta);
  bytes[size_offset] = static_cast<std::uint8_t>(adjusted & 0xff);
  bytes[size_offset + 1] = static_cast<std::uint8_t>((adjusted >> 8) & 0xff);
  bytes[size_offset + 2] = static_cast<std::uint8_t>((adjusted >> 16) & 0xff);
  bytes[size_offset + 3] = static_cast<std::uint8_t>((adjusted >> 24) & 0xff);
}

void append_stream_tail(std::vector<std::uint8_t>& bytes, std::mt19937& rng) {
  rifttrace::BinaryWriter writer;
  writer.write_u32_le(1);
  writer.write_u8_le(static_cast<std::uint8_t>(rifttrace::StreamCommand::kAppendRecord));
  std::vector<std::uint8_t> payload;
  payload.push_back(static_cast<std::uint8_t>(rifttrace::RecordType::kObject));
  const auto obj = rifttrace::encode_object_record({100 + (rng() % 50), 0, 0, 0});
  const auto len = static_cast<std::uint32_t>(obj.size());
  payload.push_back(static_cast<std::uint8_t>(len & 0xff));
  payload.push_back(static_cast<std::uint8_t>((len >> 8) & 0xff));
  payload.push_back(static_cast<std::uint8_t>((len >> 16) & 0xff));
  payload.push_back(static_cast<std::uint8_t>((len >> 24) & 0xff));
  payload.insert(payload.end(), obj.begin(), obj.end());
  writer.write_u32_le(static_cast<std::uint32_t>(payload.size()));
  writer.write_bytes(payload.data(), payload.size());
  const auto& tail = writer.bytes();
  bytes.insert(bytes.end(), tail.begin(), tail.end());
}

std::vector<std::uint8_t> mutate(std::vector<std::uint8_t> bytes, unsigned seed) {
  std::mt19937 rng(seed);
  const auto strategy = rng() % 4;
  switch (strategy) {
    case 0:
      flip_bit(bytes, rng);
      break;
    case 1:
      splice_section_size(bytes, rng);
      break;
    case 2:
      append_stream_tail(bytes, rng);
      break;
    default:
      flip_bit(bytes, rng);
      splice_section_size(bytes, rng);
      break;
  }
  return bytes;
}

}  // namespace

int main(int argc, char** argv) {
  if (argc < 3) {
    std::cerr << "usage: rifttrace-mutate-sample <input.rft> <output.rft> [seed]\n";
    return 1;
  }
  const char* input = argv[1];
  const char* output = argv[2];
  unsigned seed = 42;
  if (argc >= 4) {
    seed = static_cast<unsigned>(std::stoul(argv[3]));
  }

  auto bytes = read_file(input);
  if (bytes.empty()) {
    std::cerr << "failed to read " << input << '\n';
    return 2;
  }
  if (bytes.size() < 4 || std::memcmp(bytes.data(), rifttrace::kMagic, 4) != 0) {
    std::cerr << "input is not a RIFT archive\n";
    return 3;
  }

  bytes = mutate(std::move(bytes), seed);
  if (!write_file(output, bytes)) {
    std::cerr << "failed to write " << output << '\n';
    return 4;
  }

  try {
    const auto archive = rifttrace::parse_archive(bytes.data(), bytes.size());
    (void)rifttrace::build_model(archive);
  } catch (const rifttrace::ParseError&) {
  }

  std::cout << "wrote mutated sample " << output << " (" << bytes.size() << " bytes)\n";
  return 0;
}
