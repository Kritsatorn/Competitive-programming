# -*- coding: utf-8 -*-
#std06: Kritsatorn Saengweang 6110500577
#date: 20AUG18
#program: L03P5.py
#description:  positive and negative integer 

count1 = 0
count2 = 0
count3 = 0
while True:
    k = int(input('Enter integer : '))
    if k == 0 :
        break
    if k > 0 :
        count1 += 1
    elif k < 0 :
        count2 += 1
    
print(' number of  positive values entered : ',count1)
print(' number of  negative  values entered : ',count2)
