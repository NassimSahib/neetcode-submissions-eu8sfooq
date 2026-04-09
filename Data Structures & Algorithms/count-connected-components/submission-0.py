class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        # 1. Construire le graphe (liste d'adjacence)
        graph = {i: [] for i in range(n)}
        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)

        visited = set()

        # 2. DFS récursif
        def dfs(node):
            visited.add(node)
            for nei in graph[node]:
                if nei not in visited:
                    dfs(nei)

        # 3. Compter les composantes
        count = 0
        for i in range(n):
            if i not in visited:
                dfs(i)
                count += 1

        return count



