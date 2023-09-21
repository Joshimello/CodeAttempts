def evaluate(expr):
    return eval(expr)

T = int(input())
for t in range(T):
    result = evaluate(input())
    print(result)