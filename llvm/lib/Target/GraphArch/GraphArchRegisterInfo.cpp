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
const MCPhysReg *
GraphArchRegisterInfo::getCalleeSavedRegs(const MachineFunction *MF) const {
    COLOR_DUMP_GREEN
    return CSR_GraphArch_SaveList;
}

BitVector GraphArchRegisterInfo::getReservedRegs(const MachineFunction &MF) const {
    COLOR_DUMP_GREEN
    GraphArchFrameLowering const *TFI = getFrameLowering(MF);

    BitVector Reserved(getNumRegs());
    Reserved.set(GraphArch::X1);

    if (TFI->hasFP(MF)) {
    Reserved.set(GraphArch::X2);
    }
    return Reserved;
}

bool GraphArchRegisterInfo::requiresRegisterScavenging(
     const MachineFunction &MF) const {
    return false;
}

bool GraphArchRegisterInfo::eliminateFrameIndex(MachineBasicBlock::iterator II,
                                        int SPAdj, unsigned FIOperandNum,
                                        RegScavenger *RS) const {
    COLOR_DUMP_GREEN
    assert(SPAdj == 0 && "Unexpected non-zero SPAdj value");

    MachineInstr &MI = *II;
    MachineFunction &MF = *MI.getParent()->getParent();
    DebugLoc DL = MI.getDebugLoc();

    int FrameIndex = MI.getOperand(FIOperandNum).getIndex();
    Register FrameReg;
    int Offset = getFrameLowering(MF)
                    ->getFrameIndexReference(MF, FrameIndex, FrameReg)
                    .getFixed();
    Offset += MI.getOperand(FIOperandNum + 1).getImm();

    if (!isInt<16>(Offset)) {
        llvm_unreachable("");
    }

    MI.getOperand(FIOperandNum).ChangeToRegister(FrameReg, false, false, false);
    MI.getOperand(FIOperandNum + 1).ChangeToImmediate(Offset);
    return false;
}

Register GraphArchRegisterInfo::getFrameRegister(const MachineFunction &MF) const {
    COLOR_DUMP_GREEN
    const TargetFrameLowering *TFI = getFrameLowering(MF);
    return TFI->hasFP(MF) ? GraphArch::X2 : GraphArch::X1;
}

const uint32_t *
GraphArchRegisterInfo::getCallPreservedMask(const MachineFunction &MF,
                                    CallingConv::ID CC) const {
    COLOR_DUMP_GREEN
    return CSR_GraphArch_RegMask;
}