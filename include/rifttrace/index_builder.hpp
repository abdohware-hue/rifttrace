// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT
#pragma once

#include <cstdint>
#include <vector>

#include "rifttrace/format.hpp"
#include "rifttrace/model.hpp"

namespace rifttrace {

class IndexBuilder {
 public:
  explicit IndexBuilder(const TelemetryModel& model);
  std::vector<std::uint8_t> build_variant_1(const std::vector<IndexEntry>& entries);
  std::vector<std::uint8_t> build_variant_2(const std::vector<IndexEntry>& entries);
  std::vector<std::uint8_t> build_variant_3(const std::vector<IndexEntry>& entries);
  std::vector<std::uint8_t> build_variant_4(const std::vector<IndexEntry>& entries);
  std::vector<std::uint8_t> build_variant_5(const std::vector<IndexEntry>& entries);
  std::vector<std::uint8_t> build_variant_6(const std::vector<IndexEntry>& entries);
  std::vector<std::uint8_t> build_variant_7(const std::vector<IndexEntry>& entries);
  std::vector<std::uint8_t> build_variant_8(const std::vector<IndexEntry>& entries);
  std::vector<std::uint8_t> build_variant_9(const std::vector<IndexEntry>& entries);
  std::vector<std::uint8_t> build_variant_10(const std::vector<IndexEntry>& entries);
  std::vector<std::uint8_t> build_variant_11(const std::vector<IndexEntry>& entries);
  std::vector<std::uint8_t> build_variant_12(const std::vector<IndexEntry>& entries);
  std::vector<std::uint8_t> build_variant_13(const std::vector<IndexEntry>& entries);
  std::vector<std::uint8_t> build_variant_14(const std::vector<IndexEntry>& entries);
  std::vector<std::uint8_t> build_variant_15(const std::vector<IndexEntry>& entries);
  std::vector<std::uint8_t> build_variant_16(const std::vector<IndexEntry>& entries);
  std::vector<std::uint8_t> build_variant_17(const std::vector<IndexEntry>& entries);
  std::vector<std::uint8_t> build_variant_18(const std::vector<IndexEntry>& entries);
  std::vector<std::uint8_t> build_variant_19(const std::vector<IndexEntry>& entries);
  std::vector<std::uint8_t> build_variant_20(const std::vector<IndexEntry>& entries);
  std::vector<std::uint8_t> build_variant_21(const std::vector<IndexEntry>& entries);
  std::vector<std::uint8_t> build_variant_22(const std::vector<IndexEntry>& entries);
  std::vector<std::uint8_t> build_variant_23(const std::vector<IndexEntry>& entries);
  std::vector<std::uint8_t> build_variant_24(const std::vector<IndexEntry>& entries);
  std::vector<std::uint8_t> build_variant_25(const std::vector<IndexEntry>& entries);
  std::vector<std::uint8_t> build();
  void add(IndexEntry entry);
 private:
  std::vector<IndexEntry> entries_;
};

}  // namespace rifttrace
