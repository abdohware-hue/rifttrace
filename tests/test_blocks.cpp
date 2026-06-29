// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT

#include "rifttrace/rifttrace.hpp"

#include <cassert>
#include <vector>

int main() {
  const std::vector<std::uint8_t> payload = {'a', 'b', 'a', 'a', 'a', 'c', 'c', 'c', 'c'};
  const auto encoded = rifttrace::BlockEncoder::encode_block_1(
      payload.data(), payload.size(), rifttrace::BlockCodec::kSimpleRle);
  assert(encoded.compressed_size > 0);
  assert(encoded.uncompressed_size == payload.size());

  const auto section = rifttrace::BlockEncoder::serialize_section({encoded});
  assert(!section.empty());

  const auto delta = rifttrace::DeltaCodec::encode_auto(payload.data(), payload.size());
  assert(!delta.empty());
  const auto restored = rifttrace::DeltaCodec::decode_auto(
      delta.data(), delta.size(), payload.size());
  assert(restored == payload);

  const auto dict = rifttrace::DictionaryCodec::compress(payload.data(), payload.size());
  const auto dict_out = rifttrace::DictionaryCodec::decompress(
      dict.data(), dict.size(), payload.size());
  assert(dict_out == payload);

  const auto trans = rifttrace::CodecRegistry::transcode(
      rifttrace::BlockCodec::kRaw, rifttrace::BlockCodec::kSimpleRle, payload.data(),
      payload.size());
  assert(!trans.empty());
  return 0;
}
