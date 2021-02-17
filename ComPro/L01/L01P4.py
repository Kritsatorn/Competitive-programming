#std06: Kritsatorn Saengweang 6110500577
#date: 09AUG18
#program: l01P4.py
#description: print number of possible routes for a TSP problem

k = int(input('Enter leftmost digit:'))
k1 = int(input('Enter the next digit:'))
k2 = int(input('Enter the next digit:'))
k3 = int(input('Enter the next digit:'))
print('The value is',k*8 + k1*4 + k2*2 + k3)    