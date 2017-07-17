class Solution {
public:
    int findSubstringInWraproundString(string p) {
        int dp[26];
        memset(dp,0,sizeof(dp));
        int len = 0, res = 0;
        for(int i = 0;i<p.size();i++){
            int tmp = p[i]-'a';
            if(i>0 && ((tmp+26-1)%26 != (p[i-1]-'a')))
                len = 0;
            len++;
            if(len > dp[tmp]){
                res += len-dp[tmp];
                dp[tmp] = len;
            }
        }
        return res;
    }
};