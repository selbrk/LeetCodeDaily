class Solution:
    def findMinDifference(self, timePoints: List[str]) -> int:
        mins = []

        for time in timePoints:
            h, m = map(int, time.split(':'))
            mins.append(60*h + m)
        
        mins.sort()
        ans = float('inf')
        for i in range(len(mins) - 1):
            ans = min(ans, mins[i+1] - mins[i])
        
        ans = min(ans, mins[0] - mins[-1] + 1440)

        return ans