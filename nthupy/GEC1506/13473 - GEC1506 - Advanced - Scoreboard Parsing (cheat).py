weights = [float(x) for x in input().split(' ')]
users = []

while True:
  try:
    raw = input()
    if raw[0] == 'X':
      for i, u in enumerate(users):
        if u[0].endswith(raw[1:]):
          users[i] = u[0]
    else:
      name = raw.split(',')[1]
      scores = [int(i.split('/')[0]) / int(i.split('/')[1]) for i in raw.split(',')[2:len(weights)+2]]
      ignore = [int(i[1]) - 1 for i in raw.split(',')[len(weights)+3:]]
      users.append([name, scores, ignore])
  except EOFError:
    break

for u in users:
  if type(u) == str:
    print(u, "%.02f"%0, sep=',')
    continue

  scores = [s * (weights[i] / sum(weights)) if i not in u[2] else 0 for i, s in enumerate(u[1])]
  print(u[0], "%.02f" % (sum(scores) * 100), sep=',')