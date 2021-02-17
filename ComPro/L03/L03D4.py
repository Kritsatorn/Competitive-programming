# -*- coding: utf-8 -*-
#std06: Kritsatorn Saengweang 6110500577
#date: 20AUG18
#program: L03D4.py
#description  mortgage calculator
loan = float(input('Enter Loan AMount : '))
Term = float(input('How many years : '))
n = Term * 12
print('Interest Rate    Monthly Payment ')
for i in range(3,19) :
    r = (0.01*i)/12
    d = ( (( 1 +  r )**n) - 1 ) / (r*(( 1 +  r )**n))
    ans = format(loan/d , '.2f')
    print(i ,'% === ', ans)