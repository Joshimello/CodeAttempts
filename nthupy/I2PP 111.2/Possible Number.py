from itertools import combinations

t = int(input())
for _ in range(t):

  n, k = map(int, input().split(' '))
  m = [2**i for i in range(n)]
  o = map(sum, combinations(m, k))
  print(f'Case #{_+1}:', sorted(list(o)))