class Solution:
    def distinctPrimeFactors(self, nums: List[int]) -> int:
        p = [True] * 1001
        p[0] = False
        p[1] = False
        primes = []
        for i in range(1001):
            if p[i]:
                primes.append(i)
                for j in range(2*i,1001,i):
                    p[j] = False
        
        ans = 0
        for prime in primes:
            for e in nums:
                if e % prime == 0:
                    ans += 1
                    break
        return ans
            
        

        