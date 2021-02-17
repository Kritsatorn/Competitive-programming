.data
# define int array_2d[8][8]
	array_2d: .space 256
  space:	.asciiz " "
  newline: .asciiz "\n"

.text
  la s0, array_2d
  addi s1, s0, 36 # get array[1][1] (1*8 +1 )4
  addi t0, x0, 1
  sw t0, 0(s1) # pascal[1][1] = 1

  addi a2, x0, 2	# i = 2
  addi a3, x0, 0  # j = 0
  addi a4, x0, 7	# n = 7


firstLoop:
    bgt a2, a4, end_firstLoop # if n > i then target
    addi a3, x0, 1  # j = 1
    addi a7, a2, 1 # i +2 -1
    secondLoop:
      bge a3, a7, end_secondLoop # if t3 >= t0 then target
      addi a5, x0, 32	# 32
      addi a6, x0, 4	# 4

      mul t0, a2, a5 # i * 32
      add s1, s0, t0 # [i][0]
      sub s2, s1, a5 # [i-1][0]

      mul t1, a3, a6 # j * 4
      add s2, s2, t1 # [i-1][j]
      add s1, s1, t1 # [i][j]
      lw t3, 0(s2)

      sub s2, s2, a6 # [i-1][j-1]
      lw t4, 0(s2)

      add t5, t4, t3
      sw t5, 0(s1)

      addi a3, a3, 1 # j++
      jal secondLoop
    end_secondLoop:
    addi a2, a2, 1 # i++
    jal firstLoop
  end_firstLoop:

	addi a2, x0, 1		#i=1
thridLoop:
	bgt a2, a4, end_thridLoop
    addi a3, x0, 1		#j=1
    addi a7, a2, 1		#i+2-1
    mul t0, a2, a5
    add s1, s0, t0		#pascal[i][0]
    addi s1, s1, 4		#pascal[i][1]
    forthLoop:
    	bge a3, a7, end_forthLoop
        lw a1, 0(s1)
        addi a0, x0, 1
        ecall			#print pascal[i][j]
        la a1, space
        addi a0, x0, 4
        ecall
        addi a3, a3, 1	#j++
        addi s1, s1, 4
        jal forthLoop
    end_forthLoop:
    la a1, newline
    addi a0, x0, 4
    ecall
    addi a2, a2, 1		#i++
    jal thridLoop
end_thridLoop:
    
addi a0, x0, 10
ecall
