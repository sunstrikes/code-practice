class Solution(object):
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        prev = head
        if head is None or head.next is None:
            return head
        else:
            p = head.next
        while p:
            if p.val == prev.val:
                p=p.next
                prev.next = p
            else:
                p = p.next
                prev = prev.next
        return head