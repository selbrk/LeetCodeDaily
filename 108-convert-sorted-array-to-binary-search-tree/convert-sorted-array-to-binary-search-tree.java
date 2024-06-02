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
    public TreeNode sortedArrayToBST(int[] nums) {
        int size = nums.length;
        return solve(nums, 0, size - 1);
        
    }


    public TreeNode solve(int[] nums, int start, int end) {
        if(end < start)
            return null;
        if(end == start)
            return new TreeNode(nums[start]);
        

        int mid = (start + end + 1) / 2;
        TreeNode root = new TreeNode(nums[mid]);
        root.left = solve(nums, start, mid-1);
        root.right = solve(nums, mid+1, end);

        return root;
    }
}