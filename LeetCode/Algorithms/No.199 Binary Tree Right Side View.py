class Solution(object):
    def rightSideView(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        queue = []
        num = 1
        res = []
        if root is None:
            return res
        queue.append(root)
        while len(queue):
            tmp = None
            for i in range(num):
                tmp = queue.pop(0)
                num -= 1
                if tmp.left:
                    queue.append(tmp.left)
                    num += 1
                if tmp.right:
                    queue.append(tmp.right)
                    num += 1
            res.append(tmp.val)
        return res