class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        x = -200000000
        ret = 0
        for i in nums:
            if i != x:
                ret += 1
                x = i
        return ret
