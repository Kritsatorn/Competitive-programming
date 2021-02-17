#include <stdio.h>


int mystery(int a, int b) {
   if (0 == b) return 0;
   else return mystery(a, b-1) + a;
}

int main() {
    int x;
    x = mystery(15, 30);
    printf("%d\n", x);
    return 0;
}

/*
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

mystery:
    addi sp, sp, -4
    sw ra, 0(sp)
    beq a1, x0, termination_case
    addi a1, a1, -1
    jal mystery
    add a1, a0, a1
    lw ra, 0(sp)
    addi sp, sp, 4
    jr ra

termination_case:
    addi a1, x0, 0
    lw ra, 0(sp)
    addi sp, sp, 4
    jr ra
*/


