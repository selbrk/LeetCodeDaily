# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class FindElements:

    def __init__(self, root: Optional[TreeNode]):
        self.root = root
        self.memo = [-1] * (10**6 + 1)
        self.memo[0] = 1
    def find(self, target: int) -> bool:
        if self.memo[target] != -1: return bool(self.memo[target])
        s = bin(target + 1)
        s = s[s.find('1') + 1:]

        temp = self.root
        current = 0
        for ch in s:
            if self.memo[current] == 0:
                self.memo[target] = 0
                return False
            if ch == '1' and temp.right:
                temp = temp.right
                current = 2*current + 2
                self.memo[current] = 1
            elif ch == '1':
                self.memo[current*2 + 2] = 0
                self.memo[target] = 0
                return False
            elif ch == '0' and temp.left:
                temp = temp.left
                current = 2*current + 1
                self.memo[current] = 1
            elif ch == '0':
                self.memo[current*2 + 1] = 0
                self.memo[target] = 0
                return False
        return True
                
                






        return False



# Your FindElements object will be instantiated and called as such:
# obj = FindElements(root)
# param_1 = obj.find(target)