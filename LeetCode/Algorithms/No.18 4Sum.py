import copy
import itertools
class Solution(object):
    res = []
    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        self.res = []
        nums.sort()
        self.kSum(4,0,target,nums,[])
        return self.res

    def kSum(self,k,st,target,nums,tmp):
        if k!=2:
            x = -999999999999
            for i in range(st,len(nums)-k+1):
                if nums[i] == x:
                    continue
                tmp.append(nums[i])
                self.kSum(k-1,i+1,target-nums[i],nums,tmp)
                x=tmp.pop()
        else:
            start,end = st,len(nums)-1
            while start<end:
                sum = nums[start]+nums[end]
                if sum == target:
                    n = len(self.res)
                    if n ==0 or not(self.res[n-1][2]==nums[start] and self.res[n-1][3] == nums[end] and self.res[n-1][1] == tmp[1] and self.res[n-1][0] == tmp[0]):
                        tmp.append(nums[start])
                        tmp.append(nums[end])
                        self.res.append(copy.deepcopy(tmp))
                        tmp.pop()
                        tmp.pop()
                    start+=1
                    end-=1
                elif sum<target:
                    start+=1
                else:
                    end-=1