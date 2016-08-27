/*³¬Ê±
int trap(vector<int>& h) {
	int maxx = 0;
	int res = 0;
	for (auto x : h) {
		maxx = max(x, maxx);
	}
	for (int i = 1; i <= maxx; ++i) {
		int flag = 0;
		int start, end;
		for (int j = 0; j < h.size(); ++j) {
			if (h[j] >= i) {
				flag ++;
				if (flag == 1) {
					start = j;
				}
				else if (flag == 2) {
					end = j;
					flag = 1;
					for (int k = start + 1; k < end; ++k) {
						h[k] = i;
						res++;
					}
					start = j;
				}
			}
		}
	}
	return res;
}
*/
int trap(vector<int>& height) {
	int sz = height.size(), highest = 0, water = 0;
	//from left to right, only consider the trap's left elevation
	for (int i = 0; i<sz; i++) {
		if (height[i]<highest) water += highest - height[i];
		highest = max(highest, height[i]);
	}

	int prehighest = highest;
	highest = 0;
	//from right to left, only consider the trap's right elevation, subtract the surplus water
	for (int i = sz - 1; i >= 0; i--) {
		highest = max(height[i], highest);
		if (highest<prehighest) water -= prehighest - highest;
	}
	return water;
}