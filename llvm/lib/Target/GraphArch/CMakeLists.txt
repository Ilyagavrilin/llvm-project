add_llvm_component_group(GraphArch)

set(LLVM_TARGET_DEFINITIONS GraphArch.td)

tablegen(LLVM GraphArchGenRegisterInfo.inc -gen-register-info)
tablegen(LLVM GraphArchGenInstrInfo.inc -gen-instr-info)
tablegen(LLVM GraphArchGenSubtargetInfo.inc -gen-subtarget)

add_public_tablegen_target(GraphArchCommonTableGen)

# Define the GraphArch code-generation target.
add_llvm_target(GraphArchCodeGen
  GraphArchTargetMachine.cpp
  GraphArchRegisterInfo.cpp
  GraphArchInstrInfo.cpp
  GraphArchSubtarget.cpp

  LINK_COMPONENTS
  CodeGen
  Core
  Support
  Target
  GraphArchInfo

  ADD_TO_COMPONENT
  GraphArch
)

add_subdirectory(MCTargetDesc)
add_subdirectory(TargetInfo)