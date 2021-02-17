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

    

    
#part oopds;
lst_oop = [] 
index = 0
for i in sr :
    m = i.split(',')
    lst_sc = [ int(m[i]) for i in range(2,6)]
    lst_oop.append(student(m[0] , m[1] , lst_sc))

print(lst_oop[0].subjs)
    
