def isSquare(n):
    root = int(n**0.5)
    return root * root == n
class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        if c == 0:
            return True
        if c % 4 == 3:
            return False
        while c % 4 == 0:
            c //= 4
        i = 1
        while i*i <=c:
            if isSquare(c - i*i):
                return True
            i+=2

        return False

        
        