def reverse(L):
    newL = L[::-1]
    for idx, i in enumerate(newL):
        if type(i) == list:
            newL[idx] = reverse(newL[idx])

    return newL

T = int(input())
for t in range(T):
    L = eval(input())
    rL = reverse(L)
    print(L)
    print(rL)