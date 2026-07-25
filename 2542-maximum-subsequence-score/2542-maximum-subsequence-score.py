class Solution(object):
    def maxScore(self, nums1, nums2, k):
        pairs = zip(nums2, nums1)
        pairs = sorted(pairs, reverse=True)

        heap = []
        total = 0
        ans = 0

        for n2, n1 in pairs:
            heapq.heappush(heap, n1)
            total += n1

            if len(heap) > k:
                total -= heapq.heappop(heap)

            if len(heap) == k:
                ans = max(ans, total * n2)

        return ans