def CircularPrime():
    numb = input("Enter the number: ")
    flagCircular = True
    def CheckPrime(numb):
        flag = True
        for i in range(numb/2):
            i = i+2
            if numb%i == 0:
                flag = False
                break
        if flag == True:
            return True
        else:
            return False
    for i in range(len(str(numb))):
        if CheckPrime(numb) == True:
            flagCircular = True
        else:
            flagCircular = False
            break
        stringNumb = str(numb)
        firstDigit = stringNumb[0]
        tmpNumb =""
        for j in range(len(str(numb))-1):
            tmpNumb    += stringNumb[j+1]
        tmpNumb += stringNumb[0]
        numb = int(tmpNumb)
    if flagCircular == True:
        print( 'Entered number is a Circular Prime')
    else:
        print ('Entered number is not not Circular Prime')
CircularPrime() 