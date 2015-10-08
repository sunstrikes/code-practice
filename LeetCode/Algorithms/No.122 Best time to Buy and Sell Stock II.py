class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        start = 0
        end = 0
        res = 0
        for i in range(len(prices) -1):
            if prices[i+1] > prices[i]:
                end += 1
            else:
                res += prices[end] - prices[start]
                start = end+1
                end = start
                if start == len(prices):
                    break
        if start!= end:
            res += prices[end] - prices[start]
        return res