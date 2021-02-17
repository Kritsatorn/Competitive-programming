#std06 : Kritsatorn Saengweang 6110500577
#date: 23AUG2018 quiz02
#program: 02_kodPrime.py
#description: 02_kodPrime.py
k = int(input('Enter : '))
def prime(number): 
    return all(number% i for i in range(2,number))
n = k
print(k,' : ',end=' ')

def fuck(n,p):
    #print(n,p)
    if n <= 1 or p > k :
        return 0
    if prime(p) :
        if (n%p) == 0 :
            print(p,end= ' ')
            n = n/p
            return fuck(n,p)
    return fuck(n,p+1)
fuck(n,2)
        