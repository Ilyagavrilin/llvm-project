#include "TargetInfo/GraphArchTargetInfo.h"
#include "llvm/MC/TargetRegistry.h"
using namespace llvm;

Target &llvm::getTheGraphArchTarget() {
  static Target TheGraphArchTarget;
  return TheGraphArchTarget;
}

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeGraphArchTargetInfo() {
  // Register the GraphArch target info with its triple identifier.
  RegisterTarget<Triple::grapharch> X(getTheGraphArchTarget(), "grapharch", "GraphArch 32: simple arch for graphic applications", "GRAPHARCH");
}