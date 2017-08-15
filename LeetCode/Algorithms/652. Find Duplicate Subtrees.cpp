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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> res;
        map<int, vector<TreeNode*>> mm;
        map<int, int> mn;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* tmp = q.front();
            q.pop();
            auto it = mm.find(tmp->val);
            if(it == mm.end()){
                mm[tmp->val].push_back(tmp);
                mn[tmp->val].push_back(1);
            } else{
                vector<TreeNode*> &dup = it->second;
                vector<int>& num = mn[tmp->val];
                bool flag = false;
                for(int i=0;i<num.size();++i){
                    if(dfs(dup[i],tmp)){
                        num[i]++;
                        flag = true;
                    }
                }
                if(!flag){
                    dup.push_back(tmp);
                    num.push_back(1);
                }
            }
        }
        for(auto it=mm.begin();it!=mm.end();it++){
            vector<TreeNode*> &dup = it->second;
            vector<int> &num = mn[it->first];
            for(int i=0;i<num.size();++i){
                if(num[i] > 1){
                    res.push_back(dup[i]);
                }
            }
        }
        return res;
    }
    bool dfs(TreeNode* one, TreeNode* two){
        int r1,r2;
        if(one == nullptr && two == nullptr)
            return true;
        else if(one == nullptr || two == nullptr)
            return false;
        r1 = dfs(one->left, two->left);
        r2 = dfs(one->right,two->right);
        if(one->val == two->val && r1 && r2){
            return true;
        }
        return false;
    }
};