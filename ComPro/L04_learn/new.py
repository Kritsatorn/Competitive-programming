n = int(input('Positive  Integer :'))
k = []

for i in range(2,n): 
    ans = True
    for j in range(2,i) :
        if i % j == 0 :
            ans = False
            break
    k += ans
    print(ans)

