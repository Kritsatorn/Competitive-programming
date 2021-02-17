n = int(input('Entuer : '))
for i in range(0,n-1):
    print( ' ' * i + '*' + ' '*(n-2-i) + '*' + ' '*(n-2-i) + '*' + ' '* i)
for i in range(n+n-1):
    print('*',end='')
print()
for i in range(n-2,-1,-1):
    print( ' ' * i + '*' + ' '*(n-2-i) + '*' + ' '*(n-2-i) + '*' + ' '* i)