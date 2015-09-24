class Solution(object):
    def computeArea(self, A, B, C, D, E, F, G, H):
        """
        :type A: int
        :type B: int
        :type C: int
        :type D: int
        :type E: int
        :type F: int
        :type G: int
        :type H: int
        :rtype: int
        """
        a1 = (C-A)*(D-B)
        a2 = (G-E)*(H-F)
        A1 = max(A, E)
        B1 = max(B, F)
        C1 = min(C, G)
        D1 = min(D, H)
        if D1 <= B1 or C1 <= A1:
            return a1+a2
        else:
            return a1+a2-(D1-B1)*(C1-A1)