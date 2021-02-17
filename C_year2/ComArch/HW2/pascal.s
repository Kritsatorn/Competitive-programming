.data
	pascal: .space 256
    space:	.asciiz " "
    newline: .asciiz "\n"
    
.text
	#a2 -> i, a3 -> j, a4->n
    la s0, pascal
    addi s1, s0, 32	#pascal[1][0]
    addi s1, s1, 4	#pascal[1][1]
    addi t0, x0, 1
    sw	 t0, 0(s1)	#pascal[1][1] = 1
    addi a2, x0, 2	#i=2
    addi a4, x0, 7	#n=7
    addi a5, x0, 32	#const 32
    addi a6, x0, 4	#const 4

loop1:
	bgt	a2,	a4, endloop1	#if(i>n) break
    addi a3, x0, 1	#j=1
    addi a7, a2, 1	#i+2-1
   	mul t0, a2, a5
    add s1, s0, t0	#pascal[i][0]
    sub s2, s1, a5	#pascal[i-1][j-1]
    sw x0, 0(s2)
    addi s1, s1, 4	#pascal[i][j]
 	loop2:
    	bge a3, a7, endloop2	#if(j>i+2-1) break
		lw t1, 0(s2)	#pascal[i-1][j-1]       \
        addi s2, s2, 4
        lw t2, 0(s2)	#pascal[i-1][j]
        add t3, t1, t2	#pascal[i-1][j-1] + pascal[i-1][j]
        sw t3, 0(s1)	#pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j]
        addi a3, a3 ,1	#j++
        addi s1, s1, 4
        jal loop2
    endloop2:
    addi a2, a2, 1		#i++
    jal loop1
endloop1:

	addi a2, x0, 1		#i=1
    
loop3:
	bgt a2, a4, endloop3
    addi a3, x0, 1		#j=1
    addi a7, a2, 1		#i+2-1
    mul t0, a2, a5
    add s1, s0, t0		#pascal[i][0]
    addi s1, s1, 4		#pascal[i][1]
    loop4:
    	bge a3, a7, endloop4
        lw a1, 0(s1)
        addi a0, x0, 1
        ecall			#print pascal[i][j]
        la a1, space
        addi a0, x0, 4
        ecall
        addi a3, a3, 1	#j++
        addi s1, s1, 4
        jal loop4
    endloop4:
    la a1, newline
    addi a0, x0, 4
    ecall
    addi a2, a2, 1		#i++
    jal loop3
endloop3:
    
addi a0, x0, 10
ecall
