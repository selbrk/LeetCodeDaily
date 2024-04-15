/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        queue<pair<TreeNode *,int>> bfs;
        bfs.emplace(root, root->val);
        while(!bfs.empty()) {
            int cur_num = bfs.front().second;
            TreeNode *cur_node = bfs.front().first;
            bfs.pop();

            if(!cur_node->left && !cur_node->right) {
                ans += cur_num;
            }
            if(cur_node->left) {
                int new_num = 10*cur_num + cur_node->left->val;
                bfs.emplace(cur_node->left,new_num);
            }
            if(cur_node->right) {
                int new_num = 10*cur_num + cur_node->right->val;
                bfs.emplace(cur_node->right,new_num);
            }
        }

        return ans;
    }
};