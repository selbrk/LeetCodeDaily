class Solution:
    def getLucky(self, s: str, k: int) -> int:
        temp = ""
        for letter in s:
            temp += str(ord(letter) - ord('a') + 1)
        
        s = temp
        for i in range(k):
            ans = 0
            for no in s:
                ans += int(no)
            s = str(ans)
        return int(s)
        