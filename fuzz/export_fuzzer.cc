// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT

#include "rifttrace/rifttrace.hpp"

extern "C" int LLVMFuzzerTestOneInput(const std::uint8_t* data, std::size_t size) {
  try {
    auto model = rifttrace::build_model(rifttrace::parse_archive(data, size));
    rifttrace::Resolver resolver(&model);
    resolver.rebuild();
    rifttrace::Timeline timeline(model);
    const auto summary = rifttrace::export_summary(model, resolver, timeline);
    (void)rifttrace::hash_names(resolver);
    (void)rifttrace::hash_content(model);
    (void)summary.digest;
  } catch (const rifttrace::ParseError&) {
  }
  return 0;
}
