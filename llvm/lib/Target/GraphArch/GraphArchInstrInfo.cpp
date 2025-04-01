#include "GraphArchInstrInfo.h"
#include "GraphArch.h"
#include "llvm/CodeGen/MachineFrameInfo.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/CodeGen/MachineMemOperand.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Support/Debug.h"
#include "llvm/Support/ErrorHandling.h"

using namespace llvm;

#define GET_INSTRINFO_CTOR_DTOR
#include "GraphArchGenInstrInfo.inc"

#define DEBUG_TYPE "GraphArch-inst-info"

GraphArchInstrInfo::GraphArchInstrInfo() : GraphArchGenInstrInfo() { COLOR_DUMP_GREEN }