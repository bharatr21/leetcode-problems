class MRUQueue:

    def __init__(self, n: int):
        self.v = []
        for i in range(1, n+1):
            self.v.append(i)
    def fetch(self, k: int) -> int:
        val = self.v[k-1]
        del self.v[k-1]
        self.v.append(val)
        return val

# Your MRUQueue object will be instantiated and called as such:
# obj = MRUQueue(n)
# param_1 = obj.fetch(k)