class Solution {
public:
int minStickers(vector<string> stickers, string target) {
	int n = target.length(); int m = 1 << n;
	vector<int> dp(m, INT_MAX);
	dp[0] = 0;
	for (int i = 0; i < m; ++i) {
		if (dp[i] == INT_MAX) {
			continue;
		}
		for (auto& s : stickers) {
			int tmp = i;
			for (int j = 0; j < s.size(); ++j) {
				for (int k = 0; k < n; ++k) {
					if (s[j] == target[k] && (((tmp >> k) & 1) == 0)) {
						tmp |= 1 << k;
                        break;
					}
				}
			}
			dp[tmp] = min(dp[tmp], dp[i] + 1);
		}
	}
	return dp[m - 1] != INT_MAX ? dp[m - 1] : -1;
}
};