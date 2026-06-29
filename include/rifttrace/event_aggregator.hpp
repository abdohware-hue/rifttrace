// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT
#pragma once

#include <cstdint>
#include <string>
#include <vector>

#include "rifttrace/model.hpp"
#include "rifttrace/resolver.hpp"

namespace rifttrace {

struct EventAggregate {
  std::uint32_t event_id = 0;
  std::uint32_t frame_id = 0;
  std::string name;
  std::uint8_t severity = 0;
};

struct EventBucket {
  std::uint32_t id = 0;
  std::uint32_t count = 0;
  std::vector<EventAggregate> events;
};

struct EventAggregationReport {
  std::vector<EventBucket> buckets;
  std::uint32_t total = 0;
};

class EventAggregator {
 public:
  static EventBucket bucket_severity_0(const TelemetryModel& model, const Resolver& resolver);
  static EventBucket bucket_severity_1(const TelemetryModel& model, const Resolver& resolver);
  static EventBucket bucket_severity_2(const TelemetryModel& model, const Resolver& resolver);
  static EventBucket bucket_severity_3(const TelemetryModel& model, const Resolver& resolver);
  static EventBucket bucket_severity_4(const TelemetryModel& model, const Resolver& resolver);
  static EventBucket bucket_severity_5(const TelemetryModel& model, const Resolver& resolver);
  static EventBucket bucket_severity_6(const TelemetryModel& model, const Resolver& resolver);
  static EventBucket bucket_severity_7(const TelemetryModel& model, const Resolver& resolver);
  static EventBucket bucket_severity_8(const TelemetryModel& model, const Resolver& resolver);
  static EventBucket bucket_severity_9(const TelemetryModel& model, const Resolver& resolver);
  static EventBucket bucket_severity_10(const TelemetryModel& model, const Resolver& resolver);
  static EventBucket bucket_severity_11(const TelemetryModel& model, const Resolver& resolver);
  static EventBucket bucket_severity_12(const TelemetryModel& model, const Resolver& resolver);
  static EventBucket bucket_severity_13(const TelemetryModel& model, const Resolver& resolver);
  static EventBucket bucket_severity_14(const TelemetryModel& model, const Resolver& resolver);
  static EventBucket bucket_severity_15(const TelemetryModel& model, const Resolver& resolver);
  static EventAggregationReport aggregate_all(const TelemetryModel& model, const Resolver& resolver);
};

}  // namespace rifttrace
