class Solution(object):
    res = []
    def binaryTreePaths(self, root):
        """
        :type root: TreeNode
        :rtype: List[str]
        """
        self.res = []
        if root is None:
            return []
        else:
            self.dfs(root, str(root.val))
        return self.res
    def dfs(self,root,ss):
        if root.left is None and root.right is None:
            self.res.append(ss)
        else:
            if root.left:
                self.dfs(root.left,ss+'->'+str(root.left.val))
            if root.right:
                self.dfs(root.right,ss+'->'+str(root.right.val))