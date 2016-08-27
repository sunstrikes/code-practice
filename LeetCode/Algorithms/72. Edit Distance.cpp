class Solution {
public:
int min(int x, int y, int z) {
	int minn = x > y ? y : x;
	minn = z > minn ? minn : z;
	return minn;
}
int minDistance(string s, string t) {
	int m = s.size();
	int n = t.size();
	vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
	for (int i = 0; i <= m; i++) {
		dp[i][0] = i;
	}
	for (int i = 0; i <= n; i++) {
		dp[0][i] = i;
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (s[i - 1] == t[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1];
			}else{
				dp[i][j] = min(dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]) + 1;
			}
		}
	}
	return dp[m][n];
}
};