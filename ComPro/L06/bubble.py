def fuck(a):
    print(a)
    minv = a[0]
    pos = 0
    for i in range( 1 , len(a) ):
        if a[i] < minv :
            minv = a[i]
            pos = [i]
    return pos 

def sortasc(a):
    res = []
    while (len(a) > 1 ):
        minp =  minpos(a)
        res.append(a[minp])
        a = delelet(a,minp)
    res.append(a[0])
    return res


a = [3,4,5,7,1,2,10,20,15]
b = [ [1,3] , [2,2] , [3,7] , [4,5] ,[5,13] , [6,11] ]