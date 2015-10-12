import copy
class Solution(object):
    def generateTrees(self, n):
        """
        :type n: int
        :rtype: List[TreeNode]
        num[0] =1
        num[1] = 1
        num[i] = sum(nums[j]+nums[i-1-j])
        """
        return self.createTree(1,n)
    def createTree(self,start,end):
        results = []
        if start>end:
            results.append(None)
            return results
        for i in range(start,end+1):
            left = self.createTree(start,i-1)
            right = self.createTree(i+1,end)
            for j in range(len(left)):
                for k in range(len(right)):
                    root = TreeNode(i)
                    root.left = left[j]
                    root.right = right[k]
                    results.append(root)
        return results