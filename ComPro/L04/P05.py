# -*- coding: utf-8 -*-
#std06: Kritsatorn Saengweang 6110500577
#date: 09SEP18
#program: L04P1.py
#description  
n = int(input('Enter  : '))
lst = []
for i in range(n) : 
    k = input('Enter First name : ')
    if ( k[0] >= 'A') and ( k[0] <= 'Z') :
        lst.append(k)
print(lst)