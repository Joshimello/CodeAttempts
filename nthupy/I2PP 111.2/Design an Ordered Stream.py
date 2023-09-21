class OrderedStream:

    def __init__(self, n: int):
        self.ptr = 0
        self.data = list([None] * n)

    def insert(self, idKey: int, value: str):
        self.data[idKey - 1] = value

        arr = []
        
        start = self.ptr
        for i in self.data[start:]:
            if i == None:
                break
            else:
                arr.append(i)
                self.ptr += 1

        return arr

stream = OrderedStream(5)
print(stream.insert(5, "ccccc"))
print(stream.insert(4, "aaaaa"))
print(stream.insert(3, "bbbbb"))
print(stream.insert(2, "eeeee"))
print(stream.insert(1, "ddddd"))
