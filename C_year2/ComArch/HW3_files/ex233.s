.data
newline:    .asciiz "\n"

.text
main:
  addi a0, x0, 6
  jal ex233

  addi a0, x0, 10
  ecall
ex233:
  addi sp, sp, -8
  sw ra, 4(sp)
  sw a0, 0(sp)

  bge x0, a0, if1

  lw a1, 0(sp)
  addi a0, x0, 1
  ecall

  la a1 newline
  addi a0, x0, 4
  ecall

  lw a0, 0(sp)
  addi a0, a0, -2
  jal ex233

  lw a0, 0(sp)
  addi a0, a0, -3
  jal ex233

  lw a1, 0(sp)
  addi a0, x0, 1
  ecall

  la a1 newline
  addi a0, x0, 4
  ecall

if1:
 lw ra, 4(sp)
 addi sp, sp, 8
 jr ra
