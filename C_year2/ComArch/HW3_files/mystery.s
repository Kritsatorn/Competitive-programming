.data
newline:    .asciiz "\n"

.text
main:
    addi a0, x0, 15
    addi a1, x0, 30
    jal mystery
    addi a0, x0, 1
    ecall
    addi a0, x0, 4
    la a1, newline
    ecall
    add a1, x0, x0
    addi a0, x0, 10
    ecall

# the return value of mystery is placed in a1
mystery:
    addi sp, sp, -4 # push stack
    sw ra, 0(sp) # save address
    beq a1, x0, termination_case # if 1 b == 0
    addi a1, a1, -1 # b -1
    jal mystery # recur
    add a1, a0, a1 # + a in return
    lw ra, 0(sp) # load adress
    addi sp, sp, 4 # pop stack
    jr ra # jump address

termination_case:
    addi a1, x0, 0 # return 0
    lw ra, 0(sp)
    addi sp, sp, 4
    jr ra



