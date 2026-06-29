// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT

#pragma once

#include <cstddef>
#include <cstdint>
#include <string>
#include <string_view>
#include <vector>

namespace rifttrace {

class StringTable {
 public:
  static StringTable parse(const std::uint8_t* data, std::size_t size);

  std::size_t size() const noexcept { return strings_.size(); }
  bool empty() const noexcept { return strings_.empty(); }

  std::string_view get(std::uint32_t index) const;
  std::uint32_t intern(std::string_view value);
  void compact();

  const std::vector<std::string>& storage() const noexcept { return strings_; }

  std::vector<std::uint8_t> serialize() const;

 private:
  std::vector<std::string> strings_;
  std::vector<std::uint32_t> remap_;
};

}  // namespace rifttrace
