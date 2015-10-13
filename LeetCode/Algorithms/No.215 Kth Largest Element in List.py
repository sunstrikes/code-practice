import random
class Solution(object):
    def findKthLargest(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        pivot = random.choice(nums)
        num1,num2 = [],[]
        for num in nums:
            if num > pivot:
                num1.append(num)
            elif num < pivot:
                num2.append(num)
        if k <= len(num1):
            return self.findKthLargest(num1,k)
        if k > len(nums) - len(num2):
            return self.findKthLargest(num2,k - (len(nums)-len(num2)))
        return pivot