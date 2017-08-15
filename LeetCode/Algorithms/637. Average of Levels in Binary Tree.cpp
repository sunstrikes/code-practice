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
        vector<int> ll;
        tq.push(root); lq.push(0);
        int pre = -1;
        while(!tq.empty()){
            TreeNode * t = tq.front();
            int level = lq.front();
            tq.pop();lq.pop();
            if(res.size()<level+1){
                res.push_back(0);
                ll.push_back(0);
            }
            res[level] = (res[level] + t->val);
            ll[level]++;
            if(t->left) {tq.push(t->left); lq.push(level+1);}
            if(t->right) {tq.push(t->right); lq.push(level+1);}
        }
        for(int i=0;i<res.size();++i){
            res[i] = res[i] * 1.0/ll[i];
        }
        return res;
    }
};