#ifndef LLVM_LIB_TARGET_GRAPHARCH_MCTARGETDESC_GRAPHARCHMCASMINFO_H
#define LLVM_LIB_TARGET_GRAPHARCH_MCTARGETDESC_GRAPHARCHMCASMINFO_H

#include "llvm/MC/MCAsmInfoELF.h"

namespace llvm {

class Triple;

class GraphArchELFMCAsmInfo : public MCAsmInfoELF {
    public:
    explicit GraphArchELFMCAsmInfo(const Triple &TheTriple);
};

} // end namespace llvm

#endif // LLVM_LIB_TARGET_GRAPHARCH_MCTARGETDESC_GRAPHARCHMCASMINFO_H