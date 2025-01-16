class Solution:
    def maxScore(self, s: str) -> int:
        max_score = 0
        current_score = s.count('1')
        for i in range(len(s)-1):
            current_score += (1 if s[i] == '0' else -1)
            max_score = max(current_score, max_score)
        return max_score


        