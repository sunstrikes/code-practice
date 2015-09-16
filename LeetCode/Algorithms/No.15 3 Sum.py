__author__ = 'SunStrike'
class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        ret = []
        nums.sort()
        for i in range(len(nums)):
            if i > 0 and nums[i]==nums[i-1]:
                continue
            j = i+1
            k = len(nums) -1
            while j<k:
                sum = nums[i]+nums[k]+nums[j]
                if sum > 0:
                    k -= 1
                elif sum<0:
                    j += 1
                else:
                    tmp = []
                    tmp.append(nums[i])
                    tmp.append(nums[j])
                    tmp.append(nums[k])
                    flag = True
                    for item in ret:
                        if item == tmp:
                            flag = False
                    if flag == True:
                        ret.append(tmp)
                    j += 1
        return ret
