.data
newline:    .asciiz "\n"
.text
main:
  addi a0, x0, 15
  addi a1, x0, 30
  jal mystery

  addi a0, x0, 1
  ecall

mystery:
  addi sp, sp, -4
  sw ra, 0(sp)
  beq a1, x0, else
  addi a1, a1, -1
  jal mystery
  add a1, a0, a1
  
  lw ra, 0(sp)
  addi sp, sp, 4
  jr ra

else:
  addi a1, x0, 0
  
  lw ra, 0(sp)
  addi sp, sp, 4
  jr ra
