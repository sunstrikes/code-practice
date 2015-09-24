class Solution(object):
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        i = 1
        res = [1]
        while i < n:
            tmp = []
            num = 1
            for j in range(len(res)):
                if j<len(res)-1 and res[j] == res[j+1]:
                    num += 1
                else:
                    tmp.append(num)
                    tmp.append(res[j])
                    num = 1
            res = tmp
            i += 1
        strres = ''
        for i in res:
            strres = strres + str(i)
        return strres