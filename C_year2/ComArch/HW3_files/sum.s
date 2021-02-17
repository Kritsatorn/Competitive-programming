
.text
main:
  addi a0, x0, 20
  addi a1, x0, 30
  jal sum

  addi a0, x0, 1
  ecall

add a1, x0, x0
addi a0, x0, 10
ecall
sum:
  addi sp, sp, -4
  sw ra, 0(sp)
  add a1, a0, a1
  addi sp, sp, 4
  lw ra, 0(sp)
  jr ra