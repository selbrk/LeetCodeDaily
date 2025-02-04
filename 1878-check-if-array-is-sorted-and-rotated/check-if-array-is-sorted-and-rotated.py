class Solution:
    def check(self, nums: List[int]) -> bool:
        ''' 
        while the array is ascending, take the minimum value among them, (the first)
        when it breaks, see if the following array is sorted and the last element is less then or equal to our first number
        '''

        # find the position where the ascending pattern breaks
        i = 1
        n = len(nums)
        while i < n:
            if nums[i] < nums[i-1]:
                break
            i += 1
        if i == n:
            return True
        

        for j in range(i + 1, len(nums)):
            if nums[j] < nums[j-1]:
                return False
        

        if nums[n-1] <= nums[0]:
            return True
        return False
        