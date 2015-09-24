class Solution(object):
    def getIntersectionNode(self, headA, headB):
        """
        :type head1, head1: ListNode
        :rtype: ListNode
        """
        len1 = 0
        len2 = 0
        p1 = headA
        p2 = headB
        while p1:
            p1 = p1.next
            len1 += 1
        while p2:
            p2 = p2.next
            len2 += 1
        sub = len1 - len2
        p1 = headA
        p2 = headB
        if sub < 0:
            while sub:
                sub += 1
                p2 = p2.next
        elif sub > 0:
            while sub:
                sub -= 1
                p1 = p1.next
        while p1:
            if p1.val == p2.val:
                return p1
            else:
                p1 = p1.next
                p2 = p2.next
        return None