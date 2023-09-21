def adder(*a):
    ans = 0
    for idx, num in enumerate(a):
        if idx % 2:
            ans -= num
        else:
            ans += num
    return ans

if __name__ == '__main__':
    t = int(input())
    for i in range(1, t+1):
        args = map(int, input().split())
        print("Case #%d: %d" % (i, adder(*args)))   