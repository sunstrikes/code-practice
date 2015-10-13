import copy
class Solution(object):
    res = []
    def subsets(self, nums):
        nums.sort()
        self.res = []
        for i in range(0,len(nums)+1):
            self.combine(len(nums),i,0,[],nums,0)
        return self.res

    def combine(self,n,k,length,tmp,nums,start):
        if length == k:
            self.res.append(copy.deepcopy(tmp))
        else:
            prev = None
            for i in range(start,n):
                if prev!=nums[i]:
                    tmp.append(nums[i])
                    self.combine(n,k,length+1,tmp,nums,i+1)
                    tmp.pop()
                    prev = nums[i]
                else:
                    continue
