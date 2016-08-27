class Solution {
public:
vector<vector<int>>vis;
int to[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int m, n;
int max(int x, int y) {
	return x > y ? x : y;
}
int dfs(vector<vector<int>>& a, int x, int y) {
	if (vis[x][y] != 0)
		return vis[x][y];
	int x0, y0;
	int maxx = 1;
	int flag = false;
	for (int i = 0; i < 4; i++) {
		x0 = x + to[i][0];
		y0 = y + to[i][1];
		if (x0 > -1 && y0 > -1 && x0 < m && y0 < n) {
			if (a[x][y] < a[x0][y0]) {
				int ret = 1 + dfs(a, x0, y0);
				maxx = max(maxx, ret);
			}
		}
	}
	vis[x][y] = maxx;
	return maxx;
}

int longestIncreasingPath(vector<vector<int>>& matrix) {
	m = matrix.size();
	if (m > 0)
		n = matrix[0].size();
	vis = vector<vector<int>>(m,vector<int>(n,0));
	int maxx = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			int ret = dfs(matrix, i, j);
			maxx = max(maxx, ret);
		}
	}
	return maxx;

}
};