// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT

#include "rifttrace/rifttrace.hpp"

extern "C" int LLVMFuzzerTestOneInput(const std::uint8_t* data, std::size_t size) {
  try {
    const auto archive = rifttrace::parse_archive(data, size);
    auto model = rifttrace::build_model(archive);
    model.strings.compact();
    model.symbols.rebuild_from_strings(model.strings.storage());
    rifttrace::Resolver resolver(&model);
    resolver.rebuild();
    rifttrace::SearchIndex search(model, resolver);
    (void)search.find_substring("sensor");
    (void)rifttrace::collect_diagnostics(model);
  } catch (const rifttrace::ParseError&) {
  }
  return 0;
}
