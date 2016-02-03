'''
my error solution
class Solution(object):
    def wiggleSort(self, nums):
        nums.sort()
        half = int((len(nums)+1)/2)
        i, j, k = 0, half, 0
        if len(nums) %2:
            half += 1
        res = list()
        while i < half or j < len(nums):
            if k % 2 == 0:
                res.append(nums[i])
                i+=1
            else:
                if j == len(nums):
                    break
                res.append(nums[j])
                j += 1
            k += 1
        for i in range(len(nums)):
            nums[i] = res[i]
        return nums
'''
class Solution(object):
    def wiggleSort(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        size = len(nums)
        snums = sorted(nums)
        for x in range(1, size, 2):
            nums[x] = snums.pop()
        for x in range(0, size, 2):
            nums[x] = snums.pop()
solu = Solution()
print(solu.wiggleSort([1, 5, 1, 1, 6, 4]))