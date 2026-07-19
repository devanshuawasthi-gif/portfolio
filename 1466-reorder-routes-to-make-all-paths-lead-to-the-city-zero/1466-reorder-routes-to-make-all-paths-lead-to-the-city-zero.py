class Solution(object):
    def minReorder(self, n, connections):
        graph = [[] for _ in range(n)]

        for a, b in connections:
            graph[a].append((b, 1))
            graph[b].append((a, 0))

        visited = [False] * n
        changes = 0

        def dfs(city):
            visited[city] = True

            for next_city, cost in graph[city]:
                if not visited[next_city]:
                    self.ans += cost
                    dfs(next_city)

        self.ans = 0
        dfs(0)

        return self.ans