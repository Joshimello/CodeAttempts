class CountingList(list):
  def __init__(self, d=()):
    super().__init__(d)
    self.access_counts = [0] * len(d)

  def __getitem__(self, i):
    if isinstance(i, int):
      self.access_counts[i] += 1
    elif isinstance(i, slice):
      start, stop, step = i.indices(len(self))
      for j in range(start, stop, step):
        self.access_counts[j] += 1
    return super().__getitem__(i)

  def __setitem__(self, i, val):
    if isinstance(i, int):
      self.access_counts[i] += 1
    elif isinstance(i, slice):
      start, stop, step = i.indices(len(self))
      for j in range(start, stop, step):
        self.access_counts[j] += 1
    super().__setitem__(i, val)

  def __iter__(self):
    sorted_list = sorted(zip(self.access_counts, self), reverse=True)
    sorted_values = list(zip(*sorted_list))[1]
    return iter(sorted_values)
    
# test uwu
d = CountingList(('A', 'B', 'C', 'D', 'E'))
print(d[0], d[2], d[2], d[4])
# ('A', 'C', 'C', 'E')
print([d[-1], d[-2], d[4]])
# ['E', 'D', 'E']
for i in d:
  print(i)