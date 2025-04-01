//===----------------------------------------------------------------------===//
// GraphArch profiles and nodes
//===----------------------------------------------------------------------===//

def grapharch_ret      : SDNode<"GraphArchISD::RET", SDTNone,
                            [SDNPHasChain, SDNPOptInGlue, SDNPVariadic]>;

//===----------------------------------------------------------------------===//
// Instruction format superclass
//===----------------------------------------------------------------------===//

include "GraphArchInstrFormats.td"

//===----------------------------------------------------------------------===//
// GraphArch Operand, Complex Patterns and Transformations Definitions.
//===----------------------------------------------------------------------===//

class SImmAsmOperand<int width> : AsmOperandClass {
    let Name = "SImm" # width;
    let RenderMethod = "addImmOperands";
    let DiagnosticType = !strconcat("Invalid", Name);
}

def grapharchm16 : Operand<i32>, ImmLeaf<i32, [{return isInt<16>(Imm);}]> {
    let ParserMatchClass = SImmAsmOperand<16>;
    let EncoderMethod = "getImmOpValue";
    let DecoderMethod = "decodeSImmOperand<16>";
    let MCOperandPredicate = [{
        int64_t Imm;
        if (MCOp.evaluateAsConstantImm(Imm))
        return isInt<16>(Imm);
        return MCOp.isBareSymbolRef();
    }];
    let OperandType = "OPERAND_GRAPHARCHM16";
    let OperandNamespace = "GraphArchOp";
}

//===----------------------------------------------------------------------===//
// GraphArch Instructions
//===----------------------------------------------------------------------===//

let hasSideEffects = 0, mayLoad = 0, mayStore = 0, isCall = 1, isBranch = 1, isTerminator = 1 in
def BR : GraphArchInst<0x0, (outs), (ins GPR:$rs1), "BR $rs1",
                [(brind GPR:$rs1)]>;

let isBarrier = 1, isReturn = 1, isTerminator = 1 in
def PseudoRET : GraphArchPseudoInst<(outs), (ins), "# PseudoRET",
                [(grapharch_ret)]>,
                PseudoInstExpansion<(BR X0)>;

// movli
let isAsCheapAsAMove = 1, isCodeGenOnly = 1, isReMaterializable = 1 in
def MOVLI : GraphArchInst<0x0, (outs GPR:$rd), (ins grapharchm16:$imm),
                    "MOVli $rd $imm",
                    [(set GPR:$rd, grapharchm16:$imm)]>;