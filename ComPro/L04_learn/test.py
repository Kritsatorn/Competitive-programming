def ex(amount,k):
    res = amount//k
    rest = amount%k
    return res , rest
n = int(input('ENter : '))
l = int(input('money :'))
a  , b = ex(n,l)
print(a,'===',b)
