

def maxp( b ):
    maxv = b[0][1]
    maxpos = 0
    for i in range( 1 , len(b) ):
        if b[i][1] > maxv :
            maxv = b[i][1]
            maxpos = i
    return maxpos

lst = []
b = [ [1,3] , [2,2] , [3,7] , [4,5] ,[5,13] , [6,11] ]
doc = 'I am using this with a Nook HD+. It works as described. The HD picture on my Samsung 52 inch TV is excellent. Samsung is a Korea brand.'
for j in range( 0, len(b) ):
    maxpos = maxp(b)
    lst.append(b[maxpos])
    b.remove(b[maxpos])
print(lst)
