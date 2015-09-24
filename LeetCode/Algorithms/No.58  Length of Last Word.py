class Solution(object):
    def lengthOfLastWord(self, s):
        """
        :type s: str
        :rtype: int
        """
        tail = len(s)-1
        if len(s)==0:
            return 0
        while tail >= 0 and s[tail]==' ':
            tail -= 1
        if tail == -1:
            return 0
        tmp = tail
        while s[tmp] != ' ' and tmp != 0:
            tmp -= 1
        if s[tmp]==' ':
            return tail - tmp
        else:
            return tail+1