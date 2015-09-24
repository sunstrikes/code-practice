# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def removeElements(self, head, val):
        """
        :type head: ListNode
        :type val: int
        :rtype: ListNode
        """
        ll = []
        p1 = head
        while p1:
            if p1.val != val:
                ll.append(p1.val)
            p1 = p1.next
        if len(ll) == 0:
            return None
        head = ListNode(0)
        p1 = head
        for i in range(len(ll)):
            p1.val = ll[i]
            if i == len(ll) -1:
                p1.next = None
            else:
                p1.next = ListNode(0)
                p1 = p1.next
        return head