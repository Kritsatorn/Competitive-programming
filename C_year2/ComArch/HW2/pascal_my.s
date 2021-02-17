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

  addi a2, x0, 0 # int i = 0
  addi a3, x0, 0 # int j = 0
  addi a4, x0, 7 # n = 7
  # addi a5, x0, 32	#const 32
  # addi a6, x0, 4	#const 4

  addi a2, a2, 2 # i =2
  addi a3, a3, 1 # j = 1
  firstLoop:
    bgt a2, a4, end_firstLoop # if n > i then target
    addi t0, a2, 1 # i +2 -1
    secondLoop:
      bge a3, t0, end_secondLoop # if t3 >= t0 then target

      # t1 = i-1
      addi t3, a2, -1 # t3 = i-1
      mul t1, t3, 32

      addi s1, s0, t1 # get array[i-1][0] i*8*4
      addi t4, a4, -1 # t4 = j-1
      mul t2, t4, 4
      addi s1, s1, t2 # get array[i-1][j-1]

      addi s2, s0, t1 # get array[i-1][0] i*8*4
      mul t2, a3, 4 # j*4
      addi s2, s2, t2 # get array[i-1][j]

      addi s3, a2, 0 # i
      mul s3, s3, 32 # adrees [i][0]
      addi s3, s3, t2 # get array[i][j]

      lw t1, 0(s1)
      lw t2, 0(s2)
      add t3, t2, t1
      sw t3, 0(s3)

      addi a3, a3, 1 # j++
      jal secondLoop
    end_secondLoop:
    addi a2, a2, 4 # i++
    jal firstLoop
  end_firstLoop:

  addi a2, x0, 1 # int i = 1
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

  # addi a3, x0, 1 # int j = 1
  # addi s1, s0, 0 #array[0][0]
  # addi s1, s1, 36 # 1*8*4

  # thirdLoop:
  # bgt a2, a4, end_thirdLoop
  # addi t0, a2, 1
  #   fourthLoop:
  #   bge a3, t0, end_FourthLopp

  #   addi a3, a3, 1
  #   jal fourthLoop
  #   end_FourthLopp:
  # addi a2, a2, 1
  # jal thirdLoop
  # end_thirdLoop:

