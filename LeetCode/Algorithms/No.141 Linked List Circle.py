# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        judge = set([])
        p = head
        while p:
            if p not in judge:
                judge.add(p)
                p = p.next
            else:
                return True
        else:
            return False