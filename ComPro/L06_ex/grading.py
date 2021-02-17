def kidd(x,av,sd ):
    if x >= av+sd :
        return 'A'
    if x >= av + (sd/2) :
        return 'B'
    if x >= av - (sd/2) :
        return 'C'
    if x >= av - sd :
        return 'D'
    return 'F'


st = input('scores : ')
st = st.split()
lst = []
for i in st :
    lst.append(int(i))
av = sum(lst)/len(lst)
summ = [ (i - av)**2 for i in lst ]
sd = (sum(summ)/(len(lst)-1)) ** 0.5

for i in lst :
    print(kidd(i,av,sd),end=' ')