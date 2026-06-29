// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT

#include "rifttrace/rifttrace.hpp"

#include <iostream>

namespace rifttrace {
namespace cli {

int dump_archive(const char* path) {
  try {
    auto model = build_model(parse_archive_file(path));
    Resolver resolver(&model);
    Timeline timeline(model);
    const auto summary = export_summary(model, resolver, timeline);
    const auto diagnostics = collect_diagnostics(model);

    std::cout << "RIFT archive v" << model.archive.header.version << '\n';
    std::cout << "sections: " << model.archive.sections.size() << '\n';
    std::cout << "objects: " << summary.object_count << '\n';
    std::cout << "frames: " << summary.frame_count << '\n';
    std::cout << "events: " << summary.event_count << '\n';
    std::cout << "aliases: " << summary.alias_count << '\n';
    std::cout << "duration_ns: " << summary.duration_ns << '\n';
    std::cout << "digest: " << summary.digest << '\n';
    std::cout << format_diagnostics(diagnostics);
    return 0;
  } catch (const ParseError& error) {
    std::cerr << "parse error: " << error.what() << '\n';
    return 1;
  }
}

}  // namespace cli
}  // namespace rifttrace

int main(int argc, char** argv) {
  if (argc < 2) {
    std::cerr << "usage: rifttrace-dump <archive.rft>\n";
    return 2;
  }
  return rifttrace::cli::dump_archive(argv[1]);
}
