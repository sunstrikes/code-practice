class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        213
        """
        n = len(nums)
        dp = [0]*n
        res = 0
        if n == 0:
            return 0
        elif n== 1:
            return nums[0]
        dp[0] = nums[0]
        for i in range(1,len(nums)-1):
        	dp[i] = max(dp[i-1],0 if i==1 else dp[i-2]+nums[i])
        res = dp[n-2]
        #print(dp)
        dp[0] = 0
        dp[1] = nums[1]
        for i in range(2,n):
        	dp[i] = max(dp[i-1],dp[i-2]+nums[i])
        #print(dp)
        return max(res,dp[n-1])
