// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT

#include "rifttrace/rifttrace.hpp"

#include <iostream>

int main(int argc, char** argv) {
  if (argc < 2) {
    std::cerr << "usage: rifttrace-dump-tool <archive.rft>\n";
    return 2;
  }

  try {
    auto model = rifttrace::build_model(rifttrace::parse_archive_file(argv[1]));
    rifttrace::Resolver resolver(&model);
    rifttrace::Timeline timeline(model);
    const auto summary = rifttrace::export_summary(model, resolver, timeline);
    rifttrace::SearchIndex search(model, resolver);
    const auto hits = search.find_substring("sensor");

    std::cout << "archive sections: " << model.archive.sections.size() << '\n';
    std::cout << "records: " << model.records.decoded.size() << '\n';
    std::cout << "search hits: " << hits.size() << '\n';
    std::cout << "digest: " << summary.digest << '\n';
    return 0;
  } catch (const rifttrace::ParseError& error) {
    std::cerr << "error: " << error.what() << '\n';
    return 1;
  }
}
