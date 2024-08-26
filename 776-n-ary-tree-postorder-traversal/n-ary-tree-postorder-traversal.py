"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    def postorder(self, root: 'Node') -> List[int]:
        ans = []
        

        def dfs(root):
            if not root: return
            for child in root.children:
                dfs(child)
            ans.append(root.val)
        dfs(root)

        return ans
        