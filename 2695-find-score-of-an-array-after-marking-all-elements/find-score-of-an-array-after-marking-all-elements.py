class Solution:
    def findScore(self, nums: List[int]) -> int:
        marked = [False] * len(nums)
        marked_count = 0
        sorted_nums = sorted([ (num, ix) for ix, num in enumerate(nums) ])
        score = 0
        for num, ix in sorted_nums:
            if marked[ix]: continue
            marked[ix] = True
            marked_count += 1
            score += num
            print(num)
            if ix - 1 >= 0 and not marked[ix-1]:
                marked[ix-1] = True
                marked_count += 1
            if ix + 1 < len(nums) and not marked[ix+1]:
                marked[ix+1] = True
                marked_count += 1
            if marked_count == len(nums):
                break
        return score
                

