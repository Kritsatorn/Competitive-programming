def power(a,n) :
    res = 1
    for i in range(n) :
        res *= a 
        return res 
def rpower(a,n) :
    if n ==0 :
        return 1
    tmp = rpower( a, n//2)
    if n%2 == 0 :
        count += 1 
        return tmp*tmp
    
        