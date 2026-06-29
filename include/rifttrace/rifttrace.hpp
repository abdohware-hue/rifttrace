// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT

#pragma once

#include "rifttrace/alias_graph.hpp"
#include "rifttrace/archive_builder.hpp"
#include "rifttrace/archive_writer.hpp"
#include "rifttrace/binary_writer.hpp"
#include "rifttrace/block_cache.hpp"
#include "rifttrace/block_decoder.hpp"
#include "rifttrace/block_encoder.hpp"
#include "rifttrace/byte_reader.hpp"
#include "rifttrace/checkpoint_replay.hpp"
#include "rifttrace/checkpoint_store.hpp"
#include "rifttrace/checksum.hpp"
#include "rifttrace/codec_registry.hpp"
#include "rifttrace/container.hpp"
#include "rifttrace/correlation_engine.hpp"
#include "rifttrace/delta_codec.hpp"
#include "rifttrace/diagnostics.hpp"
#include "rifttrace/dictionary_codec.hpp"
#include "rifttrace/errors.hpp"
#include "rifttrace/event_aggregator.hpp"
#include "rifttrace/export_pipeline.hpp"
#include "rifttrace/export_summary.hpp"
#include "rifttrace/filter_engine.hpp"
#include "rifttrace/format.hpp"
#include "rifttrace/format_rules.hpp"
#include "rifttrace/frame_delta.hpp"
#include "rifttrace/frame_index.hpp"
#include "rifttrace/graph_validator.hpp"
#include "rifttrace/index_builder.hpp"
#include "rifttrace/inverted_index.hpp"
#include "rifttrace/json_report.hpp"
#include "rifttrace/metadata_parser.hpp"
#include "rifttrace/model.hpp"
#include "rifttrace/object_pool.hpp"
#include "rifttrace/pool_analyzer.hpp"
#include "rifttrace/query_ast.hpp"
#include "rifttrace/record.hpp"
#include "rifttrace/record_builder.hpp"
#include "rifttrace/record_decoder.hpp"
#include "rifttrace/replay_session.hpp"
#include "rifttrace/resolver.hpp"
#include "rifttrace/search.hpp"
#include "rifttrace/section_table.hpp"
#include "rifttrace/section_validator.hpp"
#include "rifttrace/stream.hpp"
#include "rifttrace/stream_query.hpp"
#include "rifttrace/string_table.hpp"
#include "rifttrace/summary_builder.hpp"
#include "rifttrace/symbol_table.hpp"
#include "rifttrace/telemetry_pipeline.hpp"
#include "rifttrace/timeline.hpp"
#include "rifttrace/timeline_analytics.hpp"

namespace rifttrace {

inline TelemetryModel load_archive(const std::uint8_t* data, std::size_t size) {
  return build_model(parse_archive(data, size));
}

}  // namespace rifttrace
