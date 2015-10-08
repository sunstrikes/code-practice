#±¨¾¯ÁË£¡£¡

class Solution(object):
    def findMin(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 0:
            return
        min = nums[0]
        start = 0
        end = len(nums) -1
        while start < end:
            mid = int((start + end)/2)
            if nums[mid] > min:
                start = mid+1
            else:
                min = nums[mid]
                end = mid -1
        if len(nums)> 1 and nums[1] < min:
            return nums[1]
        if nums[start]>min and start!=len(nums)-1:
            return nums[start+1]
        elif nums[start] < min:
            return nums[start]
        else:
            return min
solu = Solution()
print(solu.findMin([2,1]))