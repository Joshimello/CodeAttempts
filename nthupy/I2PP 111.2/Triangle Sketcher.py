def trisketch(n):
    for i in range(1, n+1):
        for j in range(i):
            print('*', end='')
        print()

T = int(input())
for t in range(T):
    n = int(input())
    trisketch(n)