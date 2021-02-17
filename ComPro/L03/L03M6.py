# -*- coding: utf-8 -*-
#std06: Kritsatorn Saengweang 6110500577
#date: 20AUG18
#program: L03M6.py
#description add 0.5 coin
import random
terminate = False
empty_str = ' '
while not terminate:
    amount = random.randint(1,99)
    print('Encet coins that add up to', amount, 'cents, one per 1ine.\n')
    game_over = False
    total = 0
    
    while not game_over :
        valid_entry = False
        while not valid_entry :
           # print(' Total = ',total, '\n')
            if total == 0 :
                entry = input('Enter the first coin :')
            else :
                entry = input('Enter the next coin :')
            
            if entry in ( empty_str ,'1','5','10','25','0.5'):
                valid_entry = True 
            else :
                print('Invalid Entry')
        
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
                print('Sorry - total amount exceeds ',amount,' cents.\n')
                game_over = True 
        if game_over :
            entry = input('\n Try again (y/n) ?')
            if entry == 'n':
                terminate = True 
print('Thanks')
                
            
