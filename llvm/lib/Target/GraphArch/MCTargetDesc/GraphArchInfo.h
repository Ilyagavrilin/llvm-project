#ifndef LLVM_LIB_TARGET_SIM_MCTARGETDESC_SIMINFO_H
#define LLVM_LIB_TARGET_SIM_MCTARGETDESC_SIMINFO_H

#include "llvm/MC/MCInstrDesc.h"

namespace llvm {

namespace GraphArchOp {
enum OperandType : unsigned {
    OPERAND_GRAPHARCHM16 = MCOI::OPERAND_FIRST_TARGET,
};
} // namespace GraphArchOp

} // end namespace llvm

#endif