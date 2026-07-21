class Solution(object):
    def calcEquation(self, equations, values, queries):
        graph = {}

        for i in range(len(equations)):
            a = equations[i][0]
            b = equations[i][1]
            val = values[i]

            if a not in graph:
                graph[a] = []
            if b not in graph:
                graph[b] = []

            graph[a].append((b, val))
            graph[b].append((a, 1.0 / val))

        def dfs(cur, target, product, visited):
            if cur == target:
                return product

            visited.add(cur)

            for nxt, weight in graph[cur]:
                if nxt not in visited:
                    ans = dfs(nxt, target, product * weight, visited)
                    if ans != -1.0:
                        return ans

            return -1.0

        result = []

        for a, b in queries:
            if a not in graph or b not in graph:
                result.append(-1.0)
            elif a == b:
                result.append(1.0)
            else:
                result.append(dfs(a, b, 1.0, set()))

        return result