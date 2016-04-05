/*
    但是通过前面的分析也知道，之前描述的子问题都是重叠的 (比如你在计算踩K个气球时的maxcoin，肯定会涉及到踩K-1个气球时的结果，这也是可以用bottom up 的意义)，因此根本不能用分治方法来求解。自然的一个想法是，我们可不可以先把整体分割，再分别在被分割的各个子整体中用bottom up。这显然是可行的。不过问题在于怎么分割整体，因为整体的分割需要保证各个整体在后面的计算中要保持相互独立性。比如对于[a1,a2,a3,a4,a5,a6,......,an]，将分割成两个子整体，分割点为k，则得到 N1 = [a1,a2,a3,....,a(k-1)], N2 = [a(k+1),a(k+2),.....,an]。这里分割点k的意义是踩破了第k个气球。于是把整体分成了两部分，问题在于，根据计算规则，k气球破了之后，a(k-1)和a(k+1)会变成相邻的，如果此时踩a(k-1)或者a(k+1)，则都会收到另一个子整体的影响，这样的话，两个子问题就不独立，也就不能用分治了。所以关键的问题在于确定k。

可以发现：

        N1和N2相互独立    <=>  k点为对于整体N的游戏时，最后一个被踩破的气球。

也就是k点被踩破之前，N1和N2重点的气球都不会相互影响。于是我们就成功构造了子问题。因此分治加dp就可以对问题进行求解了。

*/

int dp[1000][1000];
int maxCoins(vector<int>& nums) {
	int n = nums.size();
	vector<int> arr;
	arr.reserve(n + 2);
	arr[0] = arr[n + 1] = 1;
	for (int i = 1; i < n + 1; ++i)
		arr[i] = nums[i - 1];
	memset(dp, 0, sizeof(dp));
	n = n + 2;
	for (int k = 2; k < n; k++) {
		for (int left = 0; left < n - k; ++left) {
			int right = left + k;
			for (int i = left + 1; i < right; ++i) {
                //将i当成最后
				dp[left][right] = max(dp[left][right], arr[left] * arr[i] * arr[right] + dp[left][i] + dp[i][right]);
			}
		}
	}
	return dp[0][n - 1];
}