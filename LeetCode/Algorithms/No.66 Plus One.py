class Solution(object):
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        result = [0] + digits
        tail = len(result)-1
        up = 1
        while tail != -1:
            if result[tail] + up == 10:
                up = 1
                result[tail] = 0
                tail -= 1
            else:
                result[tail] += 1
                up = 0
                break
        if result[0] == 0:
            result.pop(0)
        return result
