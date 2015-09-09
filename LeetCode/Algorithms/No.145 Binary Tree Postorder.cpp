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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res ;
        res.clear();
        stack<TreeNode *> s ;
        if(root== NULL) return res;
         s.push(root);
        while(!s.empty()){
          TreeNode* tmp = s.top();
          if(tmp->left==NULL&&tmp->right==NULL) {
              res.push_back(tmp->val);
              s.pop();
          }
          else if(tmp->left!=NULL){
              s.push(tmp->left);
              tmp->left = NULL;
          }
          else if(tmp->right!=NULL){
              s.push(tmp->right);
              tmp->right = NULL;
          }
        }
      return res;
    }
};
