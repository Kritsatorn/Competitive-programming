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

    return ( day +2 )   %7

def splityear(start_str, start , day ):
    tmp = start_str
    for j in range (0,start):
            tmp += '   '

    for i in range ( 0 , day) :
        tmp+= format( i +1 , '=3') 
        if ( i + start +1 ) % 7 == 0 :
            tmp+=','

    return tmp.split(', ')

def month ( y ):
    lst = []
    months = ['', 'January', 'February', 'March', 'April', 'May', 'June', 'July', 'August','September','October','November','December']
    fuck = ' Su Mo Tu We Th Fr Sa'

    for m in range( 1 , 13 ): 
        start_str = ''

        headLine = months[m] +' '+ str(y)
        headSpace = (22 - len(headLine))//2
        headLine = ' '*headSpace + headLine + ' ' * ( 22 -  ( headSpace +  len(headLine) ))
        start_str += headLine
        start_str += ','

        start_str += fuck + ','
        #print(start_str)
        
        start = startDay ( m ,y )
        day = dayofmonth ( m , y)
        lst.append( splityear(start_str,start,day) )
    #print(lst)
    # FUcking print fucking Calender
    ''' 
    print(lst[0][0] + '  ' + lst[1][0] + '  ' + lst[2][0])
    print(lst[0][1] + '  ' + lst[1][1] + '  ' + lst[2][1])
    print(lst[0][2] + '  ' + lst[1][2] + '  ' + lst[2][2])
    '''
    for i in range( 0,4):
        for j in range( 0 , 6):
            print(lst[ i*3 ][j] + '  ' + lst[ i*3  + 1][j] + '  ' + lst[ i*3  +2][j])
                
        print('\n')
       

        
        


y = int(input('Enter Year : '))
month(y)

    