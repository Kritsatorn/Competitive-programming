def isLeap(n):
    if ( y % 4 == 0 ) and ( not( y % 100 == 0 ) or  ( y % 400 == 0)) :
        return True 
    return False

def dayofmonth ( m , y ):
    if m in (1,3,5,7,8,10,12):
        return 31
    elif m in ( 4,6,9,11) :
        return 30
    elif isLeap(y) :
        return 29 
    else :
        return 28

def startDay( m , y ):
    day = 0 
    for i in range( 1900 , y ):
        if isLeap(i) :
            day += 366 
        else :
            day += 365
    
    for i in range ( 1 , m ):
        day += dayofmonth(i,y)

    return ( day +2 ) % 7

m  = int(input('Enter month : '))
y = int(input('Enter Year : '))

start = startDay ( m ,y )
da = dayofmonth ( m , y)

print(' Su Mo Tu We Th Fr Sa')
print('start = ',start , ' da = ',da)

for j in range (0,start):
        print('   ',end='')
for i in range ( 0 , da) :
    
    print( format( i+1 , '=3') , end='')
    if ( i + start +1 ) % 7 == 0 :
        print('')

