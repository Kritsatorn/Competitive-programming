.data
newline:    .asciiz "\n"

.text
main:
    # call ex233 with argument 6
    addi a0, x0, 6
    jal ex233

    # exit gracefully
    addi a0, x0, 10
    ecall

ex233:
    # save the return address ra on the stack
    addi sp, sp, -4
    sw ra, 0(sp)

    # terminate if n (in a0) <= 0
    bge x0, a0, terminate
    
    # move the value n to a1 for printing
    mv a1, a0

    # save the value of a0 (in caller saved set) as it is needed later and will be overwritten when making ecall
    addi sp, sp, -4
    sw a0, 0(sp)

    # overwrite a0 and make ecall (print interger)
    addi a0, x0, 1
    ecall

    # print new line
    addi a0, x0, 4
    la a1, newline
    ecall

    # load the saved a0 from the stack for use when calling ex233 with argument n-2; adjust the stack pointer to deallocate the stack space for a0
    lw a0, 0(sp)
    addi sp, sp, 4

    # allocate space for a0 and save it to the stack again as its value will be needed after a call to ex233 with argument n-2
    addi sp, sp, -4
    sw a0, 0(sp)

    # make a call ex233(n-2)
    addi a0, a0, -2
    jal ex233

    # load the saved a0 from the stack for use when calling ex233 with argument n-3; adjust the stack pointer to deallocate the stack space for a0
    lw a0, 0(sp)
    addi sp, sp, 4

    # allocate space for a0 and save it to the stack again as its value will be needed after a call to ex233 with argument n-3
    addi sp, sp, -4
    sw a0, 0(sp)

    # make a call ex233(n-3)
    addi a0, a0, -3
    jal ex233

    # load the saved a0 from the stack for use when calling ex233 with argument n-3; adjust the stack pointer to deallocate the stack space for a0    
    lw a0, 0(sp)
    addi sp, sp, 4

    # print the value of n (in a0)
    mv a1, a0
    addi a0, x0, 1
    ecall

    # print a new line
    addi a0, x0, 4
    la a1, newline
    ecall

terminate:
    # termination case; clean up the stack and return from ex233 with jr ra
    lw ra, 0(sp)
    addi sp, sp, 4
    jr ra
