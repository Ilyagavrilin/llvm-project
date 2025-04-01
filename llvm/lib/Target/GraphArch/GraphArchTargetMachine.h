#ifndef LLVM_LIB_TARGET_GRAPHARCH_GRAPHARCHTARGETMACHINE_H
#define LLVM_LIB_TARGET_GRAPHARCH_GRAPHARCHTARGETMACHINE_H

#include "GraphArchSubtarget.h"
#include "llvm/CodeGen/CodeGenTargetMachineImpl.h"
#include <optional>

namespace llvm {

// Declaration of the GraphArch target.
extern Target TheGraphArchTarget;

class GraphArchTargetMachine : public CodeGenTargetMachineImpl {
  std::unique_ptr<TargetLoweringObjectFile> TLOF;
  GraphArchSubtarget Subtarget;
public:
  GraphArchTargetMachine(const Target &T, const Triple &TT, StringRef CPU,
                         StringRef FS, const TargetOptions &Options,
                         std::optional<Reloc::Model> RM,
                         std::optional<CodeModel::Model> CM, CodeGenOptLevel OL,
                         bool JIT, bool isLittle);

  GraphArchTargetMachine(const Target &T, const Triple &TT, StringRef CPU,
                         StringRef FS, const TargetOptions &Options,
                         std::optional<Reloc::Model> RM,
                         std::optional<CodeModel::Model> CM, CodeGenOptLevel OL,
                         bool JIT);


  const GraphArchSubtarget *getSubtargetImpl(const Function &) const override {
    COLOR_DUMP_CYAN
    return &Subtarget;
  }

  TargetPassConfig *createPassConfig(PassManagerBase &PM) override;

  TargetLoweringObjectFile *getObjFileLowering() const override;
};

} // end namespace llvm

#endif // LLVM_LIB_TARGET_GRAPHARCH_GRAPHARCHTARGETMACHINE_H