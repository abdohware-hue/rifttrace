// Copyright (c) 2026 abdohware
// SPDX-License-Identifier: MIT

#include "rifttrace/rifttrace.hpp"

#include <cassert>
#include <vector>

int main() {
  rifttrace::StringTable table;
  const auto a = table.intern("alpha.sensor");
  const auto b = table.intern("beta.sensor");
  const auto c = table.intern("alpha.sensor");
  assert(a == c);
  assert(a != b);
  assert(table.size() == 2);

  const auto bytes = table.serialize();
  const auto parsed = rifttrace::StringTable::parse(bytes.data(), bytes.size());
  assert(parsed.size() == 2);
  assert(parsed.get(a) == "alpha.sensor");

  table.compact();
  assert(table.get(a) == "alpha.sensor");

  rifttrace::SymbolTable symbols;
  symbols.rebuild_from_strings(table.storage());
  assert(!symbols.resolve(0).empty());
  return 0;
}
