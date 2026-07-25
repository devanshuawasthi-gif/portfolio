class SmallestInfiniteSet:
    def __init__(self):
        self.current = 1
        self.added = set()
        self.heap = []
    def popSmallest(self):
        if self.heap:
            x = heapq.heappop(self.heap)
            self.added.remove(x)
            return x
        x = self.current
        self.current += 1
        return x
    def addBack(self, num):
        if num < self.current and num not in self.added:
            heapq.heappush(self.heap, num)
            self.added.add(num)