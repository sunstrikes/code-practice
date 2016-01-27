class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def rotateRight(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        res = list()
        if head is None:
            return
        p = head
        while p:
            res.append(p)
            p = p.next
        n = len(res)
        k = k % n
        if k == 0:
            return head
        else:
            res[-1].next = head
            res[n-k-1].next = None
            head = res[n-k]
        return head
head = ListNode(1)
solu = Solution()
solu.rotateRight(head, 99)