a = input().split(' ')
b = input().split(' ')
c = [x for x in a if x not in b]

print(' '.join(c))