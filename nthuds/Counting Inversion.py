def getS(tree, i):
  S = 0
  while i > 0:
    S += tree[i]
    i -= i & (-i)
  return S

def update(tree, n, i, val):
  while(i <= n):
    tree[i] += val
    i += i & (-i)

def getInv(arr, n):
  inv = 0
  M = max(arr)
  B = [0] * (M+1)
  for i in range(n-1, -1, -1):
    inv += getS(B, arr[i]-1)
    update(B, M, arr[i], 1)
  return inv

n = int(input())
arr = list(map(int, input().split(' ')))
print(getInv(arr, n))