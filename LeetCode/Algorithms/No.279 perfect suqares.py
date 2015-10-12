import collections
class Solution(object):
    dp = [99999999]*(10000+1)
    def numSquares(self, n):
        """
        dp[i*i] =1
        dp[x+ y*y]  = min(dp[x+y*y],dp[x]+1)
        """
        if self.dp[n] != 99999999:
            return self.dp[n]
        else:
            y = 1
            tmp = y
            while tmp <= n:
                self.dp[tmp] =1
                y += 1
                tmp = y*y
            for x in range(1,n+1):
                y = 1
                tmp = y*y
                while x + tmp<=n:
                    self.dp[x+tmp] = min(self.dp[x] +1,self.dp[x+tmp])
                    y+=1
                    tmp = y*y
            return self.dp[n]