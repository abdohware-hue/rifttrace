// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT

#include "rifttrace/rifttrace.hpp"

extern "C" int LLVMFuzzerTestOneInput(const std::uint8_t* data, std::size_t size) {
  try {
    const auto archive = rifttrace::parse_archive(data, size);
    (void)rifttrace::FormatRules::validate_all(archive);
    auto model = rifttrace::build_model(archive);
    rifttrace::Resolver resolver(&model);
    rifttrace::Timeline timeline(model);
    const auto summary = rifttrace::export_summary(model, resolver, timeline);
    (void)rifttrace::GraphValidator::validate(model, resolver);
    (void)rifttrace::JsonReportRenderer::render(model, resolver, summary);
    (void)rifttrace::TelemetryPipeline::run(data, size);
    (void)rifttrace::ExportPipeline::run_all(model);
  } catch (const rifttrace::ParseError&) {
  }
  return 0;
}
