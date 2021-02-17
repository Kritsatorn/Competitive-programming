f = open('sudoku04.txt')
data = []
for i in f :
    i = i.strip()
    data.append(i.split())
#real_data = []

correct = True 
list_col = [ [0]*len(data) for i in range(len(data)) ] 
list_sq = [ [0]*len(data) for i in range(len(data)) ] 
count_row = 0
count_col = 0
count_sq = 0
for i in range(len(data)) :
    tmp = []
    list_row = []
    for j in range(len(data[i])) :
        h = int(data[i][j])
        # tmp.append(h)
        
        if h in list_row :
            correct = False 
            count_row += 1
        else :
            list_row.append(h)

        if h in list_col[i] :
            correct = False 
            count_col += 1
        else :
            list_col[i].append(h)
        
        chong = (i//3)*3 + j //3
        if h in list_sq[chong] :
            correct = False 
            count_sq += 1
        else :
            list_sq[chong].append(h)

print(correct)
print(count_col , ' ' , count_row , ' ' , count_sq)


        





    


