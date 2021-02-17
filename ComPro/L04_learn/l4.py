n = int(input('Enter : '))
'''
for i in range(4,-1,-1):
    print(' '*i,'*'*(2*n-1) + '*'*(2*(n-i)))
    
for i in range(1,5):
    print(' '*(2*i) + '*'*( ((n-1)*n) - (4*i)))
    '''
dots = n*2 -1
for i in range(1,6) :
    print(' '*(n-i) + '*'*dots )
    dots += 2
space = 2
dots -= 6
for i in range(1,5):
    print(' '*space + '*'*dots)
    space +=2
    dots -= 4