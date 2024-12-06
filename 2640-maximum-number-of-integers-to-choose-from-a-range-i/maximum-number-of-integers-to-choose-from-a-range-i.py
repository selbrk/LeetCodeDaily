class Solution:
    def maxCount(self, banned: List[int], n: int, maxSum: int) -> int:
        banned = set(banned)
        i, ans = 1, 0
        while i <= min(n, maxSum):
            if i not in banned:
                ans += 1
                maxSum -= i
            i += 1
        return ans


        