// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT

#include "rifttrace/rifttrace.hpp"

extern "C" int LLVMFuzzerTestOneInput(const std::uint8_t* data, std::size_t size) {
  try {
    auto model = rifttrace::build_model(rifttrace::parse_archive(data, size));
    rifttrace::StreamProcessor stream(&model);
    const auto commands = rifttrace::parse_stream_commands(data, size);
    stream.apply_batch(commands);
    stream.finalize();
    rifttrace::Resolver resolver(&model);
    resolver.rebuild();
    rifttrace::Timeline timeline(model);
    (void)rifttrace::export_summary(model, resolver, timeline);
  } catch (const rifttrace::ParseError&) {
  }
  return 0;
}
