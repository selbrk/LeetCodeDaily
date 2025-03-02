class Solution:
    def mergeArrays(self, nums1: List[List[int]], nums2: List[List[int]]) -> List[List[int]]:
        vals = [0] * 1001
        for id_,val in nums1:
            vals[id_]+=val
        for id_,val in nums2:
            vals[id_]+=val        
        return [[i,vals[i]] for i in range(1,1001) if vals[i]]