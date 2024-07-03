class Solution:
    def primePalindrome(self, n: int) -> int:
        '''
        palindromes with even digtis are always a multiple of 11, so we can ignore them.
        a
        aba
        abcba
        abcdcba
        abcdedcba
        _ _ _ _ _ _ _ _ _
        '''
        if n == 8 or n== 9 or n== 10 or n == 11:
            return 11
        def pal1(a):
            return a
        def pal2(a,b):
            return 101 * a + 10*b
        def pal3(a,b,c):
            num = 0
            num += (10**4 + 1) * a
            num += (10**3 + 10) * b
            num += (100) * c
            return num
        def pal4(a,b,c,d):
            num = 0
            num += (10**6 + 1) * a
            num += (10**5 + 10) * b
            num += (10**4 + 100) * c
            num += (10**3) * d 
            return num
        def pal5(a,b,c,d,e):
            num = 0
            num += (10**8 + 1) * a
            num += (10**7 + 10) * b
            num += (10**6 + 10**2) * c
            num += (10**5 + 10**3) * d
            num += (10**4) * e
            return num
        
        def is_prime(n):
            i = 2
            if n == 1:
                return False
            
            while i*i <=n:
                if n % i == 0:
                    return False
                i+=1
            return True

        digit = len(str(n))
        for a in range(n, 10):
            if is_prime(a):
                return a
        
        for a in range(1,10,2):
            for b in range(10):
                num = pal2(a,b)
                if num >= n and is_prime(num):
                    return num
        
        for a in range(1,10, 2):
            for b in range(10):
                for c in range(10):
                    num = pal3(a,b,c)
                    if num >= n and is_prime(num):
                        return num
        
        for a in range(1,10, 2):
            for b in range(10):
                for c in range(10):
                    for d in range(10):
                        num = pal4(a,b,c,d)
                        if num >= n and is_prime(num):
                            return num
        
        for a in range(1,2):
            for b in range(10):
                for c in range(10):
                    for d in range(10):
                        for e in range(10):
                            num = pal5(a,b,c,d,e)
                            if num >= n and is_prime(num):
                                return num
        return ans

        