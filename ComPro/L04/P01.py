# -*- coding: utf-8 -*-
#std06: Kritsatorn Saengweang 6110500577
#date: 09SEP18
#program: L04P1.py
#description  
n = int(input('Enter : '))
lst = []
for i in range(n):
    k = int(input('Enter val in lst : '))
    if ( k >= 1) and ( k <100):
        lst.append(k)
print(lst)

