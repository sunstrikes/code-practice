class Solution {
public:
/*
有三种情况需要考虑：

1. 如果两个substring相等的话，则为true

2. 如果两个substring中间某一个点，左边的substrings为scramble string，
同时右边的substrings也为scramble string，则为true

3. 如果两个substring中间某一个点，s1左边的substring和s2右边的substring为scramble
string, 同时s1右边substring和s2左边的substring也为scramble
string，则为true

*/
bool dp[100][100][101];
bool init_dp(string s1, string s2) {
	memset(dp, 0, sizeof(dp));
	int len = s1.size();
	for (int k = 1; k <= len; k++) {
		for (int i = 0; i <= len - k; i++) {
			for (int j = 0; j <= len - k; j++) {
				if (s1.substr(i, k) == s2.substr(j, k)) {
					dp[i][j][k] = true;
				}
				else {
					for (int l = 1; l < k; l++) {
						if ((dp[i][j][l] && dp[i + l][j + l][k - l]) || (dp[i][j + k - l][l] && dp[i + l][j][k - l])) {
							dp[i][j][k] = true;
							break;
						}
					}
				}
			}
		}
	}
	return dp[0][0][len];
}
bool isScramble(string s1, string s2) {
	return init_dp(s1, s2);
}

};