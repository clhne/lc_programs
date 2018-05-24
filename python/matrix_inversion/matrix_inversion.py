import numpy as np
from numpy.linalg import inv
a = np.array([[1, -1],[1, 1]])
#print('a:',a)
print(inv(a))
b = np.array([[2, 5],[-3, -7]])
#print('b:',b)
print(inv(b))
c = np.array([[4, 3],[-3, -2]])
#print('c:',c)
print(inv(c))
d = np.array([[5, -1, -1, -1],[-1, 5, -1, -1],[-1, -1, 5, -1],[-1, -1, -1, 5]])
print(d)
print(inv(d))