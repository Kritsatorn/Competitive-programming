def readTextFile(fname ):
    fd = open('name.py','r')
    text = fd.read()
    fd.close()
    return text

def writeTextFile(fname, s):
    fd = open(fname,'w')
    fd.write(s)
    fd.close()
    return True

def count(fname) :
    text =  readTextFile(fname)
    count = 0 
    for i in text:
        if i=='{':
            count+=1
        elif i=='}' :
            count+=1
        else:
            continue
    if count ==0:
        return True
    else:
        return False
    

        


s = readTextFile('fuck.py')
print(s)
writeTextFile('fuck.py',s)
news = readTextFile('fuck.py')
print(news)

