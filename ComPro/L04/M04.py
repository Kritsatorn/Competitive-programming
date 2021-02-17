# -*- coding: utf-8 -*-
#std06: Kritsatorn Saengweang 6110500577
#date: 09SEP18
#program: L04M03.py
#description  
password = ''
encrypt = { 'a':'m' , 'b':'h' , 'c':'t' ,'d':'f' ,'e':'g',
'f':'k','g':'b', 'h':'p','i':'j' , 'j':'w' ,  'k':'e' , 
'l':'r', 'm':'q' , 'n':'s' ,'o':'l' , 'p':'n' , 'q':'i',
'r':'u', 's':'o', 't':'x', 'u':'z', 'v':'y', 'w':'v',
'x':'d', 'y':'c', 'z':'a' }
decrypt = {encrypt[i]:i for i in encrypt}
which = input('Enter e to encrypt , d to decrypt : ')
while which != 'e' and which != 'd' :
    which = input(' !invalid Enter e to encrypt , d to decrypt : ')
en = (which == 'e')
password_in = input('Password : ')
secureYai = False
secureSpe = False
for ch in password_in :
    YaiMAi = False
    Spe = True
    if ( ch <= 'Z'  and ch >= 'A') :
        YaiMai = True 
        ch = ch.lower()
    #print(ch,'ddddd')
    if (ch <= 'z' and ch >= 'a')  :
        if en :
            k =  encrypt[ch]
        else :
            k =  decrypt[ch]
        if YaiMAi :
            k = k.upper()
        ch = k
        Spe = False

    if YaiMAi :
        secureYai = True
    if Spe :
        secureSpe = True
    password += ch 
    
   # print(ch,'ddd')
print(password)
print(secureYai,secureSpe)
if (secureSpe and secureYai and ( len(password_in) >= 8)) :
    print('secure')
            
        
        


    