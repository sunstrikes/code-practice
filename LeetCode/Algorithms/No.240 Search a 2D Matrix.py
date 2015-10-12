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
        if m == 0 or n == 0:
            return False
        i = 0
        j = n - 1
        while i < m and j>=0:
            x = matrix[i][j]
            if x == target:
                return True
            elif target < x:
                j -= 1
            else:
                i += 1
        else:
            return False