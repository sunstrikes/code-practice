//方法1 dp 超时o(n^2)
int jump(vector<int>& nums) {
	int size = nums.size();
	if (size == 0)
		return 0;
	vector<int> way(size, 0);
	for (int i = size - 2; i >=0; i--) {
		int minn = INT_MAX;
		if (i + nums[i] >= size - 1)
			way[i] = 1;
		else {
			for (int j = 1; j <= nums[i] && i + j < size; ++j) {
				minn = min(minn, way[i + j]);
			}
			if (minn != INT_MAX)
				way[i] = minn + 1;
			else
				way[i] = minn;
		}
	}
	return way[0];
}
//方法2 贪心o(n) 不算具体的跳跃位置, 只找位置所在的区间个数 , 就是跳的次数
int jump(vector<int> & nums) {
	int count = 0, cur = 0, nextMax = 0, i = 0;
	while (cur < nums.size() - 1) {
		count++;
		for (; i <= cur; ++i) {
			nextMax = max(nextMax, i + nums[i]);
		}
		cur = nextMax;
	}
	return count;
}