import statistics
def mode_function2(lst, multiplicity = False):
    maxFreq =  max(map(lst.count, lst))
    modes = [i for i in lst if lst.count(i) == maxFreq]
    return modes if multiplicity else set(modes)

st = input('Input number : ')
st = st.split()
lst = []
for i in st :
    lst.append(int(i))
lst.sort()
print('AV = ',sum(lst)/len(lst))
print('Min = ',lst[0])
print('Max = ',lst[len(lst)-1])
print('Median = ',statistics.median(lst))
#print('Mode = ',statistics.mode(lst))
print('Mode = ',mode_function2(lst))

