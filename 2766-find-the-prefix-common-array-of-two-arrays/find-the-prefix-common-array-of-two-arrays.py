class Solution:
    def findThePrefixCommonArray(self, A: List[int], B: List[int]) -> List[int]:
        seenA = set()
        seenB = set()
        ans = []
        cnt = 0
        for i in range(len(A)):
            if A[i] in seenB and not A[i] in seenA:
                cnt += 1
            if B[i] in seenA and not B[i] in seenB:
                cnt += 1
            if A[i] == B[i] and not (A[i] in seenA and B[i] in seenB):
                cnt += 1
            seenA.add(A[i]); seenB.add(B[i])
            ans.append(cnt)
        
        return ans
