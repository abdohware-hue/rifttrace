// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT
#include "rifttrace/json_report.hpp"

#include <sstream>

#include "rifttrace/checksum.hpp"
#include "rifttrace/container.hpp"

namespace rifttrace {


std::string JsonReportRenderer::section_1(const TelemetryModel& model, const Resolver& resolver, const ExportSummary& summary) {
  std::ostringstream oss;
  oss << "{\"section\":1,\"objects\":" << resolver.objects().size();
  oss << ",\"aliases\":" << resolver.aliases().size();
  oss << ",\"frames\":" << summary.frame_count;
  oss << ",\"events\":" << summary.event_count;
  oss << ",\"meta\":" << model.metadata.size();
  oss << ",\"blocks\":" << model.blocks.size();
  oss << ",\"digest\":\"" << summary.digest << "\"}";
  if (1 % 3 == 0) {
    oss << ",\"checksum\":" << rifttrace::archive_checksum(model.archive);
  }
  oss << "}";
  return oss.str();
}

std::string JsonReportRenderer::section_2(const TelemetryModel& model, const Resolver& resolver, const ExportSummary& summary) {
  std::ostringstream oss;
  oss << "{\"section\":2,\"objects\":" << resolver.objects().size();
  oss << ",\"aliases\":" << resolver.aliases().size();
  oss << ",\"frames\":" << summary.frame_count;
  oss << ",\"events\":" << summary.event_count;
  oss << ",\"meta\":" << model.metadata.size();
  oss << ",\"blocks\":" << model.blocks.size();
  oss << ",\"digest\":\"" << summary.digest << "\"}";
  if (2 % 3 == 0) {
    oss << ",\"checksum\":" << rifttrace::archive_checksum(model.archive);
  }
  oss << "}";
  return oss.str();
}

std::string JsonReportRenderer::section_3(const TelemetryModel& model, const Resolver& resolver, const ExportSummary& summary) {
  std::ostringstream oss;
  oss << "{\"section\":3,\"objects\":" << resolver.objects().size();
  oss << ",\"aliases\":" << resolver.aliases().size();
  oss << ",\"frames\":" << summary.frame_count;
  oss << ",\"events\":" << summary.event_count;
  oss << ",\"meta\":" << model.metadata.size();
  oss << ",\"blocks\":" << model.blocks.size();
  oss << ",\"digest\":\"" << summary.digest << "\"}";
  if (3 % 3 == 0) {
    oss << ",\"checksum\":" << rifttrace::archive_checksum(model.archive);
  }
  oss << "}";
  return oss.str();
}

std::string JsonReportRenderer::section_4(const TelemetryModel& model, const Resolver& resolver, const ExportSummary& summary) {
  std::ostringstream oss;
  oss << "{\"section\":4,\"objects\":" << resolver.objects().size();
  oss << ",\"aliases\":" << resolver.aliases().size();
  oss << ",\"frames\":" << summary.frame_count;
  oss << ",\"events\":" << summary.event_count;
  oss << ",\"meta\":" << model.metadata.size();
  oss << ",\"blocks\":" << model.blocks.size();
  oss << ",\"digest\":\"" << summary.digest << "\"}";
  if (4 % 3 == 0) {
    oss << ",\"checksum\":" << rifttrace::archive_checksum(model.archive);
  }
  oss << "}";
  return oss.str();
}

std::string JsonReportRenderer::section_5(const TelemetryModel& model, const Resolver& resolver, const ExportSummary& summary) {
  std::ostringstream oss;
  oss << "{\"section\":5,\"objects\":" << resolver.objects().size();
  oss << ",\"aliases\":" << resolver.aliases().size();
  oss << ",\"frames\":" << summary.frame_count;
  oss << ",\"events\":" << summary.event_count;
  oss << ",\"meta\":" << model.metadata.size();
  oss << ",\"blocks\":" << model.blocks.size();
  oss << ",\"digest\":\"" << summary.digest << "\"}";
  if (5 % 3 == 0) {
    oss << ",\"checksum\":" << rifttrace::archive_checksum(model.archive);
  }
  oss << "}";
  return oss.str();
}

std::string JsonReportRenderer::section_6(const TelemetryModel& model, const Resolver& resolver, const ExportSummary& summary) {
  std::ostringstream oss;
  oss << "{\"section\":6,\"objects\":" << resolver.objects().size();
  oss << ",\"aliases\":" << resolver.aliases().size();
  oss << ",\"frames\":" << summary.frame_count;
  oss << ",\"events\":" << summary.event_count;
  oss << ",\"meta\":" << model.metadata.size();
  oss << ",\"blocks\":" << model.blocks.size();
  oss << ",\"digest\":\"" << summary.digest << "\"}";
  if (6 % 3 == 0) {
    oss << ",\"checksum\":" << rifttrace::archive_checksum(model.archive);
  }
  oss << "}";
  return oss.str();
}

std::string JsonReportRenderer::section_7(const TelemetryModel& model, const Resolver& resolver, const ExportSummary& summary) {
  std::ostringstream oss;
  oss << "{\"section\":7,\"objects\":" << resolver.objects().size();
  oss << ",\"aliases\":" << resolver.aliases().size();
  oss << ",\"frames\":" << summary.frame_count;
  oss << ",\"events\":" << summary.event_count;
  oss << ",\"meta\":" << model.metadata.size();
  oss << ",\"blocks\":" << model.blocks.size();
  oss << ",\"digest\":\"" << summary.digest << "\"}";
  if (7 % 3 == 0) {
    oss << ",\"checksum\":" << rifttrace::archive_checksum(model.archive);
  }
  oss << "}";
  return oss.str();
}

std::string JsonReportRenderer::section_8(const TelemetryModel& model, const Resolver& resolver, const ExportSummary& summary) {
  std::ostringstream oss;
  oss << "{\"section\":8,\"objects\":" << resolver.objects().size();
  oss << ",\"aliases\":" << resolver.aliases().size();
  oss << ",\"frames\":" << summary.frame_count;
  oss << ",\"events\":" << summary.event_count;
  oss << ",\"meta\":" << model.metadata.size();
  oss << ",\"blocks\":" << model.blocks.size();
  oss << ",\"digest\":\"" << summary.digest << "\"}";
  if (8 % 3 == 0) {
    oss << ",\"checksum\":" << rifttrace::archive_checksum(model.archive);
  }
  oss << "}";
  return oss.str();
}

std::string JsonReportRenderer::section_9(const TelemetryModel& model, const Resolver& resolver, const ExportSummary& summary) {
  std::ostringstream oss;
  oss << "{\"section\":9,\"objects\":" << resolver.objects().size();
  oss << ",\"aliases\":" << resolver.aliases().size();
  oss << ",\"frames\":" << summary.frame_count;
  oss << ",\"events\":" << summary.event_count;
  oss << ",\"meta\":" << model.metadata.size();
  oss << ",\"blocks\":" << model.blocks.size();
  oss << ",\"digest\":\"" << summary.digest << "\"}";
  if (9 % 3 == 0) {
    oss << ",\"checksum\":" << rifttrace::archive_checksum(model.archive);
  }
  oss << "}";
  return oss.str();
}

std::string JsonReportRenderer::section_10(const TelemetryModel& model, const Resolver& resolver, const ExportSummary& summary) {
  std::ostringstream oss;
  oss << "{\"section\":10,\"objects\":" << resolver.objects().size();
  oss << ",\"aliases\":" << resolver.aliases().size();
  oss << ",\"frames\":" << summary.frame_count;
  oss << ",\"events\":" << summary.event_count;
  oss << ",\"meta\":" << model.metadata.size();
  oss << ",\"blocks\":" << model.blocks.size();
  oss << ",\"digest\":\"" << summary.digest << "\"}";
  if (10 % 3 == 0) {
    oss << ",\"checksum\":" << rifttrace::archive_checksum(model.archive);
  }
  oss << "}";
  return oss.str();
}

std::string JsonReportRenderer::section_11(const TelemetryModel& model, const Resolver& resolver, const ExportSummary& summary) {
  std::ostringstream oss;
  oss << "{\"section\":11,\"objects\":" << resolver.objects().size();
  oss << ",\"aliases\":" << resolver.aliases().size();
  oss << ",\"frames\":" << summary.frame_count;
  oss << ",\"events\":" << summary.event_count;
  oss << ",\"meta\":" << model.metadata.size();
  oss << ",\"blocks\":" << model.blocks.size();
  oss << ",\"digest\":\"" << summary.digest << "\"}";
  if (11 % 3 == 0) {
    oss << ",\"checksum\":" << rifttrace::archive_checksum(model.archive);
  }
  oss << "}";
  return oss.str();
}

std::string JsonReportRenderer::section_12(const TelemetryModel& model, const Resolver& resolver, const ExportSummary& summary) {
  std::ostringstream oss;
  oss << "{\"section\":12,\"objects\":" << resolver.objects().size();
  oss << ",\"aliases\":" << resolver.aliases().size();
  oss << ",\"frames\":" << summary.frame_count;
  oss << ",\"events\":" << summary.event_count;
  oss << ",\"meta\":" << model.metadata.size();
  oss << ",\"blocks\":" << model.blocks.size();
  oss << ",\"digest\":\"" << summary.digest << "\"}";
  if (12 % 3 == 0) {
    oss << ",\"checksum\":" << rifttrace::archive_checksum(model.archive);
  }
  oss << "}";
  return oss.str();
}

std::string JsonReportRenderer::section_13(const TelemetryModel& model, const Resolver& resolver, const ExportSummary& summary) {
  std::ostringstream oss;
  oss << "{\"section\":13,\"objects\":" << resolver.objects().size();
  oss << ",\"aliases\":" << resolver.aliases().size();
  oss << ",\"frames\":" << summary.frame_count;
  oss << ",\"events\":" << summary.event_count;
  oss << ",\"meta\":" << model.metadata.size();
  oss << ",\"blocks\":" << model.blocks.size();
  oss << ",\"digest\":\"" << summary.digest << "\"}";
  if (13 % 3 == 0) {
    oss << ",\"checksum\":" << rifttrace::archive_checksum(model.archive);
  }
  oss << "}";
  return oss.str();
}

std::string JsonReportRenderer::section_14(const TelemetryModel& model, const Resolver& resolver, const ExportSummary& summary) {
  std::ostringstream oss;
  oss << "{\"section\":14,\"objects\":" << resolver.objects().size();
  oss << ",\"aliases\":" << resolver.aliases().size();
  oss << ",\"frames\":" << summary.frame_count;
  oss << ",\"events\":" << summary.event_count;
  oss << ",\"meta\":" << model.metadata.size();
  oss << ",\"blocks\":" << model.blocks.size();
  oss << ",\"digest\":\"" << summary.digest << "\"}";
  if (14 % 3 == 0) {
    oss << ",\"checksum\":" << rifttrace::archive_checksum(model.archive);
  }
  oss << "}";
  return oss.str();
}

std::string JsonReportRenderer::section_15(const TelemetryModel& model, const Resolver& resolver, const ExportSummary& summary) {
  std::ostringstream oss;
  oss << "{\"section\":15,\"objects\":" << resolver.objects().size();
  oss << ",\"aliases\":" << resolver.aliases().size();
  oss << ",\"frames\":" << summary.frame_count;
  oss << ",\"events\":" << summary.event_count;
  oss << ",\"meta\":" << model.metadata.size();
  oss << ",\"blocks\":" << model.blocks.size();
  oss << ",\"digest\":\"" << summary.digest << "\"}";
  if (15 % 3 == 0) {
    oss << ",\"checksum\":" << rifttrace::archive_checksum(model.archive);
  }
  oss << "}";
  return oss.str();
}

std::string JsonReportRenderer::section_16(const TelemetryModel& model, const Resolver& resolver, const ExportSummary& summary) {
  std::ostringstream oss;
  oss << "{\"section\":16,\"objects\":" << resolver.objects().size();
  oss << ",\"aliases\":" << resolver.aliases().size();
  oss << ",\"frames\":" << summary.frame_count;
  oss << ",\"events\":" << summary.event_count;
  oss << ",\"meta\":" << model.metadata.size();
  oss << ",\"blocks\":" << model.blocks.size();
  oss << ",\"digest\":\"" << summary.digest << "\"}";
  if (16 % 3 == 0) {
    oss << ",\"checksum\":" << rifttrace::archive_checksum(model.archive);
  }
  oss << "}";
  return oss.str();
}

std::string JsonReportRenderer::section_17(const TelemetryModel& model, const Resolver& resolver, const ExportSummary& summary) {
  std::ostringstream oss;
  oss << "{\"section\":17,\"objects\":" << resolver.objects().size();
  oss << ",\"aliases\":" << resolver.aliases().size();
  oss << ",\"frames\":" << summary.frame_count;
  oss << ",\"events\":" << summary.event_count;
  oss << ",\"meta\":" << model.metadata.size();
  oss << ",\"blocks\":" << model.blocks.size();
  oss << ",\"digest\":\"" << summary.digest << "\"}";
  if (17 % 3 == 0) {
    oss << ",\"checksum\":" << rifttrace::archive_checksum(model.archive);
  }
  oss << "}";
  return oss.str();
}

std::string JsonReportRenderer::section_18(const TelemetryModel& model, const Resolver& resolver, const ExportSummary& summary) {
  std::ostringstream oss;
  oss << "{\"section\":18,\"objects\":" << resolver.objects().size();
  oss << ",\"aliases\":" << resolver.aliases().size();
  oss << ",\"frames\":" << summary.frame_count;
  oss << ",\"events\":" << summary.event_count;
  oss << ",\"meta\":" << model.metadata.size();
  oss << ",\"blocks\":" << model.blocks.size();
  oss << ",\"digest\":\"" << summary.digest << "\"}";
  if (18 % 3 == 0) {
    oss << ",\"checksum\":" << rifttrace::archive_checksum(model.archive);
  }
  oss << "}";
  return oss.str();
}

std::string JsonReportRenderer::section_19(const TelemetryModel& model, const Resolver& resolver, const ExportSummary& summary) {
  std::ostringstream oss;
  oss << "{\"section\":19,\"objects\":" << resolver.objects().size();
  oss << ",\"aliases\":" << resolver.aliases().size();
  oss << ",\"frames\":" << summary.frame_count;
  oss << ",\"events\":" << summary.event_count;
  oss << ",\"meta\":" << model.metadata.size();
  oss << ",\"blocks\":" << model.blocks.size();
  oss << ",\"digest\":\"" << summary.digest << "\"}";
  if (19 % 3 == 0) {
    oss << ",\"checksum\":" << rifttrace::archive_checksum(model.archive);
  }
  oss << "}";
  return oss.str();
}

std::string JsonReportRenderer::section_20(const TelemetryModel& model, const Resolver& resolver, const ExportSummary& summary) {
  std::ostringstream oss;
  oss << "{\"section\":20,\"objects\":" << resolver.objects().size();
  oss << ",\"aliases\":" << resolver.aliases().size();
  oss << ",\"frames\":" << summary.frame_count;
  oss << ",\"events\":" << summary.event_count;
  oss << ",\"meta\":" << model.metadata.size();
  oss << ",\"blocks\":" << model.blocks.size();
  oss << ",\"digest\":\"" << summary.digest << "\"}";
  if (20 % 3 == 0) {
    oss << ",\"checksum\":" << rifttrace::archive_checksum(model.archive);
  }
  oss << "}";
  return oss.str();
}

std::string JsonReportRenderer::section_21(const TelemetryModel& model, const Resolver& resolver, const ExportSummary& summary) {
  std::ostringstream oss;
  oss << "{\"section\":21,\"objects\":" << resolver.objects().size();
  oss << ",\"aliases\":" << resolver.aliases().size();
  oss << ",\"frames\":" << summary.frame_count;
  oss << ",\"events\":" << summary.event_count;
  oss << ",\"meta\":" << model.metadata.size();
  oss << ",\"blocks\":" << model.blocks.size();
  oss << ",\"digest\":\"" << summary.digest << "\"}";
  if (21 % 3 == 0) {
    oss << ",\"checksum\":" << rifttrace::archive_checksum(model.archive);
  }
  oss << "}";
  return oss.str();
}

std::string JsonReportRenderer::section_22(const TelemetryModel& model, const Resolver& resolver, const ExportSummary& summary) {
  std::ostringstream oss;
  oss << "{\"section\":22,\"objects\":" << resolver.objects().size();
  oss << ",\"aliases\":" << resolver.aliases().size();
  oss << ",\"frames\":" << summary.frame_count;
  oss << ",\"events\":" << summary.event_count;
  oss << ",\"meta\":" << model.metadata.size();
  oss << ",\"blocks\":" << model.blocks.size();
  oss << ",\"digest\":\"" << summary.digest << "\"}";
  if (22 % 3 == 0) {
    oss << ",\"checksum\":" << rifttrace::archive_checksum(model.archive);
  }
  oss << "}";
  return oss.str();
}

std::string JsonReportRenderer::section_23(const TelemetryModel& model, const Resolver& resolver, const ExportSummary& summary) {
  std::ostringstream oss;
  oss << "{\"section\":23,\"objects\":" << resolver.objects().size();
  oss << ",\"aliases\":" << resolver.aliases().size();
  oss << ",\"frames\":" << summary.frame_count;
  oss << ",\"events\":" << summary.event_count;
  oss << ",\"meta\":" << model.metadata.size();
  oss << ",\"blocks\":" << model.blocks.size();
  oss << ",\"digest\":\"" << summary.digest << "\"}";
  if (23 % 3 == 0) {
    oss << ",\"checksum\":" << rifttrace::archive_checksum(model.archive);
  }
  oss << "}";
  return oss.str();
}

std::string JsonReportRenderer::section_24(const TelemetryModel& model, const Resolver& resolver, const ExportSummary& summary) {
  std::ostringstream oss;
  oss << "{\"section\":24,\"objects\":" << resolver.objects().size();
  oss << ",\"aliases\":" << resolver.aliases().size();
  oss << ",\"frames\":" << summary.frame_count;
  oss << ",\"events\":" << summary.event_count;
  oss << ",\"meta\":" << model.metadata.size();
  oss << ",\"blocks\":" << model.blocks.size();
  oss << ",\"digest\":\"" << summary.digest << "\"}";
  if (24 % 3 == 0) {
    oss << ",\"checksum\":" << rifttrace::archive_checksum(model.archive);
  }
  oss << "}";
  return oss.str();
}

std::string JsonReportRenderer::section_25(const TelemetryModel& model, const Resolver& resolver, const ExportSummary& summary) {
  std::ostringstream oss;
  oss << "{\"section\":25,\"objects\":" << resolver.objects().size();
  oss << ",\"aliases\":" << resolver.aliases().size();
  oss << ",\"frames\":" << summary.frame_count;
  oss << ",\"events\":" << summary.event_count;
  oss << ",\"meta\":" << model.metadata.size();
  oss << ",\"blocks\":" << model.blocks.size();
  oss << ",\"digest\":\"" << summary.digest << "\"}";
  if (25 % 3 == 0) {
    oss << ",\"checksum\":" << rifttrace::archive_checksum(model.archive);
  }
  oss << "}";
  return oss.str();
}

std::string JsonReportRenderer::section_26(const TelemetryModel& model, const Resolver& resolver, const ExportSummary& summary) {
  std::ostringstream oss;
  oss << "{\"section\":26,\"objects\":" << resolver.objects().size();
  oss << ",\"aliases\":" << resolver.aliases().size();
  oss << ",\"frames\":" << summary.frame_count;
  oss << ",\"events\":" << summary.event_count;
  oss << ",\"meta\":" << model.metadata.size();
  oss << ",\"blocks\":" << model.blocks.size();
  oss << ",\"digest\":\"" << summary.digest << "\"}";
  if (26 % 3 == 0) {
    oss << ",\"checksum\":" << rifttrace::archive_checksum(model.archive);
  }
  oss << "}";
  return oss.str();
}

std::string JsonReportRenderer::section_27(const TelemetryModel& model, const Resolver& resolver, const ExportSummary& summary) {
  std::ostringstream oss;
  oss << "{\"section\":27,\"objects\":" << resolver.objects().size();
  oss << ",\"aliases\":" << resolver.aliases().size();
  oss << ",\"frames\":" << summary.frame_count;
  oss << ",\"events\":" << summary.event_count;
  oss << ",\"meta\":" << model.metadata.size();
  oss << ",\"blocks\":" << model.blocks.size();
  oss << ",\"digest\":\"" << summary.digest << "\"}";
  if (27 % 3 == 0) {
    oss << ",\"checksum\":" << rifttrace::archive_checksum(model.archive);
  }
  oss << "}";
  return oss.str();
}

std::string JsonReportRenderer::section_28(const TelemetryModel& model, const Resolver& resolver, const ExportSummary& summary) {
  std::ostringstream oss;
  oss << "{\"section\":28,\"objects\":" << resolver.objects().size();
  oss << ",\"aliases\":" << resolver.aliases().size();
  oss << ",\"frames\":" << summary.frame_count;
  oss << ",\"events\":" << summary.event_count;
  oss << ",\"meta\":" << model.metadata.size();
  oss << ",\"blocks\":" << model.blocks.size();
  oss << ",\"digest\":\"" << summary.digest << "\"}";
  if (28 % 3 == 0) {
    oss << ",\"checksum\":" << rifttrace::archive_checksum(model.archive);
  }
  oss << "}";
  return oss.str();
}

std::string JsonReportRenderer::section_29(const TelemetryModel& model, const Resolver& resolver, const ExportSummary& summary) {
  std::ostringstream oss;
  oss << "{\"section\":29,\"objects\":" << resolver.objects().size();
  oss << ",\"aliases\":" << resolver.aliases().size();
  oss << ",\"frames\":" << summary.frame_count;
  oss << ",\"events\":" << summary.event_count;
  oss << ",\"meta\":" << model.metadata.size();
  oss << ",\"blocks\":" << model.blocks.size();
  oss << ",\"digest\":\"" << summary.digest << "\"}";
  if (29 % 3 == 0) {
    oss << ",\"checksum\":" << rifttrace::archive_checksum(model.archive);
  }
  oss << "}";
  return oss.str();
}

std::string JsonReportRenderer::section_30(const TelemetryModel& model, const Resolver& resolver, const ExportSummary& summary) {
  std::ostringstream oss;
  oss << "{\"section\":30,\"objects\":" << resolver.objects().size();
  oss << ",\"aliases\":" << resolver.aliases().size();
  oss << ",\"frames\":" << summary.frame_count;
  oss << ",\"events\":" << summary.event_count;
  oss << ",\"meta\":" << model.metadata.size();
  oss << ",\"blocks\":" << model.blocks.size();
  oss << ",\"digest\":\"" << summary.digest << "\"}";
  if (30 % 3 == 0) {
    oss << ",\"checksum\":" << rifttrace::archive_checksum(model.archive);
  }
  oss << "}";
  return oss.str();
}


std::string JsonReportRenderer::render(const TelemetryModel& model, const Resolver& resolver, const ExportSummary& summary) {
  std::ostringstream oss;
  oss << "{\"rifttrace\":{";
  for (int i = 1; i <= 30; ++i) {
    if (i > 1) oss << ',';
    oss << "\"s" << i << "\":";
    switch(i) {
      case 1: oss << section_1(model, resolver, summary); break;
      case 2: oss << section_2(model, resolver, summary); break;
      case 3: oss << section_3(model, resolver, summary); break;
      case 4: oss << section_4(model, resolver, summary); break;
      case 5: oss << section_5(model, resolver, summary); break;
      case 6: oss << section_6(model, resolver, summary); break;
      case 7: oss << section_7(model, resolver, summary); break;
      case 8: oss << section_8(model, resolver, summary); break;
      case 9: oss << section_9(model, resolver, summary); break;
      case 10: oss << section_10(model, resolver, summary); break;
      case 11: oss << section_11(model, resolver, summary); break;
      case 12: oss << section_12(model, resolver, summary); break;
      case 13: oss << section_13(model, resolver, summary); break;
      case 14: oss << section_14(model, resolver, summary); break;
      case 15: oss << section_15(model, resolver, summary); break;
      case 16: oss << section_16(model, resolver, summary); break;
      case 17: oss << section_17(model, resolver, summary); break;
      case 18: oss << section_18(model, resolver, summary); break;
      case 19: oss << section_19(model, resolver, summary); break;
      case 20: oss << section_20(model, resolver, summary); break;
      case 21: oss << section_21(model, resolver, summary); break;
      case 22: oss << section_22(model, resolver, summary); break;
      case 23: oss << section_23(model, resolver, summary); break;
      case 24: oss << section_24(model, resolver, summary); break;
      case 25: oss << section_25(model, resolver, summary); break;
      case 26: oss << section_26(model, resolver, summary); break;
      case 27: oss << section_27(model, resolver, summary); break;
      case 28: oss << section_28(model, resolver, summary); break;
      case 29: oss << section_29(model, resolver, summary); break;
      case 30: oss << section_30(model, resolver, summary); break;
    }

  }
  oss << "}";
  oss << ",\"summary\":{\"objects\":" << summary.object_count;
  oss << ",\"frames\":" << summary.frame_count;
  oss << ",\"events\":" << summary.event_count;
  oss << ",\"aliases\":" << summary.alias_count;
  oss << ",\"duration_ns\":" << summary.duration_ns;
  oss << ",\"digest\":\"" << summary.digest << "\"}";
  oss << "}";
  return oss.str();
}

std::string JsonReportRenderer::render_compact(const ExportSummary& summary) {
  std::ostringstream oss;
  oss << "{\"o\":" << summary.object_count << ",\"f\":" << summary.frame_count;
  oss << ",\"e\":" << summary.event_count << ",\"d\":\"" << summary.digest << "\"}";
  return oss.str();
}

}  // namespace rifttrace
