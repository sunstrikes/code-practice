#my solution ... too young...
class Solution(object):
    def maximalSquare(self, matrix):
        """
        :type matrix: List[List[str]]
        :rtype: int
        """
        m = len(matrix)
        if m == 0:
            return 0
        n = len(matrix[0])
        maxx = 0
        dp = [[0]*n for i in range(m)]
        for i in range(len(matrix)):
            for j in range(len(matrix[i])):
                if matrix[i][j] == '1':
                    if i > 0 and j > 0:
                        num = dp[i-1][j-1]
                        flag = True
                        for x in range(1, num+1):
                            if matrix[i][j-x] == '0' or matrix[i-x][j] == '0':
                                flag = False
                                break
                        if flag:
                            dp[i][j] = num+1
                        else:
                            dp[i][j] = x
                        if maxx < dp[i][j]:
                            maxx = dp[i][j]
                    else:
                        dp[i][j] = 1
                        if maxx < dp[i][j]:
                            maxx = dp[i][j]
        print(dp)
        return maxx ** 2

#better solution ,pythonic !
#dp[i][j] = min(dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j]) + 1
class Solution(object):
    def maximalSquare(self, matrix):
        """
        :type matrix: List[List[str]]
        :rtype: int
        """
        m = len(matrix)
        if m == 0:
            return 0
        n = len(matrix[0])
        maxx = 0
        dp = [[0]*n for i in range(m)]
        for i in range(len(matrix)):
            for j in range(len(matrix[i])):
                dp[i][j] = int(matrix[i][j])
                if i and j and dp[i][j]:
                    dp[i][j] = min(dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j]) + 1
                maxx = max(maxx,dp[i][j])
        return maxx ** 2