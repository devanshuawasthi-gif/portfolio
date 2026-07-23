class Solution:
    def uniqueXorTriplets(self, nums):
        n = len(nums)
        if n < 3:
            return n
        bits = 0
        while(1 << bits) <= n:

            bits += 1
        return 1 << bits