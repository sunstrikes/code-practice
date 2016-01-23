class TreeNode(object):
    def __init__(self,val):
        self.val = val
        self.left =None
        self.right = None
class Solution(object):
    inorder = []
    postorder = []
    def buildTree(self, inorder, postorder):
        """
        :type inorder: List[int]
        :type postorder: List[int]
        :rtype: TreeNode
        106
        """
        head = None
        self.inorder = inorder
        self.postorder = postorder
        head = self.build(0,len(inorder)-1,0,len(inorder)-1)
        return head

    def build(self,inleft,inright,posleft,posright):
        if inleft > inright or posleft > posright:
            return None
        else:
            n = inright - inleft +1
            value = self.postorder[posright]
            local = self.search(value,inleft,inright)
            head = TreeNode(value)
            head.left = self.build(inleft,local-1,posleft,posleft+local-inleft-1)
            head.right = self.build(local+1,inright,posleft+local-inleft,posright-1)
            return head
    def search(self,var,left,right):
        for i in range(left,right+1):
            if self.inorder[i] == var:
                return i
