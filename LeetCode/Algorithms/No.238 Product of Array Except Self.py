class Solution(object):
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        res = [1]*len(nums)
        for i in range(1,len(nums)):
            res[i] = res[i-1]*nums[i-1]
        tmp = 1
        for i in range(len(nums)-2,-1,-1):
            tmp *= nums[i+1]
            res[i] = tmp*res[i]
        return res