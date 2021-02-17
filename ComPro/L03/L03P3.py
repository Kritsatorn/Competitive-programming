# -*- coding: utf-8 -*-
#std06: Kritsatorn Saengweang 6110500577
#date: 20AUG18
#program: L03P1.py
#description: college credits earned
n = int(input('college credits earned : '))
if n > 90 :
    print('Senior Status')
elif n > 60 :
    print('Junior Status')
elif n > 30 :
    print('Sophomore Status')
else :
    print('Freshman Status')