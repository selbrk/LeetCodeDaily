class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        l, r = 0, len(nums) - 1
        ans = []
        while r >= l:
            if abs(nums[r]) >= abs(nums[l]):
                ans.append(nums[r]**2)
                r-=1
            else:
                ans.append(nums[l]**2)
                l+=1
        
        ans.reverse()
        return ans
        