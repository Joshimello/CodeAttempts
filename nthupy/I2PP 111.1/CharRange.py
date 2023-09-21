def CharRange(start, end):
  start_code = ord(start)
  end_code = ord(end)

  if start_code > end_code:
    for code in range(start_code, end_code - 1, -1):
      yield chr(code)
  else:
    for code in range(start_code, end_code + 1):
      yield chr(code)

# test uwu
cr = CharRange('A', 'E')
print(list(cr))
# ['A', 'B', 'C', 'D', 'E']
dr = CharRange('E', 'A')
print(list(dr))
# ['E', 'D', 'C', 'B', 'A']