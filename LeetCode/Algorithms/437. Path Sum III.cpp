/**
 * Definition for a binary tree node.
 * vim.overrideCopystruct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if(!root) return 0;
        return dfs(root, sum, 0) + pathSum(root->left,sum)+pathSum(root->right, sum);
    }
    int dfs(TreeNode* node, int sum, int now){
        if(node == nullptr) return 0;
        int tmp = node->val + now;
        return (sum==tmp) + dfs(node->left, sum, tmp) + dfs(node->right, sum, tmp);

    }
};