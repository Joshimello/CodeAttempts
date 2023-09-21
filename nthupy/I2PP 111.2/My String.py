class MyString(str):
    def __lshift__(self,val):
        if len(self) == 0:
            return self
        return self[val:] + self[:val]

    def __rshift__(self,val):
        if len(self) == 0:
            return self
        return self[len(self) - val:] + self[:len(self) - val]

T = int(input())
for i in range(1,T+1):
    s = MyString(input())
    n1,n2 = map(int,input().split())
    print(f'Case #{i}_1: After left rotate {n1} positions the string will be "{s<<n1}"')
    print(f'Case #{i}_2: After right rotate {n2} positions the string will be "{s>>n2}"')
    print(f'Case #{i}_3: The origin string: "{s}"')