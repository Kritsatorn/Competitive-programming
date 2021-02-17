import math
aa = math.factorial(100)
ab = 0
while(aa>0):
    ab+=aa%10
    aa=aa//10
print(ab)
d1 = 0
d2 = 1
count = 1
while(True):
    if(d2 > 10e30 ):
        break
    else:
        count+=1
        tmp = d2; d2 = d2+d1; d1=tmp
print('ans ',count)