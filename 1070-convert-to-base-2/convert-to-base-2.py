class Solution:
    def baseNeg2(self, n: int) -> str:
        if n == 0:
            return "0"
        ans = ""
        for power in range(32):
            if n == 0:
                break
            if n % (1 << (power + 1)) == 0:
                ans += "0"
            else:
                ans += "1"
                n -= pow(-2, power)
        
        return ans[::-1]
        