# -*- coding: utf-8 -*-
#std06: Kritsatorn Saengweang 6110500577
#date: 20AUG18
#program: L03M7.py
#description dynamic coin change

import random
import sys
terminate = False
empty_str = ''


def find(num) :
    lc = [sys.maxsize -1 for i in range(num+1)]
    lc[0] = 0 
    arr = [1,5,10,25,50]
    for i in range(len(arr)):
        for j in range(1,num+1):
            if j >= arr[i]:
                if lc[ j-arr[i]] + 1 < lc[j] : 
                    lc[j] = lc[j-arr[i]] + 1 
    return lc[num]
while not terminate:
    amount = random.randint(1,99)
    print('Encet coins that add up to', amount, 'cents, one per 1ine.\n')
    game_over = False
    total = 0
    least_coin = find(amount)
    count_coin = 0
    #print('adadad ',least_coin)
    while not game_over :
        valid_entry = False
        while not valid_entry :
          #  print(' Total = ',total, '\n')
            if total == 0 :
                entry = input('Enter the first coin :')
            else :
                entry = input('Enter the next coin :')
            
            if entry in ( empty_str ,'1','5','10','25','50'):
                valid_entry = True 
            else :
                print('Invalid Entry')
        count_coin += 1
        if entry == empty_str :
            if total == amount :
                print('Correct!')
            else :
                print('Sorry - you only entered',total, 'censt.')

            game_over = True
        else :
         #   total = format(total + entry ,'.1f')
            total = total + float(entry)
            if total > amount : 
                print('Sorry - total amount exceeds  ',amount,' cents.\n')
                game_over = True 
        if least_coin < count_coin :
            print('You entered too much of coins !')
            game_over = True 
        if game_over :
            entry = input('\n Try again (y/n) ?')
            if entry == 'n':
                terminate = True 
print('Thanks')
                
            


