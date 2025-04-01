add_llvm_component_library(LLVMGraphArchDesc
  GraphArchMCTargetDesc.cpp
  GraphArchMCAsmInfo.cpp
  GraphArchInstPrinter.cpp

  LINK_COMPONENTS
  MC
  Support
  GraphArchInfo

  ADD_TO_COMPONENT
  GraphArch
 )