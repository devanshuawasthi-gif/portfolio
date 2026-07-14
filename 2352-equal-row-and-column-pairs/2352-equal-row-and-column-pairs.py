class Solution:
    def equalPairs(self, grid):
        rows = {}

        # Count each row
        for row in grid:
            t = tuple(row)
            rows[t] = rows.get(t, 0) + 1

        ans = 0
        n = len(grid)

        # Check each column
        for j in range(n):
            col = []
            for i in range(n):
                col.append(grid[i][j])

            ans += rows.get(tuple(col), 0)

        return ans