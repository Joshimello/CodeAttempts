while True:
  try:
    [name, a, b, add] = input().split(',')

    a = round(int(a.split('/')[0]) / int(a.split('/')[1]) * 40, 2)
    b = round(int(b.split('/')[0]) / int(b.split('/')[1]) * 60, 2)

    print('Student_Name:%s,Final_Score:%.2f' % (name, a + b + int(add)))

  except EOFError as e:
    break