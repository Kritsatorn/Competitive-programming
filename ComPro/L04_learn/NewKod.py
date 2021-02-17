def fuck(n):
    
    p = 2
    while ( p*p < n):
        if prime[p] == True :
            for i in range(p*2,n,p):
                prime[i] = False
        p =+ 1
    

n = int(input('ENter: '))
prime = [True for i in range(1,n+1)]

k = n
k2 = n
fuck(n)
st = str(k)
l = len(st)
for i in range(1,l):
    
    st = str(k)
    first = st[0]
    tmp = ''
    l = len(st)
    for j in range(1,l):
        tmp += st[j]
    k = int(tmp)
    print(k,' === ',prime[k])

    st2 = str(k2)
    l2 = len(st2)
    last = st2[l2-1]
    tmp = ''
    for o in range(0,l2-1):
        tmp += st2[o]
    k2 = int(tmp)
    print(k2,' === ',prime[k2])
