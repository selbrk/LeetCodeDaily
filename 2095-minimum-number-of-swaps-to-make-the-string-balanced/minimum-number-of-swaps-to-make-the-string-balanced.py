class Solution:
    def minSwaps(self, s: str) -> int:
        stack = []
        for c in s:
            if c == '[':
                stack.append(c)
            elif stack and stack[-1] == '[':
                stack.pop()
            else:
                stack.append(c)
        
        if len(stack) == 0:
            return 0
        print(stack)
        return (len(stack)  + 2) // 4
