class Solution(object):
    def setZeroes(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """
        m = len(matrix)
        n = len(matrix[0])
        line = set([])
        straight =set([])
        for i in range(m):
            for j in range(n):
                if matrix[i][j]==0:
                    line.add(i)
                    straight.add(j)
        l1 = list(line)
        l2 = list(straight)
        for i in l1:
            for j in range(n):
                matrix[i][j] =0
        for i in l2:
            for j in range(m):
                matrix[j][i]=0
solu = Solution()
solu.setZeroes([[0,0,0,5],[4,3,1,4],[0,1,1,4],[1,2,1,3],[0,0,1,1]])