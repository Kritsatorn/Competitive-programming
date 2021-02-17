# -*- coding: utf-8 -*-
#std06: Kritsatorn Saengweang 6110500577
#date: 09SEP18
#program: L04M03.py
#description  
morse = {'A':".-", 'B':"-...", 'C':"-.-.", 'D':"-..", 'E':".", 'F':"..-.", 'G':"--.", 'H':"....", 'I':"..",
'J':".---", 'K':"-.-", 'L':".-..", 'M':"--", 'N':"-.", 'O':"---", 'P':".--.", 'Q':"--.-", 'R':".-.", 'S':"...",
'T':"-", 'U':"..-", 'V':"...-", 'W':".--", 'X':"-..-", 'Y':"-.--", 'Z':"--.."}
n = input('Enter : ')
for i in n :
    if (i >= 'a' and i <= 'z') :
        i = i.upper()
    if ( i >='A' and i <= 'Z'):
        print(morse[i])
    else :
        print('\n\n')