
li a0 , 5 # n = 5
li a4 , 0 # i - 0
loop :
    addi a4,a4,1
    

If :
    andi a1, a0, 1
    bnez a1, Else
Then :
    srai a0,a0,1
    j loop

Else :
    slli a2,a0,1
    add a0, a2, a0; # a0 =a21 a0t2
    addi a0,a0, 1

End :
    

