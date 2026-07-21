from collections import deque

class Solution(object):
    def nearestExit(self, maze, entrance):
        m = len(maze)
        n = len(maze[0])

        q = deque()

        row = entrance[0]
        col = entrance[1]

        q.append((row, col, 0))

        visited = set()
        visited.add((row, col))

        directions = [(1,0), (-1,0), (0,1), (0,-1)]

        while q:
            r, c, steps = q.popleft()

            for dr, dc in directions:
                nr = r + dr
                nc = c + dc

                if (0 <= nr < m and
                    0 <= nc < n and
                    maze[nr][nc] == '.' and
                    (nr, nc) not in visited):

                    if nr == 0 or nr == m-1 or nc == 0 or nc == n-1:
                        return steps + 1

                    visited.add((nr, nc))
                    q.append((nr, nc, steps + 1))

        return -1