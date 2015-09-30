class Solution(object):
    def convertToTitle(self, n):
        """
        :type n: int
        :rtype: str
        """
        dict = ['A']*27
        for i in range(1,27):
            dict[i] = chr(ord('A')+i-1)
        res = []
        while n != 0:
            tmp = n%26
            if tmp != 0:
                res.append(dict[tmp])
                n = int(n/26)
            else:
                res.append(dict[26])
                n = int(n/26) - 1
        res.reverse()
        return ''.join(res)