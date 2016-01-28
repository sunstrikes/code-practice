class NumMatrix(object):
    def __init__(self, matrix):
        """
        initialize your data structure here.
        :type matrix: List[List[int]]
        """
        self.matrix = matrix
        m = len(matrix)
        if m == 0:
            return
        n = len(matrix[0])
        self.sum = [[0]*n for i in range(m)]
        for i in range(m):
            for j in range(n):
                if i == 0:
                    self.sum[i][j] = self.sum[i][j-1]+matrix[i][j]
                elif j == 0:
                    self.sum[i][j] = self.sum[i-1][j]+matrix[i][j]
                else:
                    self.sum[i][j] = self.sum[i-1][j]+self.sum[i][j-1]-self.sum[i-1][j-1]+matrix[i][j]


    def sumRegion(self, row1, col1, row2, col2):
        """
        sum of elements matrix[(row1,col1)..(row2,col2)], inclusive.
        :type row1: int
        :type col1: int
        :type row2: int
        :type col2: int
        :rtype: int
        """
        if not(row1<=row2 and col1<=col2):
            return 0
        sum = 0
        if row1 == 0 and col1 == 0:
            sum = self.sum[row2][col2]
        elif row1 == 0:
            sum = self.sum[row2][col2] - self.sum[row2][col1-1]
        elif col1 == 0:
            sum = self.sum[row2][col2] - self.sum[row1-1][col2]
        else:
            sum = self.sum[row2][col2] - self.sum[row2][col1-1] - self.sum[row1-1][col2] + self.sum[row1-1][col1-1]
        return sum
