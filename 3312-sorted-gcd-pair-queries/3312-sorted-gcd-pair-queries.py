class Solution(object):
    def gcdValues(self, nums, queries):
        maxVal = max(nums)
        freq = [0] * (maxVal + 1)
        for x in nums:
            freq[x] += 1
        cnt = [0] * (maxVal + 1)
        for g in xrange(maxVal, 0, -1):
            total = 0
            for multiple in xrange(g, maxVal + 1, g):
                total += freq[multiple]
            pairs = total * (total - 1) // 2
            multiple = 2 * g
            while multiple <= maxVal:
                pairs -= cnt[multiple]
                multiple += g
            cnt[g] = pairs
        values = []
        prefix = []
        s = 0
        for g in xrange(1, maxVal + 1):
            if cnt[g]:
                values.append(g)
                s += cnt[g]
                prefix.append(s)
        ans = []
        for q in queries:
            idx = bisect_left(prefix, q + 1)
            ans.append(values[idx])
        return ans 