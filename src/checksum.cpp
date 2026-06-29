// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT

#include "rifttrace/checksum.hpp"

namespace rifttrace {

std::uint64_t fnv1a64(const std::uint8_t* data, std::size_t size, std::uint64_t seed) {
  std::uint64_t hash = seed;
  for (std::size_t i = 0; i < size; ++i) {
    hash ^= static_cast<std::uint64_t>(data[i]);
    hash *= kFnvPrime;
  }
  return hash;
}

std::uint64_t fnv1a64_str(std::string_view text, std::uint64_t seed) {
  return fnv1a64(reinterpret_cast<const std::uint8_t*>(text.data()), text.size(), seed);
}

}  // namespace rifttrace
