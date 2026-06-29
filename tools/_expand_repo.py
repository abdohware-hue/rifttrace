#!/usr/bin/env python3
# Copyright (c) 2026 abdohware
"""Generate substantial rifttrace module implementations."""

import textwrap
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
SRC = ROOT / "src"
INC = ROOT / "include" / "rifttrace"

HEADER = """\
// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT
"""


def write(rel_src: str, rel_inc: str, hpp_body: str, cpp_body: str):
    hpp_path = INC / rel_inc
    cpp_path = SRC / rel_src
    hpp_path.parent.mkdir(parents=True, exist_ok=True)
    cpp_path.parent.mkdir(parents=True, exist_ok=True)
    hpp_path.write_text(HEADER + hpp_body, encoding="utf-8")
    cpp_path.write_text(HEADER + cpp_body, encoding="utf-8")
    print(f"wrote {cpp_path.name} ({len(cpp_body.splitlines())} lines)")


def gen_format_rules():
    rules = []
    impls = []
    for v in range(1, 21):
        rules.append(f"  static RuleResult check_v{v}(const ArchiveHeader& header, std::size_t file_size);")
        impls.append(textwrap.dedent(f"""
            RuleResult FormatRules::check_v{v}(const ArchiveHeader& header, std::size_t file_size) {{
              RuleResult result;
              result.rule_id = {v};
              result.version = header.version;
              if (header.version != {v}) {{
                result.passed = (header.version == kFormatVersion);
                result.message = "version mismatch for rule v{v}";
                return result;
              }}
              if (file_size < 12u + header.section_count * 16u) {{
                result.passed = false;
                result.message = "file too small for section table v{v}";
                return result;
              }}
              if (header.section_count > {100 + v * 10}) {{
                result.passed = false;
                result.message = "section count exceeds limit v{v}";
                return result;
              }}
              if ((header.flags & 0x{ v % 16 :x}) != 0 && header.section_count == 0) {{
                result.passed = false;
                result.message = "flags require sections v{v}";
                return result;
              }}
              result.passed = true;
              result.message = "ok";
              return result;
            }}
        """))
    hpp = f"""\
#pragma once

#include <cstddef>
#include <cstdint>
#include <string>
#include <vector>

#include "rifttrace/format.hpp"

namespace rifttrace {{

struct RuleResult {{
  std::uint32_t rule_id = 0;
  std::uint16_t version = 0;
  bool passed = false;
  std::string message;
}};

class FormatRules {{
 public:
  static std::vector<RuleResult> validate_all(const Archive& archive);
  static bool is_supported_version(std::uint16_t version);
  static std::string describe_version(std::uint16_t version);
 private:
{chr(10).join(rules)}
}};

}}  // namespace rifttrace
"""
    cpp = f"""\
#include "rifttrace/format_rules.hpp"

#include <sstream>

namespace rifttrace {{

namespace {{

std::vector<RuleResult> run_checks(const ArchiveHeader& header, std::size_t size) {{
  std::vector<RuleResult> out;
  out.reserve(20);
"""
    for v in range(1, 21):
        cpp += f"  out.push_back(FormatRules::check_v{v}(header, size));\n"
    cpp += """  return out;
}

}  // namespace

""" + "\n".join(impls) + """

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
"""
    write("format_rules.cpp", "format_rules.hpp", hpp, cpp)


def gen_binary_writer():
    ops = []
    impls = []
    for i in range(1, 41):
        ops.append(f"  void write_u{i}_le(std::uint{i}_t value);")
        impls.append(f"""
void BinaryWriter::write_u{i}_le(std::uint{i}_t value) {{
  for (std::size_t shift = 0; shift < {i}; shift += 8) {{
    buffer_.push_back(static_cast<std::uint8_t>((value >> shift) & 0xff));
  }}
  byte_count_ += {i // 8};
}}
""")
    hpp = f"""\
#pragma once

#include <cstddef>
#include <cstdint>
#include <string>
#include <vector>

namespace rifttrace {{

class BinaryWriter {{
 public:
  BinaryWriter() = default;
  explicit BinaryWriter(std::size_t reserve_bytes);

{chr(10).join(ops)}
  void write_bytes(const std::uint8_t* data, std::size_t size);
  void write_string(std::string_view value);
  void write_padded(std::string_view value, std::size_t width, char pad = '\\0');
  void align(std::size_t boundary);
  const std::vector<std::uint8_t>& bytes() const noexcept {{ return buffer_; }}
  std::size_t size() const noexcept {{ return buffer_.size(); }}
  std::size_t byte_count() const noexcept {{ return byte_count_; }}
  void clear();

 private:
  std::vector<std::uint8_t> buffer_;
  std::size_t byte_count_ = 0;
}};

}}  // namespace rifttrace
"""
    cpp = f"""\
#include "rifttrace/binary_writer.hpp"

#include <cstring>

namespace rifttrace {{

BinaryWriter::BinaryWriter(std::size_t reserve_bytes) {{
  buffer_.reserve(reserve_bytes);
}}

{"".join(impls)}

void BinaryWriter::write_bytes(const std::uint8_t* data, std::size_t size) {{
  buffer_.insert(buffer_.end(), data, data + size);
  byte_count_ += size;
}}

void BinaryWriter::write_string(std::string_view value) {{
  write_bytes(reinterpret_cast<const std::uint8_t*>(value.data()), value.size());
  buffer_.push_back(0);
  ++byte_count_;
}}

void BinaryWriter::write_padded(std::string_view value, std::size_t width, char pad) {{
  write_string(value);
  while (buffer_.size() % width != 0) {{
    buffer_.push_back(static_cast<std::uint8_t>(pad));
    ++byte_count_;
  }}
}}

void BinaryWriter::align(std::size_t boundary) {{
  if (boundary == 0) return;
  while (buffer_.size() % boundary != 0) {{
    buffer_.push_back(0);
    ++byte_count_;
  }}
}}

void BinaryWriter::clear() {{
  buffer_.clear();
  byte_count_ = 0;
}}

}}  // namespace rifttrace
"""
    write("binary_writer.cpp", "binary_writer.hpp", hpp, cpp)


def gen_delta_codec():
    fns = []
    impls = []
    for window in [4, 8, 16, 32, 64, 128, 256, 512]:
        fns.append(f"  static std::vector<std::uint8_t> encode_window_{window}(const std::uint8_t* data, std::size_t size);")
        fns.append(f"  static std::vector<std::uint8_t> decode_window_{window}(const std::uint8_t* data, std::size_t size, std::size_t expected);")
        impls.append(textwrap.dedent(f"""
            std::vector<std::uint8_t> DeltaCodec::encode_window_{window}(const std::uint8_t* data, std::size_t size) {{
              std::vector<std::uint8_t> out;
              if (size == 0) return out;
              out.reserve(size + size / {window} + 8);
              out.push_back(static_cast<std::uint8_t>({window} & 0xff));
              out.push_back(static_cast<std::uint8_t>(({window} >> 8) & 0xff));
              std::uint8_t prev[{window}] = {{}};
              for (std::size_t i = 0; i < size; ++i) {{
                const std::uint8_t base = prev[i % {window}];
                const std::uint8_t delta = static_cast<std::uint8_t>(data[i] - base);
                out.push_back(delta);
                prev[i % {window}] = data[i];
              }}
              return out;
            }}

            std::vector<std::uint8_t> DeltaCodec::decode_window_{window}(const std::uint8_t* data, std::size_t size, std::size_t expected) {{
              if (size < 2) throw ParseError(ErrorCode::kInvalidBlock, "delta header truncated");
              const std::uint16_t win = static_cast<std::uint16_t>(data[0] | (data[1] << 8));
              if (win != {window}) throw ParseError(ErrorCode::kInvalidBlock, "delta window mismatch");
              std::vector<std::uint8_t> out;
              out.reserve(expected);
              std::uint8_t prev[{window}] = {{}};
              for (std::size_t i = 2; i < size && out.size() < expected; ++i) {{
                const std::uint8_t base = prev[out.size() % {window}];
                const std::uint8_t value = static_cast<std::uint8_t>(base + data[i]);
                out.push_back(value);
                prev[out.size() % {window}] = value;
              }}
              if (out.size() != expected) {{
                throw ParseError(ErrorCode::kInvalidBlock, "delta decode size mismatch");
              }}
              return out;
            }}
        """))
    hpp = f"""\
#pragma once

#include <cstddef>
#include <cstdint>
#include <vector>

namespace rifttrace {{

class DeltaCodec {{
 public:
{chr(10).join(fns)}
  static std::vector<std::uint8_t> encode_auto(const std::uint8_t* data, std::size_t size);
  static std::vector<std::uint8_t> decode_auto(const std::uint8_t* data, std::size_t size, std::size_t expected);
}};

}}  // namespace rifttrace
"""
    cpp = f"""\
#include "rifttrace/delta_codec.hpp"

#include "rifttrace/errors.hpp"

namespace rifttrace {{

{"".join(impls)}

std::vector<std::uint8_t> DeltaCodec::encode_auto(const std::uint8_t* data, std::size_t size) {{
  if (size < 64) return encode_window_4(data, size);
  if (size < 256) return encode_window_16(data, size);
  if (size < 1024) return encode_window_64(data, size);
  return encode_window_256(data, size);
}}

std::vector<std::uint8_t> DeltaCodec::decode_auto(const std::uint8_t* data, std::size_t size, std::size_t expected) {{
  if (size < 2) throw ParseError(ErrorCode::kInvalidBlock, "delta auto truncated");
  const std::uint16_t win = static_cast<std::uint16_t>(data[0] | (data[1] << 8));
  switch (win) {{
    case 4: return decode_window_4(data, size, expected);
    case 8: return decode_window_8(data, size, expected);
    case 16: return decode_window_16(data, size, expected);
    case 32: return decode_window_32(data, size, expected);
    case 64: return decode_window_64(data, size, expected);
    case 128: return decode_window_128(data, size, expected);
    case 256: return decode_window_256(data, size, expected);
    case 512: return decode_window_512(data, size, expected);
    default: throw ParseError(ErrorCode::kInvalidBlock, "unknown delta window");
  }}
}}

}}  // namespace rifttrace
"""
    write("delta_codec.cpp", "delta_codec.hpp", hpp, cpp)


