#std06: Kritsatorn Saengweang 6110500577
#date: 09AUG18
#program: l01P5.py
#description: print number of possible routes for a TSP problem

import math

city = int(input('How many cities '))
print('For', city, 'cities, there are ', math.factorial(city), 'possible routes')