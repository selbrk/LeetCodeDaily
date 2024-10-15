class Solution:
    def minimumSteps(self, s: str) -> int:
        ones = []
        ans = 0
        for i, c in enumerate(s):
            if c == '0':
                ones.append((i,c))
        
        number_of_ones = len(ones)

        for i in range(number_of_ones):
            ans += ones[i][0] - i
        
        return ans
        