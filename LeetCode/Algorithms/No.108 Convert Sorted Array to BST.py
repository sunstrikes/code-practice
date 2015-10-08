class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def sortedArrayToBST(self, nums):
        """
        :type nums: List[int]
        :rtype: TreeNode
        """
        if len(nums)==0:
            return
        root = self.find_mid(0,len(nums)-1,nums)
        self.binary_search(root,0,len(nums)-1,nums)
        return root

    def find_mid(self,m,n,nums):
        if m <= n:
            mid = int((n+m)/2)
            return TreeNode(nums[mid])
        else:
            return None

    def binary_search(self,root,m,n,nums):
        mid = int((n+m)/2)
        root.left = self.find_mid(m,mid-1,nums)
        if root.left:
            self.binary_search(root.left,m,mid-1,nums)
        root.right =self.find_mid(mid+1,n,nums)
        if root.right:
            self.binary_search(root.right,mid+1,n,nums)
        else:
            return
