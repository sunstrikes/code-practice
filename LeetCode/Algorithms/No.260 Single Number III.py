class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        res = set([])
        for i in range(len(nums)):
            if nums[i] not in res:
                res.add(nums[i])
            else:
                res.remove(nums[i])
        return [i for i in res]