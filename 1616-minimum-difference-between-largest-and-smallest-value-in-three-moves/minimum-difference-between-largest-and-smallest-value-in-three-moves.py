class Solution:
    def minDifference(self, nums: List[int]) -> int:
        n = len(nums)
        base = [1,2,3,4]
        if n in base:
            return 0


        nums.sort()
        moves = [
            (3,0),
            (2,1),
            (1,2),
            (0,3)
        ]

        ans = float('inf')
        for l, r in moves:
            ans = min(ans, nums[n-1-r] - nums[l])
        
        return ans
