class Solution(object):
    def isPalindrome(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        res1 = []
        while head:
            res1.append(head.val)
            head = head.next
        tail = len(res1) -1
        flag = True
        for i in range(0,int((tail+1)/2)):
            if res1[i] != res1[tail-i]:
                flag = False
                break
        return flag
