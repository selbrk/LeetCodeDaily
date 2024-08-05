class Solution:
    def kthDistinct(self, arr: List[str], k: int) -> str:
        mp = {}
        for s in arr:
            if s in mp:
                mp[s] += 1
            else:
                mp[s] = 1
        cnt = 0
        for s in arr:
            if mp[s] == 1:
                cnt += 1
                if cnt == k:
                    return s
        

        return ""

        