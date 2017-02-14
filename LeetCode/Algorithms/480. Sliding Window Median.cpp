class Solution {
public:
	vector<double> medianSlidingWindow(vector<int>& nums, int k) {
		multiset<int> win(nums.begin(), nums.begin() + k);
		auto mid = next(win.begin(), k / 2); //找当前set中位
		vector<double> res;
		for (int i = k;; i++) {
			res.push_back(double((*mid) + *next(mid, k % 2 - 1)) / 2);
			if (i == nums.size())
				return res;
			win.insert(nums[i]);
			if (nums[i] < *mid) {
				mid--;
			}

			if (nums[i - k] <= *mid) {
				mid++;
			}
			win.erase(win.lower_bound(nums[i - k]));
		}
	}
};