Prod = {
  'pie':        { 'f': 0.5, 'b': 0.2                           },
  'cheesecake': { 'f': 1,   'b': 0.2, 'e': 2, 'c': 2, 's': 0.1 },
  'baguette':   { 'f': 3                                       },
  'croissant':  { 'f': 2,   'b': 1,   'e': 1,         's': 0.5 }
}

Stock = { 'f': 0, 'b': 0, 'e': 0, 'c': 0, 's': 0 }

while True:
  try:
    action, item, count = input().split(' ')
    count = int(count)
    if action == 'restock':
      if item[0] in Stock:
        Stock[item[0]] += count
      else:
        Stock[item[0]] = count
    if action == 'record':
      for ing in Prod[item]:
        Stock[ing] -= Prod[item][ing] * count
        if Stock[ing] < 0:
          Stock[ing] = 0
  except EOFError:
    break

Dict = {
  'f': 'flour',
  'b': 'butter',
  'e': 'egg',
  'c': 'cheese',
  's': 'sugar'
}

for i in sorted(Stock, key=lambda i: i[0]):
  if Stock[i] > 0:
    print(Dict[i], '%.01f' % float(Stock[i]))