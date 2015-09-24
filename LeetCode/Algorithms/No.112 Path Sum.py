
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    result = []
    def hasPathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: bool
        """
        if root is None:
            return False
        self.dfs(root, 0)
        for i in range(len(self.result)):
            if self.result[i] == sum:
                return True
        else:
            return False


    def dfs(self, root, sum):
        if not root.left and not root.right:
            sum += root.val
            self.result.append(sum)
            return
        else:
            sum += root.val
            if root.left:
                self.dfs(root.left, sum)
            if root.right:
                self.dfs(root.right, sum)

