.data
newline:    .asciiz "\n"

.text
main:
    # put arguments in a0 and a1 and call gcd
    addi a0, x0, 1440
    addi a1, x0, 408
    jal gcd

    # upon returning from gcd, place the return a0 to s0, overwrite a0 to call print integer, and put the value to print in s0 to a1
    mv s0, a0
    addi a0, x0, 1
    mv a1, s0
    ecall

    # print a new line
    addi a0, x0, 4
    la a1, newline
    ecall

    # return 0 and exit
    add a1, x0, x0
    addi a0, x0, 10
    ecall

gcd:
    # save the return address in ra to the stack
    addi sp, sp, -4
    sw ra, 0(sp)

    # jump to both recursive cases
    blt a0, a1, return_case_1
    blt a1, a0, return_case_2

    # survive both recursive cases to reach this termination case; the return value is already in a0 (or even a1 in this case as a0 == a1)
    lw ra, 0(sp)
    addi sp, sp, 4
    jr ra

return_case_1:
    # translation for return gcd(a, b-a)
    sub a1, a1, a0
    jal gcd
    lw ra, 0(sp)
    addi sp, sp, 4
    jr ra

return_case_2:
    # translation for return gcd(a-b, b)
    sub a0, a0, a1
    jal gcd
    lw ra, 0(sp)
    addi sp, sp, 4
    jr ra
    