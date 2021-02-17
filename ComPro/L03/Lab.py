import math
a = [math.factorial(i) for i in range(0,11) ]
for i in range(0,10):
    print(i,a[i])

def fuck(n):
    total = 0 
    tmp = n
   # print(tmp)
    
    while( tmp > 0):
        
        k = tmp%10 
           # print('hi ',k,' ',a[k] )
        total += a[k]
        if total > n :
            break
        tmp = tmp// 10

    if total == n :
        return True
    else :
        return False
    
#print(fuck(145))
summ = 0 
for i in range(3,10000000):
    if fuck(i) :
        summ += i
        print(i)
print(summ)
    
    
