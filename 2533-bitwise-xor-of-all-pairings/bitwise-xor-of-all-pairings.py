"""
    let nums1 = a1,a2,....,a_m let A= a1^a2^a3^....^a_n
    let nums2 = b1,b2,....,b_n let B = b1^b2^b3^...^b_n
    (a1 ^ b1) ^ (a1 ^ b2) ^ .... ^ (a1 ^ b_n) = (B if n is even else B ^ a_1)
    (a2 ^b1) ^ (a2 ^ b2) ^ .... ^ (a2 ^ b_n) = (B if n is even else B ^ a_2)
    .
    .
    .
    (a_m ^ b1) ^ (a_m ^ b2) ^ .... ^ (a_m ^ b_n) = (B if n is even else B ^ a_m)

    take all xors, 
    if n is even and m is even, 0
    if n is even and m is odd B
    if n is odd and m is even A
    if n is odd and m is odd A^B
"""


class Solution:
    def xorAllNums(self, nums1: List[int], nums2: List[int]) -> int:
        def allxor(nums: List[int]):
            res = 0
            for num in nums:
                res ^= num
            return res

        n, m = len(nums1), len(nums2)
        if n % 2 == 0 and m % 2 == 0:
            return 0
        elif m % 2 == 0:
            return allxor(nums2)
        elif n % 2 == 0:
            return allxor(nums1)
        else:
            return allxor(nums2) ^ allxor(nums1)
