WC = {}

while True:
  try:
    STR = input().split(' ')
    for i in STR:
      if i in WC:
        WC[i] += 1
      else:
        WC[i] = 1

  except EOFError:
    break

for i in sorted(WC.items(), key=lambda item: item[1])[:3]:
  print(i[0])