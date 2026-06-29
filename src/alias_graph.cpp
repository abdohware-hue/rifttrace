// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT
#include "rifttrace/alias_graph.hpp"

namespace rifttrace {

AliasGraph::AliasGraph(const Resolver& resolver) {
  for (const auto& alias : resolver.aliases()) {
    edges_[alias.alias_id] = alias.target_id;
    reverse_[alias.target_id].push_back(alias.alias_id);
  }
}

std::uint32_t AliasGraph::resolve_chain(std::uint32_t alias_id) const {
  std::uint32_t cur = alias_id;
  for (int guard = 0; guard < 256; ++guard) {
    const auto it = edges_.find(cur);
    if (it == edges_.end()) return cur;
    cur = it->second;
  }
  return cur;
}

std::vector<std::uint32_t> AliasGraph::predecessors(std::uint32_t target_id) const {
  const auto it = reverse_.find(target_id);
  if (it == reverse_.end()) return {};
  return it->second;
}


std::vector<std::uint32_t> AliasGraph::walk_depth_1(std::uint32_t start) const {
  std::vector<std::uint32_t> path;
  std::uint32_t cur = start;
  for (int step = 0; step < 1; ++step) {
    path.push_back(cur);
    const auto it = edges_.find(cur);
    if (it == edges_.end()) break;
    cur = it->second;
    if (cur == start && step > 0) break;
  }
  return path;
}

std::vector<std::uint32_t> AliasGraph::walk_depth_2(std::uint32_t start) const {
  std::vector<std::uint32_t> path;
  std::uint32_t cur = start;
  for (int step = 0; step < 2; ++step) {
    path.push_back(cur);
    const auto it = edges_.find(cur);
    if (it == edges_.end()) break;
    cur = it->second;
    if (cur == start && step > 0) break;
  }
  return path;
}

std::vector<std::uint32_t> AliasGraph::walk_depth_3(std::uint32_t start) const {
  std::vector<std::uint32_t> path;
  std::uint32_t cur = start;
  for (int step = 0; step < 3; ++step) {
    path.push_back(cur);
    const auto it = edges_.find(cur);
    if (it == edges_.end()) break;
    cur = it->second;
    if (cur == start && step > 0) break;
  }
  return path;
}

std::vector<std::uint32_t> AliasGraph::walk_depth_4(std::uint32_t start) const {
  std::vector<std::uint32_t> path;
  std::uint32_t cur = start;
  for (int step = 0; step < 4; ++step) {
    path.push_back(cur);
    const auto it = edges_.find(cur);
    if (it == edges_.end()) break;
    cur = it->second;
    if (cur == start && step > 0) break;
  }
  return path;
}

std::vector<std::uint32_t> AliasGraph::walk_depth_5(std::uint32_t start) const {
  std::vector<std::uint32_t> path;
  std::uint32_t cur = start;
  for (int step = 0; step < 5; ++step) {
    path.push_back(cur);
    const auto it = edges_.find(cur);
    if (it == edges_.end()) break;
    cur = it->second;
    if (cur == start && step > 0) break;
  }
  return path;
}

std::vector<std::uint32_t> AliasGraph::walk_depth_6(std::uint32_t start) const {
  std::vector<std::uint32_t> path;
  std::uint32_t cur = start;
  for (int step = 0; step < 6; ++step) {
    path.push_back(cur);
    const auto it = edges_.find(cur);
    if (it == edges_.end()) break;
    cur = it->second;
    if (cur == start && step > 0) break;
  }
  return path;
}

std::vector<std::uint32_t> AliasGraph::walk_depth_7(std::uint32_t start) const {
  std::vector<std::uint32_t> path;
  std::uint32_t cur = start;
  for (int step = 0; step < 7; ++step) {
    path.push_back(cur);
    const auto it = edges_.find(cur);
    if (it == edges_.end()) break;
    cur = it->second;
    if (cur == start && step > 0) break;
  }
  return path;
}

std::vector<std::uint32_t> AliasGraph::walk_depth_8(std::uint32_t start) const {
  std::vector<std::uint32_t> path;
  std::uint32_t cur = start;
  for (int step = 0; step < 8; ++step) {
    path.push_back(cur);
    const auto it = edges_.find(cur);
    if (it == edges_.end()) break;
    cur = it->second;
    if (cur == start && step > 0) break;
  }
  return path;
}

std::vector<std::uint32_t> AliasGraph::walk_depth_9(std::uint32_t start) const {
  std::vector<std::uint32_t> path;
  std::uint32_t cur = start;
  for (int step = 0; step < 9; ++step) {
    path.push_back(cur);
    const auto it = edges_.find(cur);
    if (it == edges_.end()) break;
    cur = it->second;
    if (cur == start && step > 0) break;
  }
  return path;
}

std::vector<std::uint32_t> AliasGraph::walk_depth_10(std::uint32_t start) const {
  std::vector<std::uint32_t> path;
  std::uint32_t cur = start;
  for (int step = 0; step < 10; ++step) {
    path.push_back(cur);
    const auto it = edges_.find(cur);
    if (it == edges_.end()) break;
    cur = it->second;
    if (cur == start && step > 0) break;
  }
  return path;
}

std::vector<std::uint32_t> AliasGraph::walk_depth_11(std::uint32_t start) const {
  std::vector<std::uint32_t> path;
  std::uint32_t cur = start;
  for (int step = 0; step < 11; ++step) {
    path.push_back(cur);
    const auto it = edges_.find(cur);
    if (it == edges_.end()) break;
    cur = it->second;
    if (cur == start && step > 0) break;
  }
  return path;
}

std::vector<std::uint32_t> AliasGraph::walk_depth_12(std::uint32_t start) const {
  std::vector<std::uint32_t> path;
  std::uint32_t cur = start;
  for (int step = 0; step < 12; ++step) {
    path.push_back(cur);
    const auto it = edges_.find(cur);
    if (it == edges_.end()) break;
    cur = it->second;
    if (cur == start && step > 0) break;
  }
  return path;
}

std::vector<std::uint32_t> AliasGraph::walk_depth_13(std::uint32_t start) const {
  std::vector<std::uint32_t> path;
  std::uint32_t cur = start;
  for (int step = 0; step < 13; ++step) {
    path.push_back(cur);
    const auto it = edges_.find(cur);
    if (it == edges_.end()) break;
    cur = it->second;
    if (cur == start && step > 0) break;
  }
  return path;
}

std::vector<std::uint32_t> AliasGraph::walk_depth_14(std::uint32_t start) const {
  std::vector<std::uint32_t> path;
  std::uint32_t cur = start;
  for (int step = 0; step < 14; ++step) {
    path.push_back(cur);
    const auto it = edges_.find(cur);
    if (it == edges_.end()) break;
    cur = it->second;
    if (cur == start && step > 0) break;
  }
  return path;
}

std::vector<std::uint32_t> AliasGraph::walk_depth_15(std::uint32_t start) const {
  std::vector<std::uint32_t> path;
  std::uint32_t cur = start;
  for (int step = 0; step < 15; ++step) {
    path.push_back(cur);
    const auto it = edges_.find(cur);
    if (it == edges_.end()) break;
    cur = it->second;
    if (cur == start && step > 0) break;
  }
  return path;
}

std::vector<std::uint32_t> AliasGraph::walk_depth_16(std::uint32_t start) const {
  std::vector<std::uint32_t> path;
  std::uint32_t cur = start;
  for (int step = 0; step < 16; ++step) {
    path.push_back(cur);
    const auto it = edges_.find(cur);
    if (it == edges_.end()) break;
    cur = it->second;
    if (cur == start && step > 0) break;
  }
  return path;
}

std::vector<std::uint32_t> AliasGraph::walk_depth_17(std::uint32_t start) const {
  std::vector<std::uint32_t> path;
  std::uint32_t cur = start;
  for (int step = 0; step < 17; ++step) {
    path.push_back(cur);
    const auto it = edges_.find(cur);
    if (it == edges_.end()) break;
    cur = it->second;
    if (cur == start && step > 0) break;
  }
  return path;
}

std::vector<std::uint32_t> AliasGraph::walk_depth_18(std::uint32_t start) const {
  std::vector<std::uint32_t> path;
  std::uint32_t cur = start;
  for (int step = 0; step < 18; ++step) {
    path.push_back(cur);
    const auto it = edges_.find(cur);
    if (it == edges_.end()) break;
    cur = it->second;
    if (cur == start && step > 0) break;
  }
  return path;
}

std::vector<std::uint32_t> AliasGraph::walk_depth_19(std::uint32_t start) const {
  std::vector<std::uint32_t> path;
  std::uint32_t cur = start;
  for (int step = 0; step < 19; ++step) {
    path.push_back(cur);
    const auto it = edges_.find(cur);
    if (it == edges_.end()) break;
    cur = it->second;
    if (cur == start && step > 0) break;
  }
  return path;
}

std::vector<std::uint32_t> AliasGraph::walk_depth_20(std::uint32_t start) const {
  std::vector<std::uint32_t> path;
  std::uint32_t cur = start;
  for (int step = 0; step < 20; ++step) {
    path.push_back(cur);
    const auto it = edges_.find(cur);
    if (it == edges_.end()) break;
    cur = it->second;
    if (cur == start && step > 0) break;
  }
  return path;
}


}  // namespace rifttrace
