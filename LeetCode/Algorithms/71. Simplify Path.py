class Solution(object):
    def simplifyPath(self, path):
        """
        :type path: str
        :rtype: str
        """
        sp = path.split('/')
        stack = []
        for i in sp:
            if i == '':
                continue
            elif i == '.':
                continue
            elif i == '..':
                if stack:
                    stack.pop()
                else:
                    continue
            else:
                stack.append(i)
        res = ''
        if len(stack)==0:
            res = '/'
        else:
            for i in range(len(stack)):
                res += '/'+stack[i]
        return res