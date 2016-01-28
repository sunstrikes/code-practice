class Solution(object):
    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        m = len(matrix)
        if m == 0 or len(matrix[0])==0:
            return []
        n = len(matrix[0])
        flag = [[0]*n for i in range(m)]
        dir = [[0,1],[1,0],[0,-1],[-1,0]]
        e = 4
        x = 0
        y = 0
        tmp = 0
        res = []
        res.append(matrix[x][y])
        flag[x][y] = 1
        while e:
            tmpx, tmpy = x + dir[tmp][0], y+dir[tmp][1]
            if tmpx<0 or tmpx>=m or tmpy<0 or tmpy>=n:
                tmp += 1
                e -= 1
                if tmp == 4:
                    tmp = 0
                continue
            elif flag[tmpx][tmpy] == 0:
                e = 4
                x, y = tmpx, tmpy
                flag[x][y] = 1
                res.append(matrix[x][y])
            else:
                tmp += 1
                if tmp == 4:
                    tmp = 0
                e -= 1
        return res

