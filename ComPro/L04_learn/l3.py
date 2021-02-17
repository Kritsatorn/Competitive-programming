import math
n = input('Enter : ')
def dick(w,x,y):
    if w == 'N' :
        return x,y+1
    elif w == 'W' :
        return x-1,y
    elif w == 'S':
        return x,y-1
    elif w == 'E':
        return x+1,y
x = 0
y = 0 
for i in range(len(n)):
    x , y = dick( n[i] ,x,y)
    print(i,' ',x,' ',y)
dist = math.hypot(x - 0, y - 0)
print(format(dist,'.2f'))