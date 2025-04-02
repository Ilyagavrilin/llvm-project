#include "MCTargetDesc/GraphArchInfo.h"
#include "GraphArch.h"
#include "GraphArchInstPrinter.h"
#include "GraphArchMCAsmInfo.h"
#include "TargetInfo/GraphArchTargetInfo.h"
#include "llvm/MC/MCDwarf.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Support/ErrorHandling.h"

using namespace llvm;

#define GET_REGINFO_MC_DESC
#include "GraphArchGenRegisterInfo.inc"

#define GET_INSTRINFO_MC_DESC
#include "GraphArchGenInstrInfo.inc"

#define GET_SUBTARGETINFO_MC_DESC
#include "GraphArchGenSubtargetInfo.inc"

static MCRegisterInfo *createGraphArchMCRegisterInfo(const Triple &TT) {
    COLOR_DUMP_MAGENTA
    MCRegisterInfo *X = new MCRegisterInfo();
    InitGraphArchMCRegisterInfo(X, GraphArch::X0);
    return X;
}

static MCInstrInfo *createGraphArchMCInstrInfo() {
    COLOR_DUMP_MAGENTA
    MCInstrInfo *X = new MCInstrInfo();
    InitGraphArchMCInstrInfo(X);
    return X;
}

static MCSubtargetInfo *createGraphArchMCSubtargetInfo(const Triple &TT,
    StringRef CPU, StringRef FS) {
    COLOR_DUMP_MAGENTA
    return createGraphArchMCSubtargetInfoImpl(TT, CPU, /*TuneCPU*/ CPU, FS);
}

static MCAsmInfo *createGraphArchMCAsmInfo(const MCRegisterInfo &MRI,
    const Triple &TT,
    const MCTargetOptions &Options) {
    COLOR_DUMP_MAGENTA
    MCAsmInfo *MAI = new GraphArchELFMCAsmInfo(TT);
    unsigned SP = MRI.getDwarfRegNum(GraphArch::X1, true);
    MCCFIInstruction Inst = MCCFIInstruction::cfiDefCfa(nullptr, SP, 0);
    MAI->addInitialFrameState(Inst);
    return MAI;
}

static MCInstPrinter *createGraphArchMCInstPrinter(const Triple &T,
                                             unsigned SyntaxVariant,
                                             const MCAsmInfo &MAI,
                                             const MCInstrInfo &MII,
                                             const MCRegisterInfo &MRI) {
    COLOR_DUMP_MAGENTA
    return new GraphArchInstPrinter(MAI, MII, MRI);
}

// Define this function so that linking succeeds.
extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeGraphArchTargetMC() {
    COLOR_DUMP_MAGENTA
    Target &TheGraphArchTarget = getTheGraphArchTarget();
    RegisterMCAsmInfoFn X(TheGraphArchTarget, createGraphArchMCAsmInfo);
    // Register the MC register info.
    TargetRegistry::RegisterMCRegInfo(TheGraphArchTarget, createGraphArchMCRegisterInfo);
    // Register the MC instruction info.
    TargetRegistry::RegisterMCInstrInfo(TheGraphArchTarget, createGraphArchMCInstrInfo);
    // Register the MC subtarget info.
    TargetRegistry::RegisterMCSubtargetInfo(TheGraphArchTarget,
    createGraphArchMCSubtargetInfo);
    // Register the MCInstPrinter
    TargetRegistry::RegisterMCInstPrinter(TheGraphArchTarget, createGraphArchMCInstPrinter);
    // Register the MC Code Emitter.
    TargetRegistry::RegisterMCCodeEmitter(TheGraphArchTarget, createGraphArchMCCodeEmitter);
}