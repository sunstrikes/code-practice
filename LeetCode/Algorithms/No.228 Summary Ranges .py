class Solution(object):
    def summaryRanges(self, nums):
        """
        :type nums: List[int]
        :rtype: List[str]
        """
        tail = len(nums) -1
        start = 0
        end = 0
        res = []
        if len(nums) ==0 :
            return []
        for i in range(0,tail):
            if nums[i] + 1 == nums[i+1]:
                end += 1
            else:
                if start!=end:
                    tmp = str(nums[start]) +'->'+str(nums[end])
                else:
                    tmp = str(nums[start])
                res.append(tmp)
                start = i + 1
                end = start
        if start == end and end == tail:
            res.append(str(nums[start]))
        else:
            res.append(str(nums[start]) +'->'+str(nums[end]))
        return res