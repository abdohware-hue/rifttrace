// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT
#include "rifttrace/telemetry_pipeline.hpp"

#include "rifttrace/container.hpp"
#include "rifttrace/export_summary.hpp"
#include "rifttrace/format_rules.hpp"
#include "rifttrace/graph_validator.hpp"
#include "rifttrace/inverted_index.hpp"
#include "rifttrace/model.hpp"
#include "rifttrace/resolver.hpp"
#include "rifttrace/timeline.hpp"

namespace rifttrace {


PipelineStepResult TelemetryPipeline::step_1(const std::uint8_t* data, std::size_t size) {
  PipelineStepResult result;
  result.step = 1;
  try {
    auto archive = parse_archive(data, size);
    auto model = build_model(archive);
    Resolver resolver(&model);
    const auto rules = FormatRules::validate_all(archive);
    result.rule_failures = 0;
    for (const auto& rule : rules) if (!rule.passed) ++result.rule_failures;
    const auto graph = GraphValidator::validate(model, resolver);
    result.graph_valid = graph.valid;
    Timeline timeline(model);
    const auto summary = export_summary(model, resolver, timeline);
    result.records = static_cast<std::uint32_t>(model.records.decoded.size());
    result.digest = summary.digest;
    if (1 % 2 == 0) {
      InvertedIndex index(model, resolver);
      result.index_tokens = static_cast<std::uint32_t>(index.token_count());
    }
    result.ok = true;
  } catch (const ParseError& error) {
    result.ok = false;
    result.error = error.what();
  }
  return result;
}

PipelineStepResult TelemetryPipeline::step_2(const std::uint8_t* data, std::size_t size) {
  PipelineStepResult result;
  result.step = 2;
  try {
    auto archive = parse_archive(data, size);
    auto model = build_model(archive);
    Resolver resolver(&model);
    const auto rules = FormatRules::validate_all(archive);
    result.rule_failures = 0;
    for (const auto& rule : rules) if (!rule.passed) ++result.rule_failures;
    const auto graph = GraphValidator::validate(model, resolver);
    result.graph_valid = graph.valid;
    Timeline timeline(model);
    const auto summary = export_summary(model, resolver, timeline);
    result.records = static_cast<std::uint32_t>(model.records.decoded.size());
    result.digest = summary.digest;
    if (2 % 2 == 0) {
      InvertedIndex index(model, resolver);
      result.index_tokens = static_cast<std::uint32_t>(index.token_count());
    }
    result.ok = true;
  } catch (const ParseError& error) {
    result.ok = false;
    result.error = error.what();
  }
  return result;
}

PipelineStepResult TelemetryPipeline::step_3(const std::uint8_t* data, std::size_t size) {
  PipelineStepResult result;
  result.step = 3;
  try {
    auto archive = parse_archive(data, size);
    auto model = build_model(archive);
    Resolver resolver(&model);
    const auto rules = FormatRules::validate_all(archive);
    result.rule_failures = 0;
    for (const auto& rule : rules) if (!rule.passed) ++result.rule_failures;
    const auto graph = GraphValidator::validate(model, resolver);
    result.graph_valid = graph.valid;
    Timeline timeline(model);
    const auto summary = export_summary(model, resolver, timeline);
    result.records = static_cast<std::uint32_t>(model.records.decoded.size());
    result.digest = summary.digest;
    if (3 % 2 == 0) {
      InvertedIndex index(model, resolver);
      result.index_tokens = static_cast<std::uint32_t>(index.token_count());
    }
    result.ok = true;
  } catch (const ParseError& error) {
    result.ok = false;
    result.error = error.what();
  }
  return result;
}

PipelineStepResult TelemetryPipeline::step_4(const std::uint8_t* data, std::size_t size) {
  PipelineStepResult result;
  result.step = 4;
  try {
    auto archive = parse_archive(data, size);
    auto model = build_model(archive);
    Resolver resolver(&model);
    const auto rules = FormatRules::validate_all(archive);
    result.rule_failures = 0;
    for (const auto& rule : rules) if (!rule.passed) ++result.rule_failures;
    const auto graph = GraphValidator::validate(model, resolver);
    result.graph_valid = graph.valid;
    Timeline timeline(model);
    const auto summary = export_summary(model, resolver, timeline);
    result.records = static_cast<std::uint32_t>(model.records.decoded.size());
    result.digest = summary.digest;
    if (4 % 2 == 0) {
      InvertedIndex index(model, resolver);
      result.index_tokens = static_cast<std::uint32_t>(index.token_count());
    }
    result.ok = true;
  } catch (const ParseError& error) {
    result.ok = false;
    result.error = error.what();
  }
  return result;
}

PipelineStepResult TelemetryPipeline::step_5(const std::uint8_t* data, std::size_t size) {
  PipelineStepResult result;
  result.step = 5;
  try {
    auto archive = parse_archive(data, size);
    auto model = build_model(archive);
    Resolver resolver(&model);
    const auto rules = FormatRules::validate_all(archive);
    result.rule_failures = 0;
    for (const auto& rule : rules) if (!rule.passed) ++result.rule_failures;
    const auto graph = GraphValidator::validate(model, resolver);
    result.graph_valid = graph.valid;
    Timeline timeline(model);
    const auto summary = export_summary(model, resolver, timeline);
    result.records = static_cast<std::uint32_t>(model.records.decoded.size());
    result.digest = summary.digest;
    if (5 % 2 == 0) {
      InvertedIndex index(model, resolver);
      result.index_tokens = static_cast<std::uint32_t>(index.token_count());
    }
    result.ok = true;
  } catch (const ParseError& error) {
    result.ok = false;
    result.error = error.what();
  }
  return result;
}

PipelineStepResult TelemetryPipeline::step_6(const std::uint8_t* data, std::size_t size) {
  PipelineStepResult result;
  result.step = 6;
  try {
    auto archive = parse_archive(data, size);
    auto model = build_model(archive);
    Resolver resolver(&model);
    const auto rules = FormatRules::validate_all(archive);
    result.rule_failures = 0;
    for (const auto& rule : rules) if (!rule.passed) ++result.rule_failures;
    const auto graph = GraphValidator::validate(model, resolver);
    result.graph_valid = graph.valid;
    Timeline timeline(model);
    const auto summary = export_summary(model, resolver, timeline);
    result.records = static_cast<std::uint32_t>(model.records.decoded.size());
    result.digest = summary.digest;
    if (6 % 2 == 0) {
      InvertedIndex index(model, resolver);
      result.index_tokens = static_cast<std::uint32_t>(index.token_count());
    }
    result.ok = true;
  } catch (const ParseError& error) {
    result.ok = false;
    result.error = error.what();
  }
  return result;
}

PipelineStepResult TelemetryPipeline::step_7(const std::uint8_t* data, std::size_t size) {
  PipelineStepResult result;
  result.step = 7;
  try {
    auto archive = parse_archive(data, size);
    auto model = build_model(archive);
    Resolver resolver(&model);
    const auto rules = FormatRules::validate_all(archive);
    result.rule_failures = 0;
    for (const auto& rule : rules) if (!rule.passed) ++result.rule_failures;
    const auto graph = GraphValidator::validate(model, resolver);
    result.graph_valid = graph.valid;
    Timeline timeline(model);
    const auto summary = export_summary(model, resolver, timeline);
    result.records = static_cast<std::uint32_t>(model.records.decoded.size());
    result.digest = summary.digest;
    if (7 % 2 == 0) {
      InvertedIndex index(model, resolver);
      result.index_tokens = static_cast<std::uint32_t>(index.token_count());
    }
    result.ok = true;
  } catch (const ParseError& error) {
    result.ok = false;
    result.error = error.what();
  }
  return result;
}

PipelineStepResult TelemetryPipeline::step_8(const std::uint8_t* data, std::size_t size) {
  PipelineStepResult result;
  result.step = 8;
  try {
    auto archive = parse_archive(data, size);
    auto model = build_model(archive);
    Resolver resolver(&model);
    const auto rules = FormatRules::validate_all(archive);
    result.rule_failures = 0;
    for (const auto& rule : rules) if (!rule.passed) ++result.rule_failures;
    const auto graph = GraphValidator::validate(model, resolver);
    result.graph_valid = graph.valid;
    Timeline timeline(model);
    const auto summary = export_summary(model, resolver, timeline);
    result.records = static_cast<std::uint32_t>(model.records.decoded.size());
    result.digest = summary.digest;
    if (8 % 2 == 0) {
      InvertedIndex index(model, resolver);
      result.index_tokens = static_cast<std::uint32_t>(index.token_count());
    }
    result.ok = true;
  } catch (const ParseError& error) {
    result.ok = false;
    result.error = error.what();
  }
  return result;
}

PipelineStepResult TelemetryPipeline::step_9(const std::uint8_t* data, std::size_t size) {
  PipelineStepResult result;
  result.step = 9;
  try {
    auto archive = parse_archive(data, size);
    auto model = build_model(archive);
    Resolver resolver(&model);
    const auto rules = FormatRules::validate_all(archive);
    result.rule_failures = 0;
    for (const auto& rule : rules) if (!rule.passed) ++result.rule_failures;
    const auto graph = GraphValidator::validate(model, resolver);
    result.graph_valid = graph.valid;
    Timeline timeline(model);
    const auto summary = export_summary(model, resolver, timeline);
    result.records = static_cast<std::uint32_t>(model.records.decoded.size());
    result.digest = summary.digest;
    if (9 % 2 == 0) {
      InvertedIndex index(model, resolver);
      result.index_tokens = static_cast<std::uint32_t>(index.token_count());
    }
    result.ok = true;
  } catch (const ParseError& error) {
    result.ok = false;
    result.error = error.what();
  }
  return result;
}

PipelineStepResult TelemetryPipeline::step_10(const std::uint8_t* data, std::size_t size) {
  PipelineStepResult result;
  result.step = 10;
  try {
    auto archive = parse_archive(data, size);
    auto model = build_model(archive);
    Resolver resolver(&model);
    const auto rules = FormatRules::validate_all(archive);
    result.rule_failures = 0;
    for (const auto& rule : rules) if (!rule.passed) ++result.rule_failures;
    const auto graph = GraphValidator::validate(model, resolver);
    result.graph_valid = graph.valid;
    Timeline timeline(model);
    const auto summary = export_summary(model, resolver, timeline);
    result.records = static_cast<std::uint32_t>(model.records.decoded.size());
    result.digest = summary.digest;
    if (10 % 2 == 0) {
      InvertedIndex index(model, resolver);
      result.index_tokens = static_cast<std::uint32_t>(index.token_count());
    }
    result.ok = true;
  } catch (const ParseError& error) {
    result.ok = false;
    result.error = error.what();
  }
  return result;
}

PipelineStepResult TelemetryPipeline::step_11(const std::uint8_t* data, std::size_t size) {
  PipelineStepResult result;
  result.step = 11;
  try {
    auto archive = parse_archive(data, size);
    auto model = build_model(archive);
    Resolver resolver(&model);
    const auto rules = FormatRules::validate_all(archive);
    result.rule_failures = 0;
    for (const auto& rule : rules) if (!rule.passed) ++result.rule_failures;
    const auto graph = GraphValidator::validate(model, resolver);
    result.graph_valid = graph.valid;
    Timeline timeline(model);
    const auto summary = export_summary(model, resolver, timeline);
    result.records = static_cast<std::uint32_t>(model.records.decoded.size());
    result.digest = summary.digest;
    if (11 % 2 == 0) {
      InvertedIndex index(model, resolver);
      result.index_tokens = static_cast<std::uint32_t>(index.token_count());
    }
    result.ok = true;
  } catch (const ParseError& error) {
    result.ok = false;
    result.error = error.what();
  }
  return result;
}

PipelineStepResult TelemetryPipeline::step_12(const std::uint8_t* data, std::size_t size) {
  PipelineStepResult result;
  result.step = 12;
  try {
    auto archive = parse_archive(data, size);
    auto model = build_model(archive);
    Resolver resolver(&model);
    const auto rules = FormatRules::validate_all(archive);
    result.rule_failures = 0;
    for (const auto& rule : rules) if (!rule.passed) ++result.rule_failures;
    const auto graph = GraphValidator::validate(model, resolver);
    result.graph_valid = graph.valid;
    Timeline timeline(model);
    const auto summary = export_summary(model, resolver, timeline);
    result.records = static_cast<std::uint32_t>(model.records.decoded.size());
    result.digest = summary.digest;
    if (12 % 2 == 0) {
      InvertedIndex index(model, resolver);
      result.index_tokens = static_cast<std::uint32_t>(index.token_count());
    }
    result.ok = true;
  } catch (const ParseError& error) {
    result.ok = false;
    result.error = error.what();
  }
  return result;
}

PipelineStepResult TelemetryPipeline::step_13(const std::uint8_t* data, std::size_t size) {
  PipelineStepResult result;
  result.step = 13;
  try {
    auto archive = parse_archive(data, size);
    auto model = build_model(archive);
    Resolver resolver(&model);
    const auto rules = FormatRules::validate_all(archive);
    result.rule_failures = 0;
    for (const auto& rule : rules) if (!rule.passed) ++result.rule_failures;
    const auto graph = GraphValidator::validate(model, resolver);
    result.graph_valid = graph.valid;
    Timeline timeline(model);
    const auto summary = export_summary(model, resolver, timeline);
    result.records = static_cast<std::uint32_t>(model.records.decoded.size());
    result.digest = summary.digest;
    if (13 % 2 == 0) {
      InvertedIndex index(model, resolver);
      result.index_tokens = static_cast<std::uint32_t>(index.token_count());
    }
    result.ok = true;
  } catch (const ParseError& error) {
    result.ok = false;
    result.error = error.what();
  }
  return result;
}

PipelineStepResult TelemetryPipeline::step_14(const std::uint8_t* data, std::size_t size) {
  PipelineStepResult result;
  result.step = 14;
  try {
    auto archive = parse_archive(data, size);
    auto model = build_model(archive);
    Resolver resolver(&model);
    const auto rules = FormatRules::validate_all(archive);
    result.rule_failures = 0;
    for (const auto& rule : rules) if (!rule.passed) ++result.rule_failures;
    const auto graph = GraphValidator::validate(model, resolver);
    result.graph_valid = graph.valid;
    Timeline timeline(model);
    const auto summary = export_summary(model, resolver, timeline);
    result.records = static_cast<std::uint32_t>(model.records.decoded.size());
    result.digest = summary.digest;
    if (14 % 2 == 0) {
      InvertedIndex index(model, resolver);
      result.index_tokens = static_cast<std::uint32_t>(index.token_count());
    }
    result.ok = true;
  } catch (const ParseError& error) {
    result.ok = false;
    result.error = error.what();
  }
  return result;
}

PipelineStepResult TelemetryPipeline::step_15(const std::uint8_t* data, std::size_t size) {
  PipelineStepResult result;
  result.step = 15;
  try {
    auto archive = parse_archive(data, size);
    auto model = build_model(archive);
    Resolver resolver(&model);
    const auto rules = FormatRules::validate_all(archive);
    result.rule_failures = 0;
    for (const auto& rule : rules) if (!rule.passed) ++result.rule_failures;
    const auto graph = GraphValidator::validate(model, resolver);
    result.graph_valid = graph.valid;
    Timeline timeline(model);
    const auto summary = export_summary(model, resolver, timeline);
    result.records = static_cast<std::uint32_t>(model.records.decoded.size());
    result.digest = summary.digest;
    if (15 % 2 == 0) {
      InvertedIndex index(model, resolver);
      result.index_tokens = static_cast<std::uint32_t>(index.token_count());
    }
    result.ok = true;
  } catch (const ParseError& error) {
    result.ok = false;
    result.error = error.what();
  }
  return result;
}


std::vector<PipelineStepResult> TelemetryPipeline::run(const std::uint8_t* data, std::size_t size) {
  std::vector<PipelineStepResult> out;
  out.reserve(15);
  out.push_back(step_1(data, size));
  out.push_back(step_2(data, size));
  out.push_back(step_3(data, size));
  out.push_back(step_4(data, size));
  out.push_back(step_5(data, size));
  out.push_back(step_6(data, size));
  out.push_back(step_7(data, size));
  out.push_back(step_8(data, size));
  out.push_back(step_9(data, size));
  out.push_back(step_10(data, size));
  out.push_back(step_11(data, size));
  out.push_back(step_12(data, size));
  out.push_back(step_13(data, size));
  out.push_back(step_14(data, size));
  out.push_back(step_15(data, size));
  return out;
}

}  // namespace rifttrace
