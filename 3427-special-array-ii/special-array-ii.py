class Solution:
    def isArraySpecial(self, nums: List[int], queries: List[List[int]]) -> List[bool]:
        ps = [0] * len(nums)
        for i in range(1, len(nums)):
            ps[i] = ps[i-1] + ((nums[i] - nums[i-1]) % 2 == 0)
        ans = []

        for l, r in queries:
            ans.append(ps[r] == ps[l])
        
        return ans

        