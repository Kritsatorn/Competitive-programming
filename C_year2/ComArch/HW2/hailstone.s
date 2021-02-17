.text
main:
			add t3, x0, x0 # i = 0
            addi t4, x0, 5 # n = 5
            addi t5, x0, 1 # t5 <- 1
while_loop: 
            beq t5, t4, exit_while_loop # exit loop if n is one
            addi t3, t3, 1 # i = i + 1
            andi t6, t4, 0x1 # check lsb of n
            bne t6, x0, else_part # if lsb of n is not 0, n is odd, jump to else_part
            srli t4, t4, 1 # srl by one simulates n/2
            j join
else_part:  
            slli t6, t4, 1 # sll by one simulates 2*n
            add t4, t6, t4 # n = 2*n + n
            addi t4, t4, 1 # n = 3*n + 1
join:
            j while_loop

exit_while_loop:
            addi    a0, x0, 1
            addi    a1, t3, 0
            ecall # print integer ecall
            addi    a0, x0, 10
            ecall # terminate ecall
