

f = open('kahoot_data.csv')
lst = []
for i in f :
    tmp = i.strip()
    tmp = tmp.split(',')
    lst.append(tmp)
    
#print(lst)
def fuck1() :
    dict_max = {}
    for i in range(1,len(lst)) :
        summ_score = 0
        for j in range(1,len(lst[i])) :
            summ_score += int(lst[i][j])
        dict_max[lst[i][0]] = summ_score

    for w in sorted(dict_max, key=dict_max.get, reverse=True):
        print( w, dict_max[w] )

def fuck2() :
    d = {}
    for i in range(1,len(lst)) :
        d[lst[i][0]] = int(lst[i][5])
    for w in sorted(d, key=d.get, reverse=True):
        print( w, d[w] )
        
def fuck3() :
    dict_max = {}
    for i in range(1,len(lst)) :
        summ_score = 0
        for j in range(1,8) :
            summ_score += int(lst[i][j])
        dict_max[lst[i][0]] = summ_score

    for w in sorted(dict_max, key=dict_max.get, reverse=True):
        print( w, dict_max[w] )

def fuck4() :
    d = {}
    max_0 = 0
    max_0_name =''
    max_1 = 0
    max_1_name = ''
    for i in range(1,len(lst)) :
        count_1 = 0
        count_0 = 0
        lst_tmp = []
        for j in range(1,len(lst[i])) :
            if int(lst[i][j]) > 0 :
                count_1 += 1
            else :
                count_0 += 1

        lst_tmp.append(count_1)
        lst_tmp.append(count_0)

        if count_0 > max_0 :
            max_0 = count_0 
            max_0_name = lst[i][0]
        if count_1 > max_1 :
            max_1 = count_1 
            max_1_name = lst[i][0]    

        d[lst[i][0]] = lst_tmp
    print(max_0_name , 'wronggg : ' , max_0)
    print(max_1_name , ' correctt: ' , max_1 )
    
def fuck5() :
    longest_combo = 0
    longest_name  = ''
    for i in range(1,len(lst)) :
        combo = 0 
        longcombo = 0 
        for j in range(1,len(lst[i])) :
            if int(lst[i][j]) > 0 :
                combo += 1 
                if combo > longcombo :
                    longcombo = combo
            else :
                combo = 0
        if combo > longest_combo :
            longest_combo = combo 
            longest_name = lst[i][0]
    print(longest_name, '  : ' , longest_combo)        

def fuck6():
    lst_tmp = [ 0 for i in range(11)]
    for i in range(1,len(lst)) :
        for j in range(1,len(lst[i])) :
            if int(lst[i][j]) == 0 :
                lst_tmp[j] += 1 
    print(lst_tmp)

def fuck7() :
    lst_tmp = [ 0 for i in range(11)]
    for i in range(1,len(lst)) :
        for j in range(1,len(lst[i])) :
            lst_tmp[j] += int(lst[i][j])
    for i in range(len(lst_tmp)) :
        lst_tmp[i] = lst_tmp[i] / 47 
    print(lst_tmp)

def fuck8():
    dict_max = {}
    for i in range(11,21) :
        summ_score = 0
        for j in range(1,len(lst[i])) :
            summ_score += int(lst[i][j])
        dict_max[lst[i][0]] = summ_score

    for w in sorted(dict_max, key=dict_max.get, reverse=True):
        print( w, dict_max[w] )

def fuck9():
    dict_max = {}
    for i in range(1,len(lst)) :
        summ_score = 0
        for j in range(1,len(lst[i])) :
            summ_score += int(lst[i][j])
        dict_max[lst[i][0]] = summ_score / 10

    for w in sorted(dict_max, key=dict_max.get, reverse=True):
        print( w, dict_max[w] )
def fuck10() :
    minn_score = 100000 
    minn_name = ''
    for i in range(1,len(lst)) :
        if minn_score > int(lst[i][8]) and  int(lst[i][8]) > 0:
            minn_score =int(lst[i][8])
            minn_name = lst[i][0]
    print(minn_name, ' ' , minn_score )

    

def fuck11():
    dict_max = {}
    for i in range(1,len(lst)) :
        summ_score = 0
        for j in range(1,len(lst[i])) :
            summ_score += int(lst[i][j])
        dict_max[lst[i][0]] = summ_score
    count = 0 
    score = 0 
    for w in sorted(dict_max, key=dict_max.get, reverse=True):
        count += 1
        if count == 27 or count == 28 :
            score += dict_max[w]
    print(score/2)

        #print( w, dict_max[w] )
    
def fuck12() :
    dict_max = {}
    max_score = 0
    for i in range(1,len(lst)) :
        summ_score = 0
        for j in range(1,len(lst[i])) :
            if int(lst[i][j]) > 0 :
                summ_score +=  1 
        dict_max[lst[i][0]] = summ_score
        if max_score < summ_score :
            max_score = summ_score
    count = 0
    for w in sorted(dict_max, key=dict_max.get, reverse=True):
        if max_score == dict_max[w] :
            print( w)
            count += 1
        else :
            print('Total : ',count)
            break
def fuck13() :
    
    dict_max = {}
    for i in range(1,len(lst)) :
        summ_score = 0
        for j in range(1,len(lst[i])) :
            summ_score += int(lst[i][j]) * j
        dict_max[lst[i][0]] = summ_score

    for w in sorted(dict_max, key=dict_max.get, reverse=True):
        print( w, dict_max[w] )


fuck1()
#print(sorted(dict_max, key=dict_max.get, reverse=True))
#print(dict_max) 

