#include "GraphArch.h"
#include "GraphArchTargetMachine.h"
#include "TargetInfo/GraphArchTargetInfo.h"
#include "llvm/CodeGen/TargetLoweringObjectFileImpl.h"
#include "llvm/CodeGen/TargetPassConfig.h"
#include "llvm/CodeGen/Passes.h"
#include "llvm/CodeGen/TargetLoweringObjectFileImpl.h"
#include "llvm/CodeGen/TargetPassConfig.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Transforms/Scalar.h"
#include <optional>

using namespace llvm;

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeGraphArchTarget() {
  RegisterTargetMachine<GraphArchTargetMachine> A(getTheGraphArchTarget());
}

static std::string computeDataLayout(const Triple &TT, StringRef CPU,
                                       const TargetOptions &Options,
                                       bool IsLittle) {
  // Example data layout: little-endian, 32-bit pointers.
  // layout similar to Xtensa CPU`s
  std::string Ret = "e-m:e-p:32:32-i8:8:32-i16:16:32-i64:64-n32";
  return Ret;
}

static Reloc::Model getEffectiveRelocModel(bool JIT,
                                           std::optional<Reloc::Model> RM) {
  if (!RM || JIT)
     return Reloc::Static;
  return *RM;
}

GraphArchTargetMachine::GraphArchTargetMachine(const Target &T, const Triple &TT,
                                                 StringRef CPU, StringRef FS,
                                                 const TargetOptions &Options,
                                                 std::optional<Reloc::Model> RM,
                                                 std::optional<CodeModel::Model> CM,
                                                 CodeGenOptLevel OL, bool JIT,
                                                 bool IsLittle)
    : CodeGenTargetMachineImpl(T, computeDataLayout(TT, CPU, Options, IsLittle), TT,
                        CPU, FS, Options, getEffectiveRelocModel(JIT, RM),
                        getEffectiveCodeModel(CM, CodeModel::Small), OL),
      TLOF(std::make_unique<TargetLoweringObjectFileELF>()) {
  COLOR_DUMP_CYAN
  initAsmInfo();
}

GraphArchTargetMachine::GraphArchTargetMachine(const Target &T, const Triple &TT,
                                                 StringRef CPU, StringRef FS,
                                                 const TargetOptions &Options,
                                                 std::optional<Reloc::Model> RM,
                                                 std::optional<CodeModel::Model> CM,
                                                 CodeGenOptLevel OL, bool JIT)
    : GraphArchTargetMachine(T, TT, CPU, FS, Options, RM, CM, OL, JIT, true) {}

namespace {

/// GraphArch Code Generator Pass Configuration Options.
class GraphArchPassConfig : public TargetPassConfig {
public:
  GraphArchPassConfig(GraphArchTargetMachine &TM, PassManagerBase &PM)
      : TargetPassConfig(TM, PM) {}

  GraphArchTargetMachine &getGraphArchTargetMachine() const {
    return getTM<GraphArchTargetMachine>();
  }

  bool addInstSelector() override {
    COLOR_DUMP_CYAN
    addPass(createGraphArchISelDag(getGraphArchTargetMachine(), getOptLevel()));
    return false;
  }
};

} // end anonymous namespace

TargetPassConfig *GraphArchTargetMachine::createPassConfig(PassManagerBase &PM) {
  COLOR_DUMP_CYAN
  return new GraphArchPassConfig(*this, PM);
}

TargetLoweringObjectFile *GraphArchTargetMachine::getObjFileLowering() const {
  COLOR_DUMP_CYAN
  return TLOF.get();
}