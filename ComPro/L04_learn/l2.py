h = int(input('Enter : '))
m = int(input('Enter : '))
n = int(input('Enter : '))
sum1 = m-n
ans = h // sum1
if( h%sum1 <= m):
    ans += 1
print(ans)