#pragma once

//
// This file is distributed under the MIT License. See LICENSE.md for details.
//

#include "llvm/ADT/StringRef.h"
#include "llvm/Support/YAMLTraits.h"

#include "revng/Support/Assert.h"

namespace model::abi {

enum Values { Invalid, SystemV_x86_64, Count };

inline llvm::StringRef getName(Values V) {
  switch (V) {
  case Invalid:
    return "Invalid";
  case SystemV_x86_64:
    return "SystemV_x86_64";
  default:
    revng_abort();
  }
  revng_abort();
}

} // namespace model::abi

namespace llvm::yaml {

template<>
struct ScalarEnumerationTraits<model::abi::Values> {
  template<typename IOType>
  static void enumeration(IOType &IO, model::abi::Values &Val) {
    using namespace model::abi;
    for (unsigned I = 0; I < Count; ++I) {
      auto V = static_cast<Values>(I);
      IO.enumCase(Val, getName(V).data(), V);
    }
  }
};

} // namespace llvm::yaml
