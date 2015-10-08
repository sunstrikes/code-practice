import copy
class Solution(object):
    res  =[]
    a = []
    def combine(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[List[int]]
        """
        self.res = []
        self.a = [0]*k
        self.build(0,k,n,1)
        return self.res

    def build(self,dep,max_dep,n,start):
        if dep == max_dep:
            self.res.append(copy.deepcopy(self.a))
            return
        else:
            for i in range(start,n+1):
                self.a[dep] = i
                self.build(dep+1,max_dep,n,i+1)