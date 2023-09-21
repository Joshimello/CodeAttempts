IN = []
while True:
  try:
    IN.append(input())
  except EOFError:
    break

CHARS = {}
for l in IN:
  for c in l.replace(' ', ''):
    if c in CHARS:
      CHARS[c] += 1
    else:
      CHARS[c] = 1

CHARS = {k: v for k, v in sorted(CHARS.items(), key=lambda i: i[1], reverse=True)}
SWAP = {' ': ' '}
temp = ord('a')
for c in CHARS:
  SWAP[c] = chr(temp)
  temp += 1

OUT = []
for l in IN:
  newl = ""
  for c in l:
    newl += SWAP[c]
  OUT.append(newl)

print('\n'.join(OUT))