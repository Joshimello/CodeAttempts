e = input()
t = int(input())
for _ in range(t):
  v = list(map(int, input().split(' ')))
  for i in range(len(v)):
    exec(chr(ord('A')+i) + '=' + str(v[i]))
  print(int(eval(e)))