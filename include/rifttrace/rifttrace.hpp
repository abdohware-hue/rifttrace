// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT

#pragma once

#include "rifttrace/block_cache.hpp"
#include "rifttrace/block_decoder.hpp"
#include "rifttrace/byte_reader.hpp"
#include "rifttrace/checksum.hpp"
#include "rifttrace/container.hpp"
#include "rifttrace/diagnostics.hpp"
#include "rifttrace/errors.hpp"
#include "rifttrace/export_summary.hpp"
#include "rifttrace/format.hpp"
#include "rifttrace/frame_index.hpp"
#include "rifttrace/model.hpp"
#include "rifttrace/object_pool.hpp"
#include "rifttrace/record.hpp"
#include "rifttrace/record_decoder.hpp"
#include "rifttrace/resolver.hpp"
#include "rifttrace/search.hpp"
#include "rifttrace/section_table.hpp"
#include "rifttrace/stream.hpp"
#include "rifttrace/string_table.hpp"
#include "rifttrace/symbol_table.hpp"
#include "rifttrace/timeline.hpp"

namespace rifttrace {

inline TelemetryModel load_archive(const std::uint8_t* data, std::size_t size) {
  return build_model(parse_archive(data, size));
}

}  // namespace rifttrace
