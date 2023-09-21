stuff = {}

while True:
  try:
    name, what, num = input().split(' ')
    num = int(num)
    if what == 'O':
      num *= -1
    if name.lower() in stuff:
      stuff[name.lower()] += num
    else:
      stuff[name.lower()] = num
  except EOFError:
    break

for i in stuff:
  print(i, stuff[i])