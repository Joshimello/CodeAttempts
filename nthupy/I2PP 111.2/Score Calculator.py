from statistics import mean

def average(scores):
    new = list(zip(*scores))
    return map(mean, new)

T = int(input())
for t in range(T):
    k = int(input())
    scores = [map(int, input().split()) for _ in range(k)]
    avers = average(scores)
    for m in avers:
        print(f'{m:.2f}', end=' ')
    print()