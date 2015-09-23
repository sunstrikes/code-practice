
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
"""
class Solution(object):
    ll =[]
    def isSymmetric(self, root):

        :type root: TreeNode
        :rtype: bool
        self.ll.clear()
        self.inorder(root)
        tail = len(self.ll)
        mid = int((tail+1)/2)
        flag = True
        for i in range(mid):
            if self.ll[i] != self.ll[tail - i -1]:
                flag = False
                break
        return flag


    def inorder(self, root):
        if root is None:
            return
        else:
            self.inorder(root.left)
            self.ll.append(root.val)
            self.inorder(root.right)
"""

class Solution(object):
    flag = True
    def isSymmetric(self, root):
        self.inorder(root, root)
        return self.flag

    def inorder(self,root1,root2):
        if root1 is None and root2 is None:
            return
        elif root1 is None or root2 is None:
            self.flag = False
            return
        elif root1.val != root2.val:
            self.flag = False
            return
        else:
            self.inorder(root1.left, root2.right)
            print(root1.val,root2.val)
            self.inorder(root1.right, root2.left)
