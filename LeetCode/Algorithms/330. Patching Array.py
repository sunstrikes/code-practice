"""
import itertools
class Solution(object):
    def minPatches(self, nums, n):
        s = set()
        num = 0
        for i in range(len(nums)):
            tmp = itertools.combinations(nums, i+1)
            for j in tmp:
                x = sum(j)
                num += 1
                s.add(x)
        res = 0
        while num != n:
            com = []
            for i in range(1, n):
                if i not in s:
                    res += 1
                    num += 1
                    s.add(i)
                    for j in s:
                        y = i+j
                        if y <= n and y not in s:
                            num += 1
                            com.append(y)
                    for k in com:
                        s.add(k)
        return res
"""


class Solution(object):
    def minPatches(self, nums, n):
        idx, total, ans = 0, 1, 0
        size = len(nums)
        while total <= n:
            if idx < size and nums[idx] <= total:
                total += nums[idx]
                idx += 1
            else:
                total <<= 1
                ans += 1
        return ans
