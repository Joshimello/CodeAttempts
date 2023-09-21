def Geometric_Sequence(first,common_ratio):
    f = first % 100
    while True:
        yield f
        f = (f % 100 * common_ratio % 100) % 100

T = int(input())
for i in range(1,T+1):
    n,f,cr = list(map(int,input().split()))
    g = Geometric_Sequence(f,cr)
    for j in range(n):
        print(f"Case #{i}_{j}: {next(g)}")