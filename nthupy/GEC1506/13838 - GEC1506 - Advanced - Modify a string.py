# string = input()[1 : -1]

# string = '"hello, world!""python"'

# array = list(filter(None, string.split('\"')))

# for i in array:
#   if len(i) % 2 == 0:
#     i = i[0 : int(len(i) / 2) - 1] + '42' + i[int(len(i) / 2) + 1 : ]
#   else:
#     
#   print(f'"{i}"', end = '')


i = "hello, world!"
if len(i) % 2 == 0:
  i = i[0 : int(len(i) / 2) - 1] + '42' + i[int(len(i) / 2) + 1 : ]
else:
  i = (i[0].upper() + i[1 : ])[::-1]
print(i)