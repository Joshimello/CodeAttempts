code = [int(x) for x in input().split(' ')]
code.sort()

msg = input().replace('*', ' ')
for i in code:
  print(msg[i-1].upper(), end='')
print()