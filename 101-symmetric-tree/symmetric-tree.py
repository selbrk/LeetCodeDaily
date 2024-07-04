# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        def mirror(left_tree, right_tree):
            if left_tree == None and right_tree == None:
                return True
            if left_tree == None or right_tree == None:
                return False
            if left_tree.val == right_tree.val:
                return mirror(left_tree.right, right_tree.left) and mirror(left_tree.left, right_tree.right)
            return False
        
        return mirror(root.left, root.right)

        