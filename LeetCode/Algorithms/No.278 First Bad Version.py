# The isBadVersion API is already defined for you.
# @param version, an integer
# @return a bool
# def isBadVersion(version):

class Solution(object):
    def firstBadVersion(self, n):
        """
        :type n: int
        :rtype: int
        """
        mid = int((n+1)/2)
        first = 1
        end = n
        while first<end:
            mid = int((first + end)/2)
            x = isBadVersion(mid)
            if x:
                end = mid - 1
            else:
                first = mid + 1
        if not isBadVersion(first):
            return first+1
        else:
            return first