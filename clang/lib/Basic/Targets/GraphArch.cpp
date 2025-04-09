#include "GraphArch.h"
#include "clang/Basic/Builtins.h"
#include "clang/Basic/MacroBuilder.h"

using namespace clang;
using namespace clang::targets;

void GraphArchTargetInfo::getTargetDefines(const LangOptions &Opts,
                                     MacroBuilder &Builder) const {
  Builder.defineMacro("__grapharch__");
}
ArrayRef<Builtin::Info> GraphArchTargetInfo::getTargetBuiltins() const {
  return std::nullopt;
}