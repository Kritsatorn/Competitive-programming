import numpy 
a = numpy.array([1,2,3,4])
print(a+1)
print(a*10)
print(a+a)

import numpy as np 
a = np.array([[1,2,3],[4,5,6]])
b = np.array([[7,8,9],[0,1,6]])
print(a)
print(np.sqrt(a))
print('FUck')
#a = np.loadtxt('text.txt',delimiter=',' )
print(a.ndim)
print(a.shape)
print(a.size)
print(a.T)
print(a*b)

c = np.matrix([[1,2,3],[4,5,6],[0,1,6]])
d = np.matrix([[7,8,9],[0,1,6],[4,5,6]])

print(c*d)

m = np.matrix( [ [1,2,3,4],[1,2,3,4],[1,2,3,4]])
print(m.shape)