#ifndef LLVM_LIB_TARGET_GraphArch_GraphArch_H
#define LLVM_LIB_TARGET_GraphArch_GraphArch_H

#include "MCTargetDesc/GraphArchMCTargetDesc.h"
#include "llvm/Support/raw_ostream.h"

#define COLOR_DUMP(Color)                                                        \
{                                                                            \
    llvm::errs().changeColor(Color)                                            \
        << __func__ << "\n\t\t" << __FILE__ << ":" << __LINE__ << "\n";        \
    llvm::errs().changeColor(llvm::raw_ostream::WHITE);                        \
}
// #define COLOR_DUMP(Color) {}

#define COLOR_DUMP_RED COLOR_DUMP(llvm::raw_ostream::RED)
#define COLOR_DUMP_GREEN COLOR_DUMP(llvm::raw_ostream::GREEN)
#define COLOR_DUMP_YELLOW COLOR_DUMP(llvm::raw_ostream::YELLOW)
#define COLOR_DUMP_CYAN COLOR_DUMP(llvm::raw_ostream::CYAN)
#define COLOR_DUMP_MAGENTA COLOR_DUMP(llvm::raw_ostream::MAGENTA)
#define COLOR_DUMP_WHITE COLOR_DUMP(llvm::raw_ostream::WHITE)

#endif // LLVM_LIB_TARGET_GraphArch_GraphArch_H