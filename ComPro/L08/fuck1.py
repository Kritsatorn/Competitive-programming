f = open('scores.txt') 
sr = []
for i in f :
    sr.append(i.strip())
#print(sr)

class student :

    def __init__(self, name,sub_name, lst_score):
        self.name = name
        self.subjs = []

    def add_subj(self, name, lst_score):
        self.subjs.append(subject(name, lst_score))

class subject :
    def __init__(self, sname, score):
        self.sname = sname
        self.score = score

    

    



# part dict
    
    
    
    
    
dic_student = {}


for i in sr :
    
    m = i.split(',')
    if not m[0] in dic_student :
        dic_student[m[0]] = {}
    tmp = [ m[j] for j in range(2,6)]
    dic_sub = {}
    dic_sub[m[1]] = tmp 
    dic_student[m[0]].append(dic_sub[m[1]] )
    print(dic_student[m[0]])
    '''
lst1 = [1,'s']
lst2 = ['b',2]
print(list(lst1) + list(lst2))
print(lst1 + lst2)
    '''