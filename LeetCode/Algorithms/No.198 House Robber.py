class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if nums == []:
            return 0
        elif len(nums) ==1:
            return nums[0]
        result = [0]*len(nums)
        result[0] = nums[0]
        result[1] = max(nums[1],nums[0])
        for i in range(2,len(nums)):
            result[i] = max(result[i-2]+nums[i],result[i-1])
        return result[len(nums)-1]
