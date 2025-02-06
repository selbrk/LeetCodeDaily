class Solution:
    def tupleSameProduct(self, nums: List[int]) -> int:
        n = len(nums)
        prod_counts = {}

        for i in range(n - 1):
            for j in range(i + 1, n):
                prod_counts[nums[i] * nums[j]] = prod_counts.get(nums[i] * nums[j], 0) + 1
        
        nums.sort()
        ans = 0
        for i in range(n - 1):
            for j in range(i + 1, n):
                target_prod = nums[i] * nums[j]
                ans += 4 * (prod_counts[target_prod] - 1)
        
        return ans