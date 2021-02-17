import sys
st = input('Input number : ')
st = st.split()
summ = 0 ;  count = 0 
minn = sys.maxsize; maxx = 0
mode = 0
for i in st :
    lst = {}
    num = int(i)
    summ += num
    count += 1
    if minn > num : 
        minn = num
    if maxx < num :
        maxx = num
    if num in lst :
        lst[num] += 1
    else :
        lst[num] = 1
    if lst[num] > mode :
        mode = num
print('Max  = ' , maxx)
print('Min  = ', minn)
print('Mean = ',summ/count)
print('Mode = ',mode)