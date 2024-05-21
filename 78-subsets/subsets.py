class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        if len(nums) == 0:
            return [[]]
        without_first = self.subsets(nums[1:])
        with_first = [ [nums[0]] + ss for ss in without_first]

        return without_first + with_first
        