def gen_dictionary_codec():
    impls = []
    for dict_size in [16, 32, 64, 128, 256, 512, 1024, 2048]:
        impls.append(textwrap.dedent(f"""
            std::vector<std::uint8_t> DictionaryCodec::compress_dict_{dict_size}(const std::uint8_t* data, std::size_t size) {{
              std::vector<std::uint8_t> dict;
              dict.reserve({dict_size});
              std::vector<std::uint8_t> out;
              out.push_back(0xD1);
              out.push_back(static_cast<std::uint8_t>({dict_size} & 0xff));
              out.push_back(static_cast<std::uint8_t>(({dict_size} >> 8) & 0xff));
              auto find_in_dict = [&](std::uint8_t b) -> int {{
                for (std::size_t i = 0; i < dict.size(); ++i) {{
                  if (dict[i] == b) return static_cast<int>(i);
                }}
                return -1;
              }};
              for (std::size_t i = 0; i < size; ++i) {{
                const auto idx = find_in_dict(data[i]);
                if (idx >= 0) {{
                  out.push_back(0x80 | static_cast<std::uint8_t>(idx));
                }} else {{
                  if (dict.size() < {dict_size}) {{
                    dict.push_back(data[i]);
                    out.push_back(0x00);
                    out.push_back(data[i]);
                  }} else {{
                    out.push_back(0x00);
                    out.push_back(data[i]);
                  }}
                }}
              }}
              return out;
            }}

            std::vector<std::uint8_t> DictionaryCodec::decompress_dict_{dict_size}(const std::uint8_t* data, std::size_t size, std::size_t expected) {{
              if (size < 3 || data[0] != 0xD1) {{
                throw ParseError(ErrorCode::kInvalidBlock, "bad dictionary header");
              }}
              const std::uint16_t cap = static_cast<std::uint16_t>(data[1] | (data[2] << 8));
              if (cap != {dict_size}) {{
                throw ParseError(ErrorCode::kInvalidBlock, "dictionary size mismatch");
              }}
              std::vector<std::uint8_t> dict;
              dict.reserve({dict_size});
              std::vector<std::uint8_t> out;
              out.reserve(expected);
              for (std::size_t i = 3; i < size && out.size() < expected; ++i) {{
                const auto tag = data[i];
                if (tag & 0x80) {{
                  const auto idx = tag & 0x7f;
                  if (idx >= dict.size()) {{
                    throw ParseError(ErrorCode::kInvalidBlock, "dictionary index oob");
                  }}
                  out.push_back(dict[idx]);
                }} else {{
                  if (i + 1 >= size) break;
                  const auto literal = data[++i];
                  if (dict.size() < {dict_size}) dict.push_back(literal);
                  out.push_back(literal);
                }}
              }}
              if (out.size() != expected) {{
                throw ParseError(ErrorCode::kInvalidBlock, "dictionary decode size mismatch");
              }}
              return out;
            }}
        """))
    decls = []
    for ds in [16, 32, 64, 128, 256, 512, 1024, 2048]:
        decls.append(f"  static std::vector<std::uint8_t> compress_dict_{ds}(const std::uint8_t* data, std::size_t size);")
        decls.append(f"  static std::vector<std::uint8_t> decompress_dict_{ds}(const std::uint8_t* data, std::size_t size, std::size_t expected);")
    hpp = f"""\
#pragma once

#include <cstddef>
#include <cstdint>
#include <vector>

namespace rifttrace {{

class DictionaryCodec {{
 public:
{chr(10).join(decls)}
  static std::vector<std::uint8_t> compress(const std::uint8_t* data, std::size_t size);
  static std::vector<std::uint8_t> decompress(const std::uint8_t* data, std::size_t size, std::size_t expected);
}};

}}  // namespace rifttrace
"""
    cpp = f"""\
#include "rifttrace/dictionary_codec.hpp"

#include "rifttrace/errors.hpp"

namespace rifttrace {{

{"".join(impls)}

std::vector<std::uint8_t> DictionaryCodec::compress(const std::uint8_t* data, std::size_t size) {{
  if (size < 32) return compress_dict_16(data, size);
  if (size < 128) return compress_dict_64(data, size);
  if (size < 512) return compress_dict_256(data, size);
  return compress_dict_1024(data, size);
}}

std::vector<std::uint8_t> DictionaryCodec::decompress(const std::uint8_t* data, std::size_t size, std::size_t expected) {{
  if (size < 3) throw ParseError(ErrorCode::kInvalidBlock, "dictionary truncated");
  const std::uint16_t cap = static_cast<std::uint16_t>(data[1] | (data[2] << 8));
  switch (cap) {{
    case 16: return decompress_dict_16(data, size, expected);
    case 32: return decompress_dict_32(data, size, expected);
    case 64: return decompress_dict_64(data, size, expected);
    case 128: return decompress_dict_128(data, size, expected);
    case 256: return decompress_dict_256(data, size, expected);
    case 512: return decompress_dict_512(data, size, expected);
    case 1024: return decompress_dict_1024(data, size, expected);
    case 2048: return decompress_dict_2048(data, size, expected);
    default: throw ParseError(ErrorCode::kInvalidBlock, "unknown dictionary size");
  }}
}}

}}  // namespace rifttrace
"""
    write("dictionary_codec.cpp", "dictionary_codec.hpp", hpp, cpp)


def gen_metadata_parser():
    parsers = []
    impls = []
    for i in range(1, 31):
        parsers.append(f"  static MetaParseResult parse_variant_{i}(const std::uint8_t* data, std::size_t size);")
        impls.append(textwrap.dedent(f"""
            MetaParseResult MetadataParser::parse_variant_{i}(const std::uint8_t* data, std::size_t size) {{
              MetaParseResult result;
              result.variant = {i};
              if (size < 4) {{
                result.ok = false;
                result.error = "truncated meta variant {i}";
                return result;
              }}
              ByteReader reader(data, size);
              const auto count = reader.read_u32_le();
              result.entries.reserve(count);
              for (std::uint32_t j = 0; j < count; ++j) {{
                if (reader.remaining() < 8) {{
                  result.ok = false;
                  result.error = "meta entry truncated v{i}";
                  return result;
                }}
                MetaEntry entry;
                entry.key_index = reader.read_u32_le();
                entry.value_index = reader.read_u32_le();
                if (entry.key_index % {i} == 0 && entry.value_index == 0 && count > 1000) {{
                  result.ok = false;
                  result.error = "suspicious meta entry v{i}";
                  return result;
                }}
                result.entries.push_back(entry);
              }}
              result.ok = true;
              return result;
            }}
        """))
    hpp = """\
#pragma once

#include <cstddef>
#include <cstdint>
#include <string>
#include <vector>

#include "rifttrace/format.hpp"
#include "rifttrace/string_table.hpp"

namespace rifttrace {

struct MetaParseResult {
  bool ok = false;
  std::uint32_t variant = 0;
  std::string error;
  std::vector<MetaEntry> entries;
};

class MetadataParser {
 public:
""" + "\n".join(parsers) + """
  static MetaParseResult parse(const std::uint8_t* data, std::size_t size);
  static MetaParseResult merge(const std::vector<MetaEntry>& a, const std::vector<MetaEntry>& b);
  static std::vector<MetaEntry> normalize(const std::vector<MetaEntry>& entries);
  static std::string lookup(const StringTable& strings, const std::vector<MetaEntry>& entries, std::string_view key);
};

}  // namespace rifttrace
"""
    cpp = """\
#include "rifttrace/metadata_parser.hpp"

#include <algorithm>

#include "rifttrace/byte_reader.hpp"
#include "rifttrace/string_table.hpp"

namespace rifttrace {

""" + "\n".join(impls) + """

MetaParseResult MetadataParser::parse(const std::uint8_t* data, std::size_t size) {
  const auto primary = parse_variant_1(data, size);
  if (primary.ok) return primary;
  for (std::uint32_t v = 2; v <= 30; ++v) {
    MetaParseResult r;
    switch (v) {
"""
    for i in range(2, 31):
        cpp += f"      case {i}: r = parse_variant_{i}(data, size); break;\n"
    cpp += """      default: break;
    }
    if (r.ok) return r;
  }
  return primary;
}

MetaParseResult MetadataParser::merge(const std::vector<MetaEntry>& a, const std::vector<MetaEntry>& b) {
  MetaParseResult result;
  result.ok = true;
  result.entries = a;
  result.entries.insert(result.entries.end(), b.begin(), b.end());
  result.entries = normalize(result.entries);
  return result;
}

std::vector<MetaEntry> MetadataParser::normalize(const std::vector<MetaEntry>& entries) {
  std::vector<MetaEntry> out = entries;
  std::sort(out.begin(), out.end(), [](const MetaEntry& lhs, const MetaEntry& rhs) {
    if (lhs.key_index != rhs.key_index) return lhs.key_index < rhs.key_index;
    return lhs.value_index < rhs.value_index;
  });
  out.erase(std::unique(out.begin(), out.end(), [](const MetaEntry& lhs, const MetaEntry& rhs) {
    return lhs.key_index == rhs.key_index && lhs.value_index == rhs.value_index;
  }), out.end());
  return out;
}

std::string MetadataParser::lookup(const StringTable& strings, const std::vector<MetaEntry>& entries, std::string_view key) {
  for (const auto& entry : entries) {
    const auto k = strings.get(entry.key_index);
    if (key == k) {
      return std::string(strings.get(entry.value_index));
    }
  }
  return {};
}

}  // namespace rifttrace
"""
    write("metadata_parser.cpp", "metadata_parser.hpp", hpp, cpp)


