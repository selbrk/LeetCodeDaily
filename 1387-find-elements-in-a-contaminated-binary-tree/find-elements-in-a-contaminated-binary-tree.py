# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class FindElements:

    def __init__(self, root: Optional[TreeNode]):
        self.root = root
    def find(self, target: int) -> bool:
        s = bin(target + 1)
        s = s[s.find('1') + 1:]

        temp = self.root
        for ch in s:
            if ch == '1' and temp.right:
                temp = temp.right
            elif ch == '1':
                return False
            elif ch == '0' and temp.left:
                temp = temp.left
            elif ch == '0':
                return False
        return True
                
                






        return False



# Your FindElements object will be instantiated and called as such:
# obj = FindElements(root)
# param_1 = obj.find(target)