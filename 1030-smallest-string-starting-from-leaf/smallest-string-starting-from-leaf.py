# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque
def to_char(value : int):
    return chr(97 + value)
class Solution:
    def smallestFromLeaf(self, root: TreeNode) -> str:
        ans = ""
        bfs = deque([(root, to_char(root.val))])
        while bfs:
            current_node, current_string = bfs.popleft()
            if not (current_node.left or current_node.right) and (ans == "" or current_string < ans):
                ans = current_string
            if current_node.left:
                bfs.append((current_node.left, to_char(current_node.left.val) + current_string))
            if current_node.right:
                bfs.append((current_node.right, to_char(current_node.right.val) + current_string))
        
        return ans

        