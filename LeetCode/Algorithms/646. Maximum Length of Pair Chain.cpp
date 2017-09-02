class Solution {
public:
int findLongestChain(vector<vector<int>>& p){
    sort(p.begin(), p.end(), [](const vector<int> &foo1, const vector<int> &foo2){
        if (foo1[0] < foo2[0])
        {
            return true;
        }
        else if (foo1[0] == foo2[0])
        {
            return foo1[1] < foo2[1];
        }
        return false;
    });
    int n = p.size();
    vector<int> dp(n, 1);
    for (int i= 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if (p[i][0] > p[j][1] && dp[i] < dp[j]+1){
                dp[i] = dp[j] +1;
            }
        }
    }
    return *max_element(dp.begin(), dp.end());
}                             
};