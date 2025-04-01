#include "GraphArchSubtarget.h"
#include "GraphArch.h"
#include "llvm/Target/TargetMachine.h"

using namespace llvm;

#define DEBUG_TYPE "sim-subtarget"

#define GET_SUBTARGETINFO_TARGET_DESC
#define GET_SUBTARGETINFO_CTOR
#include "GraphArchGenSubtargetInfo.inc"

GraphArchSubtarget::GraphArchSubtarget(const StringRef &CPU, const StringRef &TuneCPU,
                        const StringRef &FS, const TargetMachine &TM)
    : GraphArchGenSubtargetInfo(TM.getTargetTriple(), CPU, TuneCPU, FS) {
    COLOR_DUMP_CYAN
}