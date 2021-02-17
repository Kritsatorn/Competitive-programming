#std06 : Kritsatorn Saengweang 6110500577
#date: 23AUG2018 quiz02
#program: 01_primeFactorization.py
#description: 01_primeFactorization.py
def prime(number): 
    return all(number% i for i in range(2,number))
k = int(input('Enter : '))
ans1 = False
ans2 = False
n = k
if prime(n) :
    ans1 = True
str_n = str(n)
l = len(str_n)
for i in range(1,l) :
    str_n = str(n)
    tmp=''
    for j in range(0,len(str_n)-1) :
        tmp += str_n[j]
    n = int(tmp)
    print(tmp)



