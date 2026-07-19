class Solution(object):
    def findCircleNum(self, isConnected):
        n = len(isConnected)
        visited = [False] * n
        provinces = 0
        def dfs(city):
            visited[city] = True
            for next_city in range(n):
                if isConnected[city][next_city] == 1 and not visited[next_city]:
                    dfs(next_city)
        for city in range(n):
            if not visited[city]:
                dfs(city)
                provinces += 1
        return provinces