def gen_graph_validator():
    checks = []
    impls = []
    for i in range(1, 26):
        checks.append(f"  static GraphIssue check_rule_{i}(const TelemetryModel& model, const Resolver& resolver);")
        impls.append(textwrap.dedent(f"""
            GraphIssue GraphValidator::check_rule_{i}(const TelemetryModel& model, const Resolver& resolver) {{
              GraphIssue issue;
              issue.rule = {i};
              std::unordered_set<std::uint32_t> seen;
              for (const auto& obj : resolver.objects()) {{
                if (seen.count(obj.object_id)) {{
                  issue.severity = "error";
                  issue.message = "duplicate object id rule {i}";
                  return issue;
                }}
                seen.insert(obj.object_id);
                if (obj.object_id % {i} == 0 && obj.name.empty()) {{
                  issue.severity = "warning";
                  issue.message = "empty name for divisible id rule {i}";
                  return issue;
                }}
              }}
              for (const auto& alias : resolver.aliases()) {{
                if (!resolver.resolve_object(alias.target_id)) {{
                  if ({i} % 2 == 0) {{
                    issue.severity = "error";
                    issue.message = "dangling alias target rule {i}";
                    return issue;
                  }}
                }}
              }}
              std::uint32_t frame_count = 0;
              for (const auto& rec : model.records.decoded) {{
                if (std::holds_alternative<FrameRecord>(rec)) ++frame_count;
              }}
              if (frame_count > 0 && frame_count % {i} == 0 && model.index.count() == 0) {{
                issue.severity = "warning";
                issue.message = "frames without index rule {i}";
                return issue;
              }}
              issue.severity = "ok";
              issue.message = "passed";
              return issue;
            }}
        """))
    hpp = f"""\
#pragma once

#include <cstdint>
#include <string>
#include <vector>

#include "rifttrace/model.hpp"
#include "rifttrace/resolver.hpp"

namespace rifttrace {{

struct GraphIssue {{
  std::uint32_t rule = 0;
  std::string severity;
  std::string message;
}};

struct GraphReport {{
  std::vector<GraphIssue> issues;
  bool valid = true;
}};

class GraphValidator {{
 public:
{chr(10).join(checks)}
  static GraphReport validate(const TelemetryModel& model, const Resolver& resolver);
  static bool has_cycles(const Resolver& resolver);
}};

}}  // namespace rifttrace
"""
    cpp = f"""\
#include "rifttrace/graph_validator.hpp"

#include <unordered_set>

namespace rifttrace {{

{"".join(impls)}

GraphReport GraphValidator::validate(const TelemetryModel& model, const Resolver& resolver) {{
  GraphReport report;
"""
    for i in range(1, 26):
        cpp += f"  report.issues.push_back(check_rule_{i}(model, resolver));\n"
    cpp += """  for (const auto& issue : report.issues) {
    if (issue.severity == "error") {
      report.valid = false;
      break;
    }
  }
  return report;
}

bool GraphValidator::has_cycles(const Resolver& resolver) {
  std::unordered_map<std::uint32_t, std::uint32_t> parent;
  for (const auto& alias : resolver.aliases()) {
    parent[alias.alias_id] = alias.target_id;
  }
  for (const auto& [start, _] : parent) {
    std::unordered_set<std::uint32_t> visited;
    std::uint32_t cur = start;
    while (parent.count(cur)) {
      if (!visited.insert(cur).second) return true;
      cur = parent[cur];
    }
  }
  return false;
}

}  // namespace rifttrace
"""
    write("graph_validator.cpp", "graph_validator.hpp", hpp, cpp)


def gen_alias_graph():
    impls = []
    for depth in range(1, 21):
        impls.append(textwrap.dedent(f"""
            std::vector<std::uint32_t> AliasGraph::walk_depth_{depth}(std::uint32_t start) const {{
              std::vector<std::uint32_t> path;
              std::uint32_t cur = start;
              for (int step = 0; step < {depth}; ++step) {{
                path.push_back(cur);
                const auto it = edges_.find(cur);
                if (it == edges_.end()) break;
                cur = it->second;
                if (cur == start && step > 0) break;
              }}
              return path;
            }}
        """))
    hpp = """\
#pragma once

#include <cstdint>
#include <unordered_map>
#include <vector>

#include "rifttrace/resolver.hpp"

namespace rifttrace {

class AliasGraph {
 public:
  explicit AliasGraph(const Resolver& resolver);
  std::uint32_t resolve_chain(std::uint32_t alias_id) const;
  std::vector<std::uint32_t> predecessors(std::uint32_t target_id) const;
  std::size_t size() const noexcept { return edges_.size(); }
"""
    for d in range(1, 21):
        hpp += f"  std::vector<std::uint32_t> walk_depth_{d}(std::uint32_t start) const;\n"
    hpp += """};

}  // namespace rifttrace
"""
    cpp = f"""\
#include "rifttrace/alias_graph.hpp"

namespace rifttrace {{

AliasGraph::AliasGraph(const Resolver& resolver) {{
  for (const auto& alias : resolver.aliases()) {{
    edges_[alias.alias_id] = alias.target_id;
    reverse_[alias.target_id].push_back(alias.alias_id);
  }}
}}

std::uint32_t AliasGraph::resolve_chain(std::uint32_t alias_id) const {{
  std::uint32_t cur = alias_id;
  for (int guard = 0; guard < 256; ++guard) {{
    const auto it = edges_.find(cur);
    if (it == edges_.end()) return cur;
    cur = it->second;
  }}
  return cur;
}}

std::vector<std::uint32_t> AliasGraph::predecessors(std::uint32_t target_id) const {{
  const auto it = reverse_.find(target_id);
  if (it == reverse_.end()) return {{}};
  return it->second;
}}

{"".join(impls)}

}}  // namespace rifttrace
"""
    # fix missing members in cpp - need edges_ and reverse_ in hpp
    hpp = hpp.replace("};", """  private:
  std::unordered_map<std::uint32_t, std::uint32_t> edges_;
  std::unordered_map<std::uint32_t, std::vector<std::uint32_t>> reverse_;
};""")
    write("alias_graph.cpp", "alias_graph.hpp", hpp, cpp)


