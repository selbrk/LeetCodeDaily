class Solution:
    def xorBeauty(self, nums: List[int]) -> int:
        '''
        if i != j, then exchanging i,j yields the same result, and their xor gives 0.
        so just consider (i,i,k) triplets.
        nums[i] | nums[i] = nums[i]
        so we select i and k, and compute nums[i] & nums[k]
        again, if i!=k, exchanging i,k gives the same result.
        so we just consider (i,i,i) triplets => effective value = nums[i]
        so the question just asks for xor of all values
        '''

        ans = 0
        for num in nums:
            ans ^= num
        return ans
        