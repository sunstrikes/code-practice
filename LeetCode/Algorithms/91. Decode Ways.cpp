class Solution {
public:
int a[10000];
int numDecodings(string s) {
	memset(a, 0, sizeof(a));
	int m = s.size();
	a[0] = 1;
	a[1] = 1;
	for (int i = 2; i <= m; i++) {
		if (s[i - 1] == '0') {
			if (s[i - 2] > '2' || s[i - 2] == '0')
				return 0;
			else
				a[i] = a[i - 2];
		}
		else {
			if ((s[i - 1] >= '1'&&s[i - 1] <= '6'&&s[i - 2] == '2') || (s[i - 1] != '0'&&s[i - 2] == '1')) {
				a[i] = a[i - 1] + a[i - 2];
			}
			else
				a[i] = a[i - 1];
		}
	}
	if (s[0] == '0')
		return 0;
	if (m)
		return a[m];
	else
		return 0;
}
};