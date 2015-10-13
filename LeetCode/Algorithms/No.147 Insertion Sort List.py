class Solution(object):
    def insertionSortList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head is None:
            return None
        p = ListNode(-1)
        p.next = head
        pre = head
        cur = pre.next
        while cur:
            if cur.val >= pre.val:
                pre = cur
                cur = cur.next
            else:
                insert_pre = p
                insert_cur = p.next
                while insert_cur.val <  cur.val:
                    insert_pre = insert_cur
                    insert_cur = insert_cur.next
                pre.next = cur.next
                cur.next = insert_cur
                insert_pre.next = cur
                cur = pre.next
        head = p.next
        return head