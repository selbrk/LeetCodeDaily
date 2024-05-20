class Solution:
    def subsetXORSum(self, nums: List[int]) -> int:
        n = len(nums)
        total = 0
        for i in range(1 << n):
            ss_xor = 0
            for j in range(n):
                if i & (1 << j):
                    ss_xor ^= nums[j]
            
            total += ss_xor
        
        return total

        