#ifndef LLVM_LIB_TARGET_GRAPHARCH_GRAPHARCHREGISTERINFO_H
#define LLVM_LIB_TARGET_GRAPHARCH_GRAPHARCHREGISTERINFO_H

#define GET_REGINFO_HEADER
#include "GraphArchGenRegisterInfo.inc"

namespace llvm {

struct GraphArchRegisterInfo : public GraphArchGenRegisterInfo {
public:
GraphArchRegisterInfo();
};

} // end namespace llvm

#endif // LLVM_LIB_TARGET_GRAPHARCH_GRAPHARCHREGISTERINFO_H