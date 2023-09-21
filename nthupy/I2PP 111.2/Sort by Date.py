def sec(S):
    Y = int(S[-4:]) * 365
    M = int(S[:2]) * 30
    D = int(S[2:4]) * 1
    
    return Y + M + D

def sort_by_date(L):
    L.sort(key=sec)

T = int(input())
for t in range(T):
    date_list = input().split()
    sort_by_date(date_list)
    print(date_list)