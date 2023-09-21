import re, sys
if not sys.argv[1].endswith('.html'):
  print('Error: Filename should have .html suffix')
  sys.exit()
input = open(sys.argv[1], 'r')
output = open(sys.argv[1].replace('.html', '.txt'), 'w')
output.write(re.sub('<.*?>', '', input.read()))
print(f'Wrote file {sys.argv[1].replace(".html", ".txt")}')
output.close()