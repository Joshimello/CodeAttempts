idnum = ''
city = {}

while True:
  try:
    x = input()
    if x.isdigit():
      idnum = x
    else:
      a, n, c = x.split(',')
      city[c] = n
  except EOFError:
    break
# print(city)

op = [9-i for i in range(0, 9)]
op.insert(0, 1)
op.append(1)
# print(op)

for c in city:
  fullid = city[c] + idnum
  ar = [op[idx]*int(i) for idx, i in enumerate(fullid)]
  if sum(ar) % 10 == 0:
    print(c)

# idmulti = [(8-idx)*int(i) for idx, i in enumerate(idnum)]
# idmulti[-1] = int(idnum[-1])
# idsum = sum(idmulti)

# for c in city:
#   if (int(c[1]) + idsum) % 10 == 0:
#     print(c[2])
#     break