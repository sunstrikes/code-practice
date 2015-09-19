class Solution(object):
    def maximalRectangle(self, matrix):
        """
        :type matrix: List[List[str]]
        :rtype: int
        """
        ll = []
        for i in range(len(matrix)):
            tmp = []
            for j in range(len(matrix[i])):
                if matrix[i][j]== '0':
                    tmp.append(0)
                else:
                    tmp.append(1)
            ll.append(tmp)
        for i in range(len(ll)-2, -1, -1):
            for j in range(len(ll[i])):
                if ll[i][j]!=0 and ll[i][j]!=0:
                    ll[i][j] = ll[i][j] + ll[i+1][j]
        max_area = 0
        min_len = 99999
        num = 0
        for i in range(len(ll)):
            max_area = max(max_area, self.largest_retangle(ll[i]))
        return max_area

    def largest_retangle(self, height):
        stack = []
        area = 0
        i = 0
        while i != len(height):
            if len(stack) == 0 or height[stack[len(stack)-1]] < height[i]:
                stack.append(i)
                i += 1
            else:
                start = stack[len(stack)-1]
                stack.pop()
                width = 0
                if len(stack) == 0:
                    width = i
                else:
                    width = i - stack[len(stack)-1] - 1
                area = max(area, height[start]*width)

        while len(stack) != 0:
            start = stack.pop()
            width = 0
            if len(stack) == 0:
                width = len(height)
            else:
                width = len(height) - stack[len(stack)-1] - 1
            area = max(area,height[start]*width)
        return area
