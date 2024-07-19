class Solution:
    def luckyNumbers (self, matrix: List[List[int]]) -> List[int]:
        m, n = len(matrix), len(matrix[0])
        ans = []
        for row in matrix:
            ix = -1
            min_ = float('inf')
            
            for i in range(n):
                if row[i] < min_:
                    ix, min_ = i, row[i]
            maxc = 0
            for i in range(m):
                if matrix[i][ix] > maxc:
                    maxc = matrix[i][ix]
            
            if row[ix] == maxc:
                ans.append(maxc)
            print(row, ix, maxc)
        return ans


        