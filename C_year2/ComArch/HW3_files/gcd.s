.text
main:
  addi a2, x0, 1440
  addi a3, x0, 408
  jal gcd
  mv a1, a2
  addi a0, x0, 1
  ecall
gcd:
  addi sp, sp, -4
  sw ra, 0(sp)

  blt a3, a2, if1
  blt a2, a3, if2
  # bge a2, a3, if1
  # bge a3, a2, if2

  lw ra, 0(sp)
  addi sp, sp, 4
  jr ra

if1:
  sub a2, a2, a3 # t0 = t1 - t2
  jal gcd
  lw ra, 0(sp)
  addi sp, sp, 4
  jr ra
if2:
  sub a3, a3, a2
  jal gcd
  lw ra, 0(sp)
  addi sp, sp, 4
  jr ra