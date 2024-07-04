class Solution:
    def maximumPrimeDifference(self, nums: List[int]) -> int:
        def isPrime(n):
            i = 2
            while i * i <= n:
                if n % i == 0:
                    return False
                i += 1
            return True

        primes = set()

        for i in range(2, 101):
            if isPrime(i):
                primes.add(i)

        l, r = 0, len(nums) - 1
        while nums[l] not in primes:
            l += 1
        while nums[r] not in primes:
            r -= 1

        return r - l
