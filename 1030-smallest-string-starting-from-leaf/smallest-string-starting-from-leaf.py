# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque

class Solution:
    def smallestFromLeaf(self, root: TreeNode) -> str:
        if not root:
            return ""
        
        # Mapping from integer to character
        umap = {i: chr(ord('a') + i) for i in range(26)}
        
        # Initialize answer as the character representation of root's value
        ans = ""
        
        # BFS queue to store pairs of (node, string)
        bfs = deque([(root, umap[root.val])])
        
        while bfs:
            current_node, current_string = bfs.popleft()
            
            # Check if the current node is a leaf node
            if not current_node.left and not current_node.right:
                # Update answer if the current string is lexicographically smaller
                if ans == "" or current_string < ans:
                    ans = current_string
                
            
            # Explore left child
            if current_node.left:
                bfs.append((current_node.left, umap[current_node.left.val] + current_string))
            
            # Explore right child
            if current_node.right:
                bfs.append((current_node.right, umap[current_node.right.val] + current_string))
        
        return ans

        