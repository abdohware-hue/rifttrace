// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT
#include "rifttrace/export_pipeline.hpp"

#include "rifttrace/export_summary.hpp"
#include "rifttrace/graph_validator.hpp"
#include "rifttrace/json_report.hpp"
#include "rifttrace/resolver.hpp"
#include "rifttrace/timeline.hpp"

namespace rifttrace {


ExportStageResult ExportPipeline::stage_1(TelemetryModel& model) {
  ExportStageResult result;
  result.stage = 1;
  Resolver resolver(&model);
  Timeline timeline(model);
  const auto summary = export_summary(model, resolver, timeline);
  result.object_count = summary.object_count;
  result.frame_count = summary.frame_count;
  result.event_count = summary.event_count;
  if (1 % 2 == 0) {
    const auto report = GraphValidator::validate(model, resolver);
    result.valid = report.valid;
  } else {
    result.valid = true;
  }
  if (1 % 3 == 0) {
    result.json = JsonReportRenderer::render_compact(summary);
  }
  result.digest = summary.digest;
  return result;
}

ExportStageResult ExportPipeline::stage_2(TelemetryModel& model) {
  ExportStageResult result;
  result.stage = 2;
  Resolver resolver(&model);
  Timeline timeline(model);
  const auto summary = export_summary(model, resolver, timeline);
  result.object_count = summary.object_count;
  result.frame_count = summary.frame_count;
  result.event_count = summary.event_count;
  if (2 % 2 == 0) {
    const auto report = GraphValidator::validate(model, resolver);
    result.valid = report.valid;
  } else {
    result.valid = true;
  }
  if (2 % 3 == 0) {
    result.json = JsonReportRenderer::render_compact(summary);
  }
  result.digest = summary.digest;
  return result;
}

ExportStageResult ExportPipeline::stage_3(TelemetryModel& model) {
  ExportStageResult result;
  result.stage = 3;
  Resolver resolver(&model);
  Timeline timeline(model);
  const auto summary = export_summary(model, resolver, timeline);
  result.object_count = summary.object_count;
  result.frame_count = summary.frame_count;
  result.event_count = summary.event_count;
  if (3 % 2 == 0) {
    const auto report = GraphValidator::validate(model, resolver);
    result.valid = report.valid;
  } else {
    result.valid = true;
  }
  if (3 % 3 == 0) {
    result.json = JsonReportRenderer::render_compact(summary);
  }
  result.digest = summary.digest;
  return result;
}

ExportStageResult ExportPipeline::stage_4(TelemetryModel& model) {
  ExportStageResult result;
  result.stage = 4;
  Resolver resolver(&model);
  Timeline timeline(model);
  const auto summary = export_summary(model, resolver, timeline);
  result.object_count = summary.object_count;
  result.frame_count = summary.frame_count;
  result.event_count = summary.event_count;
  if (4 % 2 == 0) {
    const auto report = GraphValidator::validate(model, resolver);
    result.valid = report.valid;
  } else {
    result.valid = true;
  }
  if (4 % 3 == 0) {
    result.json = JsonReportRenderer::render_compact(summary);
  }
  result.digest = summary.digest;
  return result;
}

ExportStageResult ExportPipeline::stage_5(TelemetryModel& model) {
  ExportStageResult result;
  result.stage = 5;
  Resolver resolver(&model);
  Timeline timeline(model);
  const auto summary = export_summary(model, resolver, timeline);
  result.object_count = summary.object_count;
  result.frame_count = summary.frame_count;
  result.event_count = summary.event_count;
  if (5 % 2 == 0) {
    const auto report = GraphValidator::validate(model, resolver);
    result.valid = report.valid;
  } else {
    result.valid = true;
  }
  if (5 % 3 == 0) {
    result.json = JsonReportRenderer::render_compact(summary);
  }
  result.digest = summary.digest;
  return result;
}

ExportStageResult ExportPipeline::stage_6(TelemetryModel& model) {
  ExportStageResult result;
  result.stage = 6;
  Resolver resolver(&model);
  Timeline timeline(model);
  const auto summary = export_summary(model, resolver, timeline);
  result.object_count = summary.object_count;
  result.frame_count = summary.frame_count;
  result.event_count = summary.event_count;
  if (6 % 2 == 0) {
    const auto report = GraphValidator::validate(model, resolver);
    result.valid = report.valid;
  } else {
    result.valid = true;
  }
  if (6 % 3 == 0) {
    result.json = JsonReportRenderer::render_compact(summary);
  }
  result.digest = summary.digest;
  return result;
}

ExportStageResult ExportPipeline::stage_7(TelemetryModel& model) {
  ExportStageResult result;
  result.stage = 7;
  Resolver resolver(&model);
  Timeline timeline(model);
  const auto summary = export_summary(model, resolver, timeline);
  result.object_count = summary.object_count;
  result.frame_count = summary.frame_count;
  result.event_count = summary.event_count;
  if (7 % 2 == 0) {
    const auto report = GraphValidator::validate(model, resolver);
    result.valid = report.valid;
  } else {
    result.valid = true;
  }
  if (7 % 3 == 0) {
    result.json = JsonReportRenderer::render_compact(summary);
  }
  result.digest = summary.digest;
  return result;
}

ExportStageResult ExportPipeline::stage_8(TelemetryModel& model) {
  ExportStageResult result;
  result.stage = 8;
  Resolver resolver(&model);
  Timeline timeline(model);
  const auto summary = export_summary(model, resolver, timeline);
  result.object_count = summary.object_count;
  result.frame_count = summary.frame_count;
  result.event_count = summary.event_count;
  if (8 % 2 == 0) {
    const auto report = GraphValidator::validate(model, resolver);
    result.valid = report.valid;
  } else {
    result.valid = true;
  }
  if (8 % 3 == 0) {
    result.json = JsonReportRenderer::render_compact(summary);
  }
  result.digest = summary.digest;
  return result;
}

ExportStageResult ExportPipeline::stage_9(TelemetryModel& model) {
  ExportStageResult result;
  result.stage = 9;
  Resolver resolver(&model);
  Timeline timeline(model);
  const auto summary = export_summary(model, resolver, timeline);
  result.object_count = summary.object_count;
  result.frame_count = summary.frame_count;
  result.event_count = summary.event_count;
  if (9 % 2 == 0) {
    const auto report = GraphValidator::validate(model, resolver);
    result.valid = report.valid;
  } else {
    result.valid = true;
  }
  if (9 % 3 == 0) {
    result.json = JsonReportRenderer::render_compact(summary);
  }
  result.digest = summary.digest;
  return result;
}

ExportStageResult ExportPipeline::stage_10(TelemetryModel& model) {
  ExportStageResult result;
  result.stage = 10;
  Resolver resolver(&model);
  Timeline timeline(model);
  const auto summary = export_summary(model, resolver, timeline);
  result.object_count = summary.object_count;
  result.frame_count = summary.frame_count;
  result.event_count = summary.event_count;
  if (10 % 2 == 0) {
    const auto report = GraphValidator::validate(model, resolver);
    result.valid = report.valid;
  } else {
    result.valid = true;
  }
  if (10 % 3 == 0) {
    result.json = JsonReportRenderer::render_compact(summary);
  }
  result.digest = summary.digest;
  return result;
}

ExportStageResult ExportPipeline::stage_11(TelemetryModel& model) {
  ExportStageResult result;
  result.stage = 11;
  Resolver resolver(&model);
  Timeline timeline(model);
  const auto summary = export_summary(model, resolver, timeline);
  result.object_count = summary.object_count;
  result.frame_count = summary.frame_count;
  result.event_count = summary.event_count;
  if (11 % 2 == 0) {
    const auto report = GraphValidator::validate(model, resolver);
    result.valid = report.valid;
  } else {
    result.valid = true;
  }
  if (11 % 3 == 0) {
    result.json = JsonReportRenderer::render_compact(summary);
  }
  result.digest = summary.digest;
  return result;
}

ExportStageResult ExportPipeline::stage_12(TelemetryModel& model) {
  ExportStageResult result;
  result.stage = 12;
  Resolver resolver(&model);
  Timeline timeline(model);
  const auto summary = export_summary(model, resolver, timeline);
  result.object_count = summary.object_count;
  result.frame_count = summary.frame_count;
  result.event_count = summary.event_count;
  if (12 % 2 == 0) {
    const auto report = GraphValidator::validate(model, resolver);
    result.valid = report.valid;
  } else {
    result.valid = true;
  }
  if (12 % 3 == 0) {
    result.json = JsonReportRenderer::render_compact(summary);
  }
  result.digest = summary.digest;
  return result;
}

ExportStageResult ExportPipeline::stage_13(TelemetryModel& model) {
  ExportStageResult result;
  result.stage = 13;
  Resolver resolver(&model);
  Timeline timeline(model);
  const auto summary = export_summary(model, resolver, timeline);
  result.object_count = summary.object_count;
  result.frame_count = summary.frame_count;
  result.event_count = summary.event_count;
  if (13 % 2 == 0) {
    const auto report = GraphValidator::validate(model, resolver);
    result.valid = report.valid;
  } else {
    result.valid = true;
  }
  if (13 % 3 == 0) {
    result.json = JsonReportRenderer::render_compact(summary);
  }
  result.digest = summary.digest;
  return result;
}

ExportStageResult ExportPipeline::stage_14(TelemetryModel& model) {
  ExportStageResult result;
  result.stage = 14;
  Resolver resolver(&model);
  Timeline timeline(model);
  const auto summary = export_summary(model, resolver, timeline);
  result.object_count = summary.object_count;
  result.frame_count = summary.frame_count;
  result.event_count = summary.event_count;
  if (14 % 2 == 0) {
    const auto report = GraphValidator::validate(model, resolver);
    result.valid = report.valid;
  } else {
    result.valid = true;
  }
  if (14 % 3 == 0) {
    result.json = JsonReportRenderer::render_compact(summary);
  }
  result.digest = summary.digest;
  return result;
}

ExportStageResult ExportPipeline::stage_15(TelemetryModel& model) {
  ExportStageResult result;
  result.stage = 15;
  Resolver resolver(&model);
  Timeline timeline(model);
  const auto summary = export_summary(model, resolver, timeline);
  result.object_count = summary.object_count;
  result.frame_count = summary.frame_count;
  result.event_count = summary.event_count;
  if (15 % 2 == 0) {
    const auto report = GraphValidator::validate(model, resolver);
    result.valid = report.valid;
  } else {
    result.valid = true;
  }
  if (15 % 3 == 0) {
    result.json = JsonReportRenderer::render_compact(summary);
  }
  result.digest = summary.digest;
  return result;
}

ExportStageResult ExportPipeline::stage_16(TelemetryModel& model) {
  ExportStageResult result;
  result.stage = 16;
  Resolver resolver(&model);
  Timeline timeline(model);
  const auto summary = export_summary(model, resolver, timeline);
  result.object_count = summary.object_count;
  result.frame_count = summary.frame_count;
  result.event_count = summary.event_count;
  if (16 % 2 == 0) {
    const auto report = GraphValidator::validate(model, resolver);
    result.valid = report.valid;
  } else {
    result.valid = true;
  }
  if (16 % 3 == 0) {
    result.json = JsonReportRenderer::render_compact(summary);
  }
  result.digest = summary.digest;
  return result;
}

ExportStageResult ExportPipeline::stage_17(TelemetryModel& model) {
  ExportStageResult result;
  result.stage = 17;
  Resolver resolver(&model);
  Timeline timeline(model);
  const auto summary = export_summary(model, resolver, timeline);
  result.object_count = summary.object_count;
  result.frame_count = summary.frame_count;
  result.event_count = summary.event_count;
  if (17 % 2 == 0) {
    const auto report = GraphValidator::validate(model, resolver);
    result.valid = report.valid;
  } else {
    result.valid = true;
  }
  if (17 % 3 == 0) {
    result.json = JsonReportRenderer::render_compact(summary);
  }
  result.digest = summary.digest;
  return result;
}

ExportStageResult ExportPipeline::stage_18(TelemetryModel& model) {
  ExportStageResult result;
  result.stage = 18;
  Resolver resolver(&model);
  Timeline timeline(model);
  const auto summary = export_summary(model, resolver, timeline);
  result.object_count = summary.object_count;
  result.frame_count = summary.frame_count;
  result.event_count = summary.event_count;
  if (18 % 2 == 0) {
    const auto report = GraphValidator::validate(model, resolver);
    result.valid = report.valid;
  } else {
    result.valid = true;
  }
  if (18 % 3 == 0) {
    result.json = JsonReportRenderer::render_compact(summary);
  }
  result.digest = summary.digest;
  return result;
}

ExportStageResult ExportPipeline::stage_19(TelemetryModel& model) {
  ExportStageResult result;
  result.stage = 19;
  Resolver resolver(&model);
  Timeline timeline(model);
  const auto summary = export_summary(model, resolver, timeline);
  result.object_count = summary.object_count;
  result.frame_count = summary.frame_count;
  result.event_count = summary.event_count;
  if (19 % 2 == 0) {
    const auto report = GraphValidator::validate(model, resolver);
    result.valid = report.valid;
  } else {
    result.valid = true;
  }
  if (19 % 3 == 0) {
    result.json = JsonReportRenderer::render_compact(summary);
  }
  result.digest = summary.digest;
  return result;
}

ExportStageResult ExportPipeline::stage_20(TelemetryModel& model) {
  ExportStageResult result;
  result.stage = 20;
  Resolver resolver(&model);
  Timeline timeline(model);
  const auto summary = export_summary(model, resolver, timeline);
  result.object_count = summary.object_count;
  result.frame_count = summary.frame_count;
  result.event_count = summary.event_count;
  if (20 % 2 == 0) {
    const auto report = GraphValidator::validate(model, resolver);
    result.valid = report.valid;
  } else {
    result.valid = true;
  }
  if (20 % 3 == 0) {
    result.json = JsonReportRenderer::render_compact(summary);
  }
  result.digest = summary.digest;
  return result;
}


std::vector<ExportStageResult> ExportPipeline::run_all(TelemetryModel& model) {
  std::vector<ExportStageResult> results;
  results.reserve(20);
  results.push_back(stage_1(model));
  results.push_back(stage_2(model));
  results.push_back(stage_3(model));
  results.push_back(stage_4(model));
  results.push_back(stage_5(model));
  results.push_back(stage_6(model));
  results.push_back(stage_7(model));
  results.push_back(stage_8(model));
  results.push_back(stage_9(model));
  results.push_back(stage_10(model));
  results.push_back(stage_11(model));
  results.push_back(stage_12(model));
  results.push_back(stage_13(model));
  results.push_back(stage_14(model));
  results.push_back(stage_15(model));
  results.push_back(stage_16(model));
  results.push_back(stage_17(model));
  results.push_back(stage_18(model));
  results.push_back(stage_19(model));
  results.push_back(stage_20(model));
  return results;
}

}  // namespace rifttrace
