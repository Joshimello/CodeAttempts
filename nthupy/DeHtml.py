import re
sampleInput = '<h1>Hello World!</h1>'
print(re.sub('<.*?>', '', sampleInput))