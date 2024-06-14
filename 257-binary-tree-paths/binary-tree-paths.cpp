/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<string> ans;

    bool is_leaf(TreeNode* root) {
        return root->left == nullptr && root->right == nullptr;
    }

    void solve(TreeNode* root, string path) {
        if (is_leaf(root)) {
            path += to_string(root->val);
            ans.push_back(path);
            return;
        }
        path += to_string(root->val);
        path += "->";
        if (root->left) {
            solve(root->left, path);
        }

        if (root->right) {
            solve(root->right, path);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        solve(root, "");
        return ans;
    }
};