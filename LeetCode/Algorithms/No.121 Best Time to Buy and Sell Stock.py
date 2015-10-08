class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        start = 999999999
        res = 0
        for i in range(len(prices)):
            if prices[i] < start:
                start = prices[i]
            elif prices[i] - start > res:
                res = prices[i] - start
        return res
solu = Solution()
print(solu.maxProfit([6,1,3,2,4,7]))