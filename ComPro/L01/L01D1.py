# -*- coding: utf-8 -*-
#std06: Kritsatorn Saengweang 6110500577
#date: 10AUG18
#program: l01D1.py
#description: print years of TSP 
import math
n = int(input('How many cities?'))
con = 24*60*60*365*(10**6)
print('It will take ' + str(math.factorial(n)/con) + ' years')