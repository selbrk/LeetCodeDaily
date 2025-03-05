class Solution:
    def pivotArray(self, nums: List[int], pivot: int) -> List[int]:
        l = []
        m = []
        r = []
        for num in nums:
            if num < pivot:
                l.append(num)
            elif num > pivot:
                r.append(num)
            else:
                m.append(num)
        return l + m + r