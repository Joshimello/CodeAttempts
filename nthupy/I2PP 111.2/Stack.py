stack = []
sqrsum = 0

def init():
  global stack, sqrsum
  stack = []
  sqrsum = 0
  return None

def push(val):
  global stack, sqrsum
  stack.append(val)
  sqrsum += val*val
  return None

def pop():
  global stack, sqrsum
  sqrsum -= stack[-1]*stack[-1]
  stack.pop(-1)
  return None

def top():
  global stack, sqrsum
  return stack[-1]

def getSquareSum():
  global stack, sqrsum
  return sqrsum


print(init())
print(push(1))
print(push(2))
print(pop())
print(push(5))
print(getSquareSum())
print(top())