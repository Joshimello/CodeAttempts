class Polynomial:

  def __init__(self, *coeffs):
    self.coefficients = coeffs

  def __add__(self, other):
    max_len = max(len(self.coefficients), len(other.coefficients))
    new_coeffs = [0] * max_len
    
    for i in range(max_len):
      if i < len(self.coefficients):
        new_coeffs[i] += self.coefficients[i]
      if i < len(other.coefficients):
        new_coeffs[i] += other.coefficients[i]
        
    return Polynomial(*new_coeffs)

  def __sub__(self, other):
    max_len = max(len(self.coefficients), len(other.coefficients))
    new_coeffs = [0] * max_len

    for i in range(max_len):
      if i < len(self.coefficients):
        new_coeffs[i] += self.coefficients[i]
      if i < len(other.coefficients):
        new_coeffs[i] -= other.coefficients[i]

    return Polynomial(*new_coeffs)

  def __imul__(self, other):
    new_coeffs = [0] * len(self.coefficients)

    for i in range(len(self.coefficients)):
      new_coeffs[i] = self.coefficients[i] * other

    return Polynomial(*new_coeffs)

  def __call__(self, x):
    result = 0
    for i in range(len(self.coefficients)):
      result += self.coefficients[i] * x**i
    return result

  def __str__(self):
    return "Polynomial" + str(self.coefficients)


# test uwu
f = Polynomial(3, 2, 0, 5, 4)
g = Polynomial(7, 4, 1)
print(f + g)
print(g - f)
f *= 2
print(f)
print(f(1))
