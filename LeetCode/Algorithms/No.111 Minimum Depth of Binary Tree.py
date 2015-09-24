class Solution(object):
    def minDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        num = 1
        queue = []
        if root is None:
            return 0
        queue.append(root)
        cen = 1
        while len(queue):
            level = []
            for i in range(num):
                tmp = queue.pop(0)
                if tmp.left is None and tmp.right is None :
                    return cen
                num -= 1
                if tmp.left:
                    queue.append(tmp.left)
                    num += 1
                if tmp.right:
                    queue.append(tmp.right)
                    num += 1
            cen += 1