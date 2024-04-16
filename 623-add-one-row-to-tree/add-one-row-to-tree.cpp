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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1) {
            TreeNode* dummy = new TreeNode(val);
            dummy -> left = root;
            return dummy;
        }
        queue<pair<TreeNode*,int>> bfs;
        bfs.emplace(root, 1);
        TreeNode* last_node, *child_node;
        while(!bfs.empty()) {
            last_node = bfs.front().first;
            int current_depth = bfs.front().second;
            bfs.pop();
            if(current_depth >= depth) break;
            if(current_depth == depth - 1) {
                if(last_node->left) {
                    child_node = last_node->left;
                    last_node->left = new TreeNode(val);
                    last_node->left->left = child_node;
                }
                else
                    last_node->left = new TreeNode(val);
                
                if(last_node->right) {
                    child_node = last_node->right;
                    last_node->right = new TreeNode(val);
                    last_node->right->right = child_node;
                }
                else
                    last_node->right = new TreeNode(val);
                
            }
            else {
                if(last_node->left) {
                    bfs.emplace(last_node->left, current_depth+1);
                } 
                if(last_node->right) {
                    bfs.emplace(last_node->right, current_depth + 1);
                }
            }

        }
        return root;

        
    }
};