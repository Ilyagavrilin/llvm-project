#include "GraphArchRegisterInfo.h"
#include "GraphArch.h"
#include "GraphArchFrameLowering.h"
#include "llvm/CodeGen/TargetInstrInfo.h"

using namespace llvm;

#define GET_REGINFO_TARGET_DESC
#include "GraphArchGenRegisterInfo.inc"

GraphArchRegisterInfo::GraphArchRegisterInfo() : GraphArchGenRegisterInfo(GraphArch::X0) {
    COLOR_DUMP_GREEN
}