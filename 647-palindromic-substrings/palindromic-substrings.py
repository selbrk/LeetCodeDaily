class Solution:
    def countSubstrings(self, s: str) -> int:
        n = len(s)
        dp = [[False for _ in range(n)] for _ in range(n)]
        ans = 0
        for i in range(n):
            dp[i][i] = True
            ans += 1
            if i > 0 and s[i-1] == s[i]:
                dp[i-1][i] = True
                ans += 1
        for j in range(2,n):
            for i in range(n-j):
                if s[i] == s[i+j] and dp[i+1][i+j-1]:
                    dp[i][i+j] = True
                    ans += 1
        
        return ans
        