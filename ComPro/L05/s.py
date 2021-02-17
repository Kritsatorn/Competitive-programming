ls = [ i for i in range(1,53)]   
n = int(input('Enter : '))
while True :
    m = len(ls)
    if m == 1 :
        break
    for i in range(n) :
        tmp = ls[m-1]
        ls.remove(tmp)
        ls.insert(0,tmp)
    #print(ls[m-1])
    ls.remove(ls[m-1])
print(ls[0])