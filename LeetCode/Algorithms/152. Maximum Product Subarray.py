class Solution(object):
    def maxProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        pos = [0]*n
        nag = [0]*n
        res = max(nums)
        for i in range(n):
            if i == 0:
                if nums[i] > 0:
                    pos[0] = nums[i]
                elif nums[i]<0:
                    nag[0] = nums[i]
            else:
                if nums[i] > 0:
                    pos[i] = max(pos[i-1]*nums[i],nums[i])
                    nag[i] = nag[i-1]*nums[i]
                elif nums[i] < 0:
                    pos[i] = nag[i-1]*nums[i]
                    nag[i] = min(pos[i-1]*nums[i],nums[i])
                if pos[i] and pos[i] > res:
                    res = pos[i]
        return res
