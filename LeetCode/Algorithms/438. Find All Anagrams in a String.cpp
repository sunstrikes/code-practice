class Solution {
public:
bool cmp(unordered_map<char, int>&m1, unordered_map<char, int>&m2) {
	for (auto it = m1.begin(); it != m1.end(); it++) {
		if (it->second != m2[it->first]) {
			return false;
		}
	}
	return true;
}
vector<int> findAnagrams(string s, string p) {
	vector<int> result;
	unordered_map<char, int> m1, m2;
	for (char a : p) {
		if (m1.count(a) == 0) {
			m1[a] = 1;
		}
		else {
			m1[a] ++;
		}
	}
	for (char a : s) {
		m2[a] = 0;
	}
	for (int i = 0; i<p.size(); i++) {
		m2[s[i]]++;
	}
	int n = p.size();
	for (int i = n; i<s.size(); i++) {
		if (cmp(m1, m2)) {
			result.push_back(i - n);
		}
		m2[s[i - n]]--;
		m2[s[i]]++;
	}
	if (cmp(m1, m2)) {
		result.push_back(s.size() - n);
	}
	return result;
}
};