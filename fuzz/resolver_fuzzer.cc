// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT

#include "rifttrace/rifttrace.hpp"

extern "C" int LLVMFuzzerTestOneInput(const std::uint8_t* data, std::size_t size) {
  try {
    auto model = rifttrace::build_model(rifttrace::parse_archive(data, size));
    rifttrace::Resolver resolver(&model);
    rifttrace::AliasGraph graph(resolver);
    for (const auto& alias : resolver.aliases()) {
      (void)graph.resolve_chain(alias.alias_id);
      (void)graph.predecessors(alias.target_id);
      (void)resolver.resolve_alias(alias.alias_id);
      (void)resolver.resolve_object(alias.target_id);
    }
    rifttrace::InvertedIndex index(model, resolver);
    (void)index.find_substring("sensor");
    (void)index.search_prefix("Sym");
    rifttrace::SearchIndex search(model, resolver);
    (void)search.find_substring("rift");
    (void)rifttrace::CorrelationEngine::run_all(model, resolver);
  } catch (const rifttrace::ParseError&) {
  }
  return 0;
}
