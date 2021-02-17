#include <stdio.h>

int fib(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fib(n-1) + fib(n-2);
}

int main()
{
    int x, i;
    for (i = 0; i < 15; i++)
    {
        x = fib(i);
        printf("%d\n", x);
    }
    return 0;
}

/*
.data
newline:    .asciiz "\n"

.text
main:       
    add s0, x0, x0
    addi s1, x0, 15
loop:
    bge s0, s1, loop_exit
    mv a0, s0
    jal fib
    mv a1, a0
    addi a0, x0, 1
    ecall
    addi a0, x0, 4
    la a1, newline
    ecall
    addi s0, s0, 1
    j loop
loop_exit:
    add a1, x0, x0
    addi a0, x0, 10
    ecall # Terminate ecall

fib:
    addi sp, sp, -8
    sw ra, 4(sp)
    sw a0, 0(sp)
    addi t0, x0, 1
    beq a0, x0, terminate_case_1
    beq a0, t0, terminate_case_2
    addi a0, a0, -1
    jal fib
    lw t0, 0(sp)
    addi sp, sp, -4
    sw a0, 0(sp)
    addi a0, t0, -2
    jal fib
    lw t0, 0(sp)
    addi sp, sp, 4
    add a0, a0, t0
    lw ra, 4(sp)
    addi sp, sp, 8
    jr ra
    
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

*/

