/*
(a * b) % m = ((a % m) * (b % m)) % m。 
算法1： 分治策略:
（1）若power 为奇数： 令 power = 2k+1, k 为非负整数  , 则
                   a^(2k+1) = (a^k)^2 *a ; a^(2k+1) % m = ((a^k % m)^2 % m * a) % m
  (2)   若power 为偶数:    令 power = 2k, k为非负整数， 则
                   a^(2k) = (a^k)^2 ; a^(2k) % m = (a^k % m)^2 % m
  (3)   若power == 1 : 返回 a % m ； 若 power == 0: 返回 1 % m。


算法2： 整数的二进制分解
 将大整数 power 按照二进制进行分解：
            power = a[N] * 2^N + a[N-1] * 2^(N-1) + … + a[1] * 2 + a[0]
其中： a[i] 取值为 0 或 1 ( i=0,1,.., N)，则
           a^power = a^(a[N] * 2^N) * a^(a[N-1] * 2^(N-1)) * … * a^(a[1] * 2) * a^a[0]
 很显然:  
          (1) 若 a[i] = 0, 则 a[i] * 2^i = 0 , a^(a[i]*2^i) = 1, 该乘积项可以消去；
          (2) 若 a[i] = 1, 则 a[i] * 2^i = 2^i ， a^(2^i) % m = (a^(2^(i-1)) % m)^2 % m.  
                令 temp = a^(2^(i-1)) % m , 则 a^(2^i) % m = (temp * temp) % m。
比如,  power = 26 = 16 + 8 + 2 = (11010)2, 则 a^26 = a^(2^4 + 2^3 + 2^1);  
计算 a^power 实际上是计算 power 的二进制表示中所有位为1对应的乘积项。
                (a^26) % m = ((a^16 %m) * (a^8 %m) * (a^2 % m)) %m
而， a^8 % m = ((a^4 %m) × (a^4%m)) % m  是可以用动态规划法逐次求解的。
*/
//这个题的解法： a^1234567 % k = (a^1234560 % k) * (a^7 % k) % k = (a^123456 % k)^10 % k * (a^7 % k) % k
class Solution {
public:
int powmod(int a, int k) //a^k mod 1337 where 0 <= k <= 10 
{ // 之所以不用pow是防止INT_MAX溢出
	a %= 1337;
	int result = 1;
	for (int i = 0; i < k; ++i)
		result = (result * a) % 1337;
	return result;
}

int cal_pow(int a, vector<int>& b, int size) {
	if (size < 0) {
		return 1;
	}
	else {
		int res = powmod(cal_pow(a, b, size - 1) , 10);
		res = (res * powmod(a, b[size])) % 1337;
		return res;
	}
}
int superPow(int a, vector<int>& b) {
	return cal_pow(a, b, b.size() - 1);
}
};