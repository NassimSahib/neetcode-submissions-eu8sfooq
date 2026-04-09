class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        # Construction du graphe (Adjacence)
        g = {i: [] for i in range(n)}
        for u, v in edges:
            g[u].append(v)
            g[v].append(u)

        visited = set()

        def dfs(node):
            visited.add(node)

            for nei in g[node]:
                if nei not in visited:
                    dfs(nei)
        
        count = 0
        for i in range(n):
            if i not in visited:
                dfs(i)
                count += 1
        return count 
        