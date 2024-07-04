class Solution:
    def diagonalPrime(self, nums: List[List[int]]) -> int:
        def isPrime(n):
            if n <= 1:
                return False
            i = 2
            while i*i <= n:
                if n % i == 0:
                    return False
                i+=1
            return True
        
        m = len(nums)
        ans = 0
        for i in range(m):
            if isPrime(nums[i][i]):
                ans = max(ans, nums[i][i])

        for i in range(m):
            if isPrime(nums[i][m-1-i]):
                ans = max(ans,nums[i][m-1-i])
        
        return ans


        