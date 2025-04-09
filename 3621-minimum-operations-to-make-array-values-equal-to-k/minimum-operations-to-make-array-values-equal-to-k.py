class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        ans = 0
        nums = set(nums)
        for ele in nums:
            if ele < k:
                return -1
            elif ele > k:
                ans += 1
        return ans