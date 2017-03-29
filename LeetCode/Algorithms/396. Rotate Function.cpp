class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int a = 0, sum = 0;
        for(int i = 0; i < A.size();++i){
            a += i*A[i];
            sum += A[i];
        }
        int m = a;
        int maxx = INT_MIN;
        int n = A.size();
        if (n==0)
            return 0;
        for(int i = A.size() -1;i>=0;i--){
            m = m + sum - n*A[i];
            maxx = max(maxx, m);
        }
        
        return maxx;
    }
};