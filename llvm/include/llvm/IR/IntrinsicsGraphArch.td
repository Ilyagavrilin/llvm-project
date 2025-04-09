
let TargetPrefix = "grapharch" in {  // All intrinsics start with "llvm.grapharch.".

 def int_grapharch_putpixel:
   Intrinsic<[], [llvm_i32_ty, llvm_i32_ty, llvm_i32_ty], [IntrNoMem, IntrHasSideEffects]>;

 def int_grapharch_flush:
   Intrinsic<[], [], [IntrNoMem, IntrHasSideEffects]>;

 // circle was simlified with pre-selected color
 def int_grapharch_drawcircle:
   Intrinsic<[], [llvm_i32_ty, llvm_i32_ty, llvm_i32_ty], [IntrNoMem, IntrHasSideEffects]>;

 // draw only square with equal height and width
 def int_grapharch_drawsquare:
   Intrinsic<[], [llvm_i32_ty, llvm_i32_ty, llvm_i32_ty], [IntrNoMem, IntrHasSideEffects]>;

} // TargetPrefix = "grapharch"