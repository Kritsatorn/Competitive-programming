# -*- coding: utf-8 -*-
#std06: Kritsatorn Saengweang 6110500577
#date: 20AUG18
#program: L03M2.py
#description add kelvin to convert
which = input('Enter selection :')
while which != 'F' and which != 'C' and which != 'K' : 
    which = input(" Please enter  'F' or 'C' or 'K' :") 
temp = int(input('Enter tmp to convert :'))
if which == 'F' :
    ct = format((temp-32)*5/9, '.1f')
    print(temp,' degrees Fahrenheit equals ',ct,' degrees Celsius')
elif which == 'k':
    ct = format(temp + 273.15, '.1f')
    print(temp,' degrees Kelvin equals ',ct,' degrees Celsius')
else :
    ct = format((temp*9/5)+32,'.1f')
    print(temp,' degrees Celsius equals ',ct,' degrees Fahrenheit ')
