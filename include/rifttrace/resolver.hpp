// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT

#pragma once

#include <cstdint>
#include <optional>
#include <string>
#include <unordered_map>
#include <vector>

#include "rifttrace/model.hpp"

namespace rifttrace {

struct ResolvedAlias {
  std::uint32_t alias_id = 0;
  std::uint32_t target_id = 0;
  std::string name;
};

struct ResolvedObject {
  std::uint32_t object_id = 0;
  std::string name;
  std::string symbol;
  std::uint32_t pool_slot = 0;
};

struct ResolvedFrame {
  std::uint32_t frame_id = 0;
  std::uint64_t timestamp_ns = 0;
  std::uint32_t parent_frame = 0;
};

class Resolver {
 public:
  explicit Resolver(TelemetryModel* model);

  void rebuild();
  std::string resolve_name(std::uint32_t string_index) const;
  std::optional<ResolvedObject> resolve_object(std::uint32_t object_id) const;
  std::optional<ResolvedAlias> resolve_alias(std::uint32_t alias_id) const;
  std::optional<ResolvedFrame> resolve_frame(std::uint32_t frame_id) const;

  const std::vector<ResolvedAlias>& aliases() const noexcept { return aliases_; }
  const std::vector<ResolvedObject>& objects() const noexcept { return objects_; }

 private:
  TelemetryModel* model_;
  std::vector<ResolvedAlias> aliases_;
  std::vector<ResolvedObject> objects_;
  std::unordered_map<std::uint32_t, std::size_t> object_map_;
  std::unordered_map<std::uint32_t, std::size_t> alias_map_;
};

}  // namespace rifttrace
