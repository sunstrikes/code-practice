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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> tq;
        queue<int> lq;
        vector<double> res;
        int n = 0;
        tp.push(root); lq.push(0);
        int pre = -1;
        while(!tq.empty()){
            TreeNode * t = tq.front();
            int level = lq.front();
            tp.pop();lq.pop();
            n++;
            if(pre!=level){
                res[level] = (res[level] + t->val)/n;
                pre = level;
                n = 0;
            }else{
                res[level] += t->val;
            }
            if(t->left) {tq.push(t->left); lq.push(level+1);}
            if(t->right) {tq.push(t->right); lq.push(level+1);}
        }
        return res;
    }
};