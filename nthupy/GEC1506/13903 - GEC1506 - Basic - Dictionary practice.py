def m(f1, f2, f3):
  return 2 * f1 + 3 * f3
def t(f1, f2, f3):
  return 0.2 * f1 + 5 * f3 + 20
def w(f1, f2, f3):
  return 0.5 * f1 + 4 * f3 + 10
def r(f1, f2, f3):
  return 0.35 * f1 + 7 * f3 + 20
def f(f1, f2, f3):
  return 0.2 * f1 + 5 * f2 + 100
def s(f1, f2, f3):
  return 0.8 * f1 + 15 * f2 + 105

def p(f):
  return round(f(*map(int, input().split(" "))))

print(f'Monday:{p(m)}')
print(f'Tuesday:{p(t)}')
print(f'Wednesday:{p(w)}')
print(f'Thursday:{p(r)}')
print(f'Friday:{p(f)}')
print(f'Sunday:{p(s)}')