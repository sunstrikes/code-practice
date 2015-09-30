class Solution(object):
    def compareVersion(self, version1, version2):
        """
        :type version1: str
        :type version2: str
        :rtype: int
        """
        tmp1 = version1.split('.')
        tmp2 = version2.split('.')
        add = len(tmp1) - len(tmp2)
        if add < 0:
            add *= -1
            for i in range(add):
                tmp1.append('0')
        elif add > 0:
            for i in range(add):
                tmp2.append('0')
        for i in range(len(tmp1)):
            v1 = int(tmp1[i])
            v2 = int(tmp2[i])
            if v1 == v2:
                if i == len(tmp1) -1:
                        return 0
            elif v1 > v2:
                return 1
            else:
                return -1