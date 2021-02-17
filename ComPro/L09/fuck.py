def countdown(n,text):
    if n <= 0 :
        for i in range(0,len(text)) :
            print(text[len(text) - i - 1] , end='')
        return 
    
    text = text + str(n%10)
    print(n,' ',text)
    countdown(n//10,text)

n = int(input('FUck : '))
countdown(n,'')

