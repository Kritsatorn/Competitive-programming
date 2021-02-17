
sr = input("Enter sentence : ")
word = input("Enter word : ")

sr.lower()
word.lower()

ans = ''
i = 0
while i < len(sr):
    same = False 
    if sr[i] == word[0] :
        same = True
        for j in range(0,len(word)) :
            if sr[ i + j ] != word[j] :
                same = False 
                break
    if same :
        ans = ans + '<' + word + '>'
        i = i + len(word) 
        
    else :
        ans = ans + sr[i]
        i +=1
   
    
print( ans) 


