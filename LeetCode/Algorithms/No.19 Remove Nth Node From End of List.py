class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        p1 = head
        p2 = head
        i = 0
        while p2:
            if i < n+1:
                p2 = p2.next
                i += 1
            else:
                p1 = p1.next
                p2 = p2.next
        if p1 == head and i == n:
            head = head.next
        else:
            p1.next = p1.next.next
        return head