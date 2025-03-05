add_llvm_component_group(GraphArch)

# Define the GraphArch code-generation target.
add_llvm_target(GraphArchCodeGen
  GraphArchTargetMachine.cpp

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