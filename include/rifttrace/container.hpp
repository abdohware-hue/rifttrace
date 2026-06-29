// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT

#pragma once

#include <cstddef>
#include <cstdint>

#include "rifttrace/format.hpp"

namespace rifttrace {

Archive parse_archive(const std::uint8_t* data, std::size_t size);
Archive parse_archive_file(const char* path);

bool validate_header(const std::uint8_t* data, std::size_t size);
std::uint32_t archive_checksum(const Archive& archive);

}  // namespace rifttrace
