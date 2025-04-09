class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        nums = sorted(list(set(nums)))
        ans = 0
        for ele in nums:
            if ele < k:
                return -1
            elif ele > k:
                ans += 1
        return ans