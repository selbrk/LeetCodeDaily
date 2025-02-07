class Solution:
    def queryResults(self, limit: int, queries: List[List[int]]) -> List[int]:
        ball_colors = {}
        color_counts = {}
        ans = []
        color_count = 0
        for ball, color in queries:
            # is color new?
            if color_counts.get(color, 0) == 0:
                color_count += 1
            # if the ball already had a differnt color, it should disappear
            if ball_colors.get(ball):
                if ball_colors.get(ball) == color: 
                    ans.append(color_count)
                    continue
                color_counts[ball_colors.get(ball)] -= 1
                if color_counts[ball_colors.get(ball)] == 0:
                    color_count -= 1
            ans.append(color_count)
            ball_colors[ball] = color
            color_counts[color] = color_counts.get(color, 0) + 1
        return ans

        

        