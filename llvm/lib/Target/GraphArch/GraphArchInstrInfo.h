#ifndef LLVM_LIB_TARGET_SIM_SIMINSTRINFO_H
#define LLVM_LIB_TARGET_SIM_SIMINSTRINFO_H

#include "GraphArchRegisterInfo.h"
#include "MCTargetDesc/GraphArchInfo.h"
#include "llvm/CodeGen/TargetInstrInfo.h"

#define GET_INSTRINFO_HEADER
#include "GraphArchGenInstrInfo.inc"

namespace llvm {

class GraphArchSubtarget;

class GraphArchInstrInfo : public GraphArchGenInstrInfo {
public:
    GraphArchInstrInfo();

};

} // end namespace llvm

#endif // LLVM_LIB_TARGET_SIM_SIMINSTRINFO_H