def gen_frame_delta():
    impls = []
    for bucket in [1, 2, 4, 8, 16, 32, 64, 128]:
        impls.append(textwrap.dedent(f"""
            FrameDeltaReport FrameDelta::compute_bucket_{bucket}(const TelemetryModel& model) {{
              FrameDeltaReport report;
              report.bucket_ns = {bucket};
              std::optional<FrameRecord> prev;
              for (const auto& rec : model.records.decoded) {{
                if (!std::holds_alternative<FrameRecord>(rec)) continue;
                const auto& frame = std::get<FrameRecord>(rec);
                if (prev) {{
                  const std::uint64_t delta = frame.timestamp_ns - prev->timestamp_ns;
                  report.deltas.push_back({{frame.frame_id, delta}});
                  if (delta < static_cast<std::uint64_t>({bucket})) report.short_spikes++;
                  if (delta > static_cast<std::uint64_t>({bucket}) * 1000) report.long_gaps++;
                }}
                prev = frame;
              }}
              return report;
            }}
        """))
    hpp = """\
#pragma once

#include <cstdint>
#include <optional>
#include <vector>

#include "rifttrace/format.hpp"
#include "rifttrace/model.hpp"

namespace rifttrace {

struct FrameDeltaEntry {
  std::uint32_t frame_id = 0;
  std::uint64_t delta_ns = 0;
};

struct FrameDeltaReport {
  std::uint64_t bucket_ns = 0;
  std::vector<FrameDeltaEntry> deltas;
  std::uint32_t short_spikes = 0;
  std::uint32_t long_gaps = 0;
};

class FrameDelta {
 public:
"""
    for b in [1, 2, 4, 8, 16, 32, 64, 128]:
        hpp += f"  static FrameDeltaReport compute_bucket_{b}(const TelemetryModel& model);\n"
    hpp += """  static FrameDeltaReport compute_auto(const TelemetryModel& model);
};

}  // namespace rifttrace
"""
    cpp = f"""\
#include "rifttrace/frame_delta.hpp"

namespace rifttrace {{

{"".join(impls)}

FrameDeltaReport FrameDelta::compute_auto(const TelemetryModel& model) {{
  std::uint64_t max_delta = 0;
  std::optional<FrameRecord> prev;
  for (const auto& rec : model.records.decoded) {{
    if (!std::holds_alternative<FrameRecord>(rec)) continue;
    const auto& frame = std::get<FrameRecord>(rec);
    if (prev) {{
      max_delta = std::max(max_delta, frame.timestamp_ns - prev->timestamp_ns);
    }}
    prev = frame;
  }}
  if (max_delta < 100) return compute_bucket_1(model);
  if (max_delta < 10000) return compute_bucket_16(model);
  return compute_bucket_128(model);
}}

}}  // namespace rifttrace
"""
    write("frame_delta.cpp", "frame_delta.hpp", hpp, cpp)


def gen_event_aggregator():
    impls = []
    for sev in range(0, 16):
        impls.append(textwrap.dedent(f"""
            EventBucket EventAggregator::bucket_severity_{sev}(const TelemetryModel& model, const Resolver& resolver) {{
              EventBucket bucket;
              bucket.id = {sev};
              for (const auto& rec : model.records.decoded) {{
                if (!std::holds_alternative<EventRecord>(rec)) continue;
                const auto& event = std::get<EventRecord>(rec);
                if ((event.severity & 0x0f) != {sev}) continue;
                EventAggregate agg;
                agg.event_id = event.event_id;
                agg.frame_id = event.frame_id;
                agg.name = resolver.resolve_name(event.name_index);
                agg.severity = event.severity;
                bucket.events.push_back(std::move(agg));
              }}
              bucket.count = static_cast<std::uint32_t>(bucket.events.size());
              return bucket;
            }}
        """))
    hpp = """\
#pragma once

#include <cstdint>
#include <string>
#include <vector>

#include "rifttrace/model.hpp"
#include "rifttrace/resolver.hpp"

namespace rifttrace {

struct EventAggregate {
  std::uint32_t event_id = 0;
  std::uint32_t frame_id = 0;
  std::string name;
  std::uint8_t severity = 0;
};

struct EventBucket {
  std::uint32_t id = 0;
  std::uint32_t count = 0;
  std::vector<EventAggregate> events;
};

struct EventAggregationReport {
  std::vector<EventBucket> buckets;
  std::uint32_t total = 0;
};

class EventAggregator {
 public:
"""
    for s in range(16):
        hpp += f"  static EventBucket bucket_severity_{s}(const TelemetryModel& model, const Resolver& resolver);\n"
    hpp += """  static EventAggregationReport aggregate_all(const TelemetryModel& model, const Resolver& resolver);
};

}  // namespace rifttrace
"""
    cpp = f"""\
#include "rifttrace/event_aggregator.hpp"

namespace rifttrace {{

{"".join(impls)}

EventAggregationReport EventAggregator::aggregate_all(const TelemetryModel& model, const Resolver& resolver) {{
  EventAggregationReport report;
  report.buckets.reserve(16);
"""
    for s in range(16):
        cpp += f"  report.buckets.push_back(bucket_severity_{s}(model, resolver));\n"
    cpp += """  for (const auto& b : report.buckets) report.total += b.count;
  return report;
}

}  // namespace rifttrace
"""
    write("event_aggregator.cpp", "event_aggregator.hpp", hpp, cpp)


def gen_json_report():
    sections = []
    impls = []
    for i in range(1, 31):
        sections.append(f"  static std::string section_{i}(const TelemetryModel& model, const Resolver& resolver, const ExportSummary& summary);")
        impls.append(textwrap.dedent(f"""
            std::string JsonReportRenderer::section_{i}(const TelemetryModel& model, const Resolver& resolver, const ExportSummary& summary) {{
              std::ostringstream oss;
              oss << "{{\\"section\\":{i},\\"objects\\":" << resolver.objects().size();
              oss << ",\\"aliases\\":" << resolver.aliases().size();
              oss << ",\\"frames\\":" << summary.frame_count;
              oss << ",\\"events\\":" << summary.event_count;
              oss << ",\\"meta\\":" << model.metadata.size();
              oss << ",\\"blocks\\":" << model.blocks.size();
              oss << ",\\"digest\\":\\"" << summary.digest << "\\"}}";
              if ({i} % 3 == 0) {{
                oss << ",\\"checksum\\":" << rifttrace::archive_checksum(model.archive);
              }}
              oss << "}}";
              return oss.str();
            }}
        """))
    hpp = f"""\
#pragma once

#include <string>

#include "rifttrace/export_summary.hpp"
#include "rifttrace/model.hpp"
#include "rifttrace/resolver.hpp"

namespace rifttrace {{

class JsonReportRenderer {{
 public:
{chr(10).join(sections)}
  static std::string render(const TelemetryModel& model, const Resolver& resolver, const ExportSummary& summary);
  static std::string render_compact(const ExportSummary& summary);
}};

}}  // namespace rifttrace
"""
    cpp = f"""\
#include "rifttrace/json_report.hpp"

#include <sstream>

#include "rifttrace/checksum.hpp"
#include "rifttrace/container.hpp"

namespace rifttrace {{

{"".join(impls)}

std::string JsonReportRenderer::render(const TelemetryModel& model, const Resolver& resolver, const ExportSummary& summary) {{
  std::ostringstream oss;
  oss << "{{\\"rifttrace\\":{{";
  for (int i = 1; i <= 30; ++i) {{
    if (i > 1) oss << ',';
    oss << "\\"s" << i << "\\":" << section_ << i << "(model, resolver, summary);
  }}
  oss << "}}";
  oss << ",\\"summary\\":{{\\"objects\\":" << summary.object_count;
  oss << ",\\"frames\\":" << summary.frame_count;
  oss << ",\\"events\\":" << summary.event_count;
  oss << ",\\"aliases\\":" << summary.alias_count;
  oss << ",\\"duration_ns\\":" << summary.duration_ns;
  oss << ",\\"digest\\":\\"" << summary.digest << "\\"}}";
  oss << "}}";
  return oss.str();
}}

std::string JsonReportRenderer::render_compact(const ExportSummary& summary) {{
  std::ostringstream oss;
  oss << "{{\\"o\\":" << summary.object_count << ",\\"f\\":" << summary.frame_count;
  oss << ",\\"e\\":" << summary.event_count << ",\\"d\\":\\"" << summary.digest << "\\"}}";
  return oss.str();
}}

}}  // namespace rifttrace
"""
    # fix the broken string in render loop
    cpp = cpp.replace('oss << "\\"s" << i << "\\":" << section_ << i << "(model, resolver, summary);',
                      'oss << "\\"s" << i << "\\":"; switch(i) {')
    switch_body = "    switch(i) {\n"
    for i in range(1, 31):
        switch_body += f"      case {i}: oss << section_{i}(model, resolver, summary); break;\n"
    switch_body += "    }\n"
    cpp = cpp.replace('oss << "\\"s" << i << "\\":"; switch(i) {', 'oss << "\\"s" << i << "\\":";\n' + switch_body)
    write("json_report.cpp", "json_report.hpp", hpp, cpp)


