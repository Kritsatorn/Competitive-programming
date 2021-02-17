# -*- coding: utf-8 -*-
"""
Created on Wed Aug 15 10:32:40 2018

@author: kritsatorn
"""

def isPrime(n):
    if(n<2):
        return False
    else:
        i = 2
        while(i<n/2):
            if(n%i==0):return False
    return True
i = 2; sum = 0
while(i<1e6):
    if isPrime(i) :sum+=i
    i+=1
print('ewewe',sum)