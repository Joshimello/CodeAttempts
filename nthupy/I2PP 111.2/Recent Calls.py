class RecentCounter:
    def __init__(self):
        self.log = []

    def ping(self, t):
        self.log.append(t)
        for i, n in enumerate(self.log):
            if n >= t - 3000:
                return len(self.log[i:])

T = int(input())
for t in range(1,T+1):
    counter = RecentCounter()
    calls = list(map(int,input().split()))
    for ind,time in enumerate(calls):
        print(f'Case #{t}_{ind}: {counter.ping(time)}')
