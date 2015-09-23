class Solution(object):
    flag = True
    def isBalanced(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        self.dfs(root)
        return self.flag

    def dfs(self, root):
        if root is None:
            return 0
        else:
            h1 = self.dfs(root.left)
            h2 = self.dfs(root.right)
            if abs(h1-h2) > 1:
                self.flag = False
            return max(h1, h2)+1
