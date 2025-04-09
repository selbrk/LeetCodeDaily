class Solution:
    def grayCode(self, n: int) -> List[int]:
        ans = []
        for i in range((1 << n)):
            left_bit = 0
            right_bit = 0
            code = 0
            for j in range(n-1,-1,-1):
                right_bit = 1 if (1 << j) & i else 0
                code += (1 << j) * (right_bit ^ left_bit)
                left_bit = right_bit
            ans.append(code)
        return ans

            
