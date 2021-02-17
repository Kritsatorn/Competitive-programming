.data
  input: .word 17, 4, 6, 8, 11, 5, 13, 19, 0, 24
  bitsum: .space 40
  bitvector: .space 40
  output: .space 40
  newline: .asciiz "\n"
  space: .asciiz " "
.text
  la s0, input #in put
  la
  addi a1, x0, 0 # i
  