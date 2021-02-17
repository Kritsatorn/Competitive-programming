.data
	input:	.space 40
    bitsum: .space 40
    bitvector:	.space 40
    output:	.space 40
    newline: .asciiz "\n"
    space: .asciiz " "
.text
	#a2->i, a3->count, a4->index, s0->input
    addi a3, x0, 0
    addi a4, x0, 0
    #define input[10] = {17, 4, 6, 8, 11, 5, 13, 19, 0, 24}
    la s0, input
    addi s1, s0, 0
    addi t0, x0, 17
    sw t0, 0(s1)
    addi s1, s1, 4
    addi t0, x0, 4
    sw t0, 0(s1)
    addi s1, s1, 4
    addi t0, x0, 6
    sw t0, 0(s1)
    addi s1, s1, 4
    addi t0, x0, 8
    sw t0, 0(s1)
    addi s1, s1, 4
    addi t0, x0, 11
    sw t0, 0(s1)
    addi s1, s1, 4
    addi t0, x0, 5
    sw t0, 0(s1)
    addi s1, s1, 4
    addi t0, x0, 13
    sw t0, 0(s1)
    addi s1, s1, 4
    addi t0, x0, 19
    sw t0, 0(s1)
    addi t0, x0, 0
    addi s1, s1, 4
    sw t0, 0(s1)
    addi s1, s1, 4
    addi t0, x0, 24
    sw t0, 0(s1)
    
    addi a2, x0, 0	#i = 0
    addi a5, x0, 10 #constant 10
    addi a6, x0, 6	#constant 6
    la s2, bitvector #get bitvector[0] address
    addi s1, s0, 0	#input[i]
    addi s4, s2, 0	#bitvector[i]
    
loop1:
	bge a2, a5, endloop1
    lw t0, 0(s1)		#get input[i]
    blt t0, a6, cond2
    	addi a3, a3, 1	#cond1 input[i] >= 6
        addi t1, x0, 1
        sw t1, 0(s4) #bitvector[i] = 1
        jal endif1
    cond2:				#cond2 input[i] < 6
    	sw x0, 0(s4)
        jal endif1
    endif1:
    	addi a2, a2, 1	#i++
        addi s1, s1, 4
        addi s4, s4, 4
    jal loop1
endloop1:    
	
    la s3, bitsum
    addi s4, s2, 0	#bitvector[0]
    addi s5, s3, 0	#bitsum[0] also used as bitsum[i-1]
    addi s6, s3, 4	#bitsum[i]
    lw t0, 0(s4)
    sw t0, 0(s5)	#bitsum[0] = bitvector[0]
    addi s4, s4, 4	#bitvector[i]
    addi a2, x0, 1	#i = 1
	
    
loop2:
	bge a2, a5, endloop2
	lw t0, 0(s5)
    lw t1, 0(s4)
    add t2, t0, t1	#bitsum[i-1] + bitvector[i]
    sw t2, 0(s6)	#bitsum[i] = bitsum[i-1] + bitvector[i]
    addi s4, s4, 4
    addi s5, s5, 4
    addi s6, s6, 4
    addi a2, a2, 1
    jal loop2
endloop2:
    
    la s7, output
    addi a2, x0, 0	#i=0
    addi s6, s3, 0	#bitsum[i]
    addi s4, s2, 0	#bitvector[i]
    addi s1, s0, 0	#input[i]
    addi a6, x0, 1	#constant 1
    addi a7, x0, 4	#constant 4
    
loop3:
	bge a2, a5, endloop3
    lw	t0, 0(s4)
    bne t0, a6, endif3	#if(bitvector[i]==1)
    	lw t1, 0(s6)
        addi t1, t1, -1	#bitsum[i]-1
        mul t1, t1, a7
        add s8, s7, t1	#output[bitsum[i]-1]
        lw	t2, 0(s1)
        sw t2, 0(s8)	#output[bitsum[i]-1] = input[i]
    endif3:
    addi s1, s1, 4
    addi s4, s4, 4
    addi s6, s6, 4
    addi a2, a2, 1
    jal loop3
endloop3:

	addi a2, x0, 0	#i=0
    addi s1, s0, 0	#input[i]
    
loop4:
	bge a2, a5, endloop4
    lw t0, 0(s1)	#input[i]
    addi a1, t0, 0
    addi a0, x0, 1
    ecall	#print input[i]
    la a1, space
    addi a0, x0, 4
    ecall
    addi a2, a2, 1
    addi s1, s1, 4
    jal loop4
endloop4:
	addi a0, x0, 4
    la a1, newline
    ecall

	addi a2, x0, 0	#i=0
	addi s8, s7, 0	#output[i]
    
loop5:
	bge a2, a3, endloop5
    lw t0, 0(s8)
    addi a1, t0, 0
    addi a0, x0, 1
    ecall			#print output[i]
    la a1, space
    addi a0, x0, 4
    ecall
    addi a2, a2, 1
    addi s8, s8, 4
    jal loop5
endloop5:
	la a1, newline
    addi a0, x0, 4
    ecall

addi a0, x0, 10
ecall