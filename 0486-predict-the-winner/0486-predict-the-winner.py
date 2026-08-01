class Solution:
    def predictTheWinner(self, nums):
        def solve(i, j, p1, p2, turn):
            if i > j:
                return p1 >= p2

            if turn:
                return (solve(i + 1, j, p1 + nums[i], p2, False) or
                        solve(i, j - 1, p1 + nums[j], p2, False))
            else:
                return (solve(i + 1, j, p1, p2 + nums[i], True) and
                        solve(i, j - 1, p1, p2 + nums[j], True))

        return solve(0, len(nums) - 1, 0, 0, True)