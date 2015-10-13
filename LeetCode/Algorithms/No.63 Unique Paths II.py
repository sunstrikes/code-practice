class Solution(object):
    def uniquePathsWithObstacles(self, grid):
        """
        :type obstacleGrid: List[List[int]]
        :rtype: int
        """
        m = len(grid)
        n = len(grid[0])
        grid[0][0] = 0 if grid[0][0] == 1 else 1
        for i in range(1,m):
            grid[i][0] = 0 if grid[i][0] == 1 else grid[i-1][0]
        for j in range(1,n):
            grid[0][j] = 0 if grid[0][j] == 1 else grid[0][j-1]
        for i in range(1,m):
            for j in range(1,n):
                if grid[i][j] ==1:
                    grid[i][j] = 0
                else:
                    grid[i][j] = grid[i-1][j] + grid[i][j-1]
        return grid[m-1][n-1]