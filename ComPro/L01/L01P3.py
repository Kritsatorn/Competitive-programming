# -*- coding: utf-8 -*-
#std06: Kritsatorn Saengweang 6110500577
#date: 09AUG18
#program: l01P3.py
#description: Write a simple Python program that displays the following powers of 2, one per line: 2 1 , 2 2 , 2 3 , 2 4 , 2 5 ,2 6 , 2 7 , 2 

v = int(input('What base?'))
n = int(input('What power of ' + str(v) + ' ?'))
print(str(v) +' to the power of '+ str(n)+' is '+ str(v**n))