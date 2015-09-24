class Solution(object):
    def merge(self, nums1, m, nums2, n):
        """
        :type nums1: List[int]
        :type m: int
        :type nums2: List[int]
        :type n: int
        :rtype: void Do not return anything, modify nums1 in-place instead.
        """
        tmp = nums1[:m]
        i = 0
        p1 = p2 = 0
        while i < m+n:
            if p1 == m:
                nums1[i] = nums2[p2]
                p2 += 1
            elif p2 == n:
                nums1[i] = tmp[p1]
                p1 += 1
            else:
                if tmp[p1] < nums2[p2]:
                    nums1[i] = tmp[p1]
                    p1 += 1
                else:
                    nums1[i] = nums2[p2]
                    p2 += 1
            i += 1