def conv(num,b):
    convStr = "0123456789abcdefghijklmnopqrstuvwxyz"
    if num<b:
        return convStr[num]
    else:
        return conv(num//b,b) + convStr[num%b]  
n = int(input("FUck : "))
w = int(input('To : '))
print (conv(n,w)) #will just return 100