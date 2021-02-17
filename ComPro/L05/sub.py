a = input('ENter : ')
b = input('Enter : ')
n = len(a)
m = len(b)
for i in range(n) :
    if a[i] == b[0] :
        ans = True
        for j in range(m) :
            if not (a[i+j] == b[j] ):
                ans = False
print(ans)
            