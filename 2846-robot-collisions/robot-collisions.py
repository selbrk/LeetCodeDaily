class Solution:
    def survivedRobotsHealths(self, positions: List[int], healths: List[int], directions: str) -> List[int]:
        ix = {val : i for (i, val) in enumerate(positions)}
        health = {val : i for (i,val) in enumerate(positions)}
        positions.sort()
        stack = []
        sure = []
        for pos in positions:
            ind = ix[pos]
            if directions[ind] == 'R':
                stack.append([ind, healths[ind]])
            elif len(stack) == 0:
                sure.append([ind, healths[ind]])
            else:
                while stack and healths[ind] > stack[-1][-1]:
                    stack.pop()
                    healths[ind] -= 1
                if stack and healths[ind] == stack[-1][-1]:
                    stack.pop()
                elif stack:
                    stack[-1][-1] -= 1
                else:
                    sure.append([ind, healths[ind]])
                
                
        stack += sure
        stack.sort()
        ans = [val for ix, val in stack]
        return ans


        