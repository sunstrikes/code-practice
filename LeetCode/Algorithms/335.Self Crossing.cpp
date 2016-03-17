class Solution {
public:
//一共只有三种相交情况..全部考虑完就可以了..
bool isSelfCrossing(vector<int>& x) {
	for (int i = 3; i < x.size(); ++i) {
		if (i >= 3 && x[i] >= x[i - 2] && x[i - 1] <= x[i - 3])
			return true;
		if (i >= 4 && x[i - 1] == x[i - 3] && x[i - 2] <= x[i - 4] + x[i])
			return true;
		if (i >= 5 && x[i - 2] > x[i - 4] && x[i - 1] <= x[i - 3] && x[i - 1] + x[i - 5] >= x[i - 3] && x[i] + x[i - 4] >= x[i - 2])
			return true;
	}
	return false;
}
};