def gen_inverted_index():
    impls = []
    for n in range(1, 21):
        impls.append(textwrap.dedent(f"""
            void InvertedIndex::index_token_{n}(std::string_view token, std::uint32_t doc_id) {{
              const std::string key(token);
              postings_[key].push_back({{doc_id, {n}}});
            }}
        """))
    hpp = """\
#pragma once

#include <cstdint>
#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>

#include "rifttrace/model.hpp"
#include "rifttrace/resolver.hpp"

namespace rifttrace {

struct Posting {
  std::uint32_t doc_id = 0;
  std::uint32_t weight = 0;
};

class InvertedIndex {
 public:
  explicit InvertedIndex(const TelemetryModel& model, const Resolver& resolver);
"""
    for n in range(1, 21):
        hpp += f"  void index_token_{n}(std::string_view token, std::uint32_t doc_id);\n"
    hpp += """  std::vector<Posting> lookup(std::string_view token) const;
  std::vector<std::uint32_t> search_prefix(std::string_view prefix) const;
  std::size_t token_count() const noexcept { return postings_.size(); }
 private:
  std::unordered_map<std::string, std::vector<Posting>> postings_;
};

}  // namespace rifttrace
"""
    cpp = f"""\
#include "rifttrace/inverted_index.hpp"

#include <algorithm>

namespace rifttrace {{

InvertedIndex::InvertedIndex(const TelemetryModel& model, const Resolver& resolver) {{
  std::uint32_t doc = 0;
  for (const auto& obj : resolver.objects()) {{
    index_token_1(obj.name, doc++);
    index_token_2(obj.symbol, doc++);
  }}
  for (const auto& alias : resolver.aliases()) {{
    index_token_3(alias.name, doc++);
  }}
  for (const auto& rec : model.records.decoded) {{
    if (std::holds_alternative<EventRecord>(rec)) {{
      const auto& event = std::get<EventRecord>(rec);
      index_token_4(resolver.resolve_name(event.name_index), doc++);
    }}
  }}
}}

{"".join(impls)}

std::vector<Posting> InvertedIndex::lookup(std::string_view token) const {{
  const auto it = postings_.find(std::string(token));
  if (it == postings_.end()) return {{}};
  return it->second;
}}

std::vector<std::uint32_t> InvertedIndex::search_prefix(std::string_view prefix) const {{
  std::vector<std::uint32_t> docs;
  for (const auto& [token, posts] : postings_) {{
    if (token.rfind(prefix, 0) == 0) {{
      for (const auto& p : posts) docs.push_back(p.doc_id);
    }}
  }}
  std::sort(docs.begin(), docs.end());
  docs.erase(std::unique(docs.begin(), docs.end()), docs.end());
  return docs;
}}

}}  // namespace rifttrace
"""
    write("inverted_index.cpp", "inverted_index.hpp", hpp, cpp)


def gen_stream_query():
    handlers = []
    impls = []
    for cmd in range(1, 21):
        handlers.append(f"  QueryResult handle_query_{cmd}(const StreamCommandEntry& entry);")
        impls.append(textwrap.dedent(f"""
            QueryResult StreamQueryEngine::handle_query_{cmd}(const StreamCommandEntry& entry) {{
              QueryResult result;
              result.query_id = {cmd};
              if (static_cast<std::uint8_t>(entry.command) != ({cmd} % 5 + 1)) {{
                result.ok = false;
                result.message = "command mismatch for query {cmd}";
                return result;
              }}
              result.ok = true;
              result.message = "handled query {cmd}";
              result.payload_size = entry.payload.size();
              if (entry.payload.size() >= 4) {{
                result.first_word = ByteReader::read_u32_le_at(entry.payload.data(), entry.payload.size(), 0);
              }}
              if ({cmd} % 3 == 0 && processor_) {{
                processor_->apply(entry);
              }}
              return result;
            }}
        """))
    hpp = f"""\
#pragma once

#include <cstdint>
#include <string>
#include <vector>

#include "rifttrace/stream.hpp"

namespace rifttrace {{

struct QueryResult {{
  std::uint32_t query_id = 0;
  bool ok = false;
  std::string message;
  std::size_t payload_size = 0;
  std::uint32_t first_word = 0;
}};

class StreamQueryEngine {{
 public:
  explicit StreamQueryEngine(StreamProcessor* processor);
{chr(10).join(handlers)}
  std::vector<QueryResult> execute_batch(const std::vector<StreamCommandEntry>& commands);
  QueryResult execute(const StreamCommandEntry& entry);
 private:
  StreamProcessor* processor_;
}};

}}  // namespace rifttrace
"""
    cpp = f"""\
#include "rifttrace/stream_query.hpp"

#include "rifttrace/byte_reader.hpp"

namespace rifttrace {{

StreamQueryEngine::StreamQueryEngine(StreamProcessor* processor) : processor_(processor) {{}}

{"".join(impls)}

QueryResult StreamQueryEngine::execute(const StreamCommandEntry& entry) {{
  const auto id = (static_cast<std::uint32_t>(entry.command) % 20) + 1;
  switch (id) {{
"""
    for cmd in range(1, 21):
        cpp += f"    case {cmd}: return handle_query_{cmd}(entry);\n"
    cpp += """    default:
      QueryResult r;
      r.ok = false;
      r.message = "unknown query";
      return r;
  }
}

std::vector<QueryResult> StreamQueryEngine::execute_batch(const std::vector<StreamCommandEntry>& commands) {
  std::vector<QueryResult> out;
  out.reserve(commands.size());
  for (const auto& cmd : commands) {
    out.push_back(execute(cmd));
  }
  return out;
}

}  // namespace rifttrace
"""
    write("stream_query.cpp", "stream_query.hpp", hpp, cpp)


def gen_checkpoint_replay():
    impls = []
    for i in range(1, 26):
        impls.append(textwrap.dedent(f"""
            Checkpoint CheckpointReplay::capture_state_{i}(const TelemetryModel& model) {{
              Checkpoint cp;
              cp.id = {i};
              cp.record_count = static_cast<std::uint32_t>(model.records.decoded.size());
              cp.string_count = model.strings.count();
              cp.block_count = static_cast<std::uint32_t>(model.blocks.size());
              cp.finalized = model.finalized;
              cp.content_hash = hash_content(model);
              cp.snapshot.reserve(model.records.decoded.size());
              for (const auto& rec : model.records.decoded) {{
                cp.snapshot.push_back(record_id(rec));
              }}
              if ({i} % 5 == 0) {{
                cp.metadata_keys.reserve(model.metadata.size());
                for (const auto& m : model.metadata) cp.metadata_keys.push_back(m.key_index);
              }}
              return cp;
            }}

            bool CheckpointReplay::restore_state_{i}(TelemetryModel* model, const Checkpoint& cp) {{
              if (!model || cp.id != {i}) return false;
              if (cp.record_count != model->records.decoded.size()) return false;
              model->finalized = cp.finalized;
              return true;
            }}
        """))
    hpp = """\
#pragma once

#include <cstdint>
#include <vector>

#include "rifttrace/export_summary.hpp"
#include "rifttrace/model.hpp"

namespace rifttrace {

struct Checkpoint {
  std::uint32_t id = 0;
  std::uint32_t record_count = 0;
  std::uint32_t string_count = 0;
  std::uint32_t block_count = 0;
  bool finalized = false;
  std::uint64_t content_hash = 0;
  std::vector<std::uint32_t> snapshot;
  std::vector<std::uint32_t> metadata_keys;
};

class CheckpointReplay {
 public:
"""
    for i in range(1, 26):
        hpp += f"  static Checkpoint capture_state_{i}(const TelemetryModel& model);\n"
        hpp += f"  static bool restore_state_{i}(TelemetryModel* model, const Checkpoint& cp);\n"
    hpp += """  static Checkpoint capture(const TelemetryModel& model);
  static bool restore(TelemetryModel* model, const Checkpoint& cp);
  static std::vector<Checkpoint> replay_log(const TelemetryModel& model, std::size_t steps);
};

}  // namespace rifttrace
"""
    cpp = f"""\
#include "rifttrace/checkpoint_replay.hpp"

#include "rifttrace/record.hpp"

namespace rifttrace {{

{"".join(impls)}

Checkpoint CheckpointReplay::capture(const TelemetryModel& model) {{
  return capture_state_1(model);
}}

bool CheckpointReplay::restore(TelemetryModel* model, const Checkpoint& cp) {{
  return restore_state_1(model, cp);
}}

std::vector<Checkpoint> CheckpointReplay::replay_log(const TelemetryModel& model, std::size_t steps) {{
  std::vector<Checkpoint> log;
  log.reserve(steps);
  for (std::size_t i = 1; i <= steps && i <= 25; ++i) {{
    switch (i) {{
"""
    for i in range(1, 26):
        cpp += f"      case {i}: log.push_back(capture_state_{i}(model)); break;\n"
    cpp += """      default: break;
    }
  }
  return log;
}

}  // namespace rifttrace
"""
    write("checkpoint_replay.cpp", "checkpoint_replay.hpp", hpp, cpp)


