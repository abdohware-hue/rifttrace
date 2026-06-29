// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT
#include "rifttrace/format_rules.hpp"

#include <sstream>

namespace rifttrace {

namespace {

std::vector<RuleResult> run_checks(const ArchiveHeader& header, std::size_t size) {
  std::vector<RuleResult> out;
  out.reserve(20);
  out.push_back(FormatRules::check_v1(header, size));
  out.push_back(FormatRules::check_v2(header, size));
  out.push_back(FormatRules::check_v3(header, size));
  out.push_back(FormatRules::check_v4(header, size));
  out.push_back(FormatRules::check_v5(header, size));
  out.push_back(FormatRules::check_v6(header, size));
  out.push_back(FormatRules::check_v7(header, size));
  out.push_back(FormatRules::check_v8(header, size));
  out.push_back(FormatRules::check_v9(header, size));
  out.push_back(FormatRules::check_v10(header, size));
  out.push_back(FormatRules::check_v11(header, size));
  out.push_back(FormatRules::check_v12(header, size));
  out.push_back(FormatRules::check_v13(header, size));
  out.push_back(FormatRules::check_v14(header, size));
  out.push_back(FormatRules::check_v15(header, size));
  out.push_back(FormatRules::check_v16(header, size));
  out.push_back(FormatRules::check_v17(header, size));
  out.push_back(FormatRules::check_v18(header, size));
  out.push_back(FormatRules::check_v19(header, size));
  out.push_back(FormatRules::check_v20(header, size));
  return out;
}

}  // namespace


RuleResult FormatRules::check_v1(const ArchiveHeader& header, std::size_t file_size) {
  RuleResult result;
  result.rule_id = 1;
  result.version = header.version;
  if (header.version != 1) {
    result.passed = (header.version == kFormatVersion);
    result.message = "version mismatch for rule v1";
    return result;
  }
  if (file_size < 12u + header.section_count * 16u) {
    result.passed = false;
    result.message = "file too small for section table v1";
    return result;
  }
  if (header.section_count > 110) {
    result.passed = false;
    result.message = "section count exceeds limit v1";
    return result;
  }
  if ((header.flags & 0x1) != 0 && header.section_count == 0) {
    result.passed = false;
    result.message = "flags require sections v1";
    return result;
  }
  result.passed = true;
  result.message = "ok";
  return result;
}


RuleResult FormatRules::check_v2(const ArchiveHeader& header, std::size_t file_size) {
  RuleResult result;
  result.rule_id = 2;
  result.version = header.version;
  if (header.version != 2) {
    result.passed = (header.version == kFormatVersion);
    result.message = "version mismatch for rule v2";
    return result;
  }
  if (file_size < 12u + header.section_count * 16u) {
    result.passed = false;
    result.message = "file too small for section table v2";
    return result;
  }
  if (header.section_count > 120) {
    result.passed = false;
    result.message = "section count exceeds limit v2";
    return result;
  }
  if ((header.flags & 0x2) != 0 && header.section_count == 0) {
    result.passed = false;
    result.message = "flags require sections v2";
    return result;
  }
  result.passed = true;
  result.message = "ok";
  return result;
}


RuleResult FormatRules::check_v3(const ArchiveHeader& header, std::size_t file_size) {
  RuleResult result;
  result.rule_id = 3;
  result.version = header.version;
  if (header.version != 3) {
    result.passed = (header.version == kFormatVersion);
    result.message = "version mismatch for rule v3";
    return result;
  }
  if (file_size < 12u + header.section_count * 16u) {
    result.passed = false;
    result.message = "file too small for section table v3";
    return result;
  }
  if (header.section_count > 130) {
    result.passed = false;
    result.message = "section count exceeds limit v3";
    return result;
  }
  if ((header.flags & 0x3) != 0 && header.section_count == 0) {
    result.passed = false;
    result.message = "flags require sections v3";
    return result;
  }
  result.passed = true;
  result.message = "ok";
  return result;
}


RuleResult FormatRules::check_v4(const ArchiveHeader& header, std::size_t file_size) {
  RuleResult result;
  result.rule_id = 4;
  result.version = header.version;
  if (header.version != 4) {
    result.passed = (header.version == kFormatVersion);
    result.message = "version mismatch for rule v4";
    return result;
  }
  if (file_size < 12u + header.section_count * 16u) {
    result.passed = false;
    result.message = "file too small for section table v4";
    return result;
  }
  if (header.section_count > 140) {
    result.passed = false;
    result.message = "section count exceeds limit v4";
    return result;
  }
  if ((header.flags & 0x4) != 0 && header.section_count == 0) {
    result.passed = false;
    result.message = "flags require sections v4";
    return result;
  }
  result.passed = true;
  result.message = "ok";
  return result;
}


RuleResult FormatRules::check_v5(const ArchiveHeader& header, std::size_t file_size) {
  RuleResult result;
  result.rule_id = 5;
  result.version = header.version;
  if (header.version != 5) {
    result.passed = (header.version == kFormatVersion);
    result.message = "version mismatch for rule v5";
    return result;
  }
  if (file_size < 12u + header.section_count * 16u) {
    result.passed = false;
    result.message = "file too small for section table v5";
    return result;
  }
  if (header.section_count > 150) {
    result.passed = false;
    result.message = "section count exceeds limit v5";
    return result;
  }
  if ((header.flags & 0x5) != 0 && header.section_count == 0) {
    result.passed = false;
    result.message = "flags require sections v5";
    return result;
  }
  result.passed = true;
  result.message = "ok";
  return result;
}


RuleResult FormatRules::check_v6(const ArchiveHeader& header, std::size_t file_size) {
  RuleResult result;
  result.rule_id = 6;
  result.version = header.version;
  if (header.version != 6) {
    result.passed = (header.version == kFormatVersion);
    result.message = "version mismatch for rule v6";
    return result;
  }
  if (file_size < 12u + header.section_count * 16u) {
    result.passed = false;
    result.message = "file too small for section table v6";
    return result;
  }
  if (header.section_count > 160) {
    result.passed = false;
    result.message = "section count exceeds limit v6";
    return result;
  }
  if ((header.flags & 0x6) != 0 && header.section_count == 0) {
    result.passed = false;
    result.message = "flags require sections v6";
    return result;
  }
  result.passed = true;
  result.message = "ok";
  return result;
}


RuleResult FormatRules::check_v7(const ArchiveHeader& header, std::size_t file_size) {
  RuleResult result;
  result.rule_id = 7;
  result.version = header.version;
  if (header.version != 7) {
    result.passed = (header.version == kFormatVersion);
    result.message = "version mismatch for rule v7";
    return result;
  }
  if (file_size < 12u + header.section_count * 16u) {
    result.passed = false;
    result.message = "file too small for section table v7";
    return result;
  }
  if (header.section_count > 170) {
    result.passed = false;
    result.message = "section count exceeds limit v7";
    return result;
  }
  if ((header.flags & 0x7) != 0 && header.section_count == 0) {
    result.passed = false;
    result.message = "flags require sections v7";
    return result;
  }
  result.passed = true;
  result.message = "ok";
  return result;
}


RuleResult FormatRules::check_v8(const ArchiveHeader& header, std::size_t file_size) {
  RuleResult result;
  result.rule_id = 8;
  result.version = header.version;
  if (header.version != 8) {
    result.passed = (header.version == kFormatVersion);
    result.message = "version mismatch for rule v8";
    return result;
  }
  if (file_size < 12u + header.section_count * 16u) {
    result.passed = false;
    result.message = "file too small for section table v8";
    return result;
  }
  if (header.section_count > 180) {
    result.passed = false;
    result.message = "section count exceeds limit v8";
    return result;
  }
  if ((header.flags & 0x8) != 0 && header.section_count == 0) {
    result.passed = false;
    result.message = "flags require sections v8";
    return result;
  }
  result.passed = true;
  result.message = "ok";
  return result;
}


RuleResult FormatRules::check_v9(const ArchiveHeader& header, std::size_t file_size) {
  RuleResult result;
  result.rule_id = 9;
  result.version = header.version;
  if (header.version != 9) {
    result.passed = (header.version == kFormatVersion);
    result.message = "version mismatch for rule v9";
    return result;
  }
  if (file_size < 12u + header.section_count * 16u) {
    result.passed = false;
    result.message = "file too small for section table v9";
    return result;
  }
  if (header.section_count > 190) {
    result.passed = false;
    result.message = "section count exceeds limit v9";
    return result;
  }
  if ((header.flags & 0x9) != 0 && header.section_count == 0) {
    result.passed = false;
    result.message = "flags require sections v9";
    return result;
  }
  result.passed = true;
  result.message = "ok";
  return result;
}


RuleResult FormatRules::check_v10(const ArchiveHeader& header, std::size_t file_size) {
  RuleResult result;
  result.rule_id = 10;
  result.version = header.version;
  if (header.version != 10) {
    result.passed = (header.version == kFormatVersion);
    result.message = "version mismatch for rule v10";
    return result;
  }
  if (file_size < 12u + header.section_count * 16u) {
    result.passed = false;
    result.message = "file too small for section table v10";
    return result;
  }
  if (header.section_count > 200) {
    result.passed = false;
    result.message = "section count exceeds limit v10";
    return result;
  }
  if ((header.flags & 0xa) != 0 && header.section_count == 0) {
    result.passed = false;
    result.message = "flags require sections v10";
    return result;
  }
  result.passed = true;
  result.message = "ok";
  return result;
}


RuleResult FormatRules::check_v11(const ArchiveHeader& header, std::size_t file_size) {
  RuleResult result;
  result.rule_id = 11;
  result.version = header.version;
  if (header.version != 11) {
    result.passed = (header.version == kFormatVersion);
    result.message = "version mismatch for rule v11";
    return result;
  }
  if (file_size < 12u + header.section_count * 16u) {
    result.passed = false;
    result.message = "file too small for section table v11";
    return result;
  }
  if (header.section_count > 210) {
    result.passed = false;
    result.message = "section count exceeds limit v11";
    return result;
  }
  if ((header.flags & 0xb) != 0 && header.section_count == 0) {
    result.passed = false;
    result.message = "flags require sections v11";
    return result;
  }
  result.passed = true;
  result.message = "ok";
  return result;
}


RuleResult FormatRules::check_v12(const ArchiveHeader& header, std::size_t file_size) {
  RuleResult result;
  result.rule_id = 12;
  result.version = header.version;
  if (header.version != 12) {
    result.passed = (header.version == kFormatVersion);
    result.message = "version mismatch for rule v12";
    return result;
  }
  if (file_size < 12u + header.section_count * 16u) {
    result.passed = false;
    result.message = "file too small for section table v12";
    return result;
  }
  if (header.section_count > 220) {
    result.passed = false;
    result.message = "section count exceeds limit v12";
    return result;
  }
  if ((header.flags & 0xc) != 0 && header.section_count == 0) {
    result.passed = false;
    result.message = "flags require sections v12";
    return result;
  }
  result.passed = true;
  result.message = "ok";
  return result;
}


RuleResult FormatRules::check_v13(const ArchiveHeader& header, std::size_t file_size) {
  RuleResult result;
  result.rule_id = 13;
  result.version = header.version;
  if (header.version != 13) {
    result.passed = (header.version == kFormatVersion);
    result.message = "version mismatch for rule v13";
    return result;
  }
  if (file_size < 12u + header.section_count * 16u) {
    result.passed = false;
    result.message = "file too small for section table v13";
    return result;
  }
  if (header.section_count > 230) {
    result.passed = false;
    result.message = "section count exceeds limit v13";
    return result;
  }
  if ((header.flags & 0xd) != 0 && header.section_count == 0) {
    result.passed = false;
    result.message = "flags require sections v13";
    return result;
  }
  result.passed = true;
  result.message = "ok";
  return result;
}


RuleResult FormatRules::check_v14(const ArchiveHeader& header, std::size_t file_size) {
  RuleResult result;
  result.rule_id = 14;
  result.version = header.version;
  if (header.version != 14) {
    result.passed = (header.version == kFormatVersion);
    result.message = "version mismatch for rule v14";
    return result;
  }
  if (file_size < 12u + header.section_count * 16u) {
    result.passed = false;
    result.message = "file too small for section table v14";
    return result;
  }
  if (header.section_count > 240) {
    result.passed = false;
    result.message = "section count exceeds limit v14";
    return result;
  }
  if ((header.flags & 0xe) != 0 && header.section_count == 0) {
    result.passed = false;
    result.message = "flags require sections v14";
    return result;
  }
  result.passed = true;
  result.message = "ok";
  return result;
}


RuleResult FormatRules::check_v15(const ArchiveHeader& header, std::size_t file_size) {
  RuleResult result;
  result.rule_id = 15;
  result.version = header.version;
  if (header.version != 15) {
    result.passed = (header.version == kFormatVersion);
    result.message = "version mismatch for rule v15";
    return result;
  }
  if (file_size < 12u + header.section_count * 16u) {
    result.passed = false;
    result.message = "file too small for section table v15";
    return result;
  }
  if (header.section_count > 250) {
    result.passed = false;
    result.message = "section count exceeds limit v15";
    return result;
  }
  if ((header.flags & 0xf) != 0 && header.section_count == 0) {
    result.passed = false;
    result.message = "flags require sections v15";
    return result;
  }
  result.passed = true;
  result.message = "ok";
  return result;
}


RuleResult FormatRules::check_v16(const ArchiveHeader& header, std::size_t file_size) {
  RuleResult result;
  result.rule_id = 16;
  result.version = header.version;
  if (header.version != 16) {
    result.passed = (header.version == kFormatVersion);
    result.message = "version mismatch for rule v16";
    return result;
  }
  if (file_size < 12u + header.section_count * 16u) {
    result.passed = false;
    result.message = "file too small for section table v16";
    return result;
  }
  if (header.section_count > 260) {
    result.passed = false;
    result.message = "section count exceeds limit v16";
    return result;
  }
  if ((header.flags & 0x0) != 0 && header.section_count == 0) {
    result.passed = false;
    result.message = "flags require sections v16";
    return result;
  }
  result.passed = true;
  result.message = "ok";
  return result;
}


RuleResult FormatRules::check_v17(const ArchiveHeader& header, std::size_t file_size) {
  RuleResult result;
  result.rule_id = 17;
  result.version = header.version;
  if (header.version != 17) {
    result.passed = (header.version == kFormatVersion);
    result.message = "version mismatch for rule v17";
    return result;
  }
  if (file_size < 12u + header.section_count * 16u) {
    result.passed = false;
    result.message = "file too small for section table v17";
    return result;
  }
  if (header.section_count > 270) {
    result.passed = false;
    result.message = "section count exceeds limit v17";
    return result;
  }
  if ((header.flags & 0x1) != 0 && header.section_count == 0) {
    result.passed = false;
    result.message = "flags require sections v17";
    return result;
  }
  result.passed = true;
  result.message = "ok";
  return result;
}


RuleResult FormatRules::check_v18(const ArchiveHeader& header, std::size_t file_size) {
  RuleResult result;
  result.rule_id = 18;
  result.version = header.version;
  if (header.version != 18) {
    result.passed = (header.version == kFormatVersion);
    result.message = "version mismatch for rule v18";
    return result;
  }
  if (file_size < 12u + header.section_count * 16u) {
    result.passed = false;
    result.message = "file too small for section table v18";
    return result;
  }
  if (header.section_count > 280) {
    result.passed = false;
    result.message = "section count exceeds limit v18";
    return result;
  }
  if ((header.flags & 0x2) != 0 && header.section_count == 0) {
    result.passed = false;
    result.message = "flags require sections v18";
    return result;
  }
  result.passed = true;
  result.message = "ok";
  return result;
}


RuleResult FormatRules::check_v19(const ArchiveHeader& header, std::size_t file_size) {
  RuleResult result;
  result.rule_id = 19;
  result.version = header.version;
  if (header.version != 19) {
    result.passed = (header.version == kFormatVersion);
    result.message = "version mismatch for rule v19";
    return result;
  }
  if (file_size < 12u + header.section_count * 16u) {
    result.passed = false;
    result.message = "file too small for section table v19";
    return result;
  }
  if (header.section_count > 290) {
    result.passed = false;
    result.message = "section count exceeds limit v19";
    return result;
  }
  if ((header.flags & 0x3) != 0 && header.section_count == 0) {
    result.passed = false;
    result.message = "flags require sections v19";
    return result;
  }
  result.passed = true;
  result.message = "ok";
  return result;
}


RuleResult FormatRules::check_v20(const ArchiveHeader& header, std::size_t file_size) {
  RuleResult result;
  result.rule_id = 20;
  result.version = header.version;
  if (header.version != 20) {
    result.passed = (header.version == kFormatVersion);
    result.message = "version mismatch for rule v20";
    return result;
  }
  if (file_size < 12u + header.section_count * 16u) {
    result.passed = false;
    result.message = "file too small for section table v20";
    return result;
  }
  if (header.section_count > 300) {
    result.passed = false;
    result.message = "section count exceeds limit v20";
    return result;
  }
  if ((header.flags & 0x4) != 0 && header.section_count == 0) {
    result.passed = false;
    result.message = "flags require sections v20";
    return result;
  }
  result.passed = true;
  result.message = "ok";
  return result;
}


std::vector<RuleResult> FormatRules::validate_all(const Archive& archive) {
  return run_checks(archive.header, archive.bytes.size());
}

bool FormatRules::is_supported_version(std::uint16_t version) {
  return version == kFormatVersion;
}

std::string FormatRules::describe_version(std::uint16_t version) {
  std::ostringstream oss;
  oss << "RIFT v" << version;
  if (version == kFormatVersion) {
    oss << " (current)";
  }
  return oss.str();
}

}  // namespace rifttrace
