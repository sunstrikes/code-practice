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
    int cal_sum(TreeNode* root, unordered_map<int,int> &con, int &maxx){
        if(root == nullptr) return 0;
        int sum = root->val;
        sum+=cal_sum(root->left, con, maxx);
        sum+=cal_sum(root->right, con, maxx);
        ++con[sum];
        maxx = max(maxx, con[sum]);
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> res;
        unordered_map<int,int> con;
        int maxx = 0;
        cal_sum(root, con, maxx);
        for(auto it=con.begin();it!=con.end();it++){
            if(it->second == maxx) res.push_back(it->first);
        }
        return res;
    }
};