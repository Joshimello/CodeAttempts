class Temperature:
  def __init__(self, degree, unit='C'):
    if not isinstance(degree, (int, float)) or degree is True:
      raise ValueError()

    if unit not in ['C', 'F', 'c', 'f']:
      raise ValueError()

    self._degree = degree
    self._unit = unit.upper()

  def set_format(self):
    return f'{self._degree:0.1f} {self._unit}'

  def __repr__(self):
    return self.set_format()

  def get_temp(self, unit='WEE'):
    if self._unit == 'C' and unit == 'WEE':
      return (self._degree, 'C')
    if self._unit == 'F' and unit == 'WEE':
      return (self._degree, 'F')
    if self._unit == 'F' and unit == 'C':
      return (round((self._degree - 32) * 5/9, 1), 'C')
    if self._unit == 'C' and unit == 'F':
      return (round((self._degree * 9/5) + 32, 1), 'F')

  def get_degree(self):
    return self._degree

  def set_degree(self, degree):
    self._degree = degree

  degree = property(get_degree, set_degree)

# Test
c = Temperature(10)
d = Temperature(68, 'F')
print(c)
print(d)
print(c.get_temp())
print(c.get_temp('F'))
print(d.get_temp())
print(d.get_temp('C'))
print(c.degree)
c.degree = 50
print(c.get_temp())
print(c.get_temp('F'))
print(c)