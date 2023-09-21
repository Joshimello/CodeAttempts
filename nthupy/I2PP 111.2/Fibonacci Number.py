table = [1, 1]
for i in range(30):
    table.append(table[i] + table[i+1])

def fib(n):
    return table[n]

T = int(input())
for t in range(T):
    n = int(input())
    print(fib(n))