def read(file) :
    res = ''
    file = open(file)
    for i in file :
        res = res + ' ' + i

def docv(docsp) :
    dic = {}
    for i in docsp :
        if i in dic.keys() :
            dic[i] += 1
        else :
            dic[i] = 1
    return dic

file = 'C:/Users/kritsatorn/Desktop/amazon_review.txt'

doc = read(file)
print(doc)
docsp = doc.lower()
docsp = docsp.split()
print(docsp)
print(docv(docsp))

