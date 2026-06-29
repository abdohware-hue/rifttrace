// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT

#include "rifttrace/rifttrace.hpp"

#include <cassert>
#include <cstdint>
#include <vector>

namespace {

std::vector<std::uint8_t> minimal_archive() {
  std::vector<std::uint8_t> out;
  out.insert(out.end(), rifttrace::kMagic, rifttrace::kMagic + 4);
  auto ver = rifttrace::write_u16_le(rifttrace::kFormatVersion);
  auto flags = rifttrace::write_u16_le(0);
  auto count = rifttrace::write_u32_le(0);
  out.insert(out.end(), ver.begin(), ver.end());
  out.insert(out.end(), flags.begin(), flags.end());
  out.insert(out.end(), count.begin(), count.end());
  return out;
}

}  // namespace

int main() {
  const auto bytes = minimal_archive();
  const auto archive = rifttrace::parse_archive(bytes.data(), bytes.size());
  assert(archive.header.version == rifttrace::kFormatVersion);
  assert(archive.sections.empty());
  const auto model = rifttrace::build_model(archive);
  assert(model.records.decoded.empty());
  return 0;
}
