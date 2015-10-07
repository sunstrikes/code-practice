class Solution(object):
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        res = []
        nums.sort()
        from_index =len(nums) -1
        end_index = len(nums)
        while True:
            from_index =len(nums) -1
            tmp = [i for i in nums]
            res.append(tmp)
            while from_index > 0 and nums[from_index] < nums[from_index-1]:
                from_index -= 1
            change_index = from_index
            if from_index == 0:
                break
            while change_index +1 <end_index and nums[from_index-1] < nums[change_index+1]:
                change_index += 1

            tmp = nums[from_index-1]
            nums[from_index-1] = nums[change_index]
            nums[change_index] = tmp

            tmp2 = nums[from_index:end_index]
            tmp2.reverse()
            nums = nums[0:from_index] + tmp2

        return res

solu = Solution()
print(solu.permute([1,2,3]))
p = [1,2,3,4]
p.reverse()
print(p)