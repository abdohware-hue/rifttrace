// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT

#pragma once

#include <cstddef>
#include <cstdint>
#include <string_view>

namespace rifttrace {

constexpr std::uint64_t kFnvOffsetBasis = 14695981039346656037ull;
constexpr std::uint64_t kFnvPrime = 1099511628211ull;

std::uint64_t fnv1a64(const std::uint8_t* data, std::size_t size,
                      std::uint64_t seed = kFnvOffsetBasis);
std::uint64_t fnv1a64_str(std::string_view text, std::uint64_t seed = kFnvOffsetBasis);

}  // namespace rifttrace
