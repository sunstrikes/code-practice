class Solution {
public:
vector<string> res;
void fenzhi(string num, string tmp, long long target,long long cur, long long prev) {
	if (cur == target && num.size() == 0) {
		res.push_back(tmp);
		return;
	}
	for (int i = 1; i <= num.size(); i++) {
		string cs = num.substr(0, i);
		if (cs.size() > 1 && cs[0] == '0') {
			return;
		}
		long long curNum = atoll(cs.c_str());
		string next = num.substr(i);
		if (tmp.size() != 0) {
			fenzhi(next, tmp + "*" + cs, target, (cur - prev) + prev*curNum, prev*curNum);
			fenzhi(next, tmp + "+" + cs, target, (cur + curNum), curNum);
			fenzhi(next, tmp + "-" + cs, target, (cur - curNum), -curNum);
		}else{
			fenzhi(next, cs, target, curNum, curNum);
		}
	}
}
vector<string> addOperators(string num, int target) {
	fenzhi(num, "", target, 0,0);
	return res;
}
};