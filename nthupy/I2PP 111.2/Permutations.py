from itertools import permutations
def permute(nums):
    return [[*i] for i in permutations(nums)]

T = int(input())
for t in range(T):
    nums = list(map(int, input().split()))
    print(permute(nums))