class Solution:
    def countBeautifulPairs(self, nums: List[int]) -> int:
        def last_digit(n):
            return n % 10

        def first_digit(n):
            while n >= 10:
                n //= 10
            return n

        def gcd(a, b):
            return a if b == 0 else gcd(b, a % b)

        ans = 0
        for i in range(len(nums) - 1):
            for j in range(i + 1, len(nums)):
                if gcd(first_digit(nums[i]), last_digit(nums[j])) == 1:
                    ans += 1
        
        return ans
