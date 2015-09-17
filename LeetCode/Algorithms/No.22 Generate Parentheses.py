class Solution(object):
    def unguarded(self,ret,curr,m,n):
        if m == 0 and n == 0:
            ret.append(curr)
        else:
            if m != 0:
                self.unguarded(ret, curr+'(', m-1, n)
            if m < n and n != 0:
                self.unguarded(ret, curr+')', m, n-1)

    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        ret = []
        curr =""
        self.unguarded(ret,curr,n,n)
        return ret

