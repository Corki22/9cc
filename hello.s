.intel_syntax noprefix
.global main
main:
  push 1
  push 2
  pop rdi
  pop rax
  add rax, rdi
  push 3
  pop rdi
  pop rax
  add rax, rdi
  pop rax
  ret
