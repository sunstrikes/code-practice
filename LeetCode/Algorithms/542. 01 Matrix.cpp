class Solution {
public:
    int m, n;
    void update_element(int i, int j, vector<vector<int>>& a){
        if(i > 0 && a[i-1][j] != INT_MAX){
            a[i][j] = min(a[i-1][j]+1, a[i][j]);
        }
        if(j > 0 && a[i][j-1] != INT_MAX){
            a[i][j] = min(a[i][j-1]+1, a[i][j]);
        }
        if(i < m-1 && a[i+1][j] != INT_MAX){
            a[i][j] = min(a[i+1][j]+1, a[i][j]);
        }
        if(j < n-1 && a[i][j+1] != INT_MAX){
            a[i][j] = min(a[i][j+1]+1, a[i][j]);
        }
        return;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& a) {
        m = a.size(); n = a[0].size();
        vector<vector<int>> res(m, vector<int>(n, INT_MAX));
        for(int i= 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(a[i][j] == 0){
                    res[i][j] = 0;
                }else{
                    update_element(i,j,res);
                }
            }
        }
        for(int i=m-1;i>-1;i--){
            for(int j=n-1;j>-1;j--){
                if(a[i][j] != 0){
                    update_element(i,j,res);
                }
            }
        }
        return res;
    }
};