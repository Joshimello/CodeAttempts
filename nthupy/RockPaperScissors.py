import random
cpu = random.choice(['r', 'p', 's'])
while(True):
  player = input('rock, paper, scissors? ')
  if cpu == player:
    print(f'I am also {cpu} - tied!')
  elif (cpu =='r' and player == 'p') or (cpu =='p' and player == 's') or (cpu =='s' and player == 'r'):
    print(f'I am {cpu} - I lose!')
  elif (cpu =='p' and player == 'r') or (cpu =='s' and player == 'p') or (cpu =='r' and player == 's'):
    print(f'I am {cpu} - you lose!')
  else:
    res = input(f'{player} is invalid - try again? ')
    if(res == 'quit'):
      print('bye')
      break
    