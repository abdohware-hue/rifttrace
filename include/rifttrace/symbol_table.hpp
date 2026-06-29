// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT

#pragma once

#include <cstdint>
#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>

namespace rifttrace {

class SymbolTable {
 public:
  std::uint32_t intern(std::string_view symbol);
  std::string_view resolve(std::uint32_t index) const;
  std::size_t size() const noexcept { return symbols_.size(); }

  void rebuild_from_strings(const std::vector<std::string>& names);

 private:
  std::vector<std::string> symbols_;
  std::unordered_map<std::string, std::uint32_t> lookup_;
};

}  // namespace rifttrace
