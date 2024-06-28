class Solution:
    def __init__(self):
        self.dp = [[-1 for _ in range(1 << 14)] for _ in range(14)]
        self.mod = 10**9 + 7

    def specialPerm(self, nums: List[int]) -> int:
        def solve(length, last_used_ix, mask):
            if self.dp[last_used_ix][mask] != -1:
                return self.dp[last_used_ix][mask]
            
            if mask == 2**(length) - 1:
                return 1
            
            res = 0

            for i in range(length):
                if mask & (1 << i):
                    continue
                if mask == 0 or nums[i] % nums[last_used_ix] == 0 or nums[last_used_ix] % nums[i] == 0:
                    res += solve(length, i, mask | (1 << i))
                    res %= self.mod

            self.dp[last_used_ix][mask] = res
            return res
        
        length = len(nums)
        return solve(length, 0, 0)
        


        