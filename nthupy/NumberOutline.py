def my_thesis_format_function(index, parent, depth):
  if depth == 1:
    print('Chapter ', end='')
  elif depth == 2:
    print('Section', end=' ')
  for i in parent:
    print(i, end='.')
  print(f'{index}.', end=' ')

def my_outline_format_function(index, parent, depth):
  if depth == 1:
    for j in range(index):
      print('I', end='')
  elif depth == 2:
    print(chr(index+64), end='')
  elif depth == 3:
    print(index, end='')
  print(end='. ')

def number_outline(l, method, parent=[], depth=1):
  index=0
  for i in l:
    if type(i) is list:
      number_outline(i, method, parent+[index], depth+1)
    else:
      index+=1
      for j in range(depth-1):
        print(end='  ')
      method(index, parent, depth)
      print(i)

# Test
L=['Intro',
['Motivation', 'Contributions'],
'Related Work',
['By Author', 'By Subject'],
'Technical Approach',
['Overview',
['Block Diagram', 'Schematic'],
'Algorithm',
['Static', 'Dynamic'] ],
'Conclusions']
number_outline(L, my_outline_format_function)
print()
number_outline(L, my_thesis_format_function)