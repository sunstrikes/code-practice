class Solution(object):
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        if len(nums) ==0 :
            return [-1,-1]
        res = [-1] *2
        left = 0
        right = len(nums) -1
        flag = False
        mid = 0
        while left <= right:
            mid = int((left + right)/2)
            if nums[mid] >= target:
                right = mid-1
            else:
                if mid < len(nums) -1 and nums[mid+1] == target:
                    flag = True
                    break
                else:
                    left = mid +1
        if nums[0] == target:
            res[0] = 0
        elif flag:
            res[0] = mid+1
        else:
            return [-1,-1]

        left = 0
        right = len(nums) -1
        flag = False
        mid = 0
        while left <= right:
            mid = int((left + right)/2)
            if nums[mid] <= target:
                left = mid+1
            else:
                if mid > 0 and nums[mid-1] == target:
                    flag = True
                    break
                else:
                    right = mid
        if nums[len(nums)-1] == target:
            res[1] = len(nums) -1
        elif flag:
            res[1] = mid-1
        else:
            return [-1,-1]

        return res
