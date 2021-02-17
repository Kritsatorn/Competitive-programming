.data
  input: .word 17, 4, 6, 8, 11, 5, 13, 19, 0, 24
  bitsum: .space 40
  bitvector: .space 40
  output: .space 40
  newline: .asciiz "\n"
  space: .asciiz " "

.text
  addi a2, x0, 0 # t0 =x0 count = 0
  addi a3, x0, 0 # t1 =x0 index = 0

  # s0 input
  la s0, input

  addi a4, x0, 0 # i = 0
  addi a5, x0, 10 # constabt = 10
  addi a6, x0, 6 # constant = 6
  la s2, bitvector #  load bitvector address
  addi s1, s0, 0 #input[0]
  addi s3, s2, 0 # bitvector[0]

firstLoop:
  bge a4, a5, end_firstLoop # i < 10
  lw t0, 0(s1) # get input[i]
  blt t0, a6, cond2 # input[i] >= 6
    addi a2, a2, 1 # count++
    addi t1, x0, 1 # t1 = 1
    sw t1, 0(s3)# bitvector[i] = 1
    jal endif1
  cond2:
    sw x0, 0(s3) # bitvector[i] = 0
    jal endif1
  endif1:
    addi a4, a4, 1 # i++
    addi s1, s1, 4 # input[i+1]
    addi s3, s3, 4 # bitvector[i+1]
  jal firstLoop
end_firstLoop:

la s4, bitsum
addi s3, s2, 0 # bitvector[0]
addi s5, s4, 0 # bitsum[0] == i-1
addi s6, s4, 4 # bitsum[i]
lw t0, 0(s3) # call bitvector[0]
sw t0, 0(s5) # bitsum[0] = nitvector[0]
addi s3, s3, 4 # bitvector[i]
addi a4, x0, 1 # i = 1

secondLoop:
  bge a4, a5, end_secondLoop
  lw t0, 0(s5) # bitsum[i-1]
  lw t1, 0(s3) # bitvector[i]
  add t2, t0, t1 #  bitsum[i-1] + bitvector[i]
  sw t2, 0(s6) #  bitsum[i] = t2
  addi a4, a4, 1 # i++
  addi s3, s3, 4 #bitvector[i]
  addi s5, s5, 4 # bitsum i-1
  addi s6, s6, 4 # bitsum i
  jal secondLoop
end_secondLoop:

# load address output s7
la s7, output
addi a4, x0, 0 # i = 0
addi s3, s2, 0 # bitvector[0]
addi s5, s4, 0 # bitsum[0]
addi s1, s0, 0 #input[0]
addi a6, x0, 1 # constant = 1
addi a7, x0, 4 # constant = 4

thirdLoop:
  bge a4, a5, end_thirdLoop
  lw t0, 0(s3) # load bitvector
  bne t0, a6, cond3 # bitvector[i] == 1
    lw t1, 0(s1) # load input
    lw t2, 0(s5) # load bitsum
    addi t2, t2, -1 # bitsum[i] - 1
    mul t2, t2, a7 # bitsum*4
    add s8, s7, t2 # output[ bitsum[i] - 1 ]
    sw t1, 0(s8) # output[ bitsum[i] - 1 ] = intput[i]
  cond3:
  addi a4, a4, 1 # i++
  addi s3, s3, 4 # bitvector
  addi s5, s5, 4 # bitsum
  addi s1, s1, 4 # input
  jal thirdLoop
end_thirdLoop:

addi a4, x0, 0 # i = 0
addi s1, s0, 0 #input[0]

fourthLoop:
  bge a4, a5, end_fourthLoop
  lw t0, 0(s1) # input[i]
  addi a1, t0, 0
  addi a0, x0, 1
  ecall	#print input[i]

  addi  a0, x0, 4
  la a1, space
  ecall

  addi a4, a4, 1 # i++
  addi s1, s1, 4 # input[i+1]
  jal fourthLoop
end_fourthLoop:

addi a0, x0, 4
la a1, newline
ecall

addi a4, x0, 0 # i = 0
addi s8, s7, 0 # output[0]

fifthLoop:
  bge a4, a2, end_fifthLoop
  # print output[i]
  lw t0, 0(s8)
  addi a1, t0, 0
  addi a0, x0, 1
  ecall
#print space
  addi  a0, x0, 4
  la a1, space
  ecall

  addi a4, a4, 1
  addi s8, s8, 4
  jal fifthLoop
end_fifthLoop:

addi a0, x0, 4
la a1, newline
ecall

addi a0, x0, 10
ecall