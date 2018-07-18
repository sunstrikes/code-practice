/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        dfs(root);
        return root;
    }
    bool dfs(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        bool l = dfs(root->left);
        bool r = dfs(root->right);
        if (l && root->left) {
            delete root->left;
            root->left = nullptr;
        }
        if (r && root->right) {
            delete root->right;
            root->right = nullptr;
        }
        if (l && r && root->val == 0) {
            return true;
        } else 
            return false;
    }
};