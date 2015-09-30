class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 0:
            return 0
        num = 0
        for i in range(len(nums)):
            num = num ^ nums[i]
        num = num ^0
        return num