class Solution(object):
    def connect(self, root):
        """
        :type root: TreeLinkNode
        :rtype: nothing
        """
        num = 1
        queue = []
        result = []
        if root is None:
            return
        queue.append(root)
        while len(queue):
            tmp = None
            for i in range(num):
                tmp2 = tmp
                tmp = queue.pop(0)
                if tmp2 is not None:
                    tmp2.next = tmp
                num -= 1
                if tmp.left:
                    queue.append(tmp.left)
                    num += 1
                if tmp.right:
                    queue.append(tmp.right)
                    num += 1
        return