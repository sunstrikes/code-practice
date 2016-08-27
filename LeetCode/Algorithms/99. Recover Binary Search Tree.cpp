/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //在中序遍历的时候, 如果只遇到了一对大小关系错误, 那就是这对互换
 //如果遇到了两对错误, 那就是不相邻, 这两个节点互换
class Solution {
public:
TreeNode *p1, *p2;
void inorder(TreeNode *root, TreeNode *&previous) {
	if (root == NULL) {
		return;
	}
	inorder(root->left, previous);
	if (previous != NULL &&previous->val >= root->val) {
		if (p1 == NULL) {
			p1 = previous;
			p2 = root;
		}else{
			p2 = root;
		}
	}
	previous = root;
	inorder(root->right, previous);
}
void recoverTree(TreeNode* root) {
	TreeNode* prev = NULL;
	inorder(root, prev);
	if (p1 != NULL&&p2 != NULL) {
		int tmp = p1->val;
		p1->val = p2->val;
		p2->val = tmp;
	}
}
};