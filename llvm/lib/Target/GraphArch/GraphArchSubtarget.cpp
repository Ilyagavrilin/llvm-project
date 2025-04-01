#include "GraphArchSubtarget.h"
#include "GraphArch.h"
#include "llvm/Target/TargetMachine.h"

using namespace llvm;

#define DEBUG_TYPE "sim-subtarget"

#define GET_SUBTARGETINFO_TARGET_DESC
#define GET_SUBTARGETINFO_CTOR
#include "GraphArchGenSubtargetInfo.inc"

GraphArchSubtarget::GraphArchSubtarget(const Triple &TT, const std::string &CPU,
                        const std::string &FS, const TargetMachine &TM)
    : GraphArchGenSubtargetInfo(TT, CPU, /*TuneCPU=*/CPU, FS), TLInfo(TM, *this) {
    COLOR_DUMP_CYAN
}