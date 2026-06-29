// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT

#include "rifttrace/symbol_table.hpp"

namespace rifttrace {

std::uint32_t SymbolTable::intern(std::string_view symbol) {
  const std::string key(symbol);
  const auto it = lookup_.find(key);
  if (it != lookup_.end()) {
    return it->second;
  }
  const auto index = static_cast<std::uint32_t>(symbols_.size());
  symbols_.push_back(key);
  lookup_[key] = index;
  return index;
}

std::string_view SymbolTable::resolve(std::uint32_t index) const {
  if (index >= symbols_.size()) {
    return {};
  }
  return symbols_[index];
}

void SymbolTable::rebuild_from_strings(const std::vector<std::string>& names) {
  symbols_.clear();
  lookup_.clear();
  for (const auto& name : names) {
    intern(name);
  }
}

}  // namespace rifttrace
