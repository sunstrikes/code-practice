/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
*/
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int minCut(string s) {
        int m = s.size();
        vector<vector<bool>> tong(m+1, vector<bool>(m+1, false));
        vector<int> dp(m, 0);
        for(int i=0;i<m;++i){
            tong[i][i] = true;
            dp[i] = i;
        }
        for(int i = 0; i < m; i++) {
            for(int j =i; j >= 0; i--) {
                if (s[i] == s[j] && ((i-j)<2 ||tong[i-1][j+1])) {
                    dp[i] = min(dp[i], dp[j-1]+1);
                    tong[i][j] = true;
                }
            }
        }
        return dp[m-1];
    }
};
