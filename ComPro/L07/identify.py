import string
"""
asdsafsSAF
"""


def fuckremove (long_line):
    pos = 0 
    status = True
    while status :
        status = False
        index1 = long_line.find('\"\"\"',pos)
        if index1 >= 0 :
                index2 = long_line.find('\"\"\"',index1+3)
                print(long_line[index1:index2+3])
                pos = index2 + 3
                status = True




filename = 'identify.py'
lines  = open(filename).read()
fuckremove(lines)
"""
fuckkkkkkkkkkkkkkkk
kkkkkkkkkkkkkkkk
"""
'''
sdasdasd''
'''
""""
sdaf
"""

#print(lines)
