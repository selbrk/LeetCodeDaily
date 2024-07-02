class Solution:
    def checkRecord(self, n: int) -> int:
        mod = 10**9+7
        N = 10**5 + 5
        dpf = [0] * (N)
        dpg = [0] * (N)

        dpf[0] = 1
        dpf[1] = 3
        dpf[2] = 8

        dpg[0] = 1
        dpg[1] = 2
        dpg[2] = 4

        for i in range(3, n+1):
            dpg[i] = (dpg[i-1] + dpg[i-2] + dpg[i-3]) % mod
        
        for i in range(3,n+1):
            dpf[i] = (dpg[i] + dpf[i-1] + dpf[i-2] + dpf[i-3]) % mod
        
        return dpf[n]
        
            
        