class Solution:
    def punishmentNumber(self, n: int) -> int:
        @cache
        def solve(number, target):
            if number == 0: return True
            if number < 0: return False
            if number == target: return True
            ok = False

            i = 10
            while i <= number:
                ok |= solve(number // i, target - (number % i))
                i *= 10
            
            if ok: return True
            return False
        ans = 0
        for i in range(1, n + 1, 9):
            if solve(i*i,i): ans+=i*i
        for i in range(9, n+1, 9):
            if solve(i*i,i): ans += i*i
        return ans

        

        