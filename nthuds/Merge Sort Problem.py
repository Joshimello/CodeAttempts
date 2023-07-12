input()
a = sorted(map(int, input().split(' ')), reverse=True)
print(' '.join(map(str, a)))