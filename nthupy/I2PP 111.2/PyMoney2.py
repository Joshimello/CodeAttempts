class Record:
  """Represent a record."""
  def __init__(self, category, item, amount):
    self._category = category
    self._item = item
    self._amount = int(amount)

  @property
  def amount(self):
    return self._amount

  @property
  def item(self):
    return self._item

  @property
  def category(self):
    return self._category


class Records:
  """Maintain a list of all the 'Record's and the initial amount of money."""
  def __init__(self):
    try:
      with open('Pymoney2.txt', 'r') as file:
        tempmoney, temprecords = file.readlines()
        self._initial_money = int(tempmoney)
        self._records = []
        for i in eval(temprecords):
          self._records.append(Record(i[2], i[1], i[0]))

    except FileNotFoundError:
      self._initial_money = int(input('initial money: '))
      self._records = []

  def add(self, rawinput, categories):
    category, item, amount = '', '', ''
    try:
      category, item, amount = rawinput.split(' ')
    except:
      print('Invalid input.')
      return

    if not categories.is_category_valid(category):
      print('Invalid category.')

    self._records.append(Record(category, item, amount))
 
  def view(self):
    for index, i in enumerate(self._records):
      print(str(index)+'.', i.category, i.item, i.amount)
    print('Total:', sum([i.amount for i in self._records]))
    print('Balance:', self._initial_money + sum([i.amount for i in self._records]))
 
  def delete(self, itemindex):
    self._records.pop(int(itemindex))    
 
  def find(self, categorylist):
    result = list(filter(lambda i: i.category in categorylist, self._records))
    for i in result:
      print('-', i.category, i.item, i.amount)
    print('Total:', sum([i.amount for i in result]))
 
  def save(self):
    with open('PyMoney2.txt', 'w') as file:
      file.writelines([
        str(self._initial_money) + '\n',
        str([(i.amount, i.item, i.category) for i in self._records])
      ])

class Categories:
    """Maintain the category list and provide some methods."""
    def __init__(self):
        categories = ['expense', ['food', ['meal', 'snack', 'drink'], 'transportation', ['bus', 'railway']], 'income', ['salary', 'bonus']]
        self._categories = categories
    
    def view(self):
        def view_gen(categories, depth=0):
            for cat in categories:
                if type(cat) is list:
                    view_gen(cat, depth+1)
                else:
                    print('  ' * depth + '- '  + cat)
        view_gen(self._categories)

    def is_category_valid(self, category):
        def valid_gen(arr, category):
            if type(arr) is list:
                for item in arr:
                    if valid_gen(item, category):
                        return True
                return False
            else:
                return arr == category
        return valid_gen(self._categories, category)
        
    def find_subcategories(self, category):
        def find_gen(category, categories):
            if type(categories) is list:
                for i, cat in enumerate(categories):
                    if type(cat) is list:
                        yield from find_gen(category, cat)
                    elif cat == category:
                        yield from ([cat] + categories[i+1]) if i+1 < len(categories) and type(categories[i+1]) is list else [cat]
        return list(find_gen(category, self._categories))

import sys
 
categories = Categories()
records = Records()

while True:
  command = input('Action [Add|View|Delete|Categories|Find|Exit] :\n')

  if command == 'add':
      record = input('Add [Category Item Amount] :\n')
      records.add(record, categories)

  elif command == 'view':
      records.view()

  elif command == 'delete':
      delete_record = input("Delete [ItemIndex] :\n")
      records.delete(delete_record)

  elif command == 'view categories':
      categories.view()

  elif command == 'find':
      category = input('Find [Category] :\n')
      target_categories = categories.find_subcategories(category)
      records.find(target_categories)

  elif command == 'exit':
      records.save()
      break

  else:
      sys.stderr.write('Invalid command. Try again.\n')