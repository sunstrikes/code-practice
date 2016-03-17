class Solution {
public:
bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
	set<int> m;
	int j = 0;
	for (unsigned i = 0; i < nums.size(); i++) {
		if (i - j > k&&m.count(nums[j])) {
			m.erase(nums[j++]);
		}

			auto a = m.lower_bound(nums[i] - t);
			
			if (a != m.end() && abs(*a - nums[i]) <= t) return true;
			m.insert(nums[i]);
	}
	return false;
}
};