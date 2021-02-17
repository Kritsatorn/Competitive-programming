.data
newline:    .asciiz "\n"

.text
main:       
    add s0, x0, x0
    addi s1, x0, 5
loop:
    bge s0, s1, loop_exit # if 1 i < 15
    mv a0, s0 # a0 = i
    jal fib # call
    mv a1, a0 # move to print
    addi a0, x0, 1 #print a0
    ecall
    addi a0, x0, 4 # print new line
    la a1, newline
    ecall
    addi s0, s0, 1 # i++
    j loop # loop
loop_exit:
    add a1, x0, x0
    addi a0, x0, 10
    ecall # Terminate ecall

fib:
    addi sp, sp, -8 # add stack
    sw ra, 4(sp)
    sw a0, 0(sp)
    addi t0, x0, 1 # t0 = 1
    beq a0, x0, terminate_case_1
    beq a0, t0, terminate_case_2

    addi a0, a0, -1 # recur n-1
    jal fib

    lw t0, 0(sp) # load a0
    addi sp, sp, -4 # push stack
    sw a0, 0(sp) # save old answer
    addi a0, t0, -2 # n-2
    jal fib # call

    lw t0, 0(sp) # load first answer
    addi sp, sp, 4 # pop stack
    add a0, a0, t0 # plus
    lw ra, 4(sp) # load adress
    addi sp, sp, 8 #pop stack
    jr ra # jump address
    
terminate_case_1:
    add a0, x0, x0
    lw ra, 4(sp)
    addi sp, sp, 8
    jr ra

terminate_case_2:
    addi a0, x0, 1
    lw ra, 4(sp)
    addi sp, sp, 8
    jr ra
