n = input('ENter')
t = ''
l = []
for i in n :
    if not (i == ','):
        t += i
    else :
        l .append(t)
        t = ''
l .append(t)
print(l)
