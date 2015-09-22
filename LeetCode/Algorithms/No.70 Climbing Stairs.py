class Solution(object):
    num = 0
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        ll = [0]*100000
        ll[1] = 1
        ll[2] = 2
        for i in range(3,n+1):
            ll[i] = ll[i-1]+ll[i-2]
        return ll[n]
