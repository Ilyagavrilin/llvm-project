#include "MCTargetDesc/GraphArchInstPrinter.h"
#include "GraphArch.h"
#include "GraphArchSubtarget.h"
#include "GraphArchTargetMachine.h"
#include "TargetInfo/GraphArchTargetInfo.h"
#include "llvm/ADT/Statistic.h"
#include "llvm/CodeGen/AsmPrinter.h"
#include "llvm/CodeGen/MachineConstantPool.h"
#include "llvm/CodeGen/MachineFunctionPass.h"
#include "llvm/CodeGen/MachineInstr.h"
#include "llvm/CodeGen/MachineModuleInfo.h"
#include "llvm/MC/MCAsmInfo.h"
#include "llvm/MC/MCInst.h"
#include "llvm/MC/MCStreamer.h"
#include "llvm/MC/MCSymbol.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Support/ErrorHandling.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

#define DEBUG_TYPE "asm-printer"

namespace {

class GraphArchAsmPrinter : public AsmPrinter {
const MCSubtargetInfo *STI;

public:
explicit GraphArchAsmPrinter(TargetMachine &TM,
                        std::unique_ptr<MCStreamer> Streamer)
    : AsmPrinter(TM, std::move(Streamer)), STI(TM.getMCSubtargetInfo()) {
    COLOR_DUMP_GREEN
}

void emitInstruction(const MachineInstr *MI) override;

StringRef getPassName() const override { return "GraphArch Assembly Printer"; }

bool lowerPseudoInstExpansion(const MachineInstr *MI, MCInst &Inst);

// Used in pseudo lowerings
bool lowerOperand(const MachineOperand &MO, MCOperand &MCOp) const {
    return LowerGraphArchMachineOperandToMCOperand(MO, MCOp, *this);
}
};

} // end anonymous namespace

// GraphArchple pseudo-instructions have their lowering (with expansion to real
// instructions) auto-generated.
#include "GraphArchGenMCPseudoLowering.inc"

void GraphArchAsmPrinter::emitInstruction(const MachineInstr *MI) {
COLOR_DUMP_GREEN
// Do any auto-generated pseudo lowerings.
if (MCInst OutInst; lowerPseudoInstExpansion(MI, OutInst)) {
    EmitToStreamer(*OutStreamer, OutInst);
    return;
}
    MCInst TmpInst;
    if (!lowerGraphArchMachineInstrToMCInst(MI, TmpInst, *this))
    EmitToStreamer(*OutStreamer, TmpInst);
}

// Force static initialization.
extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeGraphArchAsmPrinter() {
RegisterAsmPrinter<GraphArchAsmPrinter> X(getTheGraphArchTarget());
}