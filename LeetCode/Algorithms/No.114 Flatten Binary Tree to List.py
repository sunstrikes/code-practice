class Solution(object):
    tmp = []
    def flatten(self, root):
        """
        :type root: TreeNode
        :rtype: void Do not return anything, modify root in-place instead.
        114
        """
        self.tmp = []
        if root is None:
            return
        self.preorder(root)
        root.left = None
        p = root
        for i in range(len(self.tmp)):
            if i != 0:
                p.right = TreeNode(self.tmp[i])
                p = p.right

    def preorder(self,root):
        if root is None:
            return
        else:
            self.tmp.append(root.val)
            self.preorder(root.left)
            self.preorder(root.right)
