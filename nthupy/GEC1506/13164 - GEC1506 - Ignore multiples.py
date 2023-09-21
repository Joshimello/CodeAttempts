a, b, x, y = input().split(',')

arr = []

c = int(a)
while c < int(b):
  if c%int(x) != 0 and c%int(y) != 0:
    arr.append(c)
  c += 1

print(','.join(map(str, arr)))