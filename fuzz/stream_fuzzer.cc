// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT

#include "rifttrace/rifttrace.hpp"

extern "C" int LLVMFuzzerTestOneInput(const std::uint8_t* data, std::size_t size) {
  try {
    auto model = rifttrace::build_model(rifttrace::parse_archive(data, size));
    rifttrace::StreamProcessor stream(&model);
    const auto commands = rifttrace::parse_stream_commands(data, size);
    rifttrace::StreamQueryEngine query(&stream);
    (void)query.execute_batch(commands);
    stream.apply_batch(commands);
    stream.finalize();
    rifttrace::Resolver resolver(&model);
    rifttrace::Timeline timeline(model);
    const auto summary = rifttrace::export_summary(model, resolver, timeline);
    (void)rifttrace::CheckpointReplay::capture(model);
    (void)rifttrace::JsonReportRenderer::render_compact(summary);
  } catch (const rifttrace::ParseError&) {
  }
  return 0;
}
