/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
void connect(TreeLinkNode* root) {
	TreeLinkNode* p = root;
	queue<TreeLinkNode*> que;
	if(root==NULL)
	    return;
	que.push(p);
	int len = 1;
	int tmpLen = 0;
	TreeLinkNode* tmp;
	TreeLinkNode* prev;
	while (len) {
		tmpLen = 0;
		prev = NULL;
		for (int i = 0; i < len; i++) {
			tmp = que.front();
			que.pop();
			if (prev == NULL)
				prev = tmp;
			else {
				prev->next = tmp;
				prev = tmp;
			}
			if (tmp->left) {
				++tmpLen;
				que.push(tmp->left);
			}
			if (tmp->right) {
				++tmpLen;
				que.push(tmp->right);
			}
		}
		len = tmpLen;
	}
}
};