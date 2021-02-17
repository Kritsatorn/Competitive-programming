# you almost want to define int data before string data to avoid alignment related problems

.data
# define int array_2d[3][3]
array_2d:			 .space 36
        
# define null terminated string with .asciiz directive
helloworld:      .asciiz "Hello World!"
space:           .asciiz " "
newline:         .asciiz "\n"

.text
        # the following segment of code will perform array_2d[2][1] = 0xbb
        la    s0, array_2d   # get &array_2d[0][0]
        addi   s1, s0, 24     # get to &array_2d[2][0] which is 2*3*4 bytes away from &array_2d[0][0]
        addi   s1, s1, 4     # get to &array_2d[2][1] which is 1*4 bytes away from &array_2d[2][0]
        addi  t0, x0, 0xbb      # t0 = 0xbb
        sw    t0, 0(s1)      # array_2d[2][1] = t0

        # put 0xaa to array_2d[0][0] to see its place relative to array_2d[2][1]
        addi  t0, x0, 0xaa     # t0 = 0xaa
        sw    t0, 0(s0)      # array_2d[0][0] = t0

        addi  a0, x0, 4      # 4 = print_string
        la    a1, helloworld # load address of helloworld
        ecall
        addi  a0, x0, 4      # 4 = print_string
        la    a1, space      # load address of space
        ecall
        addi  a0, x0, 4      # 4 = print_string
        la    a1, helloworld # load address of helloworld
        ecall
        addi  a0, x0, 4      # 4 = print_string
        la    a1, newline # load address of newline
        ecall
        addi  a0, x0, 4      # 4 = print_string
        la    a1, helloworld # load address of helloworld
        ecall        
        addi a0, x0, 10      # 10 = exit
        ecall
