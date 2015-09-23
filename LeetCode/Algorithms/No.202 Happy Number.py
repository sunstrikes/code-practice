class Solution(object):
    def isHappy(self, n):
        """
        :type n: int
        :rtype: bool
        """
        while n!=1:
            string = str(n)
            sum = 0
            for i in range(len(string)):
                sum += int(string[i])**2
            n = sum
            if n == 4:
                return False
        if n == 1:
            return True
        else:
            return False