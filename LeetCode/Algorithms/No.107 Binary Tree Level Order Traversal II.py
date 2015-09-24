
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def levelOrderBottom(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        num = 1
        queue = []
        result = []
        if root is None:
            return queue
        queue.append(root)
        while len(queue):
            level = []
            for i in range(num):
                tmp = queue.pop(0)
                num -= 1
                level.append(tmp.val)
                if tmp.left:
                    queue.append(tmp.left)
                    num += 1
                if tmp.right:
                    queue.append(tmp.right)
                    num += 1
            result.append(level)
        result.reverse()
        return result

