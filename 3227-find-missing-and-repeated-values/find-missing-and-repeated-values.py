class Solution:
    def findMissingAndRepeatedValues(self, grid: List[List[int]]) -> List[int]:
        count = [0] * (len(grid)**2)
        for row in grid:
            for elt in row:
                count[elt-1] += 1
        ans = [0,0]

        for i in range(len(count)):
            if count[i] == 0:
                ans[1] = i+1
            elif count[i] == 2:
                ans[0] = i+1
            if ans[0] and ans[1]:
                break
        
        return ans
        