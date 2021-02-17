# vector.py, written by K.Toto Na MikeLab.net
# Lecture#08, 03Oct2018
 
def minpos(a):
  minv = a[0]
  pos = 0
  for i in range(1, len(a)):
    if a[i] < minv:
      minv = a[i]
      pos = i
  return pos

def delete(a, pos):
  res = []
  for i in range(0, len(a)):
    if i!=pos:
      res.append(a[i])
  return res

def sortasc(a):
  res = []
  while (len(a)>1):  
    minp = minpos(a)
    res.append(a[minp])
    a = delete(a, minp)
    #print(res, a)
  res.append(a[0])
  return res

def maxpos(a):
  maxv = a[0][1]
  pos = 0
  for i in range(1, len(a)):
    if a[i][1] > maxv:
      maxv = a[i][1]
      pos = i
  return pos

def sortdesc(a):
  res = []
  while (len(a)>1):  
    maxp = maxpos(a)
    res.append(a[maxp])
    a = delete(a, maxp)
  res.append(a[0])
  return res

# main begins here
#a = [3,2,7,5,13,11]
#b = [[1,3],[2,2],[3,7],[4,5],[5,13],[6,11]]
#c = [[5,13],[6,11],[3,7],[4,5],[1,3],[2,2]]
# https://mike.cpe.ku.ac.th/01204111/download/amazon_review.txt

def doc2word(d):
  doc = []; dic={}
  for i in d.split():
    doc.append(i.lower())
  return doc

def word2vec(d):
  dic = {}
  for i in d:
    if i in dic.keys():
      dic[i] += 1
    else:
      dic[i] = 1
  return dic

def read_amazon_review(fname):
  res = []
  f = open(fname)
  for i in f:
    res.append(i.strip())
  return res

# main begins here
r = read_amazon_review('amazon.txt')
vec = []

for i in range(0, len(r)):
  #print('['+str(i+1)+']', r[i])
  vec.append(word2vec(doc2word(r[i])))
print(word2vec(doc2word(r) ))