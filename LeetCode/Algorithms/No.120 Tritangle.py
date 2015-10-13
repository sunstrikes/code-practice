class Solution(object):
    def minimumTotal(self, triangle):
        """
        :type triangle: List[List[int]]
        :rtype: int
        120
        """
        for i in range(1,len(triangle)):
            for j in range(len(triangle[i])):
                tmp = 99999999
                tmp = triangle[i-1][j-1] if j-1>=0 else 99999999
                if j <len(triangle[i-1]):
                    tmp = min(tmp, triangle[i-1][j])
                triangle[i][j] += tmp
        m = 99999999
        cen = len(triangle)
        for i in range(len(triangle[cen-1])):
            if triangle[cen-1][i] < m:
                m = triangle[cen-1][i]
        return m