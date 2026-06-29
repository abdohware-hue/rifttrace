// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT

#include "rifttrace/format.hpp"

namespace rifttrace {

std::string section_type_name(std::uint32_t type) {
  char name[5] = {
      static_cast<char>((type >> 0) & 0xff),
      static_cast<char>((type >> 8) & 0xff),
      static_cast<char>((type >> 16) & 0xff),
      static_cast<char>((type >> 24) & 0xff),
      '\0',
  };
  return std::string(name);
}

}  // namespace rifttrace
