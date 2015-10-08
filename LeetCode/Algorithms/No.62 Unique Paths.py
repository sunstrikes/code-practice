""" DFS TLE
class Solution(object):
    res = 0
    def uniquePaths(self, m, n):
        self.res =0
        self.DFS(1,1,m,n)
        return self.res

    def DFS(self,m,n,left,right):
        if m >left or n >right:
            return
        elif m ==left and n ==right:
            self.res += 1
            return
        else:
            self.DFS(m,n+1,left,right)
            self.DFS(m+1,n,left,right)
"""
class Solution(object):
    def uniquePaths(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        list = [([0]*n) for i in range(m)]
        for i in range(n):
            list[0][i] = 1
        for j in range(m):
            list[j][0] = 1
        for i in range(1,m):
            for j in range(1,n):
                list[i][j] = list[i-1][j]+list[i][j-1]
        return list[m-1][n-1]

solu  = Solution()
print(solu.uniquePaths(2,3))
