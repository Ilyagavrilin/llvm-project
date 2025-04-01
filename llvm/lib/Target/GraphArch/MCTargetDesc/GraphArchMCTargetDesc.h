#ifndef LLVM_LIB_TARGET_GRAPHARCH_MCTARGETDESC_GRAPHARCHMCTARGETDESC_H
#define LLVM_LIB_TARGET_GRAPHARCH_MCTARGETDESC_GRAPHARCHMCTARGETDESC_H

// Defines symbolic names for GraphArch registers.  This defines a mapping from
// register name to register number.
//
#define GET_REGINFO_ENUM
#include "GraphArchGenRegisterInfo.inc"

// Defines symbolic names for the GraphArch instructions.
#define GET_INSTRINFO_ENUM
#include "GraphArchGenInstrInfo.inc"


#endif // LLVM_LIB_TARGET_GRAPHARCH_MCTARGETDESC_GRAPHARCHMCTARGETDESC_H