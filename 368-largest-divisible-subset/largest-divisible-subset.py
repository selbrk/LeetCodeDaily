class Solution:
    def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
        nums.sort()
        n = len(nums)
        lds = [1] * n
        parent = [-1] * n
        for i in range(1, n):
            for j in range(i):
                if nums[i] % nums[j] == 0 and lds[i] < lds[j] + 1:
                    parent[i] = j
                    lds[i] = lds[j] + 1
        
        maximum = max(lds)
        for i in range(n):
            if lds[i] == maximum:
                pivot = i
                break
        
        ans = [nums[pivot]]
        while parent[pivot] != -1:
            ans.append(nums[parent[pivot]])
            pivot = parent[pivot]
        
        return ans


                
                    
        