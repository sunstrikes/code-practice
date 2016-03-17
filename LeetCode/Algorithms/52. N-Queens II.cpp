int a[1000][1000];
int total = 0;
bool judge(int x, int y,int n) {
	bool flag = true;
	for (int i = 0; i < x; i++) {
		if (a[i][y] == 1) {
			flag = false;
			break;
		}
	}//shu
	int i = x-1, j = y-1;
	while (i>-1&&j>-1) {
		if (a[i][j] == 1) {
			flag = false;
			break;
		}
		i--; j--;
	}
	i = x - 1, j = y + 1;
	while (i>-1&&j<n) {
		if (a[i][j] == 1) {
			flag = false;
			break;
		}
		i--; j++;
	}
	return flag;
}
void dfs(int n, int depth) {
	if (n == depth) {
        /*
        for(int i = 0; i<n;i++){
            for(int j =0;j<n;j++){
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
        */
		total++;
		return;
	}
	else {
		for (int i = 0; i < n; i++) {
			//a[depth][i]
			if (judge(depth, i, n)) {
				a[depth][i] = 1;
				dfs(n, depth + 1);
				a[depth][i] = 0;
			}
		}
	}
}
int totalNQueens(int n) {
	memset(a, 0, sizeof(a));
	total = 0;
	dfs(n, 0);
	return total;
}