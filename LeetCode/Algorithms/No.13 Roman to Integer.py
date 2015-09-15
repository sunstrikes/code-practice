class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        trans = {
            'M': 1000,
            'D': 500,
            'C': 100,
            'L': 50,
            'X': 10,
            'V': 5,
            'I': 1
        }
        result = 0
        sub = trans[s[0]]
        for i in range(1,len(s)):
            if trans[s[i]] == trans[s[i-1]]:
                sub += trans[s[i]]
            elif trans[s[i]]>trans[s[i-1]]:
                sub = trans[s[i]]-sub
            else:
                result += sub
                sub = trans[s[i]]
        result += sub
        return result
