__author__ = 'SunStrike'
class Solution(object):
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        nums.sort()
        ret = 0
        first = True
        for i in range(len(nums)):
            j = i+1
            k = len(nums)-1
            while j < k:
                sum = nums[i]+nums[j]+nums[k]
                if first:
                    ret = sum
                    first = False
                else:
                    if abs(sum-target) < abs(ret - target):
                        ret = sum
                if ret == target:
                    return ret
                elif sum > target:
                    k -= 1
                else:
                    j += 1
        return ret
