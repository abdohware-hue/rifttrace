// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT

#include "rifttrace/rifttrace.hpp"

extern "C" int LLVMFuzzerTestOneInput(const std::uint8_t* data, std::size_t size) {
  try {
    auto model = rifttrace::build_model(rifttrace::parse_archive(data, size));
    rifttrace::Resolver resolver(&model);
    rifttrace::Timeline timeline(model);
    const auto summary = rifttrace::export_summary(model, resolver, timeline);
    (void)rifttrace::hash_names(resolver);
    (void)rifttrace::hash_content(model);
    (void)rifttrace::EventAggregator::aggregate_all(model, resolver);
    (void)rifttrace::FrameDelta::compute_auto(model);
    (void)rifttrace::JsonReportRenderer::render(model, resolver, summary);
    (void)rifttrace::SummaryBuildEngine::run_all(model, resolver);
    (void)rifttrace::TimelineAnalyticsEngine::run_all(model, resolver);
  } catch (const rifttrace::ParseError&) {
  }
  return 0;
}
