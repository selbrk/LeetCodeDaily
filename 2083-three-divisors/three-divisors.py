class Solution:
    def isThree(self, n: int) -> bool:
        def root(n):
            l, r = 0, 10**4+5
            while l <= r:
                mid = (l + r) // 2
                if mid**2 == n:
                    return mid
                elif mid**2 < n:
                    l = mid + 1
                else:
                    r = mid - 1
            return -1

        def isPrime(n):
            if n <= 1:
                return False
            i = 2
            while i*i<=n:
                if n % i == 0:
                    return False
                i+=1
            return True
        
        return True if isPrime(root(n)) else False
        