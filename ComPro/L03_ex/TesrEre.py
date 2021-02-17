n = int(input('ENer : '))
def fuck(prime):
    
    p = 2
    while( p*p < n):
        if prime[p] == True :
            for i in range(p*2,n+1,p):
                prime[i] = False
        p += 1
   
prime = [True for i in range(1,n+2)]
fuck(prime)
for i in range(1,n):
    print(i, ' ',prime[i])
