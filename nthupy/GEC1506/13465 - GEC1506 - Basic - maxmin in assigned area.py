ar = input().split(',')

i = [x for x in ar if x[0] == 'i']

if not i:
  print(None)
  exit()

ar.pop(ar.index(i[0]))

fb = [x for x in ar if x[0] in ['f', 'b']]

if fb:
  ar.pop(ar.index(fb[0]))
  direction, *length = fb[0]
  length = int(''.join(length))

  if length == 0:
    print(None)
    exit()

  if direction == 'f':
    ar = ar[0:length]
  else:
    ar = ar[0-length:]

ar = map(int, ar)

if i[0][1] == '1':
  print(max(ar))
else:
  print(min(ar))