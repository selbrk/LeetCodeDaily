class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """

        def is_sorted(nums, start_ix):
            for i in range(start_ix, len(nums) - 1):
                if nums[i + 1] > nums[i]:
                    return False
            return True

        def swap(nums, start_ix, found_ix):
            if found_ix == -1:
                return
            
            nums[start_ix], nums[found_ix] = nums[found_ix], nums[start_ix]
        


        def find_more(nums, start_ix):
            if start_ix == -1: return -1
            
            number = nums[start_ix]
            found_ix = -1
            next_number = float('inf')

            for i in range(len(nums) - 1, start_ix - 1, -1):
                if next_number > nums[i] > number:
                    found_ix = i
                    next_number = nums[i]
            
            return found_ix
            
        def reverse(nums, start_ix):
            l, r = start_ix, len(nums) - 1

            while l < r:
                nums[l], nums[r] = nums[r], nums[l]
                l += 1
                r -= 1
        
        def rec(nums, start_ix = 0):
            if start_ix == len(nums) - 1:
                swap(nums, len(nums) - 2, len(nums) - 1)
                return
            if is_sorted(nums, start_ix):
                found_ix = find_more(nums, start_ix - 1)
                swap(nums, start_ix - 1, found_ix)
                reverse(nums, start_ix)
            else:
                rec(nums, start_ix + 1)

        
        rec(nums)