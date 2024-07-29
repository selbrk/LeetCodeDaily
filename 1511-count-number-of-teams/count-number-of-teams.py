class Solution:
    def numTeams(self, rating: List[int]) -> int:
        ans = 0
        dp = [0] * len(rating)
        dp2 = [0] * len(rating)
        for i in range(len(rating)):
            for j in range(i):
                if rating[i] > rating[j]:
                    ans += dp[j]
                    dp[i] += 1
                else:
                    ans += dp2[j]
                    dp2[i] += 1
        
        return ans
        
        