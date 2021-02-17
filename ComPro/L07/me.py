def hi(a):
    return a[0]
filename = 'identify.py'
text = open(filename).read()
fuck = True
pos = 0 ; i = 0 
lst = [] ; check=[]
while fuck :
    fuck = False ; lst_min = []
    idx1 = text.find('#',pos)
    idx2 = text.find('"""',pos)
    idx3 = text.find('\'\'\'',pos)
    if idx1 >= 0 :
        if not idx1 in check :
            tmp = []    ;   tmp.append(idx1) ;  tmp.append('#') ;lst.append(tmp)
        fuck = True
        lst_min.append(idx1+1)   
        check.append(idx1) 
        print(idx1,'  ==  1'  ,pos)
        
    if idx2 >= 0 :
        if not idx2 in check :
            tmp = []    ;   tmp.append(idx2) ;  tmp.append('"""') ;     lst.append(tmp)
        fuck = True
        lst_min.append(idx2+1)  
        check.append(idx2) 
        print(idx2,'  ==  2' ,pos )
    
    if idx3 >= 0 :
        if not idx3 in check :
            tmp = []    ;   tmp.append(idx3) ;  tmp.append('\'\'\'');lst.append(tmp)
        fuck = True
        lst_min.append(idx3+1)
        check.append(idx3) 
        print(idx3,'  ==  3'  ,pos)
    if not len(lst_min) == 0 :
        pos = min(lst_min)
    #print('pos = ',pos)
#=======================

lst.sort(key = hi)
print(lst)

#===========
status = ''
line = ''
p = 0
for i in lst :
    
    if i[0] == '#' :
        pass
    if i[1] == status :
        line += text[p:i[0]+3]
        status = ''    
        continue

    if status == '' :
        status = i[1]
        p = i[0]
    
print(line)
    