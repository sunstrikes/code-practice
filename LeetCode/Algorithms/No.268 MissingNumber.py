class Solution(object):
    def missingNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        #µÈ²îÊıÁĞ
        n = len(nums)
        res_sum = n*(n+1)/2
        res= 0
        for i in nums:
            res += i
        if res == res_sum:
            return 0
        else:
            return res_sum - res