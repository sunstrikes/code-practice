class Solution(object):
    res = []
    def kthSmallest(self, root, k):
        """
        :type root: TreeNode
        :type k: int
        :rtype: int
        230
        """
        self.res = []
        self.inorder(root,k)
        return self.res[k-1]

    def inorder(self,root,k):
        if root == None:
            return
        else:
            self.inorder(root.left,k)
            self.res.append(root.val)
            if len(self.res) == k:
                return
            self.inorder(root.right,k)