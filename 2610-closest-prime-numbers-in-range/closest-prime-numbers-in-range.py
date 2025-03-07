class Solution:
    def closestPrimes(self, left: int, right: int) -> List[int]:
        ans = [-1,-1]   
        min_diff = float('inf')
        primes = []
        isPrime = [True] * (right + 1)
        isPrime[0] = False
        isPrime[1] = False
        for i in range(2, right + 1):
            if isPrime[i]:
                if i >= left:
                    primes.append(i)
                for j in range(2*i, right + 1, i):
                    isPrime[j]=False
        
        for i in range(1, len(primes)):
            if primes[i] - primes[i-1] < min_diff:
                min_diff = primes[i] - primes[i-1]
                ans = [primes[i-1],primes[i]]
        

        return ans
        