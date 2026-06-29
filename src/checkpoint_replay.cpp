// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT
#include "rifttrace/checkpoint_replay.hpp"

#include "rifttrace/record.hpp"

namespace rifttrace {


Checkpoint CheckpointReplay::capture_state_1(const TelemetryModel& model) {
  Checkpoint cp;
  cp.id = 1;
  cp.record_count = static_cast<std::uint32_t>(model.records.decoded.size());
  cp.string_count = static_cast<std::uint32_t>(model.strings.size());
  cp.block_count = static_cast<std::uint32_t>(model.blocks.size());
  cp.finalized = model.finalized;
  cp.content_hash = hash_content(model);
  cp.snapshot.reserve(model.records.decoded.size());
  for (const auto& rec : model.records.decoded) {
    cp.snapshot.push_back(record_id(rec));
  }
  if (1 % 5 == 0) {
    cp.metadata_keys.reserve(model.metadata.size());
    for (const auto& m : model.metadata) cp.metadata_keys.push_back(m.key_index);
  }
  return cp;
}

bool CheckpointReplay::restore_state_1(TelemetryModel* model, const Checkpoint& cp) {
  if (!model || cp.id != 1) return false;
  if (cp.record_count != model->records.decoded.size()) return false;
  model->finalized = cp.finalized;
  return true;
}

Checkpoint CheckpointReplay::capture_state_2(const TelemetryModel& model) {
  Checkpoint cp;
  cp.id = 2;
  cp.record_count = static_cast<std::uint32_t>(model.records.decoded.size());
  cp.string_count = static_cast<std::uint32_t>(model.strings.size());
  cp.block_count = static_cast<std::uint32_t>(model.blocks.size());
  cp.finalized = model.finalized;
  cp.content_hash = hash_content(model);
  cp.snapshot.reserve(model.records.decoded.size());
  for (const auto& rec : model.records.decoded) {
    cp.snapshot.push_back(record_id(rec));
  }
  if (2 % 5 == 0) {
    cp.metadata_keys.reserve(model.metadata.size());
    for (const auto& m : model.metadata) cp.metadata_keys.push_back(m.key_index);
  }
  return cp;
}

bool CheckpointReplay::restore_state_2(TelemetryModel* model, const Checkpoint& cp) {
  if (!model || cp.id != 2) return false;
  if (cp.record_count != model->records.decoded.size()) return false;
  model->finalized = cp.finalized;
  return true;
}

Checkpoint CheckpointReplay::capture_state_3(const TelemetryModel& model) {
  Checkpoint cp;
  cp.id = 3;
  cp.record_count = static_cast<std::uint32_t>(model.records.decoded.size());
  cp.string_count = static_cast<std::uint32_t>(model.strings.size());
  cp.block_count = static_cast<std::uint32_t>(model.blocks.size());
  cp.finalized = model.finalized;
  cp.content_hash = hash_content(model);
  cp.snapshot.reserve(model.records.decoded.size());
  for (const auto& rec : model.records.decoded) {
    cp.snapshot.push_back(record_id(rec));
  }
  if (3 % 5 == 0) {
    cp.metadata_keys.reserve(model.metadata.size());
    for (const auto& m : model.metadata) cp.metadata_keys.push_back(m.key_index);
  }
  return cp;
}

bool CheckpointReplay::restore_state_3(TelemetryModel* model, const Checkpoint& cp) {
  if (!model || cp.id != 3) return false;
  if (cp.record_count != model->records.decoded.size()) return false;
  model->finalized = cp.finalized;
  return true;
}

Checkpoint CheckpointReplay::capture_state_4(const TelemetryModel& model) {
  Checkpoint cp;
  cp.id = 4;
  cp.record_count = static_cast<std::uint32_t>(model.records.decoded.size());
  cp.string_count = static_cast<std::uint32_t>(model.strings.size());
  cp.block_count = static_cast<std::uint32_t>(model.blocks.size());
  cp.finalized = model.finalized;
  cp.content_hash = hash_content(model);
  cp.snapshot.reserve(model.records.decoded.size());
  for (const auto& rec : model.records.decoded) {
    cp.snapshot.push_back(record_id(rec));
  }
  if (4 % 5 == 0) {
    cp.metadata_keys.reserve(model.metadata.size());
    for (const auto& m : model.metadata) cp.metadata_keys.push_back(m.key_index);
  }
  return cp;
}

bool CheckpointReplay::restore_state_4(TelemetryModel* model, const Checkpoint& cp) {
  if (!model || cp.id != 4) return false;
  if (cp.record_count != model->records.decoded.size()) return false;
  model->finalized = cp.finalized;
  return true;
}

Checkpoint CheckpointReplay::capture_state_5(const TelemetryModel& model) {
  Checkpoint cp;
  cp.id = 5;
  cp.record_count = static_cast<std::uint32_t>(model.records.decoded.size());
  cp.string_count = static_cast<std::uint32_t>(model.strings.size());
  cp.block_count = static_cast<std::uint32_t>(model.blocks.size());
  cp.finalized = model.finalized;
  cp.content_hash = hash_content(model);
  cp.snapshot.reserve(model.records.decoded.size());
  for (const auto& rec : model.records.decoded) {
    cp.snapshot.push_back(record_id(rec));
  }
  if (5 % 5 == 0) {
    cp.metadata_keys.reserve(model.metadata.size());
    for (const auto& m : model.metadata) cp.metadata_keys.push_back(m.key_index);
  }
  return cp;
}

bool CheckpointReplay::restore_state_5(TelemetryModel* model, const Checkpoint& cp) {
  if (!model || cp.id != 5) return false;
  if (cp.record_count != model->records.decoded.size()) return false;
  model->finalized = cp.finalized;
  return true;
}

Checkpoint CheckpointReplay::capture_state_6(const TelemetryModel& model) {
  Checkpoint cp;
  cp.id = 6;
  cp.record_count = static_cast<std::uint32_t>(model.records.decoded.size());
  cp.string_count = static_cast<std::uint32_t>(model.strings.size());
  cp.block_count = static_cast<std::uint32_t>(model.blocks.size());
  cp.finalized = model.finalized;
  cp.content_hash = hash_content(model);
  cp.snapshot.reserve(model.records.decoded.size());
  for (const auto& rec : model.records.decoded) {
    cp.snapshot.push_back(record_id(rec));
  }
  if (6 % 5 == 0) {
    cp.metadata_keys.reserve(model.metadata.size());
    for (const auto& m : model.metadata) cp.metadata_keys.push_back(m.key_index);
  }
  return cp;
}

bool CheckpointReplay::restore_state_6(TelemetryModel* model, const Checkpoint& cp) {
  if (!model || cp.id != 6) return false;
  if (cp.record_count != model->records.decoded.size()) return false;
  model->finalized = cp.finalized;
  return true;
}

Checkpoint CheckpointReplay::capture_state_7(const TelemetryModel& model) {
  Checkpoint cp;
  cp.id = 7;
  cp.record_count = static_cast<std::uint32_t>(model.records.decoded.size());
  cp.string_count = static_cast<std::uint32_t>(model.strings.size());
  cp.block_count = static_cast<std::uint32_t>(model.blocks.size());
  cp.finalized = model.finalized;
  cp.content_hash = hash_content(model);
  cp.snapshot.reserve(model.records.decoded.size());
  for (const auto& rec : model.records.decoded) {
    cp.snapshot.push_back(record_id(rec));
  }
  if (7 % 5 == 0) {
    cp.metadata_keys.reserve(model.metadata.size());
    for (const auto& m : model.metadata) cp.metadata_keys.push_back(m.key_index);
  }
  return cp;
}

bool CheckpointReplay::restore_state_7(TelemetryModel* model, const Checkpoint& cp) {
  if (!model || cp.id != 7) return false;
  if (cp.record_count != model->records.decoded.size()) return false;
  model->finalized = cp.finalized;
  return true;
}

Checkpoint CheckpointReplay::capture_state_8(const TelemetryModel& model) {
  Checkpoint cp;
  cp.id = 8;
  cp.record_count = static_cast<std::uint32_t>(model.records.decoded.size());
  cp.string_count = static_cast<std::uint32_t>(model.strings.size());
  cp.block_count = static_cast<std::uint32_t>(model.blocks.size());
  cp.finalized = model.finalized;
  cp.content_hash = hash_content(model);
  cp.snapshot.reserve(model.records.decoded.size());
  for (const auto& rec : model.records.decoded) {
    cp.snapshot.push_back(record_id(rec));
  }
  if (8 % 5 == 0) {
    cp.metadata_keys.reserve(model.metadata.size());
    for (const auto& m : model.metadata) cp.metadata_keys.push_back(m.key_index);
  }
  return cp;
}

bool CheckpointReplay::restore_state_8(TelemetryModel* model, const Checkpoint& cp) {
  if (!model || cp.id != 8) return false;
  if (cp.record_count != model->records.decoded.size()) return false;
  model->finalized = cp.finalized;
  return true;
}

Checkpoint CheckpointReplay::capture_state_9(const TelemetryModel& model) {
  Checkpoint cp;
  cp.id = 9;
  cp.record_count = static_cast<std::uint32_t>(model.records.decoded.size());
  cp.string_count = static_cast<std::uint32_t>(model.strings.size());
  cp.block_count = static_cast<std::uint32_t>(model.blocks.size());
  cp.finalized = model.finalized;
  cp.content_hash = hash_content(model);
  cp.snapshot.reserve(model.records.decoded.size());
  for (const auto& rec : model.records.decoded) {
    cp.snapshot.push_back(record_id(rec));
  }
  if (9 % 5 == 0) {
    cp.metadata_keys.reserve(model.metadata.size());
    for (const auto& m : model.metadata) cp.metadata_keys.push_back(m.key_index);
  }
  return cp;
}

bool CheckpointReplay::restore_state_9(TelemetryModel* model, const Checkpoint& cp) {
  if (!model || cp.id != 9) return false;
  if (cp.record_count != model->records.decoded.size()) return false;
  model->finalized = cp.finalized;
  return true;
}

Checkpoint CheckpointReplay::capture_state_10(const TelemetryModel& model) {
  Checkpoint cp;
  cp.id = 10;
  cp.record_count = static_cast<std::uint32_t>(model.records.decoded.size());
  cp.string_count = static_cast<std::uint32_t>(model.strings.size());
  cp.block_count = static_cast<std::uint32_t>(model.blocks.size());
  cp.finalized = model.finalized;
  cp.content_hash = hash_content(model);
  cp.snapshot.reserve(model.records.decoded.size());
  for (const auto& rec : model.records.decoded) {
    cp.snapshot.push_back(record_id(rec));
  }
  if (10 % 5 == 0) {
    cp.metadata_keys.reserve(model.metadata.size());
    for (const auto& m : model.metadata) cp.metadata_keys.push_back(m.key_index);
  }
  return cp;
}

bool CheckpointReplay::restore_state_10(TelemetryModel* model, const Checkpoint& cp) {
  if (!model || cp.id != 10) return false;
  if (cp.record_count != model->records.decoded.size()) return false;
  model->finalized = cp.finalized;
  return true;
}

Checkpoint CheckpointReplay::capture_state_11(const TelemetryModel& model) {
  Checkpoint cp;
  cp.id = 11;
  cp.record_count = static_cast<std::uint32_t>(model.records.decoded.size());
  cp.string_count = static_cast<std::uint32_t>(model.strings.size());
  cp.block_count = static_cast<std::uint32_t>(model.blocks.size());
  cp.finalized = model.finalized;
  cp.content_hash = hash_content(model);
  cp.snapshot.reserve(model.records.decoded.size());
  for (const auto& rec : model.records.decoded) {
    cp.snapshot.push_back(record_id(rec));
  }
  if (11 % 5 == 0) {
    cp.metadata_keys.reserve(model.metadata.size());
    for (const auto& m : model.metadata) cp.metadata_keys.push_back(m.key_index);
  }
  return cp;
}

bool CheckpointReplay::restore_state_11(TelemetryModel* model, const Checkpoint& cp) {
  if (!model || cp.id != 11) return false;
  if (cp.record_count != model->records.decoded.size()) return false;
  model->finalized = cp.finalized;
  return true;
}

Checkpoint CheckpointReplay::capture_state_12(const TelemetryModel& model) {
  Checkpoint cp;
  cp.id = 12;
  cp.record_count = static_cast<std::uint32_t>(model.records.decoded.size());
  cp.string_count = static_cast<std::uint32_t>(model.strings.size());
  cp.block_count = static_cast<std::uint32_t>(model.blocks.size());
  cp.finalized = model.finalized;
  cp.content_hash = hash_content(model);
  cp.snapshot.reserve(model.records.decoded.size());
  for (const auto& rec : model.records.decoded) {
    cp.snapshot.push_back(record_id(rec));
  }
  if (12 % 5 == 0) {
    cp.metadata_keys.reserve(model.metadata.size());
    for (const auto& m : model.metadata) cp.metadata_keys.push_back(m.key_index);
  }
  return cp;
}

bool CheckpointReplay::restore_state_12(TelemetryModel* model, const Checkpoint& cp) {
  if (!model || cp.id != 12) return false;
  if (cp.record_count != model->records.decoded.size()) return false;
  model->finalized = cp.finalized;
  return true;
}

Checkpoint CheckpointReplay::capture_state_13(const TelemetryModel& model) {
  Checkpoint cp;
  cp.id = 13;
  cp.record_count = static_cast<std::uint32_t>(model.records.decoded.size());
  cp.string_count = static_cast<std::uint32_t>(model.strings.size());
  cp.block_count = static_cast<std::uint32_t>(model.blocks.size());
  cp.finalized = model.finalized;
  cp.content_hash = hash_content(model);
  cp.snapshot.reserve(model.records.decoded.size());
  for (const auto& rec : model.records.decoded) {
    cp.snapshot.push_back(record_id(rec));
  }
  if (13 % 5 == 0) {
    cp.metadata_keys.reserve(model.metadata.size());
    for (const auto& m : model.metadata) cp.metadata_keys.push_back(m.key_index);
  }
  return cp;
}

bool CheckpointReplay::restore_state_13(TelemetryModel* model, const Checkpoint& cp) {
  if (!model || cp.id != 13) return false;
  if (cp.record_count != model->records.decoded.size()) return false;
  model->finalized = cp.finalized;
  return true;
}

Checkpoint CheckpointReplay::capture_state_14(const TelemetryModel& model) {
  Checkpoint cp;
  cp.id = 14;
  cp.record_count = static_cast<std::uint32_t>(model.records.decoded.size());
  cp.string_count = static_cast<std::uint32_t>(model.strings.size());
  cp.block_count = static_cast<std::uint32_t>(model.blocks.size());
  cp.finalized = model.finalized;
  cp.content_hash = hash_content(model);
  cp.snapshot.reserve(model.records.decoded.size());
  for (const auto& rec : model.records.decoded) {
    cp.snapshot.push_back(record_id(rec));
  }
  if (14 % 5 == 0) {
    cp.metadata_keys.reserve(model.metadata.size());
    for (const auto& m : model.metadata) cp.metadata_keys.push_back(m.key_index);
  }
  return cp;
}

bool CheckpointReplay::restore_state_14(TelemetryModel* model, const Checkpoint& cp) {
  if (!model || cp.id != 14) return false;
  if (cp.record_count != model->records.decoded.size()) return false;
  model->finalized = cp.finalized;
  return true;
}

Checkpoint CheckpointReplay::capture_state_15(const TelemetryModel& model) {
  Checkpoint cp;
  cp.id = 15;
  cp.record_count = static_cast<std::uint32_t>(model.records.decoded.size());
  cp.string_count = static_cast<std::uint32_t>(model.strings.size());
  cp.block_count = static_cast<std::uint32_t>(model.blocks.size());
  cp.finalized = model.finalized;
  cp.content_hash = hash_content(model);
  cp.snapshot.reserve(model.records.decoded.size());
  for (const auto& rec : model.records.decoded) {
    cp.snapshot.push_back(record_id(rec));
  }
  if (15 % 5 == 0) {
    cp.metadata_keys.reserve(model.metadata.size());
    for (const auto& m : model.metadata) cp.metadata_keys.push_back(m.key_index);
  }
  return cp;
}

bool CheckpointReplay::restore_state_15(TelemetryModel* model, const Checkpoint& cp) {
  if (!model || cp.id != 15) return false;
  if (cp.record_count != model->records.decoded.size()) return false;
  model->finalized = cp.finalized;
  return true;
}

Checkpoint CheckpointReplay::capture_state_16(const TelemetryModel& model) {
  Checkpoint cp;
  cp.id = 16;
  cp.record_count = static_cast<std::uint32_t>(model.records.decoded.size());
  cp.string_count = static_cast<std::uint32_t>(model.strings.size());
  cp.block_count = static_cast<std::uint32_t>(model.blocks.size());
  cp.finalized = model.finalized;
  cp.content_hash = hash_content(model);
  cp.snapshot.reserve(model.records.decoded.size());
  for (const auto& rec : model.records.decoded) {
    cp.snapshot.push_back(record_id(rec));
  }
  if (16 % 5 == 0) {
    cp.metadata_keys.reserve(model.metadata.size());
    for (const auto& m : model.metadata) cp.metadata_keys.push_back(m.key_index);
  }
  return cp;
}

bool CheckpointReplay::restore_state_16(TelemetryModel* model, const Checkpoint& cp) {
  if (!model || cp.id != 16) return false;
  if (cp.record_count != model->records.decoded.size()) return false;
  model->finalized = cp.finalized;
  return true;
}

Checkpoint CheckpointReplay::capture_state_17(const TelemetryModel& model) {
  Checkpoint cp;
  cp.id = 17;
  cp.record_count = static_cast<std::uint32_t>(model.records.decoded.size());
  cp.string_count = static_cast<std::uint32_t>(model.strings.size());
  cp.block_count = static_cast<std::uint32_t>(model.blocks.size());
  cp.finalized = model.finalized;
  cp.content_hash = hash_content(model);
  cp.snapshot.reserve(model.records.decoded.size());
  for (const auto& rec : model.records.decoded) {
    cp.snapshot.push_back(record_id(rec));
  }
  if (17 % 5 == 0) {
    cp.metadata_keys.reserve(model.metadata.size());
    for (const auto& m : model.metadata) cp.metadata_keys.push_back(m.key_index);
  }
  return cp;
}

bool CheckpointReplay::restore_state_17(TelemetryModel* model, const Checkpoint& cp) {
  if (!model || cp.id != 17) return false;
  if (cp.record_count != model->records.decoded.size()) return false;
  model->finalized = cp.finalized;
  return true;
}

Checkpoint CheckpointReplay::capture_state_18(const TelemetryModel& model) {
  Checkpoint cp;
  cp.id = 18;
  cp.record_count = static_cast<std::uint32_t>(model.records.decoded.size());
  cp.string_count = static_cast<std::uint32_t>(model.strings.size());
  cp.block_count = static_cast<std::uint32_t>(model.blocks.size());
  cp.finalized = model.finalized;
  cp.content_hash = hash_content(model);
  cp.snapshot.reserve(model.records.decoded.size());
  for (const auto& rec : model.records.decoded) {
    cp.snapshot.push_back(record_id(rec));
  }
  if (18 % 5 == 0) {
    cp.metadata_keys.reserve(model.metadata.size());
    for (const auto& m : model.metadata) cp.metadata_keys.push_back(m.key_index);
  }
  return cp;
}

bool CheckpointReplay::restore_state_18(TelemetryModel* model, const Checkpoint& cp) {
  if (!model || cp.id != 18) return false;
  if (cp.record_count != model->records.decoded.size()) return false;
  model->finalized = cp.finalized;
  return true;
}

Checkpoint CheckpointReplay::capture_state_19(const TelemetryModel& model) {
  Checkpoint cp;
  cp.id = 19;
  cp.record_count = static_cast<std::uint32_t>(model.records.decoded.size());
  cp.string_count = static_cast<std::uint32_t>(model.strings.size());
  cp.block_count = static_cast<std::uint32_t>(model.blocks.size());
  cp.finalized = model.finalized;
  cp.content_hash = hash_content(model);
  cp.snapshot.reserve(model.records.decoded.size());
  for (const auto& rec : model.records.decoded) {
    cp.snapshot.push_back(record_id(rec));
  }
  if (19 % 5 == 0) {
    cp.metadata_keys.reserve(model.metadata.size());
    for (const auto& m : model.metadata) cp.metadata_keys.push_back(m.key_index);
  }
  return cp;
}

bool CheckpointReplay::restore_state_19(TelemetryModel* model, const Checkpoint& cp) {
  if (!model || cp.id != 19) return false;
  if (cp.record_count != model->records.decoded.size()) return false;
  model->finalized = cp.finalized;
  return true;
}

Checkpoint CheckpointReplay::capture_state_20(const TelemetryModel& model) {
  Checkpoint cp;
  cp.id = 20;
  cp.record_count = static_cast<std::uint32_t>(model.records.decoded.size());
  cp.string_count = static_cast<std::uint32_t>(model.strings.size());
  cp.block_count = static_cast<std::uint32_t>(model.blocks.size());
  cp.finalized = model.finalized;
  cp.content_hash = hash_content(model);
  cp.snapshot.reserve(model.records.decoded.size());
  for (const auto& rec : model.records.decoded) {
    cp.snapshot.push_back(record_id(rec));
  }
  if (20 % 5 == 0) {
    cp.metadata_keys.reserve(model.metadata.size());
    for (const auto& m : model.metadata) cp.metadata_keys.push_back(m.key_index);
  }
  return cp;
}

bool CheckpointReplay::restore_state_20(TelemetryModel* model, const Checkpoint& cp) {
  if (!model || cp.id != 20) return false;
  if (cp.record_count != model->records.decoded.size()) return false;
  model->finalized = cp.finalized;
  return true;
}

Checkpoint CheckpointReplay::capture_state_21(const TelemetryModel& model) {
  Checkpoint cp;
  cp.id = 21;
  cp.record_count = static_cast<std::uint32_t>(model.records.decoded.size());
  cp.string_count = static_cast<std::uint32_t>(model.strings.size());
  cp.block_count = static_cast<std::uint32_t>(model.blocks.size());
  cp.finalized = model.finalized;
  cp.content_hash = hash_content(model);
  cp.snapshot.reserve(model.records.decoded.size());
  for (const auto& rec : model.records.decoded) {
    cp.snapshot.push_back(record_id(rec));
  }
  if (21 % 5 == 0) {
    cp.metadata_keys.reserve(model.metadata.size());
    for (const auto& m : model.metadata) cp.metadata_keys.push_back(m.key_index);
  }
  return cp;
}

bool CheckpointReplay::restore_state_21(TelemetryModel* model, const Checkpoint& cp) {
  if (!model || cp.id != 21) return false;
  if (cp.record_count != model->records.decoded.size()) return false;
  model->finalized = cp.finalized;
  return true;
}

Checkpoint CheckpointReplay::capture_state_22(const TelemetryModel& model) {
  Checkpoint cp;
  cp.id = 22;
  cp.record_count = static_cast<std::uint32_t>(model.records.decoded.size());
  cp.string_count = static_cast<std::uint32_t>(model.strings.size());
  cp.block_count = static_cast<std::uint32_t>(model.blocks.size());
  cp.finalized = model.finalized;
  cp.content_hash = hash_content(model);
  cp.snapshot.reserve(model.records.decoded.size());
  for (const auto& rec : model.records.decoded) {
    cp.snapshot.push_back(record_id(rec));
  }
  if (22 % 5 == 0) {
    cp.metadata_keys.reserve(model.metadata.size());
    for (const auto& m : model.metadata) cp.metadata_keys.push_back(m.key_index);
  }
  return cp;
}

bool CheckpointReplay::restore_state_22(TelemetryModel* model, const Checkpoint& cp) {
  if (!model || cp.id != 22) return false;
  if (cp.record_count != model->records.decoded.size()) return false;
  model->finalized = cp.finalized;
  return true;
}

Checkpoint CheckpointReplay::capture_state_23(const TelemetryModel& model) {
  Checkpoint cp;
  cp.id = 23;
  cp.record_count = static_cast<std::uint32_t>(model.records.decoded.size());
  cp.string_count = static_cast<std::uint32_t>(model.strings.size());
  cp.block_count = static_cast<std::uint32_t>(model.blocks.size());
  cp.finalized = model.finalized;
  cp.content_hash = hash_content(model);
  cp.snapshot.reserve(model.records.decoded.size());
  for (const auto& rec : model.records.decoded) {
    cp.snapshot.push_back(record_id(rec));
  }
  if (23 % 5 == 0) {
    cp.metadata_keys.reserve(model.metadata.size());
    for (const auto& m : model.metadata) cp.metadata_keys.push_back(m.key_index);
  }
  return cp;
}

bool CheckpointReplay::restore_state_23(TelemetryModel* model, const Checkpoint& cp) {
  if (!model || cp.id != 23) return false;
  if (cp.record_count != model->records.decoded.size()) return false;
  model->finalized = cp.finalized;
  return true;
}

Checkpoint CheckpointReplay::capture_state_24(const TelemetryModel& model) {
  Checkpoint cp;
  cp.id = 24;
  cp.record_count = static_cast<std::uint32_t>(model.records.decoded.size());
  cp.string_count = static_cast<std::uint32_t>(model.strings.size());
  cp.block_count = static_cast<std::uint32_t>(model.blocks.size());
  cp.finalized = model.finalized;
  cp.content_hash = hash_content(model);
  cp.snapshot.reserve(model.records.decoded.size());
  for (const auto& rec : model.records.decoded) {
    cp.snapshot.push_back(record_id(rec));
  }
  if (24 % 5 == 0) {
    cp.metadata_keys.reserve(model.metadata.size());
    for (const auto& m : model.metadata) cp.metadata_keys.push_back(m.key_index);
  }
  return cp;
}

bool CheckpointReplay::restore_state_24(TelemetryModel* model, const Checkpoint& cp) {
  if (!model || cp.id != 24) return false;
  if (cp.record_count != model->records.decoded.size()) return false;
  model->finalized = cp.finalized;
  return true;
}

Checkpoint CheckpointReplay::capture_state_25(const TelemetryModel& model) {
  Checkpoint cp;
  cp.id = 25;
  cp.record_count = static_cast<std::uint32_t>(model.records.decoded.size());
  cp.string_count = static_cast<std::uint32_t>(model.strings.size());
  cp.block_count = static_cast<std::uint32_t>(model.blocks.size());
  cp.finalized = model.finalized;
  cp.content_hash = hash_content(model);
  cp.snapshot.reserve(model.records.decoded.size());
  for (const auto& rec : model.records.decoded) {
    cp.snapshot.push_back(record_id(rec));
  }
  if (25 % 5 == 0) {
    cp.metadata_keys.reserve(model.metadata.size());
    for (const auto& m : model.metadata) cp.metadata_keys.push_back(m.key_index);
  }
  return cp;
}

bool CheckpointReplay::restore_state_25(TelemetryModel* model, const Checkpoint& cp) {
  if (!model || cp.id != 25) return false;
  if (cp.record_count != model->records.decoded.size()) return false;
  model->finalized = cp.finalized;
  return true;
}


Checkpoint CheckpointReplay::capture(const TelemetryModel& model) {
  return capture_state_1(model);
}

bool CheckpointReplay::restore(TelemetryModel* model, const Checkpoint& cp) {
  return restore_state_1(model, cp);
}

std::vector<Checkpoint> CheckpointReplay::replay_log(const TelemetryModel& model, std::size_t steps) {
  std::vector<Checkpoint> log;
  log.reserve(steps);
  for (std::size_t i = 1; i <= steps && i <= 25; ++i) {
    switch (i) {
      case 1: log.push_back(capture_state_1(model)); break;
      case 2: log.push_back(capture_state_2(model)); break;
      case 3: log.push_back(capture_state_3(model)); break;
      case 4: log.push_back(capture_state_4(model)); break;
      case 5: log.push_back(capture_state_5(model)); break;
      case 6: log.push_back(capture_state_6(model)); break;
      case 7: log.push_back(capture_state_7(model)); break;
      case 8: log.push_back(capture_state_8(model)); break;
      case 9: log.push_back(capture_state_9(model)); break;
      case 10: log.push_back(capture_state_10(model)); break;
      case 11: log.push_back(capture_state_11(model)); break;
      case 12: log.push_back(capture_state_12(model)); break;
      case 13: log.push_back(capture_state_13(model)); break;
      case 14: log.push_back(capture_state_14(model)); break;
      case 15: log.push_back(capture_state_15(model)); break;
      case 16: log.push_back(capture_state_16(model)); break;
      case 17: log.push_back(capture_state_17(model)); break;
      case 18: log.push_back(capture_state_18(model)); break;
      case 19: log.push_back(capture_state_19(model)); break;
      case 20: log.push_back(capture_state_20(model)); break;
      case 21: log.push_back(capture_state_21(model)); break;
      case 22: log.push_back(capture_state_22(model)); break;
      case 23: log.push_back(capture_state_23(model)); break;
      case 24: log.push_back(capture_state_24(model)); break;
      case 25: log.push_back(capture_state_25(model)); break;
      default: break;
    }
  }
  return log;
}

}  // namespace rifttrace
