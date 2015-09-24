class Solution(object):
    def containsNearbyDuplicate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        set1 = set([])
        start = 0
        end = 0
        for i in range(len(nums)):
            if nums[i] not in set1:
                set1.add(nums[i])
                if end < len(nums):
                    end += 1
            else:
                return True
            if end - start >k:
                set1.remove(nums[start])
                start += 1
                if start > len(nums) - k:
                    break
        return False