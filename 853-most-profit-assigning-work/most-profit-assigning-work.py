class Solution:
    def maxProfitAssignment(
        self, difficulty: List[int], profit: List[int], worker: List[int]) -> int:
        priority_list = sorted(zip(difficulty, profit), key=lambda e: e[1], reverse=True)
        worker.sort()

        ans = 0

        for diff, prof in priority_list:
            while worker and worker[-1] >= diff:
                ans += prof
                worker.pop()

        return ans
