class Temperature:

  def __init__(self, value, unit):
    self.value = value
    self.unit = unit

class NewTemp(Temperature):

  def __init__(self, value, unit):
    super().__init__(value, unit)

  def __add__(self, RHS):
    if type(RHS) == NewTemp:
      new_value = self.convert_unit(RHS.value, RHS.unit, self.unit) + self.value
      return NewTemp(new_value, self.unit)
    elif type(RHS) == int or float:
      new_value = RHS + self.value
      return NewTemp(new_value, self.unit)
    else:
      raise TypeError()

  def __sub__(self, RHS):
    if type(RHS) == NewTemp:
      new_value = self.value - self.convert_unit(RHS.value, RHS.unit,
                                                 self.unit)
      return NewTemp(new_value, self.unit)
    elif type(RHS) == int or float:
      new_value = self.value - RHS
      return NewTemp(new_value, self.unit)
    else:
      raise TypeError()

  def convert_unit(self, value, source_unit, target_unit):
    if source_unit == target_unit:
      return value
    elif source_unit == 'C' and target_unit == 'F':
      return value * 9 / 5 + 32
    elif source_unit == 'F' and target_unit == 'C':
      return (value - 32) * 5 / 9
    else:
      raise ValueError()

# test uwu
t = NewTemp(20, 'C')
print(t + 3)
u = NewTemp(30, 'C')
print(t + u)
print(t - u)
print(t.unit)
t.unit = 'F'
print(t)
print(t + u)