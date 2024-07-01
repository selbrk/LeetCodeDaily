class Solution:
    def maxSumAfterPartitioning(self, arr: List[int], k: int) -> int:
        n = len(arr)
        dp = [0] * (n + 1)
        for i in range(1, n + 1):
            maxval = 0
            for j in range(1, min(i, k) + 1):
                maxval = max(maxval, arr[i-j])
                dp[i] = max(dp[i], dp[i - j] + j * maxval)
        return dp[n]
