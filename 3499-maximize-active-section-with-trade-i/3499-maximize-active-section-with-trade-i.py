class Solution(object):
    def maxActiveSectionsAfterTrade(self, s):
        blocks = []

        i = 0
        n = len(s)

        while i < n:
            j = i
            while j < n and s[j] == s[i]:
                j += 1
            blocks.append((s[i], j - i))
            i = j

        total = s.count('1')
        ans = total

        for i in range(1, len(blocks) - 1):
            if (blocks[i][0] == '1' and
                blocks[i - 1][0] == '0' and
                blocks[i + 1][0] == '0'):

                gain = blocks[i - 1][1] + blocks[i + 1][1]
                ans = max(ans, total + gain)

        return ans    