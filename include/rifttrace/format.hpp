// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT

#pragma once

#include <cstdint>
#include <string>
#include <vector>

namespace rifttrace {

constexpr char kMagic[4] = {'R', 'I', 'F', 'T'};
constexpr std::uint16_t kFormatVersion = 1;

constexpr std::uint32_t kSectionStrs = 0x53545253u;  // STRS
constexpr std::uint32_t kSectionData = 0x41544144u;  // DATA
constexpr std::uint32_t kSectionIdx0 = 0x30584449u;  // IDX0
constexpr std::uint32_t kSectionMeta = 0x4154454du;  // META
constexpr std::uint32_t kSectionCmp0 = 0x30504d43u;  // CMP0

enum class RecordType : std::uint8_t {
  kObject = 1,
  kFrame = 2,
  kEvent = 3,
  kAlias = 4,
};

enum class BlockCodec : std::uint8_t {
  kRaw = 0,
  kSimpleRle = 1,
};

enum class StreamCommand : std::uint8_t {
  kAppendRecord = 1,
  kRebuildStrings = 2,
  kEvictBlock = 3,
  kCompactPool = 4,
  kFinalize = 5,
};

struct ArchiveHeader {
  std::uint16_t version = kFormatVersion;
  std::uint16_t flags = 0;
  std::uint32_t section_count = 0;
};

struct SectionEntry {
  std::uint32_t type = 0;
  std::uint32_t offset = 0;
  std::uint32_t size = 0;
  std::uint32_t flags = 0;
};

struct Archive {
  ArchiveHeader header{};
  std::vector<SectionEntry> sections;
  std::vector<std::uint8_t> bytes;
};

struct ObjectRecord {
  std::uint32_t object_id = 0;
  std::uint32_t name_index = 0;
  std::uint32_t symbol_index = 0;
  std::uint32_t pool_slot = 0;
};

struct FrameRecord {
  std::uint32_t frame_id = 0;
  std::uint64_t timestamp_ns = 0;
  std::uint32_t parent_frame = 0;
  std::uint32_t object_count = 0;
};

struct EventRecord {
  std::uint32_t event_id = 0;
  std::uint32_t frame_id = 0;
  std::uint32_t name_index = 0;
  std::uint8_t severity = 0;
};

struct AliasRecord {
  std::uint32_t alias_id = 0;
  std::uint32_t target_id = 0;
  std::uint32_t name_index = 0;
};

struct IndexEntry {
  std::uint32_t record_id = 0;
  std::uint32_t data_offset = 0;
  std::uint32_t alias_id = 0;
};

struct MetaEntry {
  std::uint32_t key_index = 0;
  std::uint32_t value_index = 0;
};

struct CompressedBlockHeader {
  std::uint32_t block_id = 0;
  BlockCodec codec = BlockCodec::kRaw;
  std::uint32_t compressed_size = 0;
  std::uint32_t uncompressed_size = 0;
};

std::string section_type_name(std::uint32_t type);

}  // namespace rifttrace
