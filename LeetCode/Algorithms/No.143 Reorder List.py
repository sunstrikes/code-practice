class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def reorderList(self, head):
        """
        :type head: ListNode
        :rtype: void Do not return anything, modify head in-place instead.
        """
        stack = list()
        num = 0
        p = head
        if p is None:
            return
        while p:
            stack.append(p)
            num+=1
            p = p.next
        num = int(num/2)
        p = head
        for i in range(num):
            tmp = stack.pop()
            h = p
            p = p.next
            h.next = tmp
            tmp.next = p
            if i == num-1:
                p.next = None
        p = head
        """
        while p:
            print(str(p.val)+',')
            p = p.next
        """