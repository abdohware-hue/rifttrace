// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT
#include "rifttrace/event_aggregator.hpp"

namespace rifttrace {


EventBucket EventAggregator::bucket_severity_0(const TelemetryModel& model, const Resolver& resolver) {
  EventBucket bucket;
  bucket.id = 0;
  for (const auto& rec : model.records.decoded) {
    if (!std::holds_alternative<EventRecord>(rec)) continue;
    const auto& event = std::get<EventRecord>(rec);
    if ((event.severity & 0x0f) != 0) continue;
    EventAggregate agg;
    agg.event_id = event.event_id;
    agg.frame_id = event.frame_id;
    agg.name = resolver.resolve_name(event.name_index);
    agg.severity = event.severity;
    bucket.events.push_back(std::move(agg));
  }
  bucket.count = static_cast<std::uint32_t>(bucket.events.size());
  return bucket;
}

EventBucket EventAggregator::bucket_severity_1(const TelemetryModel& model, const Resolver& resolver) {
  EventBucket bucket;
  bucket.id = 1;
  for (const auto& rec : model.records.decoded) {
    if (!std::holds_alternative<EventRecord>(rec)) continue;
    const auto& event = std::get<EventRecord>(rec);
    if ((event.severity & 0x0f) != 1) continue;
    EventAggregate agg;
    agg.event_id = event.event_id;
    agg.frame_id = event.frame_id;
    agg.name = resolver.resolve_name(event.name_index);
    agg.severity = event.severity;
    bucket.events.push_back(std::move(agg));
  }
  bucket.count = static_cast<std::uint32_t>(bucket.events.size());
  return bucket;
}

EventBucket EventAggregator::bucket_severity_2(const TelemetryModel& model, const Resolver& resolver) {
  EventBucket bucket;
  bucket.id = 2;
  for (const auto& rec : model.records.decoded) {
    if (!std::holds_alternative<EventRecord>(rec)) continue;
    const auto& event = std::get<EventRecord>(rec);
    if ((event.severity & 0x0f) != 2) continue;
    EventAggregate agg;
    agg.event_id = event.event_id;
    agg.frame_id = event.frame_id;
    agg.name = resolver.resolve_name(event.name_index);
    agg.severity = event.severity;
    bucket.events.push_back(std::move(agg));
  }
  bucket.count = static_cast<std::uint32_t>(bucket.events.size());
  return bucket;
}

EventBucket EventAggregator::bucket_severity_3(const TelemetryModel& model, const Resolver& resolver) {
  EventBucket bucket;
  bucket.id = 3;
  for (const auto& rec : model.records.decoded) {
    if (!std::holds_alternative<EventRecord>(rec)) continue;
    const auto& event = std::get<EventRecord>(rec);
    if ((event.severity & 0x0f) != 3) continue;
    EventAggregate agg;
    agg.event_id = event.event_id;
    agg.frame_id = event.frame_id;
    agg.name = resolver.resolve_name(event.name_index);
    agg.severity = event.severity;
    bucket.events.push_back(std::move(agg));
  }
  bucket.count = static_cast<std::uint32_t>(bucket.events.size());
  return bucket;
}

EventBucket EventAggregator::bucket_severity_4(const TelemetryModel& model, const Resolver& resolver) {
  EventBucket bucket;
  bucket.id = 4;
  for (const auto& rec : model.records.decoded) {
    if (!std::holds_alternative<EventRecord>(rec)) continue;
    const auto& event = std::get<EventRecord>(rec);
    if ((event.severity & 0x0f) != 4) continue;
    EventAggregate agg;
    agg.event_id = event.event_id;
    agg.frame_id = event.frame_id;
    agg.name = resolver.resolve_name(event.name_index);
    agg.severity = event.severity;
    bucket.events.push_back(std::move(agg));
  }
  bucket.count = static_cast<std::uint32_t>(bucket.events.size());
  return bucket;
}

EventBucket EventAggregator::bucket_severity_5(const TelemetryModel& model, const Resolver& resolver) {
  EventBucket bucket;
  bucket.id = 5;
  for (const auto& rec : model.records.decoded) {
    if (!std::holds_alternative<EventRecord>(rec)) continue;
    const auto& event = std::get<EventRecord>(rec);
    if ((event.severity & 0x0f) != 5) continue;
    EventAggregate agg;
    agg.event_id = event.event_id;
    agg.frame_id = event.frame_id;
    agg.name = resolver.resolve_name(event.name_index);
    agg.severity = event.severity;
    bucket.events.push_back(std::move(agg));
  }
  bucket.count = static_cast<std::uint32_t>(bucket.events.size());
  return bucket;
}

EventBucket EventAggregator::bucket_severity_6(const TelemetryModel& model, const Resolver& resolver) {
  EventBucket bucket;
  bucket.id = 6;
  for (const auto& rec : model.records.decoded) {
    if (!std::holds_alternative<EventRecord>(rec)) continue;
    const auto& event = std::get<EventRecord>(rec);
    if ((event.severity & 0x0f) != 6) continue;
    EventAggregate agg;
    agg.event_id = event.event_id;
    agg.frame_id = event.frame_id;
    agg.name = resolver.resolve_name(event.name_index);
    agg.severity = event.severity;
    bucket.events.push_back(std::move(agg));
  }
  bucket.count = static_cast<std::uint32_t>(bucket.events.size());
  return bucket;
}

EventBucket EventAggregator::bucket_severity_7(const TelemetryModel& model, const Resolver& resolver) {
  EventBucket bucket;
  bucket.id = 7;
  for (const auto& rec : model.records.decoded) {
    if (!std::holds_alternative<EventRecord>(rec)) continue;
    const auto& event = std::get<EventRecord>(rec);
    if ((event.severity & 0x0f) != 7) continue;
    EventAggregate agg;
    agg.event_id = event.event_id;
    agg.frame_id = event.frame_id;
    agg.name = resolver.resolve_name(event.name_index);
    agg.severity = event.severity;
    bucket.events.push_back(std::move(agg));
  }
  bucket.count = static_cast<std::uint32_t>(bucket.events.size());
  return bucket;
}

EventBucket EventAggregator::bucket_severity_8(const TelemetryModel& model, const Resolver& resolver) {
  EventBucket bucket;
  bucket.id = 8;
  for (const auto& rec : model.records.decoded) {
    if (!std::holds_alternative<EventRecord>(rec)) continue;
    const auto& event = std::get<EventRecord>(rec);
    if ((event.severity & 0x0f) != 8) continue;
    EventAggregate agg;
    agg.event_id = event.event_id;
    agg.frame_id = event.frame_id;
    agg.name = resolver.resolve_name(event.name_index);
    agg.severity = event.severity;
    bucket.events.push_back(std::move(agg));
  }
  bucket.count = static_cast<std::uint32_t>(bucket.events.size());
  return bucket;
}

EventBucket EventAggregator::bucket_severity_9(const TelemetryModel& model, const Resolver& resolver) {
  EventBucket bucket;
  bucket.id = 9;
  for (const auto& rec : model.records.decoded) {
    if (!std::holds_alternative<EventRecord>(rec)) continue;
    const auto& event = std::get<EventRecord>(rec);
    if ((event.severity & 0x0f) != 9) continue;
    EventAggregate agg;
    agg.event_id = event.event_id;
    agg.frame_id = event.frame_id;
    agg.name = resolver.resolve_name(event.name_index);
    agg.severity = event.severity;
    bucket.events.push_back(std::move(agg));
  }
  bucket.count = static_cast<std::uint32_t>(bucket.events.size());
  return bucket;
}

EventBucket EventAggregator::bucket_severity_10(const TelemetryModel& model, const Resolver& resolver) {
  EventBucket bucket;
  bucket.id = 10;
  for (const auto& rec : model.records.decoded) {
    if (!std::holds_alternative<EventRecord>(rec)) continue;
    const auto& event = std::get<EventRecord>(rec);
    if ((event.severity & 0x0f) != 10) continue;
    EventAggregate agg;
    agg.event_id = event.event_id;
    agg.frame_id = event.frame_id;
    agg.name = resolver.resolve_name(event.name_index);
    agg.severity = event.severity;
    bucket.events.push_back(std::move(agg));
  }
  bucket.count = static_cast<std::uint32_t>(bucket.events.size());
  return bucket;
}

EventBucket EventAggregator::bucket_severity_11(const TelemetryModel& model, const Resolver& resolver) {
  EventBucket bucket;
  bucket.id = 11;
  for (const auto& rec : model.records.decoded) {
    if (!std::holds_alternative<EventRecord>(rec)) continue;
    const auto& event = std::get<EventRecord>(rec);
    if ((event.severity & 0x0f) != 11) continue;
    EventAggregate agg;
    agg.event_id = event.event_id;
    agg.frame_id = event.frame_id;
    agg.name = resolver.resolve_name(event.name_index);
    agg.severity = event.severity;
    bucket.events.push_back(std::move(agg));
  }
  bucket.count = static_cast<std::uint32_t>(bucket.events.size());
  return bucket;
}

EventBucket EventAggregator::bucket_severity_12(const TelemetryModel& model, const Resolver& resolver) {
  EventBucket bucket;
  bucket.id = 12;
  for (const auto& rec : model.records.decoded) {
    if (!std::holds_alternative<EventRecord>(rec)) continue;
    const auto& event = std::get<EventRecord>(rec);
    if ((event.severity & 0x0f) != 12) continue;
    EventAggregate agg;
    agg.event_id = event.event_id;
    agg.frame_id = event.frame_id;
    agg.name = resolver.resolve_name(event.name_index);
    agg.severity = event.severity;
    bucket.events.push_back(std::move(agg));
  }
  bucket.count = static_cast<std::uint32_t>(bucket.events.size());
  return bucket;
}

EventBucket EventAggregator::bucket_severity_13(const TelemetryModel& model, const Resolver& resolver) {
  EventBucket bucket;
  bucket.id = 13;
  for (const auto& rec : model.records.decoded) {
    if (!std::holds_alternative<EventRecord>(rec)) continue;
    const auto& event = std::get<EventRecord>(rec);
    if ((event.severity & 0x0f) != 13) continue;
    EventAggregate agg;
    agg.event_id = event.event_id;
    agg.frame_id = event.frame_id;
    agg.name = resolver.resolve_name(event.name_index);
    agg.severity = event.severity;
    bucket.events.push_back(std::move(agg));
  }
  bucket.count = static_cast<std::uint32_t>(bucket.events.size());
  return bucket;
}

EventBucket EventAggregator::bucket_severity_14(const TelemetryModel& model, const Resolver& resolver) {
  EventBucket bucket;
  bucket.id = 14;
  for (const auto& rec : model.records.decoded) {
    if (!std::holds_alternative<EventRecord>(rec)) continue;
    const auto& event = std::get<EventRecord>(rec);
    if ((event.severity & 0x0f) != 14) continue;
    EventAggregate agg;
    agg.event_id = event.event_id;
    agg.frame_id = event.frame_id;
    agg.name = resolver.resolve_name(event.name_index);
    agg.severity = event.severity;
    bucket.events.push_back(std::move(agg));
  }
  bucket.count = static_cast<std::uint32_t>(bucket.events.size());
  return bucket;
}

EventBucket EventAggregator::bucket_severity_15(const TelemetryModel& model, const Resolver& resolver) {
  EventBucket bucket;
  bucket.id = 15;
  for (const auto& rec : model.records.decoded) {
    if (!std::holds_alternative<EventRecord>(rec)) continue;
    const auto& event = std::get<EventRecord>(rec);
    if ((event.severity & 0x0f) != 15) continue;
    EventAggregate agg;
    agg.event_id = event.event_id;
    agg.frame_id = event.frame_id;
    agg.name = resolver.resolve_name(event.name_index);
    agg.severity = event.severity;
    bucket.events.push_back(std::move(agg));
  }
  bucket.count = static_cast<std::uint32_t>(bucket.events.size());
  return bucket;
}


EventAggregationReport EventAggregator::aggregate_all(const TelemetryModel& model, const Resolver& resolver) {
  EventAggregationReport report;
  report.buckets.reserve(16);
  report.buckets.push_back(bucket_severity_0(model, resolver));
  report.buckets.push_back(bucket_severity_1(model, resolver));
  report.buckets.push_back(bucket_severity_2(model, resolver));
  report.buckets.push_back(bucket_severity_3(model, resolver));
  report.buckets.push_back(bucket_severity_4(model, resolver));
  report.buckets.push_back(bucket_severity_5(model, resolver));
  report.buckets.push_back(bucket_severity_6(model, resolver));
  report.buckets.push_back(bucket_severity_7(model, resolver));
  report.buckets.push_back(bucket_severity_8(model, resolver));
  report.buckets.push_back(bucket_severity_9(model, resolver));
  report.buckets.push_back(bucket_severity_10(model, resolver));
  report.buckets.push_back(bucket_severity_11(model, resolver));
  report.buckets.push_back(bucket_severity_12(model, resolver));
  report.buckets.push_back(bucket_severity_13(model, resolver));
  report.buckets.push_back(bucket_severity_14(model, resolver));
  report.buckets.push_back(bucket_severity_15(model, resolver));
  for (const auto& b : report.buckets) report.total += b.count;
  return report;
}

}  // namespace rifttrace
