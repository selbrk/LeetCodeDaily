class Solution:
    def passThePillow(self, n: int, time: int) -> int:
        period = 2 * n - 2
        time %= period
        '''
        0 => 0
        n - 1 => n-1
        1 && 2n-3 => 1
        2 && 2n - 4 => 2
        '''

        if time > n - 1:
            time = period - time
        
        return time + 1
        