// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT
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
  void index_token_1(std::string_view token, std::uint32_t doc_id);
  void index_token_2(std::string_view token, std::uint32_t doc_id);
  void index_token_3(std::string_view token, std::uint32_t doc_id);
  void index_token_4(std::string_view token, std::uint32_t doc_id);
  void index_token_5(std::string_view token, std::uint32_t doc_id);
  void index_token_6(std::string_view token, std::uint32_t doc_id);
  void index_token_7(std::string_view token, std::uint32_t doc_id);
  void index_token_8(std::string_view token, std::uint32_t doc_id);
  void index_token_9(std::string_view token, std::uint32_t doc_id);
  void index_token_10(std::string_view token, std::uint32_t doc_id);
  void index_token_11(std::string_view token, std::uint32_t doc_id);
  void index_token_12(std::string_view token, std::uint32_t doc_id);
  void index_token_13(std::string_view token, std::uint32_t doc_id);
  void index_token_14(std::string_view token, std::uint32_t doc_id);
  void index_token_15(std::string_view token, std::uint32_t doc_id);
  void index_token_16(std::string_view token, std::uint32_t doc_id);
  void index_token_17(std::string_view token, std::uint32_t doc_id);
  void index_token_18(std::string_view token, std::uint32_t doc_id);
  void index_token_19(std::string_view token, std::uint32_t doc_id);
  void index_token_20(std::string_view token, std::uint32_t doc_id);
  std::vector<Posting> lookup(std::string_view token) const;
  std::vector<std::uint32_t> search_prefix(std::string_view prefix) const;
  std::size_t token_count() const noexcept { return postings_.size(); }
 private:
  std::unordered_map<std::string, std::vector<Posting>> postings_;
};

}  // namespace rifttrace
