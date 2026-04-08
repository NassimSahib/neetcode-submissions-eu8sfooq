class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        g = defaultdict(list)

        for n1, n2 in edges:
            g[n1].append(n2)
            g[n2].append(n1)
        
        visited = set()
        def dfs(i, prev):
            if i in visited:
                return False
            
            visited.add(i)
            for nei in g[i]:
                if nei == prev:
                    continue
                if not dfs(nei, i):
                    return False
            return True
        
        return dfs(0,-1) and n == len(visited)
        