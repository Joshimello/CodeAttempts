import datetime
class DaysInYear:
  def __init__(self, year):
    self.year = year

  def __getitem__(self, i):
    if i < 0 or i >= self.num_days_in_year():
      raise StopIteration
    return datetime.date(self.year, 1, 1) + datetime.timedelta(i)

  def num_days_in_year(self):
    return 366 if self.year % 4 == 0 and (self.year % 100 != 0 or self.year % 400 == 0) else 365

# test uwu
y = DaysInYear(2019)
print(y[5])
print(y[364])
print(y[31])
print(y[365])