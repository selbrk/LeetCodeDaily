class Solution:
    def firstUniqChar(self, s: str) -> int:
        hs = {}

        for c in s:
            if c not in hs:
                hs[c] = 1
            else:
                hs[c] += 1
        
        for i in range(len(s)):
            if hs[s[i]] == 1:
                return i
        
        return -1
        

        