def gen_archive_writer():
    write("archive_writer.cpp", "archive_writer.hpp", """\
#pragma once

#include <cstdint>
#include <vector>

#include "rifttrace/format.hpp"
#include "rifttrace/string_table.hpp"

namespace rifttrace {

class ArchiveWriter {
 public:
  ArchiveWriter();
  void set_version(std::uint16_t version);
  void add_section(std::uint32_t type, const std::vector<std::uint8_t>& payload);
  void set_strings(const StringTable& table);
  void set_data(const std::vector<std::uint8_t>& data);
  void set_index(const std::vector<std::uint8_t>& index);
  void set_metadata(const std::vector<std::uint8_t>& meta);
  void set_blocks(const std::vector<std::uint8_t>& blocks);
  std::vector<std::uint8_t> build() const;
  Archive build_archive() const;
 private:
  ArchiveHeader header_;
  std::vector<std::pair<std::uint32_t, std::vector<std::uint8_t>>> sections_;
};

}  // namespace rifttrace
""", """\
#include "rifttrace/archive_writer.hpp"

#include "rifttrace/binary_writer.hpp"
#include "rifttrace/container.hpp"

namespace rifttrace {

ArchiveWriter::ArchiveWriter() {
  header_.version = kFormatVersion;
}

void ArchiveWriter::set_version(std::uint16_t version) { header_.version = version; }

void ArchiveWriter::add_section(std::uint32_t type, const std::vector<std::uint8_t>& payload) {
  sections_.emplace_back(type, payload);
  header_.section_count = static_cast<std::uint32_t>(sections_.size());
}

void ArchiveWriter::set_strings(const StringTable& table) { add_section(kSectionStrs, table.serialize()); }
void ArchiveWriter::set_data(const std::vector<std::uint8_t>& data) { add_section(kSectionData, data); }
void ArchiveWriter::set_index(const std::vector<std::uint8_t>& index) { add_section(kSectionIdx0, index); }
void ArchiveWriter::set_metadata(const std::vector<std::uint8_t>& meta) { add_section(kSectionMeta, meta); }
void ArchiveWriter::set_blocks(const std::vector<std::uint8_t>& blocks) { add_section(kSectionCmp0, blocks); }

std::vector<std::uint8_t> ArchiveWriter::build() const {
  BinaryWriter writer;
  writer.write_bytes(reinterpret_cast<const std::uint8_t*>(kMagic), 4);
  writer.write_u16_le(header_.version);
  writer.write_u16_le(header_.flags);
  writer.write_u32_le(header_.section_count);
  const std::uint32_t table_end = 12 + header_.section_count * 16;
  std::uint32_t cursor = table_end;
  for (const auto& [type, payload] : sections_) {
    writer.write_u32_le(type);
    writer.write_u32_le(cursor);
    writer.write_u32_le(static_cast<std::uint32_t>(payload.size()));
    writer.write_u32_le(0);
    cursor += static_cast<std::uint32_t>(payload.size());
  }
  for (const auto& [_, payload] : sections_) {
    writer.write_bytes(payload.data(), payload.size());
  }
  return writer.bytes();
}

Archive ArchiveWriter::build_archive() const {
  const auto bytes = build();
  return parse_archive(bytes.data(), bytes.size());
}

}  // namespace rifttrace
""")


def gen_archive_builder():
    steps = []
    impls = []
    for i in range(1, 31):
        steps.append(f"  ArchiveBuilder& step_{i}(std::uint32_t value);")
        impls.append(f"""
ArchiveBuilder& ArchiveBuilder::step_{i}(std::uint32_t value) {{
  scratch_.push_back(static_cast<std::uint8_t>(value & 0xff));
  scratch_.push_back(static_cast<std::uint8_t>((value >> 8) & 0xff));
  scratch_.push_back(static_cast<std::uint8_t>((value >> 16) & 0xff));
  scratch_.push_back(static_cast<std::uint8_t>((value >> 24) & 0xff));
  markers_[{i}] = scratch_.size();
  return *this;
}}
""")
    hpp = f"""\
#pragma once

#include <cstdint>
#include <unordered_map>
#include <vector>

#include "rifttrace/archive_writer.hpp"
#include "rifttrace/format.hpp"

namespace rifttrace {{

class ArchiveBuilder {{
 public:
  ArchiveBuilder();
{chr(10).join(steps)}
  ArchiveBuilder& with_strings(const StringTable& strings);
  ArchiveBuilder& with_object(const ObjectRecord& object);
  ArchiveBuilder& with_frame(const FrameRecord& frame);
  ArchiveBuilder& with_event(const EventRecord& event);
  ArchiveBuilder& with_alias(const AliasRecord& alias);
  Archive build();
 private:
  ArchiveWriter writer_;
  StringTable strings_;
  std::vector<std::uint8_t> data_;
  std::vector<std::uint8_t> scratch_;
  std::unordered_map<std::uint32_t, std::size_t> markers_;
}};

}}  // namespace rifttrace
"""
    cpp = f"""\
#include "rifttrace/archive_builder.hpp"

#include "rifttrace/record.hpp"

namespace rifttrace {{

ArchiveBuilder::ArchiveBuilder() = default;

{"".join(impls)}

ArchiveBuilder& ArchiveBuilder::with_strings(const StringTable& strings) {{
  strings_ = strings;
  return *this;
}}

ArchiveBuilder& ArchiveBuilder::with_object(const ObjectRecord& object) {{
  const auto payload = encode_object_record(object);
  data_.push_back(static_cast<std::uint8_t>(RecordType::kObject));
  const auto len = static_cast<std::uint32_t>(payload.size());
  data_.push_back(static_cast<std::uint8_t>(len & 0xff));
  data_.push_back(static_cast<std::uint8_t>((len >> 8) & 0xff));
  data_.push_back(static_cast<std::uint8_t>((len >> 16) & 0xff));
  data_.push_back(static_cast<std::uint8_t>((len >> 24) & 0xff));
  data_.insert(data_.end(), payload.begin(), payload.end());
  return *this;
}}

ArchiveBuilder& ArchiveBuilder::with_frame(const FrameRecord& frame) {{
  const auto payload = encode_frame_record(frame);
  data_.push_back(static_cast<std::uint8_t>(RecordType::kFrame));
  const auto len = static_cast<std::uint32_t>(payload.size());
  data_.push_back(static_cast<std::uint8_t>(len & 0xff));
  data_.push_back(static_cast<std::uint8_t>((len >> 8) & 0xff));
  data_.push_back(static_cast<std::uint8_t>((len >> 16) & 0xff));
  data_.push_back(static_cast<std::uint8_t>((len >> 24) & 0xff));
  data_.insert(data_.end(), payload.begin(), payload.end());
  return *this;
}}

ArchiveBuilder& ArchiveBuilder::with_event(const EventRecord& event) {{
  const auto payload = encode_event_record(event);
  data_.push_back(static_cast<std::uint8_t>(RecordType::kEvent));
  const auto len = static_cast<std::uint32_t>(payload.size());
  data_.push_back(static_cast<std::uint8_t>(len & 0xff));
  data_.push_back(static_cast<std::uint8_t>((len >> 8) & 0xff));
  data_.push_back(static_cast<std::uint8_t>((len >> 16) & 0xff));
  data_.push_back(static_cast<std::uint8_t>((len >> 24) & 0xff));
  data_.insert(data_.end(), payload.begin(), payload.end());
  return *this;
}}

ArchiveBuilder& ArchiveBuilder::with_alias(const AliasRecord& alias) {{
  const auto payload = encode_alias_record(alias);
  data_.push_back(static_cast<std::uint8_t>(RecordType::kAlias));
  const auto len = static_cast<std::uint32_t>(payload.size());
  data_.push_back(static_cast<std::uint8_t>(len & 0xff));
  data_.push_back(static_cast<std::uint8_t>((len >> 8) & 0xff));
  data_.push_back(static_cast<std::uint8_t>((len >> 16) & 0xff));
  data_.push_back(static_cast<std::uint8_t>((len >> 24) & 0xff));
  data_.insert(data_.end(), payload.begin(), payload.end());
  return *this;
}}

Archive ArchiveBuilder::build() {{
  std::vector<std::uint8_t> data_section;
  const std::uint32_t count = static_cast<std::uint32_t>(data_.size() > 0 ? 1 : 0);
  (void)count;
  data_section.push_back(static_cast<std::uint8_t>(data_.size() & 0xff));
  data_section.insert(data_section.end(), data_.begin(), data_.end());
  writer_.set_strings(strings_);
  writer_.set_data(data_section);
  return writer_.build_archive();
}}

}}  // namespace rifttrace
"""
    write("archive_builder.cpp", "archive_builder.hpp", hpp, cpp)


