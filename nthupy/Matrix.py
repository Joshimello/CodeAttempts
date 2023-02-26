import itertools

class Matrix:
    def __init__(self, data):
        self.data = data
        self.nrows = len(data)
        self.ncolumns = len(data[0]) if data else 0
    
    def row(self, r):
        return self.data[r]
    
    def column(self, c):
        return [row[c] for row in self.data]
    
    def __getitem__(self, ij):
        i, j = ij
        return self.data[i][j]
    
    def __setitem__(self, ij, val):
        i, j = ij
        self.data[i][j] = val
    
    def transpose(self):
        return Matrix(list(itertools.longest_zip(*self.data)))
    
    def randomize(self):
        import random
        data = [list(row) for row in self.data]
        random.shuffle(data)
        return Matrix(data)
    
    def __matmul__(self, other):
        result = [[0] * other.ncolumns for _ in range(self.nrows)]
        for i in range(self.nrows):
            for j in range(other.ncolumns):
                result[i][j] = sum(self[i, k] * other[k, j] for k in range(self.ncolumns))
        return Matrix(result)