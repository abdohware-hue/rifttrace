// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT

#include "rifttrace/rifttrace.hpp"

extern "C" int LLVMFuzzerTestOneInput(const std::uint8_t* data, std::size_t size) {
  try {
    auto model = rifttrace::build_model(rifttrace::parse_archive(data, size));
    rifttrace::Resolver resolver(&model);
    resolver.rebuild();
    for (const auto& alias : resolver.aliases()) {
      (void)resolver.resolve_alias(alias.alias_id);
      (void)resolver.resolve_object(alias.target_id);
    }
    model.pool.compact();
    resolver.rebuild();
    rifttrace::SearchIndex search(model, resolver);
    (void)search.find_by_frame(0);
  } catch (const rifttrace::ParseError&) {
  }
  return 0;
}
