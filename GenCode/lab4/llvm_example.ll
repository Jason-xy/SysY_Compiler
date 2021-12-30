; ModuleID = './llvm_example.c'
target datalayout = "e-p:64:64:64-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v64:64:64-v128:128:128-a0:0:64-s0:64:64-f80:128:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

; Function Attrs: nounwind uwtable
define void @func() #0 {
  %A = alloca i32, align 4
  %B = alloca i32, align 4
  %C = alloca i32, align 4
  %D = alloca i32, align 4
  store i32 1, i32* %A, align 4
  store i32 2, i32* %B, align 4
  store i32 3, i32* %C, align 4
  store i32 4, i32* %D, align 4
  %1 = load i32* %B, align 4
  %2 = sub nsw i32 0, %1
  %3 = load i32* %C, align 4
  %4 = load i32* %D, align 4
  %5 = add nsw i32 %3, %4
  %6 = mul nsw i32 %2, %5
  store i32 %6, i32* %A, align 4
  ret void
}

attributes #0 = { nounwind uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.ident = !{!0}

!0 = metadata !{metadata !"Ubuntu clang version 3.4-1ubuntu3 (tags/RELEASE_34/final) (based on LLVM 3.4)"}
