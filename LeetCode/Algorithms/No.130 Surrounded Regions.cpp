class Solution {
public:
//dfs边上的o,替换掉,然后再把剩下的o替换成X就行
void dfs(int i, int j, vector<vector<char>>& a) {
	int n = a.size();
	if (n == 0)
		return;
	int m = a[0].size();
	if (i - 1 > 0 && a[i - 1][j] == 'O') {
		a[i - 1][j] = 'M';
		dfs(i - 1, j, a);
	}
	if (i + 1 < n - 1 && a[i + 1][j] == 'O') {
		a[i + 1][j] = 'M';
		dfs(i + 1, j, a);
	}
	if (j + 1 < m - 1 && a[i][j+1] == 'O') {
		a[i][j+1] = 'M';
		dfs(i, j+1, a);
	}
	if (j - 1 >0 && a[i][j-1] == 'O') {
		a[i][j-1] = 'M';
		dfs(i, j-1, a);
	}
}
void solve(vector<vector<char>>& board) {
	int n = board.size();
	if (n == 0)
		return;
	int m = board[0].size();
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if ((i == 0 || i == n - 1 || j == 0 || j == m - 1)&&board[i][j]=='O') {
				board[i][j] = 'M';
				dfs(i, j, board);
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (board[i][j] == 'O')
				board[i][j] = 'X';
			else if (board[i][j] == 'M')
				board[i][j] = 'O';
		}
	}
}
};