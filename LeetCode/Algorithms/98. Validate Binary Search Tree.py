class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """

        def inOrder(root):
            #rtype:list
            if root is None:
                return
            else:
                inOrder(root.left)
                ll.append(root.val)
                inOrder(root.right)


        ll = list()
        inOrder(root)
        flag = True
        for i in range(len(ll) -1):
            if ll[i]>=ll[i+1]:
                flag = False
                break
        return flag