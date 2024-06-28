class Solution:
    def maximumImportance(self, n: int, roads: List[List[int]]) -> int:
        ans = 0
        freq = [[0,_] for _ in range(n)]
        for u, v in roads:
            freq[u][0] += 1
            freq[v][0] += 1
        freq.sort(reverse = True)
        val = [0 for _ in range(n)]
        cur = n
        for deg, node in freq:
            val[node] = cur
            cur -= 1
        for u, v in roads:
            ans += val[u] + val[v]
        
        return ans


       


        