from math import sqrt

class Triangle:
    # accepts the three sides of triangle
    def __init__(self, s0, s1, s2):
        self.s = [s0, s1, s2]

    # return the perimeter of this triangle.
    @property
    def perimeter(self):
        return sum(self.s)

    # return the area of this triangle.
    @property
    def area(self):
        a, b, c = self.s
        s = sum(self.s) / 2
        return sqrt(s * (s - a) * (s - b) * (s - c))


T = int(input())
for t in range(T):
    side = list(map(int, input().split()))
    t = Triangle(side[0], side[1], side[2])
    print(f'{t.perimeter} {t.area:.2f}')
