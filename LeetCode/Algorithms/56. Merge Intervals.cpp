/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
static bool cmp(Interval &a, Interval &b) {
	if (a.start < b.start)
		return true;
	else if (a.start == b.start && a.end > b.end) {
		return true;
	}
	return false;
}
vector<Interval> merge(vector<Interval>& a) {
	vector<Interval> res;
	std::sort(a.begin(), a.end(), cmp);
	vector<int> vis(a.size(), 0);
	for (int i = 0; i < a.size(); i++) {
		if (vis[i])
			continue;
		int end = a[i].end;
		int j = i+1;
		while (j < a.size() && end >= a[j].start) {
			end = max(end, a[j].end);
			vis[j] = 1;
			j++;
		}
		Interval tmp(a[i].start, end);
		res.push_back(tmp);
	}
	return res;
}
};