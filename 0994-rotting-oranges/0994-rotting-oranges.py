class Solution(object):
    def orangesRotting(self, grid):
        rows = len(grid)
        cols = len(grid[0])

        q = deque()
        fresh = 0

        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == 2:
                    q.append((i, j))
                elif grid[i][j] == 1:
                    fresh += 1

        if fresh == 0:
            return 0

        minutes = 0
        directions = [(1,0), (-1,0), (0,1), (0,-1)]

        while q and fresh > 0:
            size = len(q)

            for _ in range(size):
                r, c = q.popleft()

                for dr, dc in directions:
                    nr = r + dr
                    nc = c + dc

                    if (0 <= nr < rows and
                        0 <= nc < cols and
                        grid[nr][nc] == 1):

                        grid[nr][nc] = 2
                        fresh -= 1
                        q.append((nr, nc))

            minutes += 1

        if fresh == 0:
            return minutes
        else:
            return -1