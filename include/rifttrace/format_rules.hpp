// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT
#pragma once

#include <cstddef>
#include <cstdint>
#include <string>
#include <vector>

#include "rifttrace/format.hpp"

namespace rifttrace {

struct RuleResult {
  std::uint32_t rule_id = 0;
  std::uint16_t version = 0;
  bool passed = false;
  std::string message;
};

class FormatRules {
 public:
  static std::vector<RuleResult> validate_all(const Archive& archive);
  static bool is_supported_version(std::uint16_t version);
  static std::string describe_version(std::uint16_t version);
 private:
  static RuleResult check_v1(const ArchiveHeader& header, std::size_t file_size);
  static RuleResult check_v2(const ArchiveHeader& header, std::size_t file_size);
  static RuleResult check_v3(const ArchiveHeader& header, std::size_t file_size);
  static RuleResult check_v4(const ArchiveHeader& header, std::size_t file_size);
  static RuleResult check_v5(const ArchiveHeader& header, std::size_t file_size);
  static RuleResult check_v6(const ArchiveHeader& header, std::size_t file_size);
  static RuleResult check_v7(const ArchiveHeader& header, std::size_t file_size);
  static RuleResult check_v8(const ArchiveHeader& header, std::size_t file_size);
  static RuleResult check_v9(const ArchiveHeader& header, std::size_t file_size);
  static RuleResult check_v10(const ArchiveHeader& header, std::size_t file_size);
  static RuleResult check_v11(const ArchiveHeader& header, std::size_t file_size);
  static RuleResult check_v12(const ArchiveHeader& header, std::size_t file_size);
  static RuleResult check_v13(const ArchiveHeader& header, std::size_t file_size);
  static RuleResult check_v14(const ArchiveHeader& header, std::size_t file_size);
  static RuleResult check_v15(const ArchiveHeader& header, std::size_t file_size);
  static RuleResult check_v16(const ArchiveHeader& header, std::size_t file_size);
  static RuleResult check_v17(const ArchiveHeader& header, std::size_t file_size);
  static RuleResult check_v18(const ArchiveHeader& header, std::size_t file_size);
  static RuleResult check_v19(const ArchiveHeader& header, std::size_t file_size);
  static RuleResult check_v20(const ArchiveHeader& header, std::size_t file_size);
};

}  // namespace rifttrace
