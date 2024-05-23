class Solution:
    def beautifulSubsets(self, nums: List[int], k: int) -> int:
        res = -1
        def solve(index, current):
            nonlocal res
            if index == len(nums):
                res += 1
                return 
            if(nums[index] - k in current or nums[index] + k in current):
                solve(index + 1, current)
            else:
                solve(index + 1, current)
                solve(index + 1, current + [nums[index]])
        
        solve(0, [])
        return res
    

