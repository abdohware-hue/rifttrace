// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT

#pragma once

#include <cstdint>
#include <string>
#include <vector>

#include "rifttrace/block_cache.hpp"
#include "rifttrace/format.hpp"
#include "rifttrace/frame_index.hpp"
#include "rifttrace/object_pool.hpp"
#include "rifttrace/record.hpp"
#include "rifttrace/string_table.hpp"
#include "rifttrace/symbol_table.hpp"

namespace rifttrace {

struct TelemetryModel {
  Archive archive;
  StringTable strings;
  SymbolTable symbols;
  FrameIndex index;
  ObjectPool pool;
  BlockCache cache;
  RecordBatch records;
  std::vector<MetaEntry> metadata;
  std::vector<DecodedBlock> blocks;
  bool finalized = false;
};

TelemetryModel build_model(const Archive& archive);

}  // namespace rifttrace
