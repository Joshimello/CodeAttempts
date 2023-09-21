money = input('How much money do you have? ')
money = int(money)

print('Add an expense or income record with description and amount:')

while(True):
  
  record = input()
  
  if(record == 'exit'):
    break

  money += int(record.split(' ')[1])

print(f'Now you have {money} dollars.')
