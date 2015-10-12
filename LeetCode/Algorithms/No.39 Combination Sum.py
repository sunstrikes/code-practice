import copy
class Solution(object):
    res = []
    def combinationSum(self, c, t):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        39
        """
        self.res = []
        c.sort()
        self.caculate([],c,t,t)
        return self.res
    def caculate(self,tmp,c,t,now):
        if now == 0:
            self.res.append(copy.deepcopy(tmp))
            return
        if now < 0:
            return
        else:
            if len(tmp):
                x = tmp[len(tmp)-1]
            else:
                x = -1
            for i in range(len(c)):
                if c[i]>=x:
                    tmp.append(c[i])
                    self.caculate(tmp,c,t,now - c[i])
                    tmp.pop()
