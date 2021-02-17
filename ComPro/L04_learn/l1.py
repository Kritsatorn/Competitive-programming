n = int(input('Enter : '))
arr = [110]
arr += [ 0 for i in range(1,8) ]
arr += [17 for i in range(8,21)]
arr += [10 for i in range(21,41)]
arr += [7 for i in range(41,n)]
sum = 0
for i in range(0,n+1):
    #print(i, ' ' ,arr[i])
    sum += arr[i]
print(sum)