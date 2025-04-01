#include "GraphArchISelLowering.h"
#include "GraphArch.h"
#include "GraphArchRegisterInfo.h"
#include "GraphArchSubtarget.h"
#include "llvm/CodeGen/CallingConvLower.h"
#include "llvm/CodeGen/MachineFunction.h"

#define DEBUG_TYPE "GraphArch-lower"

using namespace llvm;

GraphArchTargetLowering::GraphArchTargetLowering(const TargetMachine &TM,
                                    const GraphArchSubtarget &STI)
    : TargetLowering(TM), STI(STI) {
    COLOR_DUMP_RED
    addRegisterClass(MVT::i32, &GraphArch::GPRRegClass);
}

const char *GraphArchTargetLowering::getTargetNodeName(unsigned Opcode) const {
    COLOR_DUMP_RED
    switch (Opcode) {
    case GraphArchISD::CALL:
        return "GraphArchISD::CALL";
    case GraphArchISD::RET:
        return "GraphArchISD::RET";
    }
    return nullptr;
}