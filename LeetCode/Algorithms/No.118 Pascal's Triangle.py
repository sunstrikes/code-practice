
class Solution(object):
    def generate(self, numRows):
        """
        :type numRows: int
        :rtype: List[List[int]]
        """
        result = []
        tmp =[]
        for i in range(numRows):
            tmp = [1]*(i+1)
            for j in range(1, i):
                tmp[j] = result[i-1][j-1] + result[i-1][j]
            add = tmp
            result.append(add)
        return result