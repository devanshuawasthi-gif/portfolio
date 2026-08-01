class Solution:
    def numTilings(self, n: int) -> int:
        MOD = 10**9 + 7

        if n == 1:
            return 1

        dp0, dp1 = 1, 1      
        g0, g1 = 0, 0        

        for i in range(2, n + 1):
            g = (g1 + dp0) % MOD
            dp = (dp1 + dp0 + 2 * g1) % MOD

            dp0, dp1 = dp1, dp
            g0, g1 = g1, g

        return dp1