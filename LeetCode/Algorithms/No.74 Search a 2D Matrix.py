class Solution(object):
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        m = len(matrix)
        n = len(matrix[0])
        tmp = 0
        for i in range(m):
            if matrix[i][0]>target:
                tmp = i-1
                break
        else:
            tmp = m-1
        if tmp < 0:
            return False
        for j in range(n):
            if matrix[tmp][j]==target:
                return True
        else:
            return False
solu = Solution()
print(solu.searchMatrix([[1],[3]],3))