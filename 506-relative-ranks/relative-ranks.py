class Solution:
    def findRelativeRanks(self, score: List[int]) -> List[str]:
        sorted_list = sorted(enumerate(score), key = lambda x : -x[1])
        ans = ["" for _ in range(len(score))]
        for i in range(len(sorted_list)):
            position = sorted_list[i][0]
            if(i == 0):
                ans[position] = "Gold Medal"
            elif i == 1:
                ans[position] = "Silver Medal"
            elif i == 2:
                ans[position] = "Bronze Medal"
            else:
                ans[position] = str(i+1)
        return ans






        