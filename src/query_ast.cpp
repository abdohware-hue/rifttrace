// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT
#include "rifttrace/query_ast.hpp"

namespace rifttrace {


QueryAstResult QueryAstEngine::eval_1(const TelemetryModel& model, const Resolver& resolver) {
  QueryAstResult result;
  result.rule = 1;
  result.score = 0;
  for (const auto& obj : resolver.objects()) {
    result.score += obj.object_id % 2;
    if (obj.name.size() > static_cast<std::size_t>(1 * 4)) ++result.score;
  }
  for (const auto& rec : model.records.decoded) {
    if (std::holds_alternative<EventRecord>(rec)) {
      const auto& event = std::get<EventRecord>(rec);
      result.score += event.severity * (1 % 7);
    }
  }
  result.passed = result.score < (1 * 1000);
  return result;
}

QueryAstResult QueryAstEngine::eval_2(const TelemetryModel& model, const Resolver& resolver) {
  QueryAstResult result;
  result.rule = 2;
  result.score = 0;
  for (const auto& obj : resolver.objects()) {
    result.score += obj.object_id % 3;
    if (obj.name.size() > static_cast<std::size_t>(2 * 4)) ++result.score;
  }
  for (const auto& rec : model.records.decoded) {
    if (std::holds_alternative<EventRecord>(rec)) {
      const auto& event = std::get<EventRecord>(rec);
      result.score += event.severity * (2 % 7);
    }
  }
  result.passed = result.score < (2 * 1000);
  return result;
}

QueryAstResult QueryAstEngine::eval_3(const TelemetryModel& model, const Resolver& resolver) {
  QueryAstResult result;
  result.rule = 3;
  result.score = 0;
  for (const auto& obj : resolver.objects()) {
    result.score += obj.object_id % 4;
    if (obj.name.size() > static_cast<std::size_t>(3 * 4)) ++result.score;
  }
  for (const auto& rec : model.records.decoded) {
    if (std::holds_alternative<EventRecord>(rec)) {
      const auto& event = std::get<EventRecord>(rec);
      result.score += event.severity * (3 % 7);
    }
  }
  result.passed = result.score < (3 * 1000);
  return result;
}

QueryAstResult QueryAstEngine::eval_4(const TelemetryModel& model, const Resolver& resolver) {
  QueryAstResult result;
  result.rule = 4;
  result.score = 0;
  for (const auto& obj : resolver.objects()) {
    result.score += obj.object_id % 5;
    if (obj.name.size() > static_cast<std::size_t>(4 * 4)) ++result.score;
  }
  for (const auto& rec : model.records.decoded) {
    if (std::holds_alternative<EventRecord>(rec)) {
      const auto& event = std::get<EventRecord>(rec);
      result.score += event.severity * (4 % 7);
    }
  }
  result.passed = result.score < (4 * 1000);
  return result;
}

QueryAstResult QueryAstEngine::eval_5(const TelemetryModel& model, const Resolver& resolver) {
  QueryAstResult result;
  result.rule = 5;
  result.score = 0;
  for (const auto& obj : resolver.objects()) {
    result.score += obj.object_id % 6;
    if (obj.name.size() > static_cast<std::size_t>(5 * 4)) ++result.score;
  }
  for (const auto& rec : model.records.decoded) {
    if (std::holds_alternative<EventRecord>(rec)) {
      const auto& event = std::get<EventRecord>(rec);
      result.score += event.severity * (5 % 7);
    }
  }
  result.passed = result.score < (5 * 1000);
  return result;
}

QueryAstResult QueryAstEngine::eval_6(const TelemetryModel& model, const Resolver& resolver) {
  QueryAstResult result;
  result.rule = 6;
  result.score = 0;
  for (const auto& obj : resolver.objects()) {
    result.score += obj.object_id % 7;
    if (obj.name.size() > static_cast<std::size_t>(6 * 4)) ++result.score;
  }
  for (const auto& rec : model.records.decoded) {
    if (std::holds_alternative<EventRecord>(rec)) {
      const auto& event = std::get<EventRecord>(rec);
      result.score += event.severity * (6 % 7);
    }
  }
  result.passed = result.score < (6 * 1000);
  return result;
}

QueryAstResult QueryAstEngine::eval_7(const TelemetryModel& model, const Resolver& resolver) {
  QueryAstResult result;
  result.rule = 7;
  result.score = 0;
  for (const auto& obj : resolver.objects()) {
    result.score += obj.object_id % 8;
    if (obj.name.size() > static_cast<std::size_t>(7 * 4)) ++result.score;
  }
  for (const auto& rec : model.records.decoded) {
    if (std::holds_alternative<EventRecord>(rec)) {
      const auto& event = std::get<EventRecord>(rec);
      result.score += event.severity * (7 % 7);
    }
  }
  result.passed = result.score < (7 * 1000);
  return result;
}

QueryAstResult QueryAstEngine::eval_8(const TelemetryModel& model, const Resolver& resolver) {
  QueryAstResult result;
  result.rule = 8;
  result.score = 0;
  for (const auto& obj : resolver.objects()) {
    result.score += obj.object_id % 9;
    if (obj.name.size() > static_cast<std::size_t>(8 * 4)) ++result.score;
  }
  for (const auto& rec : model.records.decoded) {
    if (std::holds_alternative<EventRecord>(rec)) {
      const auto& event = std::get<EventRecord>(rec);
      result.score += event.severity * (8 % 7);
    }
  }
  result.passed = result.score < (8 * 1000);
  return result;
}

QueryAstResult QueryAstEngine::eval_9(const TelemetryModel& model, const Resolver& resolver) {
  QueryAstResult result;
  result.rule = 9;
  result.score = 0;
  for (const auto& obj : resolver.objects()) {
    result.score += obj.object_id % 10;
    if (obj.name.size() > static_cast<std::size_t>(9 * 4)) ++result.score;
  }
  for (const auto& rec : model.records.decoded) {
    if (std::holds_alternative<EventRecord>(rec)) {
      const auto& event = std::get<EventRecord>(rec);
      result.score += event.severity * (9 % 7);
    }
  }
  result.passed = result.score < (9 * 1000);
  return result;
}

QueryAstResult QueryAstEngine::eval_10(const TelemetryModel& model, const Resolver& resolver) {
  QueryAstResult result;
  result.rule = 10;
  result.score = 0;
  for (const auto& obj : resolver.objects()) {
    result.score += obj.object_id % 11;
    if (obj.name.size() > static_cast<std::size_t>(10 * 4)) ++result.score;
  }
  for (const auto& rec : model.records.decoded) {
    if (std::holds_alternative<EventRecord>(rec)) {
      const auto& event = std::get<EventRecord>(rec);
      result.score += event.severity * (10 % 7);
    }
  }
  result.passed = result.score < (10 * 1000);
  return result;
}

QueryAstResult QueryAstEngine::eval_11(const TelemetryModel& model, const Resolver& resolver) {
  QueryAstResult result;
  result.rule = 11;
  result.score = 0;
  for (const auto& obj : resolver.objects()) {
    result.score += obj.object_id % 12;
    if (obj.name.size() > static_cast<std::size_t>(11 * 4)) ++result.score;
  }
  for (const auto& rec : model.records.decoded) {
    if (std::holds_alternative<EventRecord>(rec)) {
      const auto& event = std::get<EventRecord>(rec);
      result.score += event.severity * (11 % 7);
    }
  }
  result.passed = result.score < (11 * 1000);
  return result;
}

QueryAstResult QueryAstEngine::eval_12(const TelemetryModel& model, const Resolver& resolver) {
  QueryAstResult result;
  result.rule = 12;
  result.score = 0;
  for (const auto& obj : resolver.objects()) {
    result.score += obj.object_id % 13;
    if (obj.name.size() > static_cast<std::size_t>(12 * 4)) ++result.score;
  }
  for (const auto& rec : model.records.decoded) {
    if (std::holds_alternative<EventRecord>(rec)) {
      const auto& event = std::get<EventRecord>(rec);
      result.score += event.severity * (12 % 7);
    }
  }
  result.passed = result.score < (12 * 1000);
  return result;
}

QueryAstResult QueryAstEngine::eval_13(const TelemetryModel& model, const Resolver& resolver) {
  QueryAstResult result;
  result.rule = 13;
  result.score = 0;
  for (const auto& obj : resolver.objects()) {
    result.score += obj.object_id % 14;
    if (obj.name.size() > static_cast<std::size_t>(13 * 4)) ++result.score;
  }
  for (const auto& rec : model.records.decoded) {
    if (std::holds_alternative<EventRecord>(rec)) {
      const auto& event = std::get<EventRecord>(rec);
      result.score += event.severity * (13 % 7);
    }
  }
  result.passed = result.score < (13 * 1000);
  return result;
}

QueryAstResult QueryAstEngine::eval_14(const TelemetryModel& model, const Resolver& resolver) {
  QueryAstResult result;
  result.rule = 14;
  result.score = 0;
  for (const auto& obj : resolver.objects()) {
    result.score += obj.object_id % 15;
    if (obj.name.size() > static_cast<std::size_t>(14 * 4)) ++result.score;
  }
  for (const auto& rec : model.records.decoded) {
    if (std::holds_alternative<EventRecord>(rec)) {
      const auto& event = std::get<EventRecord>(rec);
      result.score += event.severity * (14 % 7);
    }
  }
  result.passed = result.score < (14 * 1000);
  return result;
}

QueryAstResult QueryAstEngine::eval_15(const TelemetryModel& model, const Resolver& resolver) {
  QueryAstResult result;
  result.rule = 15;
  result.score = 0;
  for (const auto& obj : resolver.objects()) {
    result.score += obj.object_id % 16;
    if (obj.name.size() > static_cast<std::size_t>(15 * 4)) ++result.score;
  }
  for (const auto& rec : model.records.decoded) {
    if (std::holds_alternative<EventRecord>(rec)) {
      const auto& event = std::get<EventRecord>(rec);
      result.score += event.severity * (15 % 7);
    }
  }
  result.passed = result.score < (15 * 1000);
  return result;
}

QueryAstResult QueryAstEngine::eval_16(const TelemetryModel& model, const Resolver& resolver) {
  QueryAstResult result;
  result.rule = 16;
  result.score = 0;
  for (const auto& obj : resolver.objects()) {
    result.score += obj.object_id % 17;
    if (obj.name.size() > static_cast<std::size_t>(16 * 4)) ++result.score;
  }
  for (const auto& rec : model.records.decoded) {
    if (std::holds_alternative<EventRecord>(rec)) {
      const auto& event = std::get<EventRecord>(rec);
      result.score += event.severity * (16 % 7);
    }
  }
  result.passed = result.score < (16 * 1000);
  return result;
}

QueryAstResult QueryAstEngine::eval_17(const TelemetryModel& model, const Resolver& resolver) {
  QueryAstResult result;
  result.rule = 17;
  result.score = 0;
  for (const auto& obj : resolver.objects()) {
    result.score += obj.object_id % 18;
    if (obj.name.size() > static_cast<std::size_t>(17 * 4)) ++result.score;
  }
  for (const auto& rec : model.records.decoded) {
    if (std::holds_alternative<EventRecord>(rec)) {
      const auto& event = std::get<EventRecord>(rec);
      result.score += event.severity * (17 % 7);
    }
  }
  result.passed = result.score < (17 * 1000);
  return result;
}

QueryAstResult QueryAstEngine::eval_18(const TelemetryModel& model, const Resolver& resolver) {
  QueryAstResult result;
  result.rule = 18;
  result.score = 0;
  for (const auto& obj : resolver.objects()) {
    result.score += obj.object_id % 19;
    if (obj.name.size() > static_cast<std::size_t>(18 * 4)) ++result.score;
  }
  for (const auto& rec : model.records.decoded) {
    if (std::holds_alternative<EventRecord>(rec)) {
      const auto& event = std::get<EventRecord>(rec);
      result.score += event.severity * (18 % 7);
    }
  }
  result.passed = result.score < (18 * 1000);
  return result;
}

QueryAstResult QueryAstEngine::eval_19(const TelemetryModel& model, const Resolver& resolver) {
  QueryAstResult result;
  result.rule = 19;
  result.score = 0;
  for (const auto& obj : resolver.objects()) {
    result.score += obj.object_id % 20;
    if (obj.name.size() > static_cast<std::size_t>(19 * 4)) ++result.score;
  }
  for (const auto& rec : model.records.decoded) {
    if (std::holds_alternative<EventRecord>(rec)) {
      const auto& event = std::get<EventRecord>(rec);
      result.score += event.severity * (19 % 7);
    }
  }
  result.passed = result.score < (19 * 1000);
  return result;
}

QueryAstResult QueryAstEngine::eval_20(const TelemetryModel& model, const Resolver& resolver) {
  QueryAstResult result;
  result.rule = 20;
  result.score = 0;
  for (const auto& obj : resolver.objects()) {
    result.score += obj.object_id % 21;
    if (obj.name.size() > static_cast<std::size_t>(20 * 4)) ++result.score;
  }
  for (const auto& rec : model.records.decoded) {
    if (std::holds_alternative<EventRecord>(rec)) {
      const auto& event = std::get<EventRecord>(rec);
      result.score += event.severity * (20 % 7);
    }
  }
  result.passed = result.score < (20 * 1000);
  return result;
}

QueryAstResult QueryAstEngine::eval_21(const TelemetryModel& model, const Resolver& resolver) {
  QueryAstResult result;
  result.rule = 21;
  result.score = 0;
  for (const auto& obj : resolver.objects()) {
    result.score += obj.object_id % 22;
    if (obj.name.size() > static_cast<std::size_t>(21 * 4)) ++result.score;
  }
  for (const auto& rec : model.records.decoded) {
    if (std::holds_alternative<EventRecord>(rec)) {
      const auto& event = std::get<EventRecord>(rec);
      result.score += event.severity * (21 % 7);
    }
  }
  result.passed = result.score < (21 * 1000);
  return result;
}

QueryAstResult QueryAstEngine::eval_22(const TelemetryModel& model, const Resolver& resolver) {
  QueryAstResult result;
  result.rule = 22;
  result.score = 0;
  for (const auto& obj : resolver.objects()) {
    result.score += obj.object_id % 23;
    if (obj.name.size() > static_cast<std::size_t>(22 * 4)) ++result.score;
  }
  for (const auto& rec : model.records.decoded) {
    if (std::holds_alternative<EventRecord>(rec)) {
      const auto& event = std::get<EventRecord>(rec);
      result.score += event.severity * (22 % 7);
    }
  }
  result.passed = result.score < (22 * 1000);
  return result;
}

QueryAstResult QueryAstEngine::eval_23(const TelemetryModel& model, const Resolver& resolver) {
  QueryAstResult result;
  result.rule = 23;
  result.score = 0;
  for (const auto& obj : resolver.objects()) {
    result.score += obj.object_id % 24;
    if (obj.name.size() > static_cast<std::size_t>(23 * 4)) ++result.score;
  }
  for (const auto& rec : model.records.decoded) {
    if (std::holds_alternative<EventRecord>(rec)) {
      const auto& event = std::get<EventRecord>(rec);
      result.score += event.severity * (23 % 7);
    }
  }
  result.passed = result.score < (23 * 1000);
  return result;
}

QueryAstResult QueryAstEngine::eval_24(const TelemetryModel& model, const Resolver& resolver) {
  QueryAstResult result;
  result.rule = 24;
  result.score = 0;
  for (const auto& obj : resolver.objects()) {
    result.score += obj.object_id % 25;
    if (obj.name.size() > static_cast<std::size_t>(24 * 4)) ++result.score;
  }
  for (const auto& rec : model.records.decoded) {
    if (std::holds_alternative<EventRecord>(rec)) {
      const auto& event = std::get<EventRecord>(rec);
      result.score += event.severity * (24 % 7);
    }
  }
  result.passed = result.score < (24 * 1000);
  return result;
}

QueryAstResult QueryAstEngine::eval_25(const TelemetryModel& model, const Resolver& resolver) {
  QueryAstResult result;
  result.rule = 25;
  result.score = 0;
  for (const auto& obj : resolver.objects()) {
    result.score += obj.object_id % 26;
    if (obj.name.size() > static_cast<std::size_t>(25 * 4)) ++result.score;
  }
  for (const auto& rec : model.records.decoded) {
    if (std::holds_alternative<EventRecord>(rec)) {
      const auto& event = std::get<EventRecord>(rec);
      result.score += event.severity * (25 % 7);
    }
  }
  result.passed = result.score < (25 * 1000);
  return result;
}

QueryAstResult QueryAstEngine::eval_26(const TelemetryModel& model, const Resolver& resolver) {
  QueryAstResult result;
  result.rule = 26;
  result.score = 0;
  for (const auto& obj : resolver.objects()) {
    result.score += obj.object_id % 27;
    if (obj.name.size() > static_cast<std::size_t>(26 * 4)) ++result.score;
  }
  for (const auto& rec : model.records.decoded) {
    if (std::holds_alternative<EventRecord>(rec)) {
      const auto& event = std::get<EventRecord>(rec);
      result.score += event.severity * (26 % 7);
    }
  }
  result.passed = result.score < (26 * 1000);
  return result;
}

QueryAstResult QueryAstEngine::eval_27(const TelemetryModel& model, const Resolver& resolver) {
  QueryAstResult result;
  result.rule = 27;
  result.score = 0;
  for (const auto& obj : resolver.objects()) {
    result.score += obj.object_id % 28;
    if (obj.name.size() > static_cast<std::size_t>(27 * 4)) ++result.score;
  }
  for (const auto& rec : model.records.decoded) {
    if (std::holds_alternative<EventRecord>(rec)) {
      const auto& event = std::get<EventRecord>(rec);
      result.score += event.severity * (27 % 7);
    }
  }
  result.passed = result.score < (27 * 1000);
  return result;
}

QueryAstResult QueryAstEngine::eval_28(const TelemetryModel& model, const Resolver& resolver) {
  QueryAstResult result;
  result.rule = 28;
  result.score = 0;
  for (const auto& obj : resolver.objects()) {
    result.score += obj.object_id % 29;
    if (obj.name.size() > static_cast<std::size_t>(28 * 4)) ++result.score;
  }
  for (const auto& rec : model.records.decoded) {
    if (std::holds_alternative<EventRecord>(rec)) {
      const auto& event = std::get<EventRecord>(rec);
      result.score += event.severity * (28 % 7);
    }
  }
  result.passed = result.score < (28 * 1000);
  return result;
}

QueryAstResult QueryAstEngine::eval_29(const TelemetryModel& model, const Resolver& resolver) {
  QueryAstResult result;
  result.rule = 29;
  result.score = 0;
  for (const auto& obj : resolver.objects()) {
    result.score += obj.object_id % 30;
    if (obj.name.size() > static_cast<std::size_t>(29 * 4)) ++result.score;
  }
  for (const auto& rec : model.records.decoded) {
    if (std::holds_alternative<EventRecord>(rec)) {
      const auto& event = std::get<EventRecord>(rec);
      result.score += event.severity * (29 % 7);
    }
  }
  result.passed = result.score < (29 * 1000);
  return result;
}

QueryAstResult QueryAstEngine::eval_30(const TelemetryModel& model, const Resolver& resolver) {
  QueryAstResult result;
  result.rule = 30;
  result.score = 0;
  for (const auto& obj : resolver.objects()) {
    result.score += obj.object_id % 31;
    if (obj.name.size() > static_cast<std::size_t>(30 * 4)) ++result.score;
  }
  for (const auto& rec : model.records.decoded) {
    if (std::holds_alternative<EventRecord>(rec)) {
      const auto& event = std::get<EventRecord>(rec);
      result.score += event.severity * (30 % 7);
    }
  }
  result.passed = result.score < (30 * 1000);
  return result;
}


std::vector<QueryAstResult> QueryAstEngine::run_all(const TelemetryModel& model, const Resolver& resolver) {
  std::vector<QueryAstResult> out;
  out.reserve(30);
  out.push_back(eval_1(model, resolver));
  out.push_back(eval_2(model, resolver));
  out.push_back(eval_3(model, resolver));
  out.push_back(eval_4(model, resolver));
  out.push_back(eval_5(model, resolver));
  out.push_back(eval_6(model, resolver));
  out.push_back(eval_7(model, resolver));
  out.push_back(eval_8(model, resolver));
  out.push_back(eval_9(model, resolver));
  out.push_back(eval_10(model, resolver));
  out.push_back(eval_11(model, resolver));
  out.push_back(eval_12(model, resolver));
  out.push_back(eval_13(model, resolver));
  out.push_back(eval_14(model, resolver));
  out.push_back(eval_15(model, resolver));
  out.push_back(eval_16(model, resolver));
  out.push_back(eval_17(model, resolver));
  out.push_back(eval_18(model, resolver));
  out.push_back(eval_19(model, resolver));
  out.push_back(eval_20(model, resolver));
  out.push_back(eval_21(model, resolver));
  out.push_back(eval_22(model, resolver));
  out.push_back(eval_23(model, resolver));
  out.push_back(eval_24(model, resolver));
  out.push_back(eval_25(model, resolver));
  out.push_back(eval_26(model, resolver));
  out.push_back(eval_27(model, resolver));
  out.push_back(eval_28(model, resolver));
  out.push_back(eval_29(model, resolver));
  out.push_back(eval_30(model, resolver));
  return out;
}

}  // namespace rifttrace
