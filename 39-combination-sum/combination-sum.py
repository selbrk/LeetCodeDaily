class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        targets = [[] for _ in range(target + 1)]
        for num in candidates:
            if num > target:
                continue
            targets[num].append([num])
            for i in range(num + 1, target + 1):
                for sols in targets[i - num]:
                    targets[i].append(sols + [num])

        return targets[target]
    

        