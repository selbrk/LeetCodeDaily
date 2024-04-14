# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

def dfs(root):
    global ans
    
    if root.left and not (root.left.left or root.left.right):
        ans += root.left.val
    if root.right:
        dfs(root.right)
    if root.left:
        dfs(root.left)
        
            
        
class Solution:
    def sumOfLeftLeaves(self, root: Optional[TreeNode]) -> int:
        global ans
        ans = 0
        dfs(root)
        return ans

        