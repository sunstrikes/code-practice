import copy
class Solution(object):
    res = list()
    def restoreIpAddresses(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        self.res = []
        self.dfs(0, 4, [], s)
        return self.res

    def dfs(self, start, segment, ans, s):
        if start >= len(s) and segment != 0:
            return
        if start != len(s) and segment == 0:
            return
        if start == len(s) and segment == 0:
            self.res.append('.'.join(ans))
            return
        for i in range(start, start+3):
            if start >= len(s):
                break
            digit = s[start:i+1]
            if int(digit) > 255:
                return
            ans.append(digit)
            self.dfs(i+1, segment-1, ans, s)
            ans.pop()
            if s[start] == '0':
                return
