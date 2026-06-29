// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT

#include "rifttrace/rifttrace.hpp"

#include <cassert>
#include <vector>

int main() {
  rifttrace::FrameIndex index;
  index.insert({10, 0, 0});
  index.insert({20, 32, 30});
  assert(index.entries().size() == 2);

  const auto found = index.find_by_record(20);
  assert(found.has_value());
  assert(found->alias_id == 30);

  std::vector<std::uint8_t> raw;
  auto u32 = rifttrace::write_u32_le(2);
  raw.insert(raw.end(), u32.begin(), u32.end());
  for (const auto id : {1u, 10u, 0u, 0u, 2u, 20u, 32u, 30u}) {
    u32 = rifttrace::write_u32_le(id);
    raw.insert(raw.end(), u32.begin(), u32.end());
  }
  const auto parsed = rifttrace::FrameIndex::parse(raw.data(), raw.size());
  assert(parsed.entries().size() == 2);

  rifttrace::TelemetryModel model;
  model.index = parsed;
  const auto built = rifttrace::IndexBuilder(model).build();
  assert(!built.empty());
  return 0;
}
