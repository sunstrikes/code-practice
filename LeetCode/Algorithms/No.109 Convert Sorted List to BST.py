class Solution(object):
    res =[]
    def sortedListToBST(self, head):
        """
        :type head: ListNode
        :rtype: TreeNode
        """
        self.res = []
        while head:
            self.res.append(head.val)
            head = head.next
        if len(self.res)==0 :
            return None
        root = self.build(0,len(self.res)-1)
        return root
    def build(self,left,right):

        mid = int((left + right)/2)
        p = TreeNode(self.res[mid])
        if left <= mid -1:
            p.left = self.build(left,mid-1)
        if mid +1 <= right:
            p.right = self.build(mid+1,right)
        return p

