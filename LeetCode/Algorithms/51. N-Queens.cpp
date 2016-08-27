class Solution {
public:
int num;
void dfs(vector<vector<string>>&res, vector<string>&tmp, int cen) {
	if (cen == num)
		return;
	for (int i = 0; i < num; i++) {
		bool flag = true;
		for (int j = 0; j < cen; j++) {
			if (tmp[j][i] == 'Q') {
				flag = false;
				break;
			}
			if ((i + cen - j >= 0 && tmp[j][i + cen - j] == 'Q') || ((i + j - cen) < num && tmp[j][i + j - cen] == 'Q')) {
				flag = false;
				break;
			}
		}
		if (flag) {
			tmp[cen][i] = 'Q';
			dfs(res, tmp, cen + 1);
			if (cen == num - 1) {
				res.push_back(tmp);
			}
			tmp[cen][i] = '.';
		}
	}
}
vector<vector<string>> solveNQueens(int n) {
	num = n;
	vector<vector<string>> res;
	vector<string> tmp(n,string(n,'.'));
	dfs(res, tmp, 0);
	return res;
}
};