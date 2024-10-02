class Solution:
    def arrayRankTransform(self, arr: List[int]) -> List[int]:
        ans = [0] * len(arr)
        v = list(sorted(enumerate(arr), key= lambda x: x[1]))
        print(v)
        for i in range(len(v)):
            if i > 0 and v[i][1] != v[i-1][1]:
                ans[v[i][0]] = ans[v[i-1][0]] + 1
            elif i == 0:
                ans[v[i][0]] = 1
            elif v[i][1] == v[i-1][1]:
                ans[v[i][0]] = ans[v[i-1][0]]
        return ans
        
        