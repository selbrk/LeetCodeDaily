class Solution:
    def longestMonotonicSubarray(self, nums: List[int]) -> int:
        def inc(nums):
            cur, ans = 1,1
            for i in range(1,len(nums)):
                if nums[i] > nums[i-1]:
                    cur += 1
                    ans = max(ans, cur)
                else:
                    cur = 1
            return ans
        
        def dec(nums):
            cur, ans = 1,1
            for i in range(1,len(nums)):
                if nums[i] < nums[i-1]:
                    cur += 1
                    ans = max(ans, cur)
                else:
                    cur = 1
            return ans
        
        return max(inc(nums), dec(nums))
            

        