//我的简直慢爆了...1278ms
class Solution {
public:
static bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.first < b.first || (a.first == b.first&&a.second < b.second))
		return true;
	return false;
}
int maxEnvelopes(vector<pair<int, int>>& envelopes) {
	int maxx = 0;
	sort(envelopes.begin(), envelopes.end(), cmp);
	vector<int> dp(envelopes.size(), 0);
	for (int i = 1; i < dp.size(); i++) {
		bool flag = false;
		for (int j = 0; j < i; j++) {
			if (envelopes[i].first > envelopes[j].first && envelopes[i].second > envelopes[j].second) {
				dp[i] = dp[i] < dp[j] ? dp[j] : dp[i];
				flag = true;
			}
		}
		if (flag) {
			dp[i]++;
			if (maxx < dp[i])
				maxx = dp[i];
		}
	}
	if (envelopes.size() == 0)
		return 0;
	return maxx+1;
}
};

//二分,nlogn
class Solution {
public:
static bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.first < b.first || (a.first == b.first&&a.second > b.second))
		return true;
	return false;
}
int maxEnvelopes(vector<pair<int, int>>& envelopes) {
	int maxx = 1;
	sort(envelopes.begin(), envelopes.end(), cmp);
	vector<int> dp;
	for (int i = 0; i < envelopes.size(); i++) {
		auto it = lower_bound(dp.begin(), dp.end(), envelopes[i].second);
		if (it == dp.end()) dp.push_back(envelopes[i].second);
		else *it = envelopes[i].second;
	}
	return dp.size();
}
};