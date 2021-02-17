.data
newline:    .asciiz "\n"
.text
main:
  addi s0, x0, 0 # i= 0
  addi s1, x0, 5 # constant 15
# save at a1
loop:
  bge s0, s1, end_loop # if t0 >= t1 then target
  mv  a0, s0 # a0 = i
  jal fib

  mv a1, a0
  addi a0, x0, 1

  ecall
  addi a0, x0, 4
  la a1, newline
  ecall

  addi s0, s0, 1 # i++
  jal loop
end_loop:
    add a1, x0, x0
    addi a0, x0, 10
    ecall

fib:
  addi sp, sp, -8
  sw ra, 4(sp)
  sw a0, 0(sp) # store a0
  addi t0, x0, 1
  beq a0, x0, if1 # if a2 =x0t1if1target
  beq a0, t0, if2

  addi a0, a0, -1
  jal fib
  lw t0, 0(sp) # pop to t0
  addi sp, sp, -4

  sw a0, 0(sp) # push stack
  addi a0, t0, -2
  jal fib

  lw t0, 0(sp)
  addi sp, sp, 4

  add a0, a0, t0

  lw ra, 4(sp)
  addi sp, sp, 8
  jr ra

if1:
  add a0, x0, x0
  lw ra, 4(sp)
  addi sp, sp, 8
  jr ra

if2:
  addi a0, x0, 1
  lw ra, 4(sp)
  addi sp, sp, 8
  jr ra