class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        a = {}
        b = {}
        for i in s:
            if i in a:
                a[i] +=1
            else:
                a[i] = 1
        for i in t:
            if i in b:
                b[i]+=1
            else:
                b[i] =1
        return a == b