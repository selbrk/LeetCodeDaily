class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        stack = []
        for i in range(len(num)):
            while stack and num[i] < stack[-1] and k > 0:
                stack.pop()
                k -= 1
            stack.append(num[i])
        for i in range(k):
            stack.pop()
        
        res = ''.join(stack)
        res = res.lstrip('0')

        if res:
            return res
        else:
            return "0"
        
        