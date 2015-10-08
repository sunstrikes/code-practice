class Solution(object):
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        res = [0] *(999999)
        max =0
        for i in range(len(nums)):
            res[nums[i]]+=1
            if nums[i] >max:
                max = nums[i]
        j = 0
        for i in range(max+1):
            if res[i]!=0:
                for k in range(res[i]):
                    nums[j] = i
                    j += 1
        return
