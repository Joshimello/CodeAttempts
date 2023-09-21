import numpy as np

class Matrix:

    def __init__(self, size, m):
        self.m = np.matrix(m)
        self.s = size

    # create a new Matrix with the value of current matrix + rhs matrix
    def __add__(self, rhs):
        l = (self.m + rhs.m).tolist()
        l = '\n'.join([' '.join(map(str, i)) for i in l])
        return l

    # create a new Matrix with the value of current matrix - rhs matrix
    def __sub__(self, rhs):
        l = (self.m - rhs.m).tolist()
        l = '\n'.join([' '.join(map(str, i)) for i in l])
        return l

    # create a new Matrix with the value of current matrix * rhs matrix
    def __mul__(self, rhs):
        l = (self.m * rhs.m).tolist()
        l = '\n'.join([' '.join(map(str, i)) for i in l])
        return l

    # output format of Matrix
    def __repr__(self):
        return '\n'.join([' '.join(map(str, self.m[i])) for i in range(self.size)])

T = int(input())
for t in range(T):
    k = int(input())
    m1_list = []
    for _ in range(k):
        m1_list.append(list(map(int, input().split())))

    m2_list = []
    for _ in range(k):
        m2_list.append(list(map(int, input().split())))

    m1 = Matrix(k, m1_list)
    m2 = Matrix(k, m2_list)
    print(m1+m2)
    print(m1-m2)
    print(m1*m2)