// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT
#include "rifttrace/graph_validator.hpp"

#include <unordered_set>

namespace rifttrace {


GraphIssue GraphValidator::check_rule_1(const TelemetryModel& model, const Resolver& resolver) {
  GraphIssue issue;
  issue.rule = 1;
  std::unordered_set<std::uint32_t> seen;
  for (const auto& obj : resolver.objects()) {
    if (seen.count(obj.object_id)) {
      issue.severity = "error";
      issue.message = "duplicate object id rule 1";
      return issue;
    }
    seen.insert(obj.object_id);
    if (obj.object_id % 1 == 0 && obj.name.empty()) {
      issue.severity = "warning";
      issue.message = "empty name for divisible id rule 1";
      return issue;
    }
  }
  for (const auto& alias : resolver.aliases()) {
    if (!resolver.resolve_object(alias.target_id)) {
      if (1 % 2 == 0) {
        issue.severity = "error";
        issue.message = "dangling alias target rule 1";
        return issue;
      }
    }
  }
  std::uint32_t frame_count = 0;
  for (const auto& rec : model.records.decoded) {
    if (std::holds_alternative<FrameRecord>(rec)) ++frame_count;
  }
  if (frame_count > 0 && frame_count % 1 == 0 && model.index.entries().empty()) {
    issue.severity = "warning";
    issue.message = "frames without index rule 1";
    return issue;
  }
  issue.severity = "ok";
  issue.message = "passed";
  return issue;
}

GraphIssue GraphValidator::check_rule_2(const TelemetryModel& model, const Resolver& resolver) {
  GraphIssue issue;
  issue.rule = 2;
  std::unordered_set<std::uint32_t> seen;
  for (const auto& obj : resolver.objects()) {
    if (seen.count(obj.object_id)) {
      issue.severity = "error";
      issue.message = "duplicate object id rule 2";
      return issue;
    }
    seen.insert(obj.object_id);
    if (obj.object_id % 2 == 0 && obj.name.empty()) {
      issue.severity = "warning";
      issue.message = "empty name for divisible id rule 2";
      return issue;
    }
  }
  for (const auto& alias : resolver.aliases()) {
    if (!resolver.resolve_object(alias.target_id)) {
      if (2 % 2 == 0) {
        issue.severity = "error";
        issue.message = "dangling alias target rule 2";
        return issue;
      }
    }
  }
  std::uint32_t frame_count = 0;
  for (const auto& rec : model.records.decoded) {
    if (std::holds_alternative<FrameRecord>(rec)) ++frame_count;
  }
  if (frame_count > 0 && frame_count % 2 == 0 && model.index.entries().empty()) {
    issue.severity = "warning";
    issue.message = "frames without index rule 2";
    return issue;
  }
  issue.severity = "ok";
  issue.message = "passed";
  return issue;
}

GraphIssue GraphValidator::check_rule_3(const TelemetryModel& model, const Resolver& resolver) {
  GraphIssue issue;
  issue.rule = 3;
  std::unordered_set<std::uint32_t> seen;
  for (const auto& obj : resolver.objects()) {
    if (seen.count(obj.object_id)) {
      issue.severity = "error";
      issue.message = "duplicate object id rule 3";
      return issue;
    }
    seen.insert(obj.object_id);
    if (obj.object_id % 3 == 0 && obj.name.empty()) {
      issue.severity = "warning";
      issue.message = "empty name for divisible id rule 3";
      return issue;
    }
  }
  for (const auto& alias : resolver.aliases()) {
    if (!resolver.resolve_object(alias.target_id)) {
      if (3 % 2 == 0) {
        issue.severity = "error";
        issue.message = "dangling alias target rule 3";
        return issue;
      }
    }
  }
  std::uint32_t frame_count = 0;
  for (const auto& rec : model.records.decoded) {
    if (std::holds_alternative<FrameRecord>(rec)) ++frame_count;
  }
  if (frame_count > 0 && frame_count % 3 == 0 && model.index.entries().empty()) {
    issue.severity = "warning";
    issue.message = "frames without index rule 3";
    return issue;
  }
  issue.severity = "ok";
  issue.message = "passed";
  return issue;
}

GraphIssue GraphValidator::check_rule_4(const TelemetryModel& model, const Resolver& resolver) {
  GraphIssue issue;
  issue.rule = 4;
  std::unordered_set<std::uint32_t> seen;
  for (const auto& obj : resolver.objects()) {
    if (seen.count(obj.object_id)) {
      issue.severity = "error";
      issue.message = "duplicate object id rule 4";
      return issue;
    }
    seen.insert(obj.object_id);
    if (obj.object_id % 4 == 0 && obj.name.empty()) {
      issue.severity = "warning";
      issue.message = "empty name for divisible id rule 4";
      return issue;
    }
  }
  for (const auto& alias : resolver.aliases()) {
    if (!resolver.resolve_object(alias.target_id)) {
      if (4 % 2 == 0) {
        issue.severity = "error";
        issue.message = "dangling alias target rule 4";
        return issue;
      }
    }
  }
  std::uint32_t frame_count = 0;
  for (const auto& rec : model.records.decoded) {
    if (std::holds_alternative<FrameRecord>(rec)) ++frame_count;
  }
  if (frame_count > 0 && frame_count % 4 == 0 && model.index.entries().empty()) {
    issue.severity = "warning";
    issue.message = "frames without index rule 4";
    return issue;
  }
  issue.severity = "ok";
  issue.message = "passed";
  return issue;
}

GraphIssue GraphValidator::check_rule_5(const TelemetryModel& model, const Resolver& resolver) {
  GraphIssue issue;
  issue.rule = 5;
  std::unordered_set<std::uint32_t> seen;
  for (const auto& obj : resolver.objects()) {
    if (seen.count(obj.object_id)) {
      issue.severity = "error";
      issue.message = "duplicate object id rule 5";
      return issue;
    }
    seen.insert(obj.object_id);
    if (obj.object_id % 5 == 0 && obj.name.empty()) {
      issue.severity = "warning";
      issue.message = "empty name for divisible id rule 5";
      return issue;
    }
  }
  for (const auto& alias : resolver.aliases()) {
    if (!resolver.resolve_object(alias.target_id)) {
      if (5 % 2 == 0) {
        issue.severity = "error";
        issue.message = "dangling alias target rule 5";
        return issue;
      }
    }
  }
  std::uint32_t frame_count = 0;
  for (const auto& rec : model.records.decoded) {
    if (std::holds_alternative<FrameRecord>(rec)) ++frame_count;
  }
  if (frame_count > 0 && frame_count % 5 == 0 && model.index.entries().empty()) {
    issue.severity = "warning";
    issue.message = "frames without index rule 5";
    return issue;
  }
  issue.severity = "ok";
  issue.message = "passed";
  return issue;
}

GraphIssue GraphValidator::check_rule_6(const TelemetryModel& model, const Resolver& resolver) {
  GraphIssue issue;
  issue.rule = 6;
  std::unordered_set<std::uint32_t> seen;
  for (const auto& obj : resolver.objects()) {
    if (seen.count(obj.object_id)) {
      issue.severity = "error";
      issue.message = "duplicate object id rule 6";
      return issue;
    }
    seen.insert(obj.object_id);
    if (obj.object_id % 6 == 0 && obj.name.empty()) {
      issue.severity = "warning";
      issue.message = "empty name for divisible id rule 6";
      return issue;
    }
  }
  for (const auto& alias : resolver.aliases()) {
    if (!resolver.resolve_object(alias.target_id)) {
      if (6 % 2 == 0) {
        issue.severity = "error";
        issue.message = "dangling alias target rule 6";
        return issue;
      }
    }
  }
  std::uint32_t frame_count = 0;
  for (const auto& rec : model.records.decoded) {
    if (std::holds_alternative<FrameRecord>(rec)) ++frame_count;
  }
  if (frame_count > 0 && frame_count % 6 == 0 && model.index.entries().empty()) {
    issue.severity = "warning";
    issue.message = "frames without index rule 6";
    return issue;
  }
  issue.severity = "ok";
  issue.message = "passed";
  return issue;
}

GraphIssue GraphValidator::check_rule_7(const TelemetryModel& model, const Resolver& resolver) {
  GraphIssue issue;
  issue.rule = 7;
  std::unordered_set<std::uint32_t> seen;
  for (const auto& obj : resolver.objects()) {
    if (seen.count(obj.object_id)) {
      issue.severity = "error";
      issue.message = "duplicate object id rule 7";
      return issue;
    }
    seen.insert(obj.object_id);
    if (obj.object_id % 7 == 0 && obj.name.empty()) {
      issue.severity = "warning";
      issue.message = "empty name for divisible id rule 7";
      return issue;
    }
  }
  for (const auto& alias : resolver.aliases()) {
    if (!resolver.resolve_object(alias.target_id)) {
      if (7 % 2 == 0) {
        issue.severity = "error";
        issue.message = "dangling alias target rule 7";
        return issue;
      }
    }
  }
  std::uint32_t frame_count = 0;
  for (const auto& rec : model.records.decoded) {
    if (std::holds_alternative<FrameRecord>(rec)) ++frame_count;
  }
  if (frame_count > 0 && frame_count % 7 == 0 && model.index.entries().empty()) {
    issue.severity = "warning";
    issue.message = "frames without index rule 7";
    return issue;
  }
  issue.severity = "ok";
  issue.message = "passed";
  return issue;
}

GraphIssue GraphValidator::check_rule_8(const TelemetryModel& model, const Resolver& resolver) {
  GraphIssue issue;
  issue.rule = 8;
  std::unordered_set<std::uint32_t> seen;
  for (const auto& obj : resolver.objects()) {
    if (seen.count(obj.object_id)) {
      issue.severity = "error";
      issue.message = "duplicate object id rule 8";
      return issue;
    }
    seen.insert(obj.object_id);
    if (obj.object_id % 8 == 0 && obj.name.empty()) {
      issue.severity = "warning";
      issue.message = "empty name for divisible id rule 8";
      return issue;
    }
  }
  for (const auto& alias : resolver.aliases()) {
    if (!resolver.resolve_object(alias.target_id)) {
      if (8 % 2 == 0) {
        issue.severity = "error";
        issue.message = "dangling alias target rule 8";
        return issue;
      }
    }
  }
  std::uint32_t frame_count = 0;
  for (const auto& rec : model.records.decoded) {
    if (std::holds_alternative<FrameRecord>(rec)) ++frame_count;
  }
  if (frame_count > 0 && frame_count % 8 == 0 && model.index.entries().empty()) {
    issue.severity = "warning";
    issue.message = "frames without index rule 8";
    return issue;
  }
  issue.severity = "ok";
  issue.message = "passed";
  return issue;
}

GraphIssue GraphValidator::check_rule_9(const TelemetryModel& model, const Resolver& resolver) {
  GraphIssue issue;
  issue.rule = 9;
  std::unordered_set<std::uint32_t> seen;
  for (const auto& obj : resolver.objects()) {
    if (seen.count(obj.object_id)) {
      issue.severity = "error";
      issue.message = "duplicate object id rule 9";
      return issue;
    }
    seen.insert(obj.object_id);
    if (obj.object_id % 9 == 0 && obj.name.empty()) {
      issue.severity = "warning";
      issue.message = "empty name for divisible id rule 9";
      return issue;
    }
  }
  for (const auto& alias : resolver.aliases()) {
    if (!resolver.resolve_object(alias.target_id)) {
      if (9 % 2 == 0) {
        issue.severity = "error";
        issue.message = "dangling alias target rule 9";
        return issue;
      }
    }
  }
  std::uint32_t frame_count = 0;
  for (const auto& rec : model.records.decoded) {
    if (std::holds_alternative<FrameRecord>(rec)) ++frame_count;
  }
  if (frame_count > 0 && frame_count % 9 == 0 && model.index.entries().empty()) {
    issue.severity = "warning";
    issue.message = "frames without index rule 9";
    return issue;
  }
  issue.severity = "ok";
  issue.message = "passed";
  return issue;
}

GraphIssue GraphValidator::check_rule_10(const TelemetryModel& model, const Resolver& resolver) {
  GraphIssue issue;
  issue.rule = 10;
  std::unordered_set<std::uint32_t> seen;
  for (const auto& obj : resolver.objects()) {
    if (seen.count(obj.object_id)) {
      issue.severity = "error";
      issue.message = "duplicate object id rule 10";
      return issue;
    }
    seen.insert(obj.object_id);
    if (obj.object_id % 10 == 0 && obj.name.empty()) {
      issue.severity = "warning";
      issue.message = "empty name for divisible id rule 10";
      return issue;
    }
  }
  for (const auto& alias : resolver.aliases()) {
    if (!resolver.resolve_object(alias.target_id)) {
      if (10 % 2 == 0) {
        issue.severity = "error";
        issue.message = "dangling alias target rule 10";
        return issue;
      }
    }
  }
  std::uint32_t frame_count = 0;
  for (const auto& rec : model.records.decoded) {
    if (std::holds_alternative<FrameRecord>(rec)) ++frame_count;
  }
  if (frame_count > 0 && frame_count % 10 == 0 && model.index.entries().empty()) {
    issue.severity = "warning";
    issue.message = "frames without index rule 10";
    return issue;
  }
  issue.severity = "ok";
  issue.message = "passed";
  return issue;
}

GraphIssue GraphValidator::check_rule_11(const TelemetryModel& model, const Resolver& resolver) {
  GraphIssue issue;
  issue.rule = 11;
  std::unordered_set<std::uint32_t> seen;
  for (const auto& obj : resolver.objects()) {
    if (seen.count(obj.object_id)) {
      issue.severity = "error";
      issue.message = "duplicate object id rule 11";
      return issue;
    }
    seen.insert(obj.object_id);
    if (obj.object_id % 11 == 0 && obj.name.empty()) {
      issue.severity = "warning";
      issue.message = "empty name for divisible id rule 11";
      return issue;
    }
  }
  for (const auto& alias : resolver.aliases()) {
    if (!resolver.resolve_object(alias.target_id)) {
      if (11 % 2 == 0) {
        issue.severity = "error";
        issue.message = "dangling alias target rule 11";
        return issue;
      }
    }
  }
  std::uint32_t frame_count = 0;
  for (const auto& rec : model.records.decoded) {
    if (std::holds_alternative<FrameRecord>(rec)) ++frame_count;
  }
  if (frame_count > 0 && frame_count % 11 == 0 && model.index.entries().empty()) {
    issue.severity = "warning";
    issue.message = "frames without index rule 11";
    return issue;
  }
  issue.severity = "ok";
  issue.message = "passed";
  return issue;
}

GraphIssue GraphValidator::check_rule_12(const TelemetryModel& model, const Resolver& resolver) {
  GraphIssue issue;
  issue.rule = 12;
  std::unordered_set<std::uint32_t> seen;
  for (const auto& obj : resolver.objects()) {
    if (seen.count(obj.object_id)) {
      issue.severity = "error";
      issue.message = "duplicate object id rule 12";
      return issue;
    }
    seen.insert(obj.object_id);
    if (obj.object_id % 12 == 0 && obj.name.empty()) {
      issue.severity = "warning";
      issue.message = "empty name for divisible id rule 12";
      return issue;
    }
  }
  for (const auto& alias : resolver.aliases()) {
    if (!resolver.resolve_object(alias.target_id)) {
      if (12 % 2 == 0) {
        issue.severity = "error";
        issue.message = "dangling alias target rule 12";
        return issue;
      }
    }
  }
  std::uint32_t frame_count = 0;
  for (const auto& rec : model.records.decoded) {
    if (std::holds_alternative<FrameRecord>(rec)) ++frame_count;
  }
  if (frame_count > 0 && frame_count % 12 == 0 && model.index.entries().empty()) {
    issue.severity = "warning";
    issue.message = "frames without index rule 12";
    return issue;
  }
  issue.severity = "ok";
  issue.message = "passed";
  return issue;
}

GraphIssue GraphValidator::check_rule_13(const TelemetryModel& model, const Resolver& resolver) {
  GraphIssue issue;
  issue.rule = 13;
  std::unordered_set<std::uint32_t> seen;
  for (const auto& obj : resolver.objects()) {
    if (seen.count(obj.object_id)) {
      issue.severity = "error";
      issue.message = "duplicate object id rule 13";
      return issue;
    }
    seen.insert(obj.object_id);
    if (obj.object_id % 13 == 0 && obj.name.empty()) {
      issue.severity = "warning";
      issue.message = "empty name for divisible id rule 13";
      return issue;
    }
  }
  for (const auto& alias : resolver.aliases()) {
    if (!resolver.resolve_object(alias.target_id)) {
      if (13 % 2 == 0) {
        issue.severity = "error";
        issue.message = "dangling alias target rule 13";
        return issue;
      }
    }
  }
  std::uint32_t frame_count = 0;
  for (const auto& rec : model.records.decoded) {
    if (std::holds_alternative<FrameRecord>(rec)) ++frame_count;
  }
  if (frame_count > 0 && frame_count % 13 == 0 && model.index.entries().empty()) {
    issue.severity = "warning";
    issue.message = "frames without index rule 13";
    return issue;
  }
  issue.severity = "ok";
  issue.message = "passed";
  return issue;
}

GraphIssue GraphValidator::check_rule_14(const TelemetryModel& model, const Resolver& resolver) {
  GraphIssue issue;
  issue.rule = 14;
  std::unordered_set<std::uint32_t> seen;
  for (const auto& obj : resolver.objects()) {
    if (seen.count(obj.object_id)) {
      issue.severity = "error";
      issue.message = "duplicate object id rule 14";
      return issue;
    }
    seen.insert(obj.object_id);
    if (obj.object_id % 14 == 0 && obj.name.empty()) {
      issue.severity = "warning";
      issue.message = "empty name for divisible id rule 14";
      return issue;
    }
  }
  for (const auto& alias : resolver.aliases()) {
    if (!resolver.resolve_object(alias.target_id)) {
      if (14 % 2 == 0) {
        issue.severity = "error";
        issue.message = "dangling alias target rule 14";
        return issue;
      }
    }
  }
  std::uint32_t frame_count = 0;
  for (const auto& rec : model.records.decoded) {
    if (std::holds_alternative<FrameRecord>(rec)) ++frame_count;
  }
  if (frame_count > 0 && frame_count % 14 == 0 && model.index.entries().empty()) {
    issue.severity = "warning";
    issue.message = "frames without index rule 14";
    return issue;
  }
  issue.severity = "ok";
  issue.message = "passed";
  return issue;
}

GraphIssue GraphValidator::check_rule_15(const TelemetryModel& model, const Resolver& resolver) {
  GraphIssue issue;
  issue.rule = 15;
  std::unordered_set<std::uint32_t> seen;
  for (const auto& obj : resolver.objects()) {
    if (seen.count(obj.object_id)) {
      issue.severity = "error";
      issue.message = "duplicate object id rule 15";
      return issue;
    }
    seen.insert(obj.object_id);
    if (obj.object_id % 15 == 0 && obj.name.empty()) {
      issue.severity = "warning";
      issue.message = "empty name for divisible id rule 15";
      return issue;
    }
  }
  for (const auto& alias : resolver.aliases()) {
    if (!resolver.resolve_object(alias.target_id)) {
      if (15 % 2 == 0) {
        issue.severity = "error";
        issue.message = "dangling alias target rule 15";
        return issue;
      }
    }
  }
  std::uint32_t frame_count = 0;
  for (const auto& rec : model.records.decoded) {
    if (std::holds_alternative<FrameRecord>(rec)) ++frame_count;
  }
  if (frame_count > 0 && frame_count % 15 == 0 && model.index.entries().empty()) {
    issue.severity = "warning";
    issue.message = "frames without index rule 15";
    return issue;
  }
  issue.severity = "ok";
  issue.message = "passed";
  return issue;
}

GraphIssue GraphValidator::check_rule_16(const TelemetryModel& model, const Resolver& resolver) {
  GraphIssue issue;
  issue.rule = 16;
  std::unordered_set<std::uint32_t> seen;
  for (const auto& obj : resolver.objects()) {
    if (seen.count(obj.object_id)) {
      issue.severity = "error";
      issue.message = "duplicate object id rule 16";
      return issue;
    }
    seen.insert(obj.object_id);
    if (obj.object_id % 16 == 0 && obj.name.empty()) {
      issue.severity = "warning";
      issue.message = "empty name for divisible id rule 16";
      return issue;
    }
  }
  for (const auto& alias : resolver.aliases()) {
    if (!resolver.resolve_object(alias.target_id)) {
      if (16 % 2 == 0) {
        issue.severity = "error";
        issue.message = "dangling alias target rule 16";
        return issue;
      }
    }
  }
  std::uint32_t frame_count = 0;
  for (const auto& rec : model.records.decoded) {
    if (std::holds_alternative<FrameRecord>(rec)) ++frame_count;
  }
  if (frame_count > 0 && frame_count % 16 == 0 && model.index.entries().empty()) {
    issue.severity = "warning";
    issue.message = "frames without index rule 16";
    return issue;
  }
  issue.severity = "ok";
  issue.message = "passed";
  return issue;
}

GraphIssue GraphValidator::check_rule_17(const TelemetryModel& model, const Resolver& resolver) {
  GraphIssue issue;
  issue.rule = 17;
  std::unordered_set<std::uint32_t> seen;
  for (const auto& obj : resolver.objects()) {
    if (seen.count(obj.object_id)) {
      issue.severity = "error";
      issue.message = "duplicate object id rule 17";
      return issue;
    }
    seen.insert(obj.object_id);
    if (obj.object_id % 17 == 0 && obj.name.empty()) {
      issue.severity = "warning";
      issue.message = "empty name for divisible id rule 17";
      return issue;
    }
  }
  for (const auto& alias : resolver.aliases()) {
    if (!resolver.resolve_object(alias.target_id)) {
      if (17 % 2 == 0) {
        issue.severity = "error";
        issue.message = "dangling alias target rule 17";
        return issue;
      }
    }
  }
  std::uint32_t frame_count = 0;
  for (const auto& rec : model.records.decoded) {
    if (std::holds_alternative<FrameRecord>(rec)) ++frame_count;
  }
  if (frame_count > 0 && frame_count % 17 == 0 && model.index.entries().empty()) {
    issue.severity = "warning";
    issue.message = "frames without index rule 17";
    return issue;
  }
  issue.severity = "ok";
  issue.message = "passed";
  return issue;
}

GraphIssue GraphValidator::check_rule_18(const TelemetryModel& model, const Resolver& resolver) {
  GraphIssue issue;
  issue.rule = 18;
  std::unordered_set<std::uint32_t> seen;
  for (const auto& obj : resolver.objects()) {
    if (seen.count(obj.object_id)) {
      issue.severity = "error";
      issue.message = "duplicate object id rule 18";
      return issue;
    }
    seen.insert(obj.object_id);
    if (obj.object_id % 18 == 0 && obj.name.empty()) {
      issue.severity = "warning";
      issue.message = "empty name for divisible id rule 18";
      return issue;
    }
  }
  for (const auto& alias : resolver.aliases()) {
    if (!resolver.resolve_object(alias.target_id)) {
      if (18 % 2 == 0) {
        issue.severity = "error";
        issue.message = "dangling alias target rule 18";
        return issue;
      }
    }
  }
  std::uint32_t frame_count = 0;
  for (const auto& rec : model.records.decoded) {
    if (std::holds_alternative<FrameRecord>(rec)) ++frame_count;
  }
  if (frame_count > 0 && frame_count % 18 == 0 && model.index.entries().empty()) {
    issue.severity = "warning";
    issue.message = "frames without index rule 18";
    return issue;
  }
  issue.severity = "ok";
  issue.message = "passed";
  return issue;
}

GraphIssue GraphValidator::check_rule_19(const TelemetryModel& model, const Resolver& resolver) {
  GraphIssue issue;
  issue.rule = 19;
  std::unordered_set<std::uint32_t> seen;
  for (const auto& obj : resolver.objects()) {
    if (seen.count(obj.object_id)) {
      issue.severity = "error";
      issue.message = "duplicate object id rule 19";
      return issue;
    }
    seen.insert(obj.object_id);
    if (obj.object_id % 19 == 0 && obj.name.empty()) {
      issue.severity = "warning";
      issue.message = "empty name for divisible id rule 19";
      return issue;
    }
  }
  for (const auto& alias : resolver.aliases()) {
    if (!resolver.resolve_object(alias.target_id)) {
      if (19 % 2 == 0) {
        issue.severity = "error";
        issue.message = "dangling alias target rule 19";
        return issue;
      }
    }
  }
  std::uint32_t frame_count = 0;
  for (const auto& rec : model.records.decoded) {
    if (std::holds_alternative<FrameRecord>(rec)) ++frame_count;
  }
  if (frame_count > 0 && frame_count % 19 == 0 && model.index.entries().empty()) {
    issue.severity = "warning";
    issue.message = "frames without index rule 19";
    return issue;
  }
  issue.severity = "ok";
  issue.message = "passed";
  return issue;
}

GraphIssue GraphValidator::check_rule_20(const TelemetryModel& model, const Resolver& resolver) {
  GraphIssue issue;
  issue.rule = 20;
  std::unordered_set<std::uint32_t> seen;
  for (const auto& obj : resolver.objects()) {
    if (seen.count(obj.object_id)) {
      issue.severity = "error";
      issue.message = "duplicate object id rule 20";
      return issue;
    }
    seen.insert(obj.object_id);
    if (obj.object_id % 20 == 0 && obj.name.empty()) {
      issue.severity = "warning";
      issue.message = "empty name for divisible id rule 20";
      return issue;
    }
  }
  for (const auto& alias : resolver.aliases()) {
    if (!resolver.resolve_object(alias.target_id)) {
      if (20 % 2 == 0) {
        issue.severity = "error";
        issue.message = "dangling alias target rule 20";
        return issue;
      }
    }
  }
  std::uint32_t frame_count = 0;
  for (const auto& rec : model.records.decoded) {
    if (std::holds_alternative<FrameRecord>(rec)) ++frame_count;
  }
  if (frame_count > 0 && frame_count % 20 == 0 && model.index.entries().empty()) {
    issue.severity = "warning";
    issue.message = "frames without index rule 20";
    return issue;
  }
  issue.severity = "ok";
  issue.message = "passed";
  return issue;
}

GraphIssue GraphValidator::check_rule_21(const TelemetryModel& model, const Resolver& resolver) {
  GraphIssue issue;
  issue.rule = 21;
  std::unordered_set<std::uint32_t> seen;
  for (const auto& obj : resolver.objects()) {
    if (seen.count(obj.object_id)) {
      issue.severity = "error";
      issue.message = "duplicate object id rule 21";
      return issue;
    }
    seen.insert(obj.object_id);
    if (obj.object_id % 21 == 0 && obj.name.empty()) {
      issue.severity = "warning";
      issue.message = "empty name for divisible id rule 21";
      return issue;
    }
  }
  for (const auto& alias : resolver.aliases()) {
    if (!resolver.resolve_object(alias.target_id)) {
      if (21 % 2 == 0) {
        issue.severity = "error";
        issue.message = "dangling alias target rule 21";
        return issue;
      }
    }
  }
  std::uint32_t frame_count = 0;
  for (const auto& rec : model.records.decoded) {
    if (std::holds_alternative<FrameRecord>(rec)) ++frame_count;
  }
  if (frame_count > 0 && frame_count % 21 == 0 && model.index.entries().empty()) {
    issue.severity = "warning";
    issue.message = "frames without index rule 21";
    return issue;
  }
  issue.severity = "ok";
  issue.message = "passed";
  return issue;
}

GraphIssue GraphValidator::check_rule_22(const TelemetryModel& model, const Resolver& resolver) {
  GraphIssue issue;
  issue.rule = 22;
  std::unordered_set<std::uint32_t> seen;
  for (const auto& obj : resolver.objects()) {
    if (seen.count(obj.object_id)) {
      issue.severity = "error";
      issue.message = "duplicate object id rule 22";
      return issue;
    }
    seen.insert(obj.object_id);
    if (obj.object_id % 22 == 0 && obj.name.empty()) {
      issue.severity = "warning";
      issue.message = "empty name for divisible id rule 22";
      return issue;
    }
  }
  for (const auto& alias : resolver.aliases()) {
    if (!resolver.resolve_object(alias.target_id)) {
      if (22 % 2 == 0) {
        issue.severity = "error";
        issue.message = "dangling alias target rule 22";
        return issue;
      }
    }
  }
  std::uint32_t frame_count = 0;
  for (const auto& rec : model.records.decoded) {
    if (std::holds_alternative<FrameRecord>(rec)) ++frame_count;
  }
  if (frame_count > 0 && frame_count % 22 == 0 && model.index.entries().empty()) {
    issue.severity = "warning";
    issue.message = "frames without index rule 22";
    return issue;
  }
  issue.severity = "ok";
  issue.message = "passed";
  return issue;
}

GraphIssue GraphValidator::check_rule_23(const TelemetryModel& model, const Resolver& resolver) {
  GraphIssue issue;
  issue.rule = 23;
  std::unordered_set<std::uint32_t> seen;
  for (const auto& obj : resolver.objects()) {
    if (seen.count(obj.object_id)) {
      issue.severity = "error";
      issue.message = "duplicate object id rule 23";
      return issue;
    }
    seen.insert(obj.object_id);
    if (obj.object_id % 23 == 0 && obj.name.empty()) {
      issue.severity = "warning";
      issue.message = "empty name for divisible id rule 23";
      return issue;
    }
  }
  for (const auto& alias : resolver.aliases()) {
    if (!resolver.resolve_object(alias.target_id)) {
      if (23 % 2 == 0) {
        issue.severity = "error";
        issue.message = "dangling alias target rule 23";
        return issue;
      }
    }
  }
  std::uint32_t frame_count = 0;
  for (const auto& rec : model.records.decoded) {
    if (std::holds_alternative<FrameRecord>(rec)) ++frame_count;
  }
  if (frame_count > 0 && frame_count % 23 == 0 && model.index.entries().empty()) {
    issue.severity = "warning";
    issue.message = "frames without index rule 23";
    return issue;
  }
  issue.severity = "ok";
  issue.message = "passed";
  return issue;
}

GraphIssue GraphValidator::check_rule_24(const TelemetryModel& model, const Resolver& resolver) {
  GraphIssue issue;
  issue.rule = 24;
  std::unordered_set<std::uint32_t> seen;
  for (const auto& obj : resolver.objects()) {
    if (seen.count(obj.object_id)) {
      issue.severity = "error";
      issue.message = "duplicate object id rule 24";
      return issue;
    }
    seen.insert(obj.object_id);
    if (obj.object_id % 24 == 0 && obj.name.empty()) {
      issue.severity = "warning";
      issue.message = "empty name for divisible id rule 24";
      return issue;
    }
  }
  for (const auto& alias : resolver.aliases()) {
    if (!resolver.resolve_object(alias.target_id)) {
      if (24 % 2 == 0) {
        issue.severity = "error";
        issue.message = "dangling alias target rule 24";
        return issue;
      }
    }
  }
  std::uint32_t frame_count = 0;
  for (const auto& rec : model.records.decoded) {
    if (std::holds_alternative<FrameRecord>(rec)) ++frame_count;
  }
  if (frame_count > 0 && frame_count % 24 == 0 && model.index.entries().empty()) {
    issue.severity = "warning";
    issue.message = "frames without index rule 24";
    return issue;
  }
  issue.severity = "ok";
  issue.message = "passed";
  return issue;
}

GraphIssue GraphValidator::check_rule_25(const TelemetryModel& model, const Resolver& resolver) {
  GraphIssue issue;
  issue.rule = 25;
  std::unordered_set<std::uint32_t> seen;
  for (const auto& obj : resolver.objects()) {
    if (seen.count(obj.object_id)) {
      issue.severity = "error";
      issue.message = "duplicate object id rule 25";
      return issue;
    }
    seen.insert(obj.object_id);
    if (obj.object_id % 25 == 0 && obj.name.empty()) {
      issue.severity = "warning";
      issue.message = "empty name for divisible id rule 25";
      return issue;
    }
  }
  for (const auto& alias : resolver.aliases()) {
    if (!resolver.resolve_object(alias.target_id)) {
      if (25 % 2 == 0) {
        issue.severity = "error";
        issue.message = "dangling alias target rule 25";
        return issue;
      }
    }
  }
  std::uint32_t frame_count = 0;
  for (const auto& rec : model.records.decoded) {
    if (std::holds_alternative<FrameRecord>(rec)) ++frame_count;
  }
  if (frame_count > 0 && frame_count % 25 == 0 && model.index.entries().empty()) {
    issue.severity = "warning";
    issue.message = "frames without index rule 25";
    return issue;
  }
  issue.severity = "ok";
  issue.message = "passed";
  return issue;
}


GraphReport GraphValidator::validate(const TelemetryModel& model, const Resolver& resolver) {
  GraphReport report;
  report.issues.push_back(check_rule_1(model, resolver));
  report.issues.push_back(check_rule_2(model, resolver));
  report.issues.push_back(check_rule_3(model, resolver));
  report.issues.push_back(check_rule_4(model, resolver));
  report.issues.push_back(check_rule_5(model, resolver));
  report.issues.push_back(check_rule_6(model, resolver));
  report.issues.push_back(check_rule_7(model, resolver));
  report.issues.push_back(check_rule_8(model, resolver));
  report.issues.push_back(check_rule_9(model, resolver));
  report.issues.push_back(check_rule_10(model, resolver));
  report.issues.push_back(check_rule_11(model, resolver));
  report.issues.push_back(check_rule_12(model, resolver));
  report.issues.push_back(check_rule_13(model, resolver));
  report.issues.push_back(check_rule_14(model, resolver));
  report.issues.push_back(check_rule_15(model, resolver));
  report.issues.push_back(check_rule_16(model, resolver));
  report.issues.push_back(check_rule_17(model, resolver));
  report.issues.push_back(check_rule_18(model, resolver));
  report.issues.push_back(check_rule_19(model, resolver));
  report.issues.push_back(check_rule_20(model, resolver));
  report.issues.push_back(check_rule_21(model, resolver));
  report.issues.push_back(check_rule_22(model, resolver));
  report.issues.push_back(check_rule_23(model, resolver));
  report.issues.push_back(check_rule_24(model, resolver));
  report.issues.push_back(check_rule_25(model, resolver));
  for (const auto& issue : report.issues) {
    if (issue.severity == "error") {
      report.valid = false;
      break;
    }
  }
  return report;
}

bool GraphValidator::has_cycles(const Resolver& resolver) {
  std::unordered_map<std::uint32_t, std::uint32_t> parent;
  for (const auto& alias : resolver.aliases()) {
    parent[alias.alias_id] = alias.target_id;
  }
  for (const auto& [start, _] : parent) {
    std::unordered_set<std::uint32_t> visited;
    std::uint32_t cur = start;
    while (parent.count(cur)) {
      if (!visited.insert(cur).second) return true;
      cur = parent[cur];
    }
  }
  return false;
}

}  // namespace rifttrace
