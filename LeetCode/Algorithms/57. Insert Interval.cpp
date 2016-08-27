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
vector<Interval> insert(vector<Interval>& a, Interval ins) {
	int n = a.size();
	vector<Interval> res;
	bool flag = false;
	for (int i = 0; i < n; ++i) {
		if (flag)
			res.push_back(a[i]);
		else {
			if (a[i].start > ins.end) {
				res.push_back(ins);
				flag = true;
				res.push_back(a[i]);
			} else if(a[i].end < ins.start){
				res.push_back(a[i]);
			}else{
				ins.start = min(ins.start, a[i].start);
				ins.end = max(ins.end, a[i].end);
			}
		}
	}
	if (!flag)
		res.push_back(ins);
	return res;
}
};