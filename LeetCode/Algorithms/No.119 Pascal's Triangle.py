class Solution(object):
    def getRow(self, k):
        """
        :type rowIndex: int
        :rtype: List[int]
        """
        p1 = [1,1]
        p2 = []
        if k == 0:
            return [1]
        elif k == 1:
            return [1, 1]
        else:
            for i in range(2,k+1):
                p2 = [1]*(i+1)
                for j in range(1,i):
                    p2[j] = p1[j-1]+p1[j]
                p1 = p2
            return p2
 