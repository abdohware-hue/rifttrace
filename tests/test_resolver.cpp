// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT

#include "rifttrace/rifttrace.hpp"

#include <cassert>
#include <vector>

namespace {

std::vector<std::uint8_t> sample_with_alias() {
  rifttrace::StringTable strings;
  strings.intern("object.main");
  strings.intern("alias.view");
  strings.intern("SymMain");
  const auto strs = strings.serialize();

  std::vector<std::uint8_t> data;
  auto append_u32 = [](std::vector<std::uint8_t>& out, std::uint32_t v) {
    const auto b = rifttrace::write_u32_le(v);
    out.insert(out.end(), b.begin(), b.end());
  };
  append_u32(data, 2);
  data.push_back(static_cast<std::uint8_t>(rifttrace::RecordType::kObject));
  auto obj = rifttrace::encode_object_record({1, 0, 2, 0});
  append_u32(data, static_cast<std::uint32_t>(obj.size()));
  data.insert(data.end(), obj.begin(), obj.end());
  data.push_back(static_cast<std::uint8_t>(rifttrace::RecordType::kAlias));
  auto alias = rifttrace::encode_alias_record({30, 1, 1});
  append_u32(data, static_cast<std::uint32_t>(alias.size()));
  data.insert(data.end(), alias.begin(), alias.end());

  struct Part {
    std::uint32_t type;
    std::vector<std::uint8_t> bytes;
  };
  const std::vector<Part> parts = {{rifttrace::kSectionStrs, strs},
                                     {rifttrace::kSectionData, data}};

  std::vector<std::uint8_t> out;
  out.insert(out.end(), rifttrace::kMagic, rifttrace::kMagic + 4);
  const auto ver = rifttrace::write_u16_le(rifttrace::kFormatVersion);
  const auto flags = rifttrace::write_u16_le(0);
  out.insert(out.end(), ver.begin(), ver.end());
  out.insert(out.end(), flags.begin(), flags.end());
  append_u32(out, static_cast<std::uint32_t>(parts.size()));

  std::uint32_t cursor = 12 + static_cast<std::uint32_t>(parts.size()) * 16;
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

}  // namespace

int main() {
  const auto bytes = sample_with_alias();
  auto model = rifttrace::build_model(rifttrace::parse_archive(bytes.data(), bytes.size()));
  rifttrace::Resolver resolver(&model);
  resolver.rebuild();

  const auto object = resolver.resolve_object(1);
  assert(object.has_value());
  assert(object->name == "object.main");

  const auto alias = resolver.resolve_alias(30);
  assert(alias.has_value());
  assert(alias->target_id == 1);
  return 0;
}
