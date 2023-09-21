from fractions import Fraction

def Pi_seq(n):
    for i in range(n):
        yield Fraction((-1) ** i * 4, 2 * i + 1)

T = int(input())
for t in range(T):
    k = int(input())
    Pi = Fraction()
    for t in Pi_seq(k):
        Pi += t
    print(f'{Pi}')