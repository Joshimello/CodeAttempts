print('customers: What are you serving today?')
menulist = input('server: We have ').split(', ')

menu = {}
for i in menulist:
  menu[i.split(' ($')[0]] = {
    'price': int(i.split(' ($')[1].replace(')', '')),
    'count': 0
  }

# print(menu)

for i in range(1, 5):
  order = input(f'customer{i}: ')
  for j in order.split(', '):
    # print(menu[j])
    menu[j]['count'] += 1

total = 0
print('server: Okay you ordered ', end='')
for i in menu:
  if menu[i]['count'] != 0:
    print(f'{i} * {menu[i]["count"]}, ', end='')
    total += menu[i]['price'] * menu[i]['count']
print(f'${total} in total.')