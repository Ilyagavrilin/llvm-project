#ifndef LLVM_LIB_TARGET_GRAPHARCH_TARGETINFO_GRAPHARCHTARGETINFO_H
#define LLVM_LIB_TARGET_GRAPHARCH_TARGETINFO_GRAPHARCHTARGETINFO_H

namespace llvm {

class Target;

// Returns a reference to the GraphArch target.
Target &getTheGraphArchTarget();

} // end namespace llvm

#endif // LLVM_LIB_TARGET_GRAPHARCH_TARGETINFO_GRAPHARCHTARGETINFO_H