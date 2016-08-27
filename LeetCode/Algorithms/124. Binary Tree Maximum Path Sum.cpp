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
 int dfs(TreeNode *root, int &maxx) {
	 if (!root)
		 return 0;
	 int left = dfs(root->left, maxx);
	 int right = dfs(root->right, maxx);
	 maxx = max(maxx, root->val + left + right);
	 return max(max(0, max(left, right)) + root->val, 0);
 }
 int maxPathSum(TreeNode* root) {
	 if (!root)
		 return INT_MIN;
	 int maxx = root->val;
	 dfs(root, maxx);
	 return maxx;
 }
};