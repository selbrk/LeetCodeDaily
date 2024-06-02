/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public TreeNode insertIntoBST(TreeNode root, int val) {    
        TreeNode current = root;
        if(root == null)
            return new TreeNode(val);
        while(true) {
            if(current.val > val) {
                if(current.left == null){
                    current.left = new TreeNode(val);
                    break;
                }
                current = current.left;
            } else {
                if(current.right == null){
                    current.right = new TreeNode(val);
                    break;
                }
                current = current.right;
            }
        }



        return root;

        
    }
}