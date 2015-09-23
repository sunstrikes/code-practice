class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head:
            return head
        else:
            p = head.next
            head.next = None
            while p:
                tmp = p.next
                p.next = head
                head = p
                p = tmp
            return head
