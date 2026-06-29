// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT

#include "rifttrace/rifttrace.hpp"

extern "C" int LLVMFuzzerTestOneInput(const std::uint8_t* data, std::size_t size) {
  try {
    const auto archive = rifttrace::parse_archive(data, size);
    auto model = rifttrace::build_model(archive);
    rifttrace::Resolver resolver(&model);
    resolver.rebuild();
    rifttrace::Timeline timeline(model);
    (void)rifttrace::export_summary(model, resolver, timeline);
    (void)rifttrace::collect_diagnostics(model);
  } catch (const rifttrace::ParseError&) {
  }
  return 0;
}
