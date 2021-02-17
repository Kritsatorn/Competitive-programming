.data
newline:    .asciiz "\n"
space:    .asciiz " "
.text
main:
  addi a0, x0, 100
  addi a1, x0, 3
  jal combination

  mv  a1, a0 # a1 =a01
  addi a0, x0, 1
  ecall

  addi a0, x0, 10
  ecall

combination:
# save in a0
    addi sp, sp, -12 # push stack for addrss n and k
    sw ra, 8(sp)
    sw a0, 4(sp)
    sw a1, 0(sp)
  # --- print check
    # mv t0, a1
    # addi a0, x0, 1
    # ecall

    # addi a0, x0, 4
    # la a1, space
    # ecall

    # lw a1, 4(sp)
    # addi a0, x0, 1
    # ecall

    # addi a0, x0, 4
    # la a1, newline
    # ecall
  #----
  lw a0, 4(sp) # load again for sure
  lw a1, 0(sp)
  beq a1, x0, terminate # if k == 0
  beq a0, a1, terminate # if n == k
  ble a0, a1, terminate2 # if n <= k

    addi a0, a0, -1 # n- 1
    jal combination # recur

    lw t0, 4(sp) # get n
    lw a1, 0(sp) # get k
    addi sp, sp, -4 # push stack for save old answer
    sw a0, 0(sp) # save
    addi a0, t0, -1 # n-1
    addi a1, a1, -1 # k-1

    jal combination # call

    lw t0, 0(sp) # load first answer
    addi sp, sp, 4 # pop stack
    add a0, a0, t0 # plus

    lw ra, 8(sp) # load address
    addi sp, sp, 12 # pop stack
    jr ra # jump to address


terminate:
    addi a0, x0, 1 # return 1
    lw ra, 8(sp)
    addi sp, sp, 12
    jr ra

terminate2:
    addi a0, x0, 0 # return 0
    lw ra, 8(sp)
    addi sp, sp, 12
    jr ra