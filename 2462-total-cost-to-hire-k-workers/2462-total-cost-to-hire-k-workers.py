class Solution(object):
    def totalCost(self, costs, k, candidates):
        n = len(costs)

        left = []
        right = []

        i = 0
        j = n - 1

        while i < candidates and i <= j:
            heapq.heappush(left, costs[i])
            i += 1

        while j >= n - candidates and j >= i:
            heapq.heappush(right, costs[j])
            j -= 1

        ans = 0

        for _ in range(k):
            if not right or (left and left[0] <= right[0]):
                ans += heapq.heappop(left)
                if i <= j:
                    heapq.heappush(left, costs[i])
                    i += 1
            else:
                ans += heapq.heappop(right)
                if i <= j:
                    heapq.heappush(right, costs[j])
                    j -= 1

        return ans