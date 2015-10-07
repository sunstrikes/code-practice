import copy
class Solution(object):
    def rotate(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix[0])
        tmp = copy.deepcopy(matrix)
        for i in range(len(matrix)):
            tmp.append(matrix[i])
        for i in range(n):
            for j in range(n):
                matrix[j][n-i-1] = tmp[i][j]
solu = Solution()
solu.rotate([[1,1,0],[1,0,1],[0,1,1]])