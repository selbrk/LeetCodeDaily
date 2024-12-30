class Solution:
    def minimizeXor(self, num1: int, num2: int) -> int:
        setbits = 0
        while num2:
            if num2 & 1:
                setbits += 1
            num2 = num2 >> 1
        used = 0
        ans = 0
        for i in range(31, -1, -1):
            if num1 & (1 << i) and used < setbits:
                ans ^= (1 << i)
                used += 1
        
        i = 0
        while setbits != used:
            if not ans & (1 << i):
                ans ^= (1 << i)
                used+=1
            i+=1
            
        
        return ans



        