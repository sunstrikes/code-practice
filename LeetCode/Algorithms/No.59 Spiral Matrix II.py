class Solution(object):
    def generateMatrix(self, n):
        """
        :type n: int
        :rtype: List[List[int]]
        """
        res = []
        for i in range(n):
            res.append([0]*n)
        start = 0
        end = n-1
        num =1
        while start<end:
            for j in range(start,end):
                res[start][j] = num
                num+=1
            for i in range(start,end):
                res[i][end] = num
                num+=1
            for j in range(end,start,-1):
                res[end][j] = num
                num+=1
            for i in range(end,start,-1):
                res[i][start]=num
                num+=1
            start +=1
            end -=1
        if start == end:
            res[start][start] = num
        return res
solu = Solution()
print(solu.generateMatrix(3))