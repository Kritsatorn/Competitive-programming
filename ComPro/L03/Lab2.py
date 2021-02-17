def prime(number): 
    return all(number% i for i in range(2,number))
    
n = int(input('Enter number : '))
ans = True
digit = len(str(1000))
for i in range(len(str(n))):
    if prime(n) : 
        ans = True
    else :
        ans = False
        break
    
    str_n = str(n)
    First = str_n[0]
    tmp = ''
    for j in range(len(str_n)-1):
        tmp += str_n[j+1]
    tmp += First
    n = int(tmp)
if ans :
    print('Yesssssssssss')
else :
    print('SUS fuck')
    
    
