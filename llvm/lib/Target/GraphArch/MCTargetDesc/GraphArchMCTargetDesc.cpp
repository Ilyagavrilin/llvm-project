#include "GraphArch.h"
#include "TargetInfo/GraphArchTargetInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/TargetRegistry.h"

using namespace llvm;

#define GET_REGINFO_MC_DESC
#include "GraphArchGenRegisterInfo.inc"

static MCRegisterInfo *createGraphArchMCRegisterInfo(const Triple &TT) {
    COLOR_DUMP_MAGENTA
    MCRegisterInfo *X = new MCRegisterInfo();
    InitGraphArchMCRegisterInfo(X, GraphArch::X0);
    return X;
}

// Define this function so that linking succeeds.
extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeGraphArchTargetMC() {
    COLOR_DUMP_MAGENTA
    Target &TheGraphArchTarget = getTheGraphArchTarget();
    // Register the MC register info.
    TargetRegistry::RegisterMCRegInfo(TheGraphArchTarget, createGraphArchMCRegisterInfo);
  }