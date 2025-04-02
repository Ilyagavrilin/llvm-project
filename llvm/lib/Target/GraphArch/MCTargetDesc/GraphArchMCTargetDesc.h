#ifndef LLVM_LIB_TARGET_GRAPHARCH_MCTARGETDESC_GRAPHARCHMCTARGETDESC_H
#define LLVM_LIB_TARGET_GRAPHARCH_MCTARGETDESC_GRAPHARCHMCTARGETDESC_H

namespace llvm {
class MCCodeEmitter;
class MCContext;
class MCInstrInfo;
class MCAsmBackend;
class MCObjectTargetWriter;
class MCRegisterInfo;
class MCSubtargetInfo;
class MCTargetOptions;
class Target;

MCCodeEmitter *createGraphArchMCCodeEmitter(const MCInstrInfo &MCII, MCContext &Ctx);

MCAsmBackend *createGraphArchAsmBackend(const Target &T, const MCSubtargetInfo &STI,
    const MCRegisterInfo &MRI,
    const MCTargetOptions &Options);
}
// Defines symbolic names for GraphArch registers.  This defines a mapping from
// register name to register number.
//
#define GET_REGINFO_ENUM
#include "GraphArchGenRegisterInfo.inc"

// Defines symbolic names for the GraphArch instructions.
#define GET_INSTRINFO_ENUM
#include "GraphArchGenInstrInfo.inc"


#endif // LLVM_LIB_TARGET_GRAPHARCH_MCTARGETDESC_GRAPHARCHMCTARGETDESC_H