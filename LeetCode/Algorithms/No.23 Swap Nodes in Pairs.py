class Solution(object):
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        p1 = head
        if p1 == None:
            return head
        else:
            p2 = head.next
            while p1 and p2:
                tmp = p1.val
                p1.val = p2.val
                p2.val = tmp
                if p2.next:
                    p1 = p2.next
                else:
                    break
                if p1.next:
                    p2 = p1.next
                else:
                    break
            return head