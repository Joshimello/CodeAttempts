table = [[1], [1, 1]]

for i in range(2, 11):
    row = [1]
    for j in range(i-1):
        row.append(sum(table[i-1][j:j+2]))
    row.append(1)
    table.append(row)

def print_pascal(n):
    for i in range(n):
        for j in table[i]:
            print(f'{j:3d}', end='')
        print()

T = int(input())
for t in range(T):
    n = int(input())
    print_pascal(n)