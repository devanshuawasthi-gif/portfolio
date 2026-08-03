class Solution:
    def maxProfit(self, prices: List[int], fee: int) -> int:
        hold = -prices[0]
        cash = 0

        for price in prices[1:]:
            prev_cash = cash
            cash = max(cash, hold + price - fee)
            hold = max(hold, prev_cash - price)

        return cash