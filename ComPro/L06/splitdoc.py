'''
with open("amazon.txt") as f:
    content = f.read()
print(content)
'''
def sp(d):
    doc = []
    for i in d.split() :
        doc.append(i.lower())
    return doc

def tran(d):
    dick = {}
    for i in d :
        if i in dick.keys() :
            dick[i] += 1
        else :
            dick[i] = 1
    return dick

doc = 'I am using this with a Nook HD+. It works as described. The HD picture on my Samsung 52 inch TV is excellent. Samsung is a Korea brand.'
def readfuck(fname):
    res = []
    f = open(fname)
    for i in f :
        res.append(i.strip())
    return res 

#rr = open('amazon.txt', 'r') 
#print (rr.read() )
rr = readfuck('amazon.txt')
rr = sp(rr)
print(rr)
#


#lst = sp(doc)
#print(tran(lst))