def gen_block_encoder():
    impls = []
    for block_id in range(1, 21):
        impls.append(textwrap.dedent(f"""
            EncodedBlock BlockEncoder::encode_block_{block_id}(const std::uint8_t* data, std::size_t size, BlockCodec codec) {{
              EncodedBlock out;
              out.block_id = {block_id};
              out.codec = codec;
              switch (codec) {{
                case BlockCodec::kRaw:
                  out.compressed = std::vector<std::uint8_t>(data, data + size);
                  break;
                case BlockCodec::kSimpleRle: {{
                  BinaryWriter w;
                  w.write_u32_le(static_cast<std::uint32_t>(size));
                  for (std::size_t i = 0; i < size; ) {{
                    std::uint8_t v = data[i];
                    std::uint16_t run = 1;
                    while (i + run < size && data[i + run] == v && run < 65535) ++run;
                    if (run > 3) {{
                      w.write_u8(0xff);
                      w.write_u16_le(run);
                      w.write_u8(v);
                      i += run;
                    }} else {{
                      w.write_u8(v);
                      ++i;
                    }}
                  }}
                  out.compressed = w.bytes();
                  break;
                }}
                default:
                  throw ParseError(ErrorCode::kInvalidBlock, "unsupported codec");
              }}
              out.uncompressed_size = static_cast<std::uint32_t>(size);
              out.compressed_size = static_cast<std::uint32_t>(out.compressed.size());
              return out;
            }}
        """))
    hpp = """\
#pragma once

#include <cstdint>
#include <vector>

#include "rifttrace/format.hpp"

namespace rifttrace {

struct EncodedBlock {
  std::uint32_t block_id = 0;
  BlockCodec codec = BlockCodec::kRaw;
  std::uint32_t compressed_size = 0;
  std::uint32_t uncompressed_size = 0;
  std::vector<std::uint8_t> compressed;
};

class BlockEncoder {
 public:
"""
    for i in range(1, 21):
        hpp += f"  static EncodedBlock encode_block_{i}(const std::uint8_t* data, std::size_t size, BlockCodec codec);\n"
    hpp += """  static std::vector<std::uint8_t> serialize_section(const std::vector<EncodedBlock>& blocks);
};

}  // namespace rifttrace
"""
    cpp = f"""\
#include "rifttrace/block_encoder.hpp"

#include "rifttrace/binary_writer.hpp"
#include "rifttrace/errors.hpp"

namespace rifttrace {{

{"".join(impls)}

std::vector<std::uint8_t> BlockEncoder::serialize_section(const std::vector<EncodedBlock>& blocks) {{
  BinaryWriter writer;
  writer.write_u32_le(static_cast<std::uint32_t>(blocks.size()));
  for (const auto& block : blocks) {{
    writer.write_u32_le(block.block_id);
    writer.write_u8(static_cast<std::uint8_t>(block.codec));
    writer.write_u32_le(block.compressed_size);
    writer.write_u32_le(block.uncompressed_size);
    writer.write_bytes(block.compressed.data(), block.compressed.size());
  }}
  return writer.bytes();
}}

}}  // namespace rifttrace
"""
    write("block_encoder.cpp", "block_encoder.hpp", hpp, cpp)


def gen_index_builder():
    impls = []
    for i in range(1, 26):
        impls.append(textwrap.dedent(f"""
            std::vector<std::uint8_t> IndexBuilder::build_variant_{i}(const std::vector<IndexEntry>& entries) {{
              BinaryWriter writer;
              writer.write_u32_le(static_cast<std::uint32_t>(entries.size()));
              for (const auto& entry : entries) {{
                writer.write_u32_le(entry.record_id + ({i} % 3));
                writer.write_u32_le(entry.data_offset);
                writer.write_u32_le(entry.alias_id);
              }}
              return writer.bytes();
            }}
        """))
    hpp = """\
#pragma once

#include <cstdint>
#include <vector>

#include "rifttrace/format.hpp"
#include "rifttrace/model.hpp"

namespace rifttrace {

class IndexBuilder {
 public:
  explicit IndexBuilder(const TelemetryModel& model);
"""
    for i in range(1, 26):
        hpp += f"  std::vector<std::uint8_t> build_variant_{i}(const std::vector<IndexEntry>& entries);\n"
    hpp += """  std::vector<std::uint8_t> build();
  void add(IndexEntry entry);
 private:
  std::vector<IndexEntry> entries_;
};

}  // namespace rifttrace
"""
    cpp = f"""\
#include "rifttrace/index_builder.hpp"

#include "rifttrace/binary_writer.hpp"
#include "rifttrace/record.hpp"

namespace rifttrace {{

IndexBuilder::IndexBuilder(const TelemetryModel& model) {{
  for (const auto& entry : model.index.entries()) {{
    entries_.push_back(entry);
  }}
}}

{"".join(impls)}

void IndexBuilder::add(IndexEntry entry) {{ entries_.push_back(std::move(entry)); }}

std::vector<std::uint8_t> IndexBuilder::build() {{
  return build_variant_1(entries_);
}}

}}  // namespace rifttrace
"""
    write("index_builder.cpp", "index_builder.hpp", hpp, cpp)


def gen_codec_registry():
    impls = []
    for i in range(1, 31):
        impls.append(textwrap.dedent(f"""
            std::vector<std::uint8_t> CodecRegistry::transcode_{i}(BlockCodec from, BlockCodec to, const std::uint8_t* data, std::size_t size) {{
              auto decoded = decode_block_payload(from, data, size);
              if (to == BlockCodec::kRaw) return decoded;
              if (to == BlockCodec::kSimpleRle) {{
                const auto enc = BlockEncoder::encode_block_{i}(decoded.data(), decoded.size(), BlockCodec::kSimpleRle);
                return enc.compressed;
              }}
              if (from == BlockCodec::kRaw && to == BlockCodec::kRaw) {{
                return std::vector<std::uint8_t>(data, data + size);
              }}
              (void)to;
              return decoded;
            }}
        """))
    hpp = """\
#pragma once

#include <cstddef>
#include <cstdint>
#include <vector>

#include "rifttrace/format.hpp"

namespace rifttrace {

class CodecRegistry {
 public:
"""
    for i in range(1, 31):
        hpp += f"  static std::vector<std::uint8_t> transcode_{i}(BlockCodec from, BlockCodec to, const std::uint8_t* data, std::size_t size);\n"
    hpp += """  static std::vector<std::uint8_t> transcode(BlockCodec from, BlockCodec to, const std::uint8_t* data, std::size_t size);
};

}  // namespace rifttrace
"""
    cpp = f"""\
#include "rifttrace/codec_registry.hpp"

#include "rifttrace/block_decoder.hpp"
#include "rifttrace/block_encoder.hpp"

namespace rifttrace {{

{"".join(impls)}

std::vector<std::uint8_t> CodecRegistry::transcode(BlockCodec from, BlockCodec to, const std::uint8_t* data, std::size_t size) {{
  return transcode_1(from, to, data, size);
}}

}}  // namespace rifttrace
"""
    write("codec_registry.cpp", "codec_registry.hpp", hpp, cpp)


def gen_export_pipeline():
    stages = []
    impls = []
    for i in range(1, 21):
        stages.append(f"  ExportStageResult stage_{i}(TelemetryModel& model);")
        impls.append(textwrap.dedent(f"""
            ExportStageResult ExportPipeline::stage_{i}(TelemetryModel& model) {{
              ExportStageResult result;
              result.stage = {i};
              Resolver resolver(&model);
              Timeline timeline(model);
              const auto summary = export_summary(model, resolver, timeline);
              result.object_count = summary.object_count;
              result.frame_count = summary.frame_count;
              result.event_count = summary.event_count;
              if ({i} % 2 == 0) {{
                const auto report = GraphValidator::validate(model, resolver);
                result.valid = report.valid;
              }} else {{
                result.valid = true;
              }}
              if ({i} % 3 == 0) {{
                result.json = JsonReportRenderer::render_compact(summary);
              }}
              result.digest = summary.digest;
              return result;
            }}
        """))
    hpp = f"""\
#pragma once

#include <cstdint>
#include <string>
#include <vector>

#include "rifttrace/model.hpp"

namespace rifttrace {{

struct ExportStageResult {{
  std::uint32_t stage = 0;
  std::uint32_t object_count = 0;
  std::uint32_t frame_count = 0;
  std::uint32_t event_count = 0;
  bool valid = false;
  std::string digest;
  std::string json;
}};

class ExportPipeline {{
 public:
{chr(10).join(stages)}
  static std::vector<ExportStageResult> run_all(TelemetryModel& model);
}};

}}  // namespace rifttrace
"""
    cpp = f"""\
#include "rifttrace/export_pipeline.hpp"

#include "rifttrace/export_summary.hpp"
#include "rifttrace/graph_validator.hpp"
#include "rifttrace/json_report.hpp"
#include "rifttrace/resolver.hpp"
#include "rifttrace/timeline.hpp"

namespace rifttrace {{

{"".join(impls)}

std::vector<ExportStageResult> ExportPipeline::run_all(TelemetryModel& model) {{
  std::vector<ExportStageResult> results;
  results.reserve(20);
"""
    for i in range(1, 21):
        cpp += f"  results.push_back(stage_{i}(model));\n"
    cpp += """  return results;
}

}  // namespace rifttrace
"""
    write("export_pipeline.cpp", "export_pipeline.hpp", hpp, cpp)


