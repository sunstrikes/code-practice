class Solution(object):
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        ll = ListNode(-200000000)
        lt = ll
        while l1 and l2:
            if l1.val >= l2.val:
                lt.next = ListNode(l2.val)
                lt = lt.next
                l2 = l2.next
            else:
                lt.next = ListNode(l1.val)
                lt = lt.next
                l1 = l1.next
        if l1:
            lt.next = l1
        if l2:
            lt.next = l2
        ll = ll.next
        return ll
