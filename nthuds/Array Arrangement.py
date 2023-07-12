cases = int(input())
for _ in range(cases):
  n, q = map(int, input().split(' '))
  H = []
  T = []
  M = list(range(1, n+1))
  for _ in range(q):
    c, t = input().split(' ')
    t = int(t)
    if c == 'H':
      # H.append(t)
      M[t-1] = 'H'
    else:
      # T.append(t)
      M[t-1] = 'T'

  V = [False] * 10
  for i in H[::-1]:
    if V[i-1] or M[i-1] != 'H':
      continue
    print(i, end=' ')
    V[i-1] = True

  for i in M:
    if type(i) == int:
      print(i, end=' ')

  temp = []
  for i in T[::-1]:
    if V[i-1] or M[i-1] != 'T':
      continue
    temp.append(i)
    V[i-1] = True

  for i in temp[::-1]:
    print(i, end=' ')

  print()