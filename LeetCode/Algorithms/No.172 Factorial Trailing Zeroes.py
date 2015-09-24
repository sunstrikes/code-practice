
class Solution(object):
    def trailingZeroes(self, n):
        """
        :type n: int
        :rtype: int

        n!=2x*3y*5z*...
        显然0的个数等于min(x,z)，并且min(x,z)==z
        [n/k]代表1~n中能被k整除的个数
        [n/2] > [n/5]
        [n/2^2] > [n/5^2]
        ……
        [n/2^p] > [n/5^p]
        """
        ret = 0
        while n:
            ret += int(n/5)
            n = int(n/5)
        return ret
