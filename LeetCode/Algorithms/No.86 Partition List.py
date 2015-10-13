class Solution(object):
    def partition(self, head, x):
        """
        :type head: ListNode
        :type x: int
        :rtype: ListNode
        86
        """
        res = []
        p = head
        head1 = None
        head2 = None
        p1 = None
        p2 = None
        while p:
            if p.val < x:
                if head1 is None:
                    head1 = p
                    p1 = head1
                else:
                    p1.next = p
                    p1 = p1.next
            else:
                if head2 is None:
                    head2 = p
                    p2 = head2
                else:
                    p2.next = p
                    p2 = p2.next
            p = p.next
        if p1:
            p1.next = head2
        if p2:
            p2.next = None
        return head1