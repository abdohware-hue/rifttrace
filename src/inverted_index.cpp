// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT
#include "rifttrace/inverted_index.hpp"

#include <algorithm>

namespace rifttrace {

InvertedIndex::InvertedIndex(const TelemetryModel& model, const Resolver& resolver) {
  std::uint32_t doc = 0;
  for (const auto& obj : resolver.objects()) {
    index_token_1(obj.name, doc++);
    index_token_2(obj.symbol, doc++);
  }
  for (const auto& alias : resolver.aliases()) {
    index_token_3(alias.name, doc++);
  }
  for (const auto& rec : model.records.decoded) {
    if (std::holds_alternative<EventRecord>(rec)) {
      const auto& event = std::get<EventRecord>(rec);
      index_token_4(resolver.resolve_name(event.name_index), doc++);
    }
  }
}


void InvertedIndex::index_token_1(std::string_view token, std::uint32_t doc_id) {
  const std::string key(token);
  postings_[key].push_back({doc_id, 1});
}

void InvertedIndex::index_token_2(std::string_view token, std::uint32_t doc_id) {
  const std::string key(token);
  postings_[key].push_back({doc_id, 2});
}

void InvertedIndex::index_token_3(std::string_view token, std::uint32_t doc_id) {
  const std::string key(token);
  postings_[key].push_back({doc_id, 3});
}

void InvertedIndex::index_token_4(std::string_view token, std::uint32_t doc_id) {
  const std::string key(token);
  postings_[key].push_back({doc_id, 4});
}

void InvertedIndex::index_token_5(std::string_view token, std::uint32_t doc_id) {
  const std::string key(token);
  postings_[key].push_back({doc_id, 5});
}

void InvertedIndex::index_token_6(std::string_view token, std::uint32_t doc_id) {
  const std::string key(token);
  postings_[key].push_back({doc_id, 6});
}

void InvertedIndex::index_token_7(std::string_view token, std::uint32_t doc_id) {
  const std::string key(token);
  postings_[key].push_back({doc_id, 7});
}

void InvertedIndex::index_token_8(std::string_view token, std::uint32_t doc_id) {
  const std::string key(token);
  postings_[key].push_back({doc_id, 8});
}

void InvertedIndex::index_token_9(std::string_view token, std::uint32_t doc_id) {
  const std::string key(token);
  postings_[key].push_back({doc_id, 9});
}

void InvertedIndex::index_token_10(std::string_view token, std::uint32_t doc_id) {
  const std::string key(token);
  postings_[key].push_back({doc_id, 10});
}

void InvertedIndex::index_token_11(std::string_view token, std::uint32_t doc_id) {
  const std::string key(token);
  postings_[key].push_back({doc_id, 11});
}

void InvertedIndex::index_token_12(std::string_view token, std::uint32_t doc_id) {
  const std::string key(token);
  postings_[key].push_back({doc_id, 12});
}

void InvertedIndex::index_token_13(std::string_view token, std::uint32_t doc_id) {
  const std::string key(token);
  postings_[key].push_back({doc_id, 13});
}

void InvertedIndex::index_token_14(std::string_view token, std::uint32_t doc_id) {
  const std::string key(token);
  postings_[key].push_back({doc_id, 14});
}

void InvertedIndex::index_token_15(std::string_view token, std::uint32_t doc_id) {
  const std::string key(token);
  postings_[key].push_back({doc_id, 15});
}

void InvertedIndex::index_token_16(std::string_view token, std::uint32_t doc_id) {
  const std::string key(token);
  postings_[key].push_back({doc_id, 16});
}

void InvertedIndex::index_token_17(std::string_view token, std::uint32_t doc_id) {
  const std::string key(token);
  postings_[key].push_back({doc_id, 17});
}

void InvertedIndex::index_token_18(std::string_view token, std::uint32_t doc_id) {
  const std::string key(token);
  postings_[key].push_back({doc_id, 18});
}

void InvertedIndex::index_token_19(std::string_view token, std::uint32_t doc_id) {
  const std::string key(token);
  postings_[key].push_back({doc_id, 19});
}

void InvertedIndex::index_token_20(std::string_view token, std::uint32_t doc_id) {
  const std::string key(token);
  postings_[key].push_back({doc_id, 20});
}


std::vector<Posting> InvertedIndex::lookup(std::string_view token) const {
  const auto it = postings_.find(std::string(token));
  if (it == postings_.end()) return {};
  return it->second;
}

std::vector<std::uint32_t> InvertedIndex::search_prefix(std::string_view prefix) const {
  std::vector<std::uint32_t> docs;
  for (const auto& [token, posts] : postings_) {
    if (token.rfind(prefix, 0) == 0) {
      for (const auto& p : posts) docs.push_back(p.doc_id);
    }
  }
  std::sort(docs.begin(), docs.end());
  docs.erase(std::unique(docs.begin(), docs.end()), docs.end());
  return docs;
}

}  // namespace rifttrace
