import keyword
import operator
f = open('fuck2.py')
text = f.read()
text1 = text.split()
data = dict((i, 0) for i in keyword.kwlist)
for i in text1 :
    if i in keyword.kwlist :
        data[i] += 1

for i in data :
    if data[i] != 0 :
        print(i,' ',data[i])

