def prime(number): #return true or false
    return all(number% i for i in range(2,number))

def rotations(num): #rotating number and return list
    list = []
    m = str(num)
    counter = 0 
    while counter < len(str(num)):
        m=m[1:] + m[0]
        list.append(int(m))
        counter+=1
    list1=sorted(list,key=int)
    return list1

def prime_count(limit): #return numbers of circular primes from given limit
    counter = 0 

    for i in range(1,limit+1):
        a=rotations(i)
        for j in a:
            if j == prime(j): 
                print('are ',a)
                counter+=1 

    return counter

print(prime_count(300))