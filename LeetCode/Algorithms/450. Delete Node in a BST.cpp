class Solution {
public:
	TreeNode* deleteNode(TreeNode* root, int key) {
		if (root == NULL)
			return NULL;
		if (key < root->val)
			root->left = deleteNode(root->left, key);
		else if (key > root->val)
			root->right = deleteNode(root->right, key);
		else {
			if (root->left == NULL) {
				return root->right;
			}
			else if (root->right == NULL) {
				return root->left;
			}

			TreeNode* minN = findMin(root->right);
			root->val = minN->val;
			root->right = deleteNode(root->right, root->val);
		}
		return root;
	}
	TreeNode* findMin（TreeNode* root){
	while (root->left) {
		root = root->left;
	}
	return root;
	}

};