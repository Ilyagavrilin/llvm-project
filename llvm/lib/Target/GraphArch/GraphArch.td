include "llvm/Target/Target.td"
include "GraphArchRegisterInfo.td"
include "GraphArchInstrInfo.td"

class Proc<string Name, list<SubtargetFeature> Features>
: Processor<Name, NoItineraries, Features>;

def : Proc<"generic", []>;

def GraphArchInstrInfo : InstrInfo;
def GraphArch : Target {
let InstructionSet = GraphArchInstrInfo;
}