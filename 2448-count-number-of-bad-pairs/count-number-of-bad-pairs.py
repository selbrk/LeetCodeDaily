class Solution:
    def countBadPairs(self, nums: List[int]) -> int:
        n = len(nums)
        good_pairs = 0
        ctr = {}

        for i in range(n):
            good_pairs += ctr.get(i-nums[i], 0)
            ctr[i-nums[i]] = ctr.get(i-nums[i], 0) + 1
        total = n * (n - 1) // 2
        return total - good_pairs

        
        