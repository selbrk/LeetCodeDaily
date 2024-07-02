class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        counter1 = Counter(nums1)
        counter2 = Counter(nums2)

        ans = []

        for letter in counter1:
            st = counter1.get(letter,0)
            nd = counter2.get(letter,0)

            for _ in range(min(st,nd)):
                ans.append(letter)
            
        return ans
        