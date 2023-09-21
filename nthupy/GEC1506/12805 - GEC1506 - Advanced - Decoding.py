IN = input().lower()
CHARS = {}
for c in IN:
  if c in CHARS:
    CHARS[c] += 1
  else:
    CHARS[c] = 1

CHARS = {k: v for k, v in sorted(CHARS.items(), key=lambda i: i[1], reverse=True)}
SWAP = {n: k for n, k in enumerate(CHARS)}

MAX0 = len(SWAP) - 1

CODE = [len(i) for i in input().split('1')][:-1]
for i, n in enumerate(CODE):
  if n > MAX0:
    CODE[i : i+1] = MAX0, n - MAX0

DECODE = ''
for i in CODE:
  DECODE += SWAP[i]

print(DECODE)