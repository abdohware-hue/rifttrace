// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT

#pragma once

#include <stdexcept>
#include <string>

namespace rifttrace {

enum class ErrorCode {
  kOk = 0,
  kTruncated,
  kBadMagic,
  kUnsupportedVersion,
  kInvalidSection,
  kInvalidRecord,
  kInvalidBlock,
  kInvalidStream,
  kInvalidReference,
  kChecksumMismatch,
};

class ParseError : public std::runtime_error {
 public:
  ParseError(ErrorCode code, const std::string& message)
      : std::runtime_error(message), code_(code) {}

  ErrorCode code() const noexcept { return code_; }

 private:
  ErrorCode code_;
};

}  // namespace rifttrace
