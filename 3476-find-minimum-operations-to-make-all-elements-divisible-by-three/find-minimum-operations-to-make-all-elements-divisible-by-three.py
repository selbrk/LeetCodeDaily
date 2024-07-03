class Solution:
    def minimumOperations(self, nums: List[int]) -> int:
        ans = 0
        for num in nums:
            if num % 3:
                ans +=1
        return ans
        