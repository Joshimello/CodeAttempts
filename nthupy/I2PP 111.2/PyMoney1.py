# add function
def add(e):
  # try reading format by assigning 2 variables
  try:
    a, b = input('Add expense:\n').split(' ')
    e += [[a, int(b)]]
  # show error when assigning fails
  except:
    print('Expected format: "banana -10"')
  # return e regardless of change
  return e

# view function
def view(e, b):
  print('Your expenses:')
  # loop through list and show
  for n, i in enumerate(e):
    print(f'[{n+1}] {i[0]:<16} {i[1]}')
    b += i[1]
  print('=============================')
  # calculate and show balance
  print(f'Current balance:     {b}')

# delete function
def delete(e):
  # assign index to each item
  for n, i in enumerate(e):
    print(f'[{n+1}] {i[0]:<16} {i[1]}')
  print('=============================')
  d = int(input('Delete which index:\n'))
  # delete if index exists
  if 0 < d < len(e) + 1:
    del e[d - 1]
  # show error otherwise
  else:
    print('Index doesn\'t exist')
  return e

# save function
def save(e, b):
  # open and write list and balance
  f = open('PyMoney1.txt', 'w')
  f.write(f'{b}\n')
  f.writelines([f'{a} {b}\n' for a, b in e])

# init function
def init():
  b = 0
  e = []
  # open file
  try:
    f = open('PyMoney1.txt', 'r')
    # read and parse file data
    try:
      b = int(f.readline())
      e = [[a, int(b)] for a, b in [i.replace('\n', '').split(' ') for i in f.readlines()]]
      print('Welcome back!')
    # show error and reset if file not valid
    except:
      print('Error in saved file, reseting by default')
      return b, e
  # if no save file
  except IOError:
    # ask for init balance
    try:
      b = int(input('Initial balance:\n'))
    # error if input is invalid
    except:
      b = 0
      print('Invalid balance, Set to 0 by default')
  return b, e




bal, exp = init()

while True:
  # ask for action input and assign function to call
  cmd = input('What action(add/view/delete/exit):\n')

  if cmd == 'add':
    exp = add(exp)

  elif cmd == 'view':
    view(exp, bal)

  elif cmd == 'delete':
    exp = delete(exp)

  elif cmd == 'exit':
    save(exp, bal)
    break

  # error if command does not exist
  else:
    print('Invalid command. Try again')