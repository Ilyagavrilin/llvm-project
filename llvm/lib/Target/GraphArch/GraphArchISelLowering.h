#ifndef LLVM_LIB_TARGET_GRAPHARCH_GRAPHARCHISELLOWERING_H
#define LLVM_LIB_TARGET_GRAPHARCH_GRAPHARCHISELLOWERING_H

#include "GraphArch.h"
#include "llvm/CodeGen/SelectionDAG.h"
#include "llvm/CodeGen/TargetLowering.h"

namespace llvm {

class GraphArchSubtarget;
class GraphArchTargetMachine;

namespace GraphArchISD {

enum NodeType : unsigned {
// Start the numbering where the builtin ops and target ops leave off.
FIRST_NUMBER = ISD::BUILTIN_OP_END,
RET,
CALL,
BR_CC,
};

} // namespace GraphArchISD

class GraphArchTargetLowering : public TargetLowering {
public:
    explicit GraphArchTargetLowering(const TargetMachine &TM, const GraphArchSubtarget &STI);

    /// This method returns the name of a target specific DAG node.
    const char *getTargetNodeName(unsigned Opcode) const override;

    GraphArchSubtarget const &getSubtarget() const { return STI; }

private:
    const GraphArchSubtarget &STI;
};


} // end namespace llvm

#endif // LLVM_LIB_TARGET_GRAPHARCH_GRAPHARCHISELLOWERING_H