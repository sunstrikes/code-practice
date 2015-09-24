class Solution(object):
    def isIsomorphic(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        dict1 = {}
        dict2 = {}
        if len(s) != len(t):
            return False
        for i in range(len(s)):
            tmp1 = dict1.get(s[i], None)
            tmp2 = dict2.get(t[i],None)
            if tmp1 is None and tmp2 is None:
                dict1[s[i]] = t[i]
                dict2[t[i]] = s[i]
            elif tmp1 is None or tmp2 is None:
                return False
            else:
                if tmp1 != t[i] or tmp2 != s[i]:
                    return False
        return True