class Solution(object):
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """

        s = s.lower()
        res1 = []
        for i in range(len(s)):
                if s[i].isalpha() or s[i].isdigit():
                    res1.append(s[i])
        tail = len(res1) -1
        flag = True
        for i in range(0,int((tail+1)/2)):
            if res1[i] != res1[tail-i]:
                flag = False
                break
        return flag
