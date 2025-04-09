
let TargetPrefix = "grapharch" in {  // All intrinsics start with "llvm.grapharch.".

 def int_grapharch_putpixel: ClangBuiltin<"grapharchPutPixel">,
   Intrinsic<[], [llvm_i32_ty, llvm_i32_ty, llvm_i32_ty], [IntrNoMem, IntrHasSideEffects]>;

 def int_grapharch_flush: ClangBuiltin<"grapharchFlush">,
   Intrinsic<[], [], [IntrNoMem, IntrHasSideEffects]>;

 // circle was simplified with pre-selected color
 def int_grapharch_drawcircle: ClangBuiltin<"grapharchDrawCircle">,
   Intrinsic<[], [llvm_i32_ty, llvm_i32_ty, llvm_i32_ty], [IntrNoMem, IntrHasSideEffects]>;

 // draw only square with equal height and width
 def int_grapharch_drawsquare: ClangBuiltin<"grapharchDrawSquare">,
   Intrinsic<[], [llvm_i32_ty, llvm_i32_ty, llvm_i32_ty], [IntrNoMem, IntrHasSideEffects]>;

} // TargetPrefix = "grapharch"