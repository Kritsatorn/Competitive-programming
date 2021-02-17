
n = int(input())
m = int(input())
data = []
for i in range(n) :
    h = input()
    tmp = [ int(j) for j in h.split()]
    data.append(tmp)
minn = 11111110
for i in range(len(data) ) :
    for j in range(len(data[i]) -1) :

        if i < len(data) - 1 :
            k = data[i][j] + (data[i][j+1] * 1.1) + (data[i+1][j+1] * 1.1) + (data[i+1][j]*1.1)*1.1
            if k < minn : minn = k 
        
        if i > 0 :
            k = data[i][j] + (data[i][j+1] * 1.1) + (data[i-1][j+1] * 1.1) + (data[i-1][j]*1.1)*1.1
            if k < minn : minn = k 

#print(data[i][j] + (data[i][j+1] * 1.1) + (data[i-1][j+1] * 1.1) + (data[i-1][j]*1.1)*1.1)
print(minn)