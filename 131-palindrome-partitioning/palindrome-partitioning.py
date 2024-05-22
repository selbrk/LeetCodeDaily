class Solution:
    def partition(self, s: str) -> List[List[str]]:
        def palCheck(substring : str):
            l, r = 0, len(substring) - 1
            while l < r:
                if substring[l] != substring[r]:
                    return False
                l += 1
                r -= 1
            
            return True
        
        res = []

        def solve(first, current):
            if first == len(s):
                res.append(current)
                return
            
            for last in range(first, len(s)):
                if palCheck(s[first:last+1]):
                    solve(last + 1, current + [s[first:last+1]])
        
        solve(0,[])

        return res

        