// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT

#pragma once

#include <cstdint>
#include <string>
#include <string_view>
#include <vector>

#include "rifttrace/model.hpp"
#include "rifttrace/resolver.hpp"

namespace rifttrace {

struct SearchHit {
  std::uint32_t record_id = 0;
  std::string kind;
  std::string label;
  std::uint64_t timestamp_ns = 0;
};

class SearchIndex {
 public:
  SearchIndex(const TelemetryModel& model, const Resolver& resolver);

  std::vector<SearchHit> find_substring(std::string_view needle) const;
  std::vector<SearchHit> find_by_frame(std::uint32_t frame_id) const;

 private:
  std::vector<SearchHit> hits_;
};

}  // namespace rifttrace
