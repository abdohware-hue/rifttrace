// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT

#include "rifttrace/rifttrace.hpp"

extern "C" int LLVMFuzzerTestOneInput(const std::uint8_t* data, std::size_t size) {
  try {
    const auto archive = rifttrace::parse_archive(data, size);
    rifttrace::SectionTable table = rifttrace::SectionTable::parse(archive);
    for (const auto& entry : table.entries()) {
      const auto payload = table.payload(archive, entry);
      if (entry.type == rifttrace::kSectionMeta) {
        (void)rifttrace::MetadataParser::parse(payload.data(), payload.size());
      }
    }
    auto model = rifttrace::build_model(archive);
    (void)rifttrace::collect_diagnostics(model);
    (void)rifttrace::MetadataParser::normalize(model.metadata);
    rifttrace::Resolver resolver(&model);
    (void)rifttrace::SectionValidateEngine::run_all(model, resolver);
  } catch (const rifttrace::ParseError&) {
  }
  return 0;
}
