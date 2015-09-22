__author__ = 'SunStrike'
class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        mid = nums[0]
        flag = 0
        for i in range(1,len(nums)):
            if nums[i]!=mid:
                flag -= 1
            else:
                flag += 1
            if flag == -1:
                mid = nums[i]
                flag = 0
        return mid