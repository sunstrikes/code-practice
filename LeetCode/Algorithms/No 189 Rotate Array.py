class Solution(object):
    def rotate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        tail = len(nums)
        if k>=tail:
            k = k%tail
        tmp1 = nums[tail-k:tail]
        tmp2 = nums[0:tail-k]
        for i in range(len(nums)):
            if i<k:
                nums[i] = tmp1[i]
            else:
                nums[i] = tmp2[i-k]
        print(nums)