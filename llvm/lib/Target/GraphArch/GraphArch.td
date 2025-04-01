include "llvm/Target/Target.td"
include "GraphArchRegisterInfo.td"
include "GraphArchInstrInfo.td"

def GraphArchInstrInfo : InstrInfo;
def GraphArch : Target {
let InstructionSet = GraphArchInstrInfo;
}