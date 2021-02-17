# -*- coding: utf-8 -*-
#std06: Kritsatorn Saengweang 6110500577
#date: 09SEP18
#program: L04P1.py
#description  
n = int(input('Enter : '))
lst1 = [] 
lst2 = []
for i in range(n) :
    k = int(input('Enter lst 1 : '))
    lst1.append(k)
n = int(input('Enter'))
for i in range(n) :
    k = int(input('Enter lst 2 : '))
    lst2.append(k)
if len(lst1) == len(lst2) :
    print('Same lent')
else :
    print(' not Same lent')
if sum(lst1) ==  sum(lst2) :
    print(' same SUm')
else :
    print('not same Sum')
print('Same vals in both list are :')
for i in lst1 :
    if i in lst2 :
        print(i)
