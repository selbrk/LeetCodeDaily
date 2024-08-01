class Solution:
    def countSeniors(self, details: List[str]) -> int:
        ans = 0
        for detail in details:
            if int(detail[11:13]) > 60:
                ans += 1
        return ans
            