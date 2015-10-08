# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    res = []
    def preorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        self.res = []
        self.preorder(root)
        return self.res
    def preorder(self, root):
        if root is None:
            return
        else:
            self.res.append(root.val)
            self.preorder(root.left)
            self.preorder(root.right)
