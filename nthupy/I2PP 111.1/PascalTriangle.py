import math
def print_Pascal_triangle(n):
  # Top row
  print('Col:  ', end='')
  for i in range(n+1):
    print(i, end='  ')
  print()

  # Each n row
  for i in range(n+1):
    print(f'Row{i}:', end='')
    for j in range(i+1):
      num = math.factorial(i)//(math.factorial(j)*math.factorial(i-j))
      print(f'{num:2d}', end=' ')
    print()

# Testing
print_Pascal_triangle(int(input()))