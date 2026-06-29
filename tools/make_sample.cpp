// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT

#include "rifttrace/rifttrace.hpp"

#include <cstring>
#include <fstream>
#include <iostream>
#include <vector>

namespace {

std::vector<std::uint8_t> append_u16(std::vector<std::uint8_t>& out, std::uint16_t v) {
  out.push_back(static_cast<std::uint8_t>(v & 0xff));
  out.push_back(static_cast<std::uint8_t>((v >> 8) & 0xff));
  return out;
}

std::vector<std::uint8_t> append_u32(std::vector<std::uint8_t>& out, std::uint32_t v) {
  out.push_back(static_cast<std::uint8_t>(v & 0xff));
  out.push_back(static_cast<std::uint8_t>((v >> 8) & 0xff));
  out.push_back(static_cast<std::uint8_t>((v >> 16) & 0xff));
  out.push_back(static_cast<std::uint8_t>((v >> 24) & 0xff));
  return out;
}

std::vector<std::uint8_t> build_strings() {
  rifttrace::StringTable table;
  table.intern("sensor.alpha");
  table.intern("sensor.beta");
  table.intern("frame.root");
  table.intern("event.tick");
  table.intern("alias.primary");
  table.intern("SymSensor");
  table.intern("SymAlias");
  return table.serialize();
}

std::vector<std::uint8_t> build_data() {
  std::vector<std::uint8_t> out;
  append_u32(out, 5);

  rifttrace::ObjectRecord obj{1, 0, 5, 0};
  auto obj_payload = rifttrace::encode_object_record(obj);
  out.push_back(static_cast<std::uint8_t>(rifttrace::RecordType::kObject));
  append_u32(out, static_cast<std::uint32_t>(obj_payload.size()));
  out.insert(out.end(), obj_payload.begin(), obj_payload.end());

  rifttrace::FrameRecord frame{10, 1000, 0, 1};
  auto frame_payload = rifttrace::encode_frame_record(frame);
  out.push_back(static_cast<std::uint8_t>(rifttrace::RecordType::kFrame));
  append_u32(out, static_cast<std::uint32_t>(frame_payload.size()));
  out.insert(out.end(), frame_payload.begin(), frame_payload.end());

  rifttrace::EventRecord event{20, 10, 3, 2};
  auto event_payload = rifttrace::encode_event_record(event);
  out.push_back(static_cast<std::uint8_t>(rifttrace::RecordType::kEvent));
  append_u32(out, static_cast<std::uint32_t>(event_payload.size()));
  out.insert(out.end(), event_payload.begin(), event_payload.end());

  rifttrace::AliasRecord alias{30, 1, 4};
  auto alias_payload = rifttrace::encode_alias_record(alias);
  out.push_back(static_cast<std::uint8_t>(rifttrace::RecordType::kAlias));
  append_u32(out, static_cast<std::uint32_t>(alias_payload.size()));
  out.insert(out.end(), alias_payload.begin(), alias_payload.end());

  rifttrace::ObjectRecord obj2{2, 1, 5, 0};
  auto obj2_payload = rifttrace::encode_object_record(obj2);
  out.push_back(static_cast<std::uint8_t>(rifttrace::RecordType::kObject));
  append_u32(out, static_cast<std::uint32_t>(obj2_payload.size()));
  out.insert(out.end(), obj2_payload.begin(), obj2_payload.end());

  return out;
}

std::vector<std::uint8_t> build_index() {
  std::vector<std::uint8_t> out;
  append_u32(out, 3);
  append_u32(out, 1);
  append_u32(out, 0);
  append_u32(out, 0);
  append_u32(out, 10);
  append_u32(out, 32);
  append_u32(out, 0);
  append_u32(out, 30);
  append_u32(out, 64);
  append_u32(out, 30);
  return out;
}

std::vector<std::uint8_t> build_meta() {
  std::vector<std::uint8_t> out;
  append_u32(out, 1);
  append_u32(out, 2);
  append_u32(out, 0);
  return out;
}

std::vector<std::uint8_t> build_cmp0() {
  const std::vector<std::uint8_t> payload = {'h', 'e', 'l', 'l', 'o'};

  std::vector<std::uint8_t> out;
  append_u32(out, 1);
  append_u32(out, 7);
  out.push_back(static_cast<std::uint8_t>(rifttrace::BlockCodec::kRaw));
  append_u32(out, static_cast<std::uint32_t>(payload.size()));
  append_u32(out, static_cast<std::uint32_t>(payload.size()));
  out.insert(out.end(), payload.begin(), payload.end());
  return out;
}

std::vector<std::uint8_t> build_archive() {
  const auto strs = build_strings();
  const auto data = build_data();
  const auto idx0 = build_index();
  const auto meta = build_meta();
  const auto cmp0 = build_cmp0();

  const std::uint32_t section_count = 5;
  const std::uint32_t header_size = 12;
  const std::uint32_t table_size = section_count * 16;
  std::uint32_t cursor = header_size + table_size;

  struct Part {
    std::uint32_t type;
    std::vector<std::uint8_t> bytes;
  };
  std::vector<Part> parts = {
      {rifttrace::kSectionStrs, strs},
      {rifttrace::kSectionData, data},
      {rifttrace::kSectionIdx0, idx0},
      {rifttrace::kSectionMeta, meta},
      {rifttrace::kSectionCmp0, cmp0},
  };

  std::vector<std::uint8_t> out;
  out.insert(out.end(), rifttrace::kMagic, rifttrace::kMagic + 4);
  append_u16(out, rifttrace::kFormatVersion);
  append_u16(out, 0);
  append_u32(out, section_count);

  for (const auto& part : parts) {
    append_u32(out, part.type);
    append_u32(out, cursor);
    append_u32(out, static_cast<std::uint32_t>(part.bytes.size()));
    append_u32(out, 0);
    cursor += static_cast<std::uint32_t>(part.bytes.size());
  }

  for (const auto& part : parts) {
    out.insert(out.end(), part.bytes.begin(), part.bytes.end());
  }
  return out;
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

}  // namespace

int main(int argc, char** argv) {
  const char* output = "sample.rft";
  if (argc >= 2) {
    output = argv[1];
  }
  const auto bytes = build_archive();
  if (!write_file(output, bytes)) {
    std::cerr << "failed to write " << output << '\n';
    return 1;
  }
  try {
    const auto archive = rifttrace::parse_archive(bytes.data(), bytes.size());
    const auto model = rifttrace::build_model(archive);
    (void)model;
  } catch (const rifttrace::ParseError& error) {
    std::cerr << "generated archive is invalid: " << error.what() << '\n';
    return 2;
  }
  std::cout << "wrote " << output << " (" << bytes.size() << " bytes)\n";
  return 0;
}
