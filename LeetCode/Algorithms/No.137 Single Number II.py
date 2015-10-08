class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        dict = {}
        for i in range(len(nums)):
            if nums[i] not in dict:
                dict[nums[i]] = 1
            else:
                if dict[nums[i]] == 2:
                    dict.pop(nums[i])
                else:
                    dict[nums[i]] += 1
        for k in dict:
            return k