// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT
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
  std::vector<std::uint32_t> walk_depth_1(std::uint32_t start) const;
  std::vector<std::uint32_t> walk_depth_2(std::uint32_t start) const;
  std::vector<std::uint32_t> walk_depth_3(std::uint32_t start) const;
  std::vector<std::uint32_t> walk_depth_4(std::uint32_t start) const;
  std::vector<std::uint32_t> walk_depth_5(std::uint32_t start) const;
  std::vector<std::uint32_t> walk_depth_6(std::uint32_t start) const;
  std::vector<std::uint32_t> walk_depth_7(std::uint32_t start) const;
  std::vector<std::uint32_t> walk_depth_8(std::uint32_t start) const;
  std::vector<std::uint32_t> walk_depth_9(std::uint32_t start) const;
  std::vector<std::uint32_t> walk_depth_10(std::uint32_t start) const;
  std::vector<std::uint32_t> walk_depth_11(std::uint32_t start) const;
  std::vector<std::uint32_t> walk_depth_12(std::uint32_t start) const;
  std::vector<std::uint32_t> walk_depth_13(std::uint32_t start) const;
  std::vector<std::uint32_t> walk_depth_14(std::uint32_t start) const;
  std::vector<std::uint32_t> walk_depth_15(std::uint32_t start) const;
  std::vector<std::uint32_t> walk_depth_16(std::uint32_t start) const;
  std::vector<std::uint32_t> walk_depth_17(std::uint32_t start) const;
  std::vector<std::uint32_t> walk_depth_18(std::uint32_t start) const;
  std::vector<std::uint32_t> walk_depth_19(std::uint32_t start) const;
  std::vector<std::uint32_t> walk_depth_20(std::uint32_t start) const;
  private:
  std::unordered_map<std::uint32_t, std::uint32_t> edges_;
  std::unordered_map<std::uint32_t, std::vector<std::uint32_t>> reverse_;
};

}  // namespace rifttrace
