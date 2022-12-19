class NewList(list):

  def __init__(self, lst):
    list.__init__(self, lst)

  def __matmul__(self, RHS):
    result = []
    for l in self:
      for r in RHS:
        result.append((l, r))
    return NewList(result)

  def __rmul__(self, scalar):
    result = []
    if isinstance(scalar, int):
      for l in self:
        result += [l] * scalar
    else:
      for l in self:
        result += [l * scalar]
    return NewList(result)

  def __getitem__(self, itemref):
    if isinstance(itemref, slice):
      start, stop, step = itemref.start, itemref.stop, itemref.step
      if start is None:
        start = 0 if step > 0 else -1
      if stop is None:
        stop = len(self) - 1 if step > 0 else -len(self)
      if step is None:
        step = 1
      stop += 1
      if start < 0:
        start = len(self) + start
      if stop < 0:
        stop = len(self) + stop
      return NewList(list.__getitem__(self, slice(start, stop, step)))
    else:
      if itemref < 0:
        itemref = len(self) + itemref
      return list.__getitem__(self, itemref)

  def __setitem__(self, itemref, val):
    if isinstance(itemref, slice):
      start, stop, step = itemref.start, itemref.stop, itemref.step
      if start is None:
        start = 0 if step > 0 else -1
      if stop is None:
        stop = len(self) - 1 if step > 0 else -len(self)
      if step is None:
        step = 1
      stop += 1
      if start < 0:
        start = len(self) + start
      if stop < 0:
        stop = len(self) + stop
      list.__setitem__(self, slice(start, stop, step), val)
    else:
      if itemref < 0:
        itemref = len(self) + itemref
      list.__setitem__(self, itemref, val)

  def __delitem__(self, itemref):
    if isinstance(itemref, slice):
      start, stop, step = itemref.start, itemref.stop, itemref.step
      if start is None:
        start = 0 if step > 0 else -1
      if stop is None:
        stop = len(self) - 1 if step > 0 else -len(self)
      if step is None:
        step = 1
      stop += 1
      if start < 0:
        start = len(self) + start
      if stop < 0:
        stop = len(self) + stop
      list.__delitem__(self, slice(start, stop, step))
    else:
      if itemref < 0:
        itemref = len(self) + itemref
      list.__delitem__(self, itemref)


print(NewList([6, 7, 8]) @ NewList(['a', 'b']))

print(NewList([6, 7, 8]) * 2)
print(2 * NewList([6, 7, 8]))
print(3 * NewList(['a', 'b', 'c']))

L = NewList(['a', 'b', 'c', 'd', 'e'])
print(L[1])
print(L[5])

print(L[2:3])
print(L[4:2:-1])
print(L[-1])
