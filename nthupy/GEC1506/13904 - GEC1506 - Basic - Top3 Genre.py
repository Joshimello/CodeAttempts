g = {}
while True:
  try:
    n, gs, s = input().split(',')
    for i in gs.split('|'):
      if i in g:
        g[i] += [float(s)]
      else:
        g[i] = [float(s)]
  except EOFError:
    break

for i in g:
  g[i] = sum(g[i]) / len(g[i])
  g[i] = int(g[i] * 100) / 100
  g[i] = "{:.2f}".format(g[i])

for i in sorted(g.items(), key=lambda item: item[1])[::-1][:3]:
  print(i[0], i[1], sep=',')