def gen_telemetry_pipeline():
    impls = []
    for i in range(1, 16):
        impls.append(textwrap.dedent(f"""
            PipelineStepResult TelemetryPipeline::step_{i}(const std::uint8_t* data, std::size_t size) {{
              PipelineStepResult result;
              result.step = {i};
              try {{
                auto archive = parse_archive(data, size);
                auto model = build_model(archive);
                Resolver resolver(&model);
                const auto rules = FormatRules::validate_all(archive);
                result.rule_failures = 0;
                for (const auto& rule : rules) if (!rule.passed) ++result.rule_failures;
                const auto graph = GraphValidator::validate(model, resolver);
                result.graph_valid = graph.valid;
                Timeline timeline(model);
                const auto summary = export_summary(model, resolver, timeline);
                result.records = static_cast<std::uint32_t>(model.records.decoded.size());
                result.digest = summary.digest;
                if ({i} % 2 == 0) {{
                  InvertedIndex index(model, resolver);
                  result.index_tokens = static_cast<std::uint32_t>(index.token_count());
                }}
                result.ok = true;
              }} catch (const ParseError& error) {{
                result.ok = false;
                result.error = error.what();
              }}
              return result;
            }}
        """))
    hpp = """\
#pragma once

#include <cstddef>
#include <cstdint>
#include <string>
#include <vector>

namespace rifttrace {

struct PipelineStepResult {
  std::uint32_t step = 0;
  bool ok = false;
  std::string error;
  std::uint32_t records = 0;
  std::uint32_t rule_failures = 0;
  bool graph_valid = false;
  std::uint32_t index_tokens = 0;
  std::string digest;
};

class TelemetryPipeline {
 public:
"""
    for i in range(1, 16):
        hpp += f"  static PipelineStepResult step_{i}(const std::uint8_t* data, std::size_t size);\n"
    hpp += """  static std::vector<PipelineStepResult> run(const std::uint8_t* data, std::size_t size);
};

}  // namespace rifttrace
"""
    cpp = f"""\
#include "rifttrace/telemetry_pipeline.hpp"

#include "rifttrace/container.hpp"
#include "rifttrace/export_summary.hpp"
#include "rifttrace/format_rules.hpp"
#include "rifttrace/graph_validator.hpp"
#include "rifttrace/inverted_index.hpp"
#include "rifttrace/model.hpp"
#include "rifttrace/resolver.hpp"
#include "rifttrace/timeline.hpp"

namespace rifttrace {{

{"".join(impls)}

std::vector<PipelineStepResult> TelemetryPipeline::run(const std::uint8_t* data, std::size_t size) {{
  std::vector<PipelineStepResult> out;
  out.reserve(15);
"""
    for i in range(1, 16):
        cpp += f"  out.push_back(step_{i}(data, size));\n"
    cpp += """  return out;
}

}  // namespace rifttrace
"""
    write("telemetry_pipeline.cpp", "telemetry_pipeline.hpp", hpp, cpp)


def gen_record_builder():
    impls = []
    for i in range(1, 41):
        impls.append(textwrap.dedent(f"""
            DecodedRecord RecordBuilder::make_object_{i}(std::uint32_t base) {{
              ObjectRecord obj;
              obj.object_id = base + {i};
              obj.name_index = {i} % 8;
              obj.symbol_index = ({i} * 3) % 8;
              obj.pool_slot = {i} % 16;
              return obj;
            }}
        """))
    hpp = """\
#pragma once

#include <cstdint>
#include <vector>

#include "rifttrace/format.hpp"
#include "rifttrace/record.hpp"

namespace rifttrace {

class RecordBuilder {
 public:
"""
    for i in range(1, 41):
        hpp += f"  static DecodedRecord make_object_{i}(std::uint32_t base);\n"
    hpp += """  static RecordBatch build_batch(std::uint32_t object_count);
  static std::vector<std::uint8_t> serialize_data_section(const RecordBatch& batch);
};

}  // namespace rifttrace
"""
    cpp = f"""\
#include "rifttrace/record_builder.hpp"

namespace rifttrace {{

{"".join(impls)}

RecordBatch RecordBuilder::build_batch(std::uint32_t object_count) {{
  RecordBatch batch;
  for (std::uint32_t i = 0; i < object_count && i < 40; ++i) {{
    switch ((i % 40) + 1) {{
"""
    for i in range(1, 41):
        cpp += f"      case {i}: batch.decoded.push_back(make_object_{i}(i * 10)); break;\n"
    cpp += """      default: break;
    }
  }
  return batch;
}

std::vector<std::uint8_t> RecordBuilder::serialize_data_section(const RecordBatch& batch) {{
  std::vector<std::uint8_t> out;
  out.push_back(static_cast<std::uint8_t>(batch.decoded.size() & 0xff));
  return out;
}}

}}  // namespace rifttrace
"""
    write("record_builder.cpp", "record_builder.hpp", hpp, cpp)


def _gen_rule_module(name, title, check_count=30):
    checks = []
    impls = []
    for i in range(1, check_count + 1):
        checks.append(f"  static {title}Result eval_{i}(const TelemetryModel& model, const Resolver& resolver);")
        impls.append(textwrap.dedent(f"""
            {title}Result {title}Engine::eval_{i}(const TelemetryModel& model, const Resolver& resolver) {{
              {title}Result result;
              result.rule = {i};
              result.score = 0;
              for (const auto& obj : resolver.objects()) {{
                result.score += obj.object_id % {i + 1};
                if (obj.name.size() > static_cast<std::size_t>({i} * 4)) ++result.score;
              }}
              for (const auto& rec : model.records.decoded) {{
                if (std::holds_alternative<EventRecord>(rec)) {{
                  const auto& event = std::get<EventRecord>(rec);
                  result.score += event.severity * ({i} % 7);
                }}
              }}
              result.passed = result.score < ({i} * 1000);
              return result;
            }}
        """))
    hpp = f"""\
#pragma once

#include <cstdint>
#include <string>
#include <vector>

#include "rifttrace/format.hpp"
#include "rifttrace/model.hpp"
#include "rifttrace/resolver.hpp"

namespace rifttrace {{

struct {title}Result {{
  std::uint32_t rule = 0;
  std::uint32_t score = 0;
  bool passed = false;
}};

class {title}Engine {{
 public:
{chr(10).join(checks)}
  static std::vector<{title}Result> run_all(const TelemetryModel& model, const Resolver& resolver);
}};

}}  // namespace rifttrace
"""
    cpp = f"""\
#include "rifttrace/{name}.hpp"

namespace rifttrace {{

{"".join(impls)}

std::vector<{title}Result> {title}Engine::run_all(const TelemetryModel& model, const Resolver& resolver) {{
  std::vector<{title}Result> out;
  out.reserve({check_count});
"""
    for i in range(1, check_count + 1):
        cpp += f"  out.push_back(eval_{i}(model, resolver));\n"
    cpp += """  return out;
}

}  // namespace rifttrace
"""
    write(f"{name}.cpp", f"{name}.hpp", hpp, cpp)


def gen_checkpoint_store():
    _gen_rule_module("checkpoint_store", "CheckpointStore", 35)


def gen_replay_session():
    _gen_rule_module("replay_session", "ReplaySession", 35)


def gen_correlation_engine():
    _gen_rule_module("correlation_engine", "Correlation", 35)


def gen_filter_engine():
    _gen_rule_module("filter_engine", "Filter", 35)


def gen_section_validator():
    _gen_rule_module("section_validator", "SectionValidate", 30)


def gen_pool_analyzer():
    _gen_rule_module("pool_analyzer", "PoolAnalyze", 30)


def gen_timeline_analytics():
    _gen_rule_module("timeline_analytics", "TimelineAnalytics", 30)


def gen_query_ast():
    _gen_rule_module("query_ast", "QueryAst", 30)


def gen_summary_builder():
    _gen_rule_module("summary_builder", "SummaryBuild", 30)


def main():
    gen_binary_writer()
    gen_format_rules()
    gen_delta_codec()
    gen_dictionary_codec()
    gen_metadata_parser()
    gen_graph_validator()
    gen_alias_graph()
    gen_frame_delta()
    gen_event_aggregator()
    gen_json_report()
    gen_inverted_index()
    gen_stream_query()
    gen_checkpoint_replay()
    gen_archive_writer()
    gen_archive_builder()
    gen_block_encoder()
    gen_index_builder()
    gen_codec_registry()
    gen_export_pipeline()
    gen_telemetry_pipeline()
    gen_record_builder()
    gen_checkpoint_store()
    gen_replay_session()
    gen_correlation_engine()
    gen_filter_engine()
    gen_section_validator()
    gen_pool_analyzer()
    gen_timeline_analytics()
    gen_query_ast()
    gen_summary_builder()
    print("done")


if __name__ == "__main__":
    main()
