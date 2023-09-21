n = int(input())

words = []

while True:
  try:
    words += input().split(' ')
  except EOFError:
    break

def sord(s):
  return sum(map(ord, list(s)))

words = list(map(lambda x: (x, len(x), sord(x)), words))
words.sort(key = lambda x: x[1] * x[2], reverse = True)

for i in words[:n]:
  print(i[0])