class Polynomial:
  def __init__(self, *coeff):
    self.data = []
    for i in coeff:
      self.data.append(i)
  def evaluate(self, xvalue):
    for i in self.data:
      self.data[self.data.index(i)] = i * pow(xvalue, (self.data.index(i)))
    return sum(self.data)

f = Polynomial(3, 5, 4, 7, 1)
print(f.